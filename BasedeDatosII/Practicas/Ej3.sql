/* 1) En función de un código, realizar los siguientes procedimientos. Si el código es: 
    1 – Mostrar el menor precio de los artículos existentes.
    2 – Mostrar cuál es el valor del precio máximo de todos los productos. 
    3 – Mostrar cuántos clientes tiene la empresa. 
    4 – Mostrar cuántas facturas se emitieron este mes. 
    5 – Mostrar la media del precio unitario de los ofrecidos. Para cualquier otro valor ingresado hay que indicar que el código no es válido. */
/*
DECLARE
    v_codigo NUMBER := &codigo;
    v_precio productos.precio_unitario%TYPE;
    v_res NUMBER;
BEGIN
    IF v_codigo = 1 THEN
        SELECT MIN(precio_unitario) 
        INTO v_precio
        FROM productos;

        DBMS_OUTPUT.PUT_LINE('Menor precio: $' || v_precio);

    ELSIF v_codigo = 2 THEN
        SELECT MAX(precio_unitario) 
        INTO v_precio
        FROM productos;

        DBMS_OUTPUT.PUT_LINE('Precio máximo: $' || v_precio);

    ELSIF v_codigo = 3 THEN
        SELECT COUNT(*)
        INTO v_res
        FROM clientes;

        DBMS_OUTPUT.PUT_LINE('Cant. clientes: ' || v_res);

    ELSIF v_codigo = 4 THEN
        SELECT COUNT(*)
        INTO v_res
        FROM facturas
        WHERE EXTRACT(MONTH FROM fecha_emision) = EXTRACT(MONTH FROM SYSDATE)
        AND EXTRACT(YEAR FROM fecha_emision) = EXTRACT(YEAR FROM SYSDATE);

        DBMS_OUTPUT.PUT_LINE('Facturas este mes: ' || v_res);

    ELSIF v_codigo = 5 THEN
        SELECT AVG(precio_unitario)
        INTO v_precio
        FROM productos;

        DBMS_OUTPUT.PUT_LINE('Precio unitario promedio: $' || v_precio);

    ELSE
        DBMS_OUTPUT.PUT_LINE('ERROR: Código inválido.');
    END IF;

END;
/

--2)Dar de alta una Localidad del Municipio de La Matanza, ID 20, con todos sus datos.
-- (Municipios de La Matanza: San Justo, Ramos Mejía, Aldo Bonzi, Rafael Castillo, Ciudad Evita, Gonzalez Catán,
-- Gregorio de Laferrere, La Tablada, Lomas del Mirador, Isidro Casanova, Tapiales, 20 de Junio, Villa Eduardo Madero,
-- Villa Luzuriaga, y Virrey del Pino.)

INSERT INTO localidades (municipio_id,nombre)   
    values (20,'San justo');

--3)Mostrar la superficie y el nombre de la capital de la provincia de Buenos Aires. (El código de la provincia de Buenos Aires es 1).


DECLARE
    v_superficie provincias.superficie%TYPE;
    v_nombre provincias.nombre%TYPE;
BEGIN
    SELECT superficie, nombre 
    INTO v_superficie, v_nombre
    FROM provincias
    WHERE id = 1;

    DBMS_OUTPUT.PUT_LINE('La capital de la provincia de Buenos Aires es ' || v_nombre || ' y su superficie es ' || v_superficie || ' km².');
END;
/







--6)Crear un procedimiento que permita insertar información al detalle de una factura existente (el producto vendido,
-- su cantidad y el subtotal de la venta). Considere que la Factura existe.

CREATE OR REPLACE PROCEDURE sp_insertar_detalle_factura (
    -- CORRECCIÓN 1: Los códigos de factura y producto en la tabla son CHAR(5) ('F0001'), no NUMBER.
    p_cod_factura  IN CHAR,   
    p_cod_producto IN CHAR,   
    p_cantidad     IN NUMBER, 
    -- CORRECCIÓN 2: El enunciado pide explícitamente \"el subtotal de la venta\" como dato.
    p_subtotal     IN NUMBER  
)
IS
    -- Ya no necesitamos la variable v_subtotal porque el dato entra directo por parámetro.
BEGIN
    -- CORRECCIÓN 3: El nombre correcto de la tabla es detalle_facturas.
    -- CORRECCIÓN 4: Usamos estrictamente las columnas que existen en la tabla (no hay precio_unitario).
    INSERT INTO detalle_facturas (
        cod_factura,
        cod_producto,
        cantidad,
        subtotal
    )
    VALUES (
        p_cod_factura,
        p_cod_producto,
        p_cantidad,
        p_subtotal
    );

    COMMIT;

    DBMS_OUTPUT.PUT_LINE('Detalle agregado correctamente a la factura ' || p_cod_factura);

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
        ROLLBACK;
END;
/

EXEC sp_insertar_detalle_factura('F0001', 'P0003', 2, 1680);


*/
/*B) Uso de Cursores Explícitos.  Crear los siguientes bloques en PL/SQL:*/

/* 1. Muestre cuál sería el mail institucional de cada alumno cuyo usuario se forma con la inicial de su primer nombre adicionándole su apellido y los tres últimos dígitos de su legajo, usando como dominio ‘frh.utn.edu.ar’. (Por ejemplo, Aida Irene Blat, legajo 123456, el mail será ablat456@frh.utn.edu.ar) */

/*
================================================================================
TEORÍA: ¿QUÉ ES UN CURSOR EXPLÍCITO Y POR QUÉ LO USAMOS ACÁ?
================================================================================
Cuando hacemos un "SELECT ... INTO", Oracle exige que el resultado sea EXACTAMENTE UNA FILA.
Si hacemos un SELECT de TODOS los alumnos, nos devuelve muchas filas y el INTO explota ("too many rows").
Para procesar múltiples filas, usamos un CURSOR. Imaginá el cursor como una "cinta transportadora" 
que guarda en memoria todas las filas de tu consulta y nos permite sacarlas de a una usando un LOOP.

Pasos automáticos del CURSOR FOR LOOP:
1. DECLARE: Definimos la consulta en el cursor.
2. OPEN / FETCH / CLOSE: El "FOR r_alumno IN c_alumnos" se encarga de abrir la consulta, 
   leer fila por fila guardando los datos en la variable "r_alumno", y cerrar todo al terminar.
================================================================================


DECLARE
    -- PASO 1: Declaramos el cursor con la consulta que devuelve MÚLTIPLES filas.
    -- (Aclaración: como no vi una tabla 'alumnos' en tus scripts, uso la tabla 'empleados' 
    -- asumiendo que representa a los alumnos, usando su ID como legajo. Si tenés otra tabla, cambialo).
    CURSOR c_alumnos IS 
        SELECT nombre, apellido, id as legajo FROM empleados;
        
    v_mail VARCHAR2(100);
BEGIN
    DBMS_OUTPUT.PUT_LINE('--- LISTADO DE MAILS INSTITUCIONALES ---');
    
    -- PASO 2: Recorremos el cursor. Por cada vuelta, 'r_alumno' tiene los datos de una sola persona.
    FOR r_alumno IN c_alumnos LOOP
    
        -- PASO 3: Lógica individual por fila. 
        -- SUBSTR(r_alumno.nombre, 1, 1) extrae 1 letra empezando desde la posición 1.
        -- SUBSTR(r_alumno.legajo, -3) extrae los últimos 3 caracteres contando de atrás para adelante.
        -- LOWER() lo convierte todo a minúsculas para que el mail quede prolijo.
        v_mail := LOWER(
            SUBSTR(r_alumno.nombre, 1, 1) || 
            r_alumno.apellido || 
            SUBSTR(r_alumno.legajo, -3) || 
            '@frh.utn.edu.ar'
        );
        
        -- PASO 4: Imprimimos en pantalla
        DBMS_OUTPUT.PUT_LINE('Nombre: ' || r_alumno.nombre || ' ' || r_alumno.apellido || ' -> Mail: ' || v_mail);
        
    END LOOP;
END;
/


*/
-- 2. Mostrar de cada provincia la cantidad de municipios que tiene.

DECLARE 
    CURSOR c_provincias IS
        SELECT nombre, id FROM provincias;
    
    v_cant_municipios NUMBER;
BEGIN
    FOR r_prov IN c_provincias LOOP
        SELECT COUNT(*)
        INTO v_cant_municipios
        FROM MUNICIPIOS
        WHERE provincia_id = r_prov.id;
        
        DBMS_OUTPUT.PUT_LINE('Provincia: ' || r_prov.nombre || ' - Cantidad de Municipios: ' || v_cant_municipios);
    END LOOP;
END;
/

-- 3. Escribir un procedimiento almacenado que actualice el importe total de todas las facturas, según el detalle que tengan asignadas.

CREATE OR REPLACE PROCEDURE sp_actualizar_total_facturas
IS
    -- Declaramos el cursor explícito. 
    -- Usamos LEFT JOIN para asegurarnos de traer todas las facturas, incluso si no tienen detalle.
    -- NVL(..., 0) asegura que si no hay detalle, el total sea 0 en lugar de NULL.
    CURSOR c_totales IS
        SELECT f.cod_factura, NVL(SUM(df.subtotal), 0) AS total_calculado
        FROM facturas f
        LEFT JOIN detalle_facturas df ON f.cod_factura = df.cod_factura
        GROUP BY f.cod_factura;
BEGIN
    -- Recorremos el cursor. Cada vuelta nos trae una factura y su total calculado.
    FOR r_total IN c_totales LOOP
        
        -- Actualizamos la tabla facturas usando los datos de la fila actual del cursor
        UPDATE facturas
        SET importe_total = r_total.total_calculado
        WHERE cod_factura = r_total.cod_factura;
        
    END LOOP;
    
    -- Consolidamos los cambios
    COMMIT;
    
    DBMS_OUTPUT.PUT_LINE('Se actualizaron exitosamente los importes de todas las facturas usando cursores explícitos.');
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error inesperado: ' || SQLERRM);
        ROLLBACK;
END;
/

/*
* 4. Hacer un listado de los alumnos en el que figure de cada uno su apellido, nombre y, si su edad fuese mayor o igual a 21, indicarlo mediante un mensaje (por ejemplo, ‘Mayor de edad’). Caso contrario colocar una leyenda con 5 guiones altos '-----’. NOTA: utilizar la función DIF_FECHAS del punto C1.
* 5. Devolver un reporte con la lista de todas facturas agrupadas de un cliente e indique el monto total facturado.
* 6. Calcular el total que se le ha facturado a cada una de las empresas clientes, desde una fecha dada hasta el presente.
*/
