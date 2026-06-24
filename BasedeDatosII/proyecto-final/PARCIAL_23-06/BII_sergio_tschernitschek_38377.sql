
/*   1. ESPECIFICACION DEL PAQUETE */
CREATE OR REPLACE PACKAGE PKG_VETERINARIA AS

    EX_MASCOTA_INEXISTENTE     EXCEPTION;
    EX_VETERINARIO_INEXISTENTE EXCEPTION;
    EX_VETERINARIO_INACTIVO    EXCEPTION;
    EX_STOCK_INSUFICIENTE      EXCEPTION;

    FUNCTION  GESTION_CONSULTAS       (p_veterinario IN VARCHAR2, p_mascota_id IN NUMBER) RETURN NUMBER;
    PROCEDURE GESTION_STOCK_PRODUCTOS (p_producto_id IN NUMBER,   p_cantidad   IN NUMBER);
    PROCEDURE GESTION_STOCK_PRODUCTOS (p_nombre      IN VARCHAR2, p_tipo       IN VARCHAR2, p_cantidad IN NUMBER);

END PKG_VETERINARIA;
/

/* 2. CUERPO DEL PAQUETE  */
CREATE OR REPLACE PACKAGE BODY PKG_VETERINARIA AS

    FUNCTION GESTION_CONSULTAS(p_veterinario IN VARCHAR2, p_mascota_id IN NUMBER) RETURN NUMBER IS
        v_veterinario_id VETERINARIOS.ID_VETERINARIO%TYPE;
        v_activo         VETERINARIOS.ACTIVO%TYPE;
        v_count          NUMBER;
        v_consulta_id    CONSULTAS.ID_CONSULTA%TYPE;
    BEGIN
        -- Validar que la mascota exista
        SELECT COUNT(*) INTO v_count FROM MASCOTAS WHERE ID_MASCOTA = p_mascota_id;
        IF v_count = 0 THEN
            RAISE EX_MASCOTA_INEXISTENTE;
        END IF;

        -- Resolver el veterinario: numero=ID, @ =email, texto=apellido
        IF REGEXP_LIKE(p_veterinario, '^[0-9]+$') THEN
            v_veterinario_id := TO_NUMBER(p_veterinario);
        ELSIF REGEXP_LIKE(p_veterinario, '@') THEN
            SELECT ID_VETERINARIO INTO v_veterinario_id
            FROM VETERINARIOS WHERE EMAIL = p_veterinario;
        ELSE
            SELECT ID_VETERINARIO INTO v_veterinario_id
            FROM VETERINARIOS WHERE UPPER(APELLIDO) = UPPER(p_veterinario);
        END IF;

        -- Validar existencia y estado activo del veterinario
        SELECT ACTIVO INTO v_activo
        FROM VETERINARIOS WHERE ID_VETERINARIO = v_veterinario_id;

        IF v_activo = 'N' THEN
            RAISE EX_VETERINARIO_INACTIVO;
        END IF;

        -- Registrar el turno en estado PENDIENTE
        INSERT INTO CONSULTAS(ID_MASCOTA, ID_VETERINARIO, ESTADO)
        VALUES (p_mascota_id, v_veterinario_id, 'PENDIENTE')
        RETURNING ID_CONSULTA INTO v_consulta_id;

        RETURN v_consulta_id;

    EXCEPTION
        WHEN EX_MASCOTA_INEXISTENTE THEN
            RAISE_APPLICATION_ERROR(-20001, 'ERROR: La mascota indicada no existe en el sistema');
        WHEN EX_VETERINARIO_INACTIVO THEN
            RAISE_APPLICATION_ERROR(-20002, 'ERROR: El veterinario se encuentra inactivo');
        WHEN NO_DATA_FOUND THEN
            RAISE_APPLICATION_ERROR(-20003, 'ERROR: El veterinario no existe en el sistema');
    END GESTION_CONSULTAS;

/*==========================================================================*/

    PROCEDURE GESTION_STOCK_PRODUCTOS(p_producto_id IN NUMBER, p_cantidad IN NUMBER) IS
        v_stock PRODUCTOS.STOCK%TYPE;
        v_count NUMBER;
    BEGIN
        SELECT COUNT(*) INTO v_count FROM PRODUCTOS WHERE ID_PRODUCTO = p_producto_id;
        IF v_count = 0 THEN
            RAISE_APPLICATION_ERROR(-20004, 'ERROR: Producto no encontrado');
        END IF;

        SELECT STOCK INTO v_stock FROM PRODUCTOS WHERE ID_PRODUCTO = p_producto_id;

        IF v_stock < p_cantidad THEN
            RAISE EX_STOCK_INSUFICIENTE;
        END IF;

        UPDATE PRODUCTOS SET STOCK = STOCK - p_cantidad WHERE ID_PRODUCTO = p_producto_id;

    EXCEPTION
        WHEN EX_STOCK_INSUFICIENTE THEN
            RAISE_APPLICATION_ERROR(-20005, 'ERROR: Stock insuficiente. Disponible: ' || v_stock);
    END GESTION_STOCK_PRODUCTOS;

/*==========================================================================*/

    PROCEDURE GESTION_STOCK_PRODUCTOS(p_nombre IN VARCHAR2, p_tipo IN VARCHAR2, p_cantidad IN NUMBER) IS
        v_producto_id PRODUCTOS.ID_PRODUCTO%TYPE;
    BEGIN
        SELECT ID_PRODUCTO INTO v_producto_id
        FROM PRODUCTOS
        WHERE UPPER(NOMBRE) = UPPER(p_nombre) AND UPPER(TIPO) = UPPER(p_tipo);

        GESTION_STOCK_PRODUCTOS(v_producto_id, p_cantidad);

    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RAISE_APPLICATION_ERROR(-20004, 'ERROR: Producto no encontrado con el nombre y tipo indicados');
    END GESTION_STOCK_PRODUCTOS;

END PKG_VETERINARIA;
/

/* 3. PROCEDIMIENTO DE AUDITORIA (AUTONOMO)*/
CREATE OR REPLACE PROCEDURE REG_CONTROL_VET(
    p_tabla     IN VARCHAR2,
    p_operacion IN VARCHAR2,
    p_id        IN NUMBER,
    p_anterior  IN VARCHAR2,
    p_nuevo     IN VARCHAR2
) IS
    PRAGMA AUTONOMOUS_TRANSACTION;
BEGIN
    INSERT INTO CONTROL_VETERINARIA(TABLA_AFECTADA, OPERACION, ID_REGISTRO, VALOR_ANTERIOR, VALOR_NUEVO)
    VALUES (p_tabla, p_operacion, p_id, p_anterior, p_nuevo);
    COMMIT;
END REG_CONTROL_VET;
/

/*4. TRIGGER - CONTROL DE PRECIO EN DETALLE_CONSULTAS*/

CREATE OR REPLACE TRIGGER TRG_PRECIO_DETALLE
BEFORE INSERT ON DETALLE_CONSULTAS
FOR EACH ROW
DECLARE
    v_precio PRODUCTOS.PRECIO_UNITARIO%TYPE;
BEGIN
    IF :NEW.PRECIO_UNITARIO IS NULL OR :NEW.PRECIO_UNITARIO = 0 THEN

        SELECT PRECIO_UNITARIO INTO v_precio
        FROM PRODUCTOS WHERE ID_PRODUCTO = :NEW.ID_PRODUCTO;

        REG_CONTROL_VET(
            'DETALLE_CONSULTAS',
            'INSERT',
            :NEW.ID_CONSULTA,
            TO_CHAR(NVL(:NEW.PRECIO_UNITARIO, 0)),
            TO_CHAR(v_precio)
        );

        :NEW.PRECIO_UNITARIO := v_precio;
    END IF;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        RAISE_APPLICATION_ERROR(-20006, 'ERROR: No se encontro el producto para obtener su precio vigente');
END TRG_PRECIO_DETALLE;
/

SET SERVEROUTPUT ON;
/

/* BLOQUES DE PRUEBA - GESTION_CONSULTAS */

-- Prueba por ID de veterinario
DECLARE
    v_id NUMBER;
BEGIN
    v_id := PKG_VETERINARIA.GESTION_CONSULTAS('1', 3);
    DBMS_OUTPUT.PUT_LINE('Consulta registrada con ID: ' || v_id);
END;
/
COMMIT;

-- Prueba por email de veterinario
DECLARE
    v_id NUMBER;
BEGIN
    v_id := PKG_VETERINARIA.GESTION_CONSULTAS('ana.suarez@vet.com', 5);
    DBMS_OUTPUT.PUT_LINE('Consulta registrada con ID: ' || v_id);
END;
/
COMMIT;

-- Prueba por apellido de veterinario
DECLARE
    v_id NUMBER;
BEGIN
    v_id := PKG_VETERINARIA.GESTION_CONSULTAS('Mendez', 7);
    DBMS_OUTPUT.PUT_LINE('Consulta registrada con ID: ' || v_id);
END;
/
COMMIT;

/*BLOQUES DE PRUEBA - GESTION_STOCK_PRODUCTOS*/

-- Prueba sobrecarga 1: por ID de producto
BEGIN
    PKG_VETERINARIA.GESTION_STOCK_PRODUCTOS(1, 5);
    DBMS_OUTPUT.PUT_LINE('Stock descontado correctamente por ID');
END;
/
COMMIT;

-- Prueba sobrecarga 2: por nombre y tipo
BEGIN
    PKG_VETERINARIA.GESTION_STOCK_PRODUCTOS('Meloxicam Inyectable', 'Medicamento', 2);
    DBMS_OUTPUT.PUT_LINE('Stock descontado correctamente por nombre y tipo');
END;
/
COMMIT;

/*BLOQUES DE PRUEBA - TRIGGER TRG_PRECIO_DETALLE*/

-- Prueba: insertar detalle sin precio (= 0), debe completarse automaticamente
BEGIN
    INSERT INTO DETALLE_CONSULTAS(ID_CONSULTA, ID_PRODUCTO, CANTIDAD, PRECIO_UNITARIO)
    VALUES (19, 4, 1, 0);
    DBMS_OUTPUT.PUT_LINE('Detalle insertado. Precio completado automaticamente por trigger.');
END;
/
COMMIT;

-- Verificar el registro generado en CONTROL_VETERINARIA
SELECT * FROM CONTROL_VETERINARIA;
