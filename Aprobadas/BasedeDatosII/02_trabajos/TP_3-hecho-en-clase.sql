--SALA 3 Turno Mañana

/*En función de un código, realizar los siguientes procedimientos. Si el código es:
1 – Mostrar el menor precio de los artículos existentes.
2 – Mostrar cuál es el valor del precio máximo de todos los productos.
3 – Mostrar cuántos clientes tiene la empresa.
4 – Mostrar cuántas facturas se emitieron este mes.
5 – Mostrar la media del precio unitario de los ofrecidos. Para cualquier otro valor ingresado hay que indicar que el código no es válido.*/

DECLARE
    v_codigo NUMBER := &codigo;
    v_menor_precio productos.precio_unitario%TYPE;
    v_res NUMBER;
BEGIN
    IF v_codigo = 1 THEN
        SELECT MIN(precio_unitario) 
        INTO v_menor_precio
        FROM productos;

        DBMS_OUTPUT.PUT_LINE('Menor precio: $' || v_menor_precio);

    ELSIF v_codigo = 2 THEN
        SELECT MAX(precio_unitario) 
        INTO v_menor_precio
        FROM productos;

        DBMS_OUTPUT.PUT_LINE('Precio máximo: $' || v_menor_precio);

    ELSIF v_codigo = 3 THEN
        SELECT COUNT(*)
        INTO v_res
        FROM clientes;

        DBMS_OUTPUT.PUT_LINE('Cant. clientes: ' || v_res);

    ELSIF v_codigo = 4 THEN
        SELECT COUNT(*)
        INTO v_res
        FROM facturas
        WHERE EXTRACT(MONTH from fecha_emision) = EXTRACT(MONTH FROM SYSDATE)
        AND EXTRACT(YEAR FROM fecha_emision) = EXTRACT(YEAR FROM SYSDATE);

        DBMS_OUTPUT.PUT_LINE('Facturas este mes: ' || v_res);

    ELSIF v_codigo = 5 THEN
        SELECT AVG(precio_unitario)
        INTO v_menor_precio
        FROM productos;

        DBMS_OUTPUT.PUT_LINE('Precio unitario promedio: $' || v_menor_precio);

    ELSE
        DBMS_OUTPUT.PUT_LINE('ERROR: Código inválido.');
    END IF;

END;
/

 

-- 2. Dar de alta una Localidad del Municipio de La Matanza, ID 20, con todos sus datos. (Municipios de La 
-- Matanza: San Justo, Ramos Mejía, Aldo Bonzi, Rafael Castillo, Ciudad Evita, Gonzalez Catán, Gregorio de 
-- Laferrere, La Tablada, Lomas del Mirador, Isidro Casanova, Tapiales, 20 de Junio, Villa Eduardo Madero, Villa 
-- Luzuriaga, y Virrey del Pino.) 
INSERT INTO localidades (municipio_id, nombre)
VALUES (20, 'San Justo');

 

INSERT INTO localidades (municipio_id, nombre)
VALUES (20, 'Ramos Mejía');

 

-- 3. Mostrar la superficie y el nombre de la capital de la provincia de Buenos Aires. (El código de la provincia de 
-- Buenos Aires es 1). 
SELECT superficie, capital
FROM provincias
WHERE id = 1;

 

-- 4. Crear un procedimiento, de nombre BORRAR_CLIENTE, que permita borrar el registro de un cliente, cuyo 
-- número se pasará en la llamada de la tabla clientes. 
CREATE OR REPLACE PROCEDURE borrar_cliente (
    p_id_cliente in clientes.cod_cliente%TYPE
)
IS
BEGIN
    DELETE FROM clientes
    WHERE cod_cliente = p_id_cliente;

    DBMS_OUTPUT.PUT_LINE('Cliente de código ' || p_id_cliente || ' eliminado correctamente.'); 
END;
/

 

BEGIN
    borrar_cliente('C0010');
END;
/
-- C0010  Flor Paz  Lince  3564165

 

-- 5. Escribir un procedimiento almacenado que permita actualizar el importe total de una factura, según el 
-- detalle que tenga asignado. El código que identifica la factura debe enviarse como parámetro de entrada. 
CREATE OR REPLACE PROCEDURE actualizar_total_factura (
    p_id_factura IN facturas.cod_factura%TYPE
)
IS 
    v_total facturas.importe_total%TYPE;
BEGIN
    SELECT SUM(subtotal)
    INTO v_total
    FROM detalle_facturas
    WHERE cod_factura = p_id_factura;

    UPDATE facturas
    SET importe_total = v_total
    WHERE cod_factura = p_id_factura;

    DBMS_OUTPUT.PUT_LINE('Total actualizado: $' || v_total);
END;
/

 

BEGIN
    actualizar_total_factura('F0010');
END;
/

 

-- 6. Crear un procedimiento que permita insertar información al detalle de una factura existente (el producto 
-- vendido, su cantidad y el subtotal de la venta). Considere que la Factura existe. 
CREATE OR REPLACE PROCEDURE insertar_detalle_factura (
    p_cod_factura in detalle_facturas.cod_factura%TYPE,
    p_cod_producto in detalle_facturas.cod_producto%TYPE,
    p_cantidad in detalle_facturas.cantidad%TYPE,
    p_subtotal in detalle_facturas.subtotal%TYPE
)
IS
BEGIN
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

    DBMS_OUTPUT.PUT_LINE('Detalle de factura insertado correctamente.');

    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('ERROR: Hiciste alguna cagada.');
END;
/

 

BEGIN
    insertar_detalle_factura(
        'F0010',
        'P0011',
        2,
        3000
    );
END;
/

 

-- B. Uso de Cursores Explícitos.  
-- 1. Muestre cuál sería el mail institucional de cada alumno cuyo usuario se forma con la inicial de su primer 
-- nombre adicionándole su apellido y los tres últimos dígitos de su legajo, usando como dominio 
-- ‘frh.utn.edu.ar’. (Por ejemplo, Aida Irene Blat, legajo 123456, el mail será ablat456@frh.utn.edu.ar) 
DECLARE
    CURSOR c_clientes IS
        SELECT nombres, distrito, telefono
        FROM clientes;

    v_nombre clientes.nombres%TYPE;
    v_distrito clientes.distrito%TYPE;
    v_telefono clientes.telefono%TYPE;

    v_mail VARCHAR2(100);

 

BEGIN
    OPEN c_clientes;

    LOOP
        FETCH c_clientes INTO v_nombre, v_distrito, v_telefono;

        EXIT WHEN c_clientes%NOTFOUND;

        v_mail :=
            LOWER(SUBSTR(v_nombre, 1, 1)) ||
            LOWER(REPLACE(v_distrito, ' ', '')) ||
            SUBSTR(v_telefono, -3) ||
            '@cliente.desto.yqs';

        DBMS_OUTPUT.PUT_LINE('Mail generado: ' || v_mail);

    END LOOP;

    CLOSE c_clientes;
END;
/

 

-- 2. Mostrar de cada provincia la cantidad de municipios que tiene. 
DECLARE
    CURSOR c_provincias IS
        SELECT id, nombre
        FROM provincias;

    v_id_prov provincias.id%TYPE;
    v_nombre_prov provincias.nombre%TYPE;

    v_cant_mun NUMBER;

BEGIN
    OPEN c_provincias;

    LOOP
        FETCH c_provincias INTO v_id_prov, v_nombre_prov;

        EXIT WHEN c_provincias%NOTFOUND;

        SELECT COUNT(*)
        INTO v_cant_mun
        FROM municipios
        WHERE provincia_id = v_id_prov;

        DBMS_OUTPUT.PUT_LINE('Hay ' || v_cant_mun || ' municipios en: ' || v_nombre_prov);

    END LOOP;

    CLOSE c_provincias;
END;
/

 

-- 3. Escribir un procedimiento almacenado que actualice el importe total de todas las facturas, según el detalle 
-- que tengan asignadas. 
CREATE OR REPLACE PROCEDURE actualizar_importe_facturas
IS
    CURSOR c_facturas IS
        SELECT cod_factura
        FROM facturas;

    v_fac_cod_fac   facturas.cod_factura%TYPE;

    CURSOR c_detalle_facturas IS
        SELECT cod_factura, subtotal
        FROM detalle_facturas;

    v_df_cod_fac    detalle_facturas.cod_factura%TYPE;
    v_df_subtotal   detalle_facturas.subtotal%TYPE;

    v_total         facturas.importe_total%TYPE;

BEGIN
    OPEN c_facturas;

    LOOP
        FETCH c_facturas INTO v_fac_cod_fac;

        EXIT WHEN c_facturas%NOTFOUND;

        v_total := 0;

        OPEN c_detalle_facturas;

        LOOP
            FETCH c_detalle_facturas INTO v_df_cod_fac, v_df_subtotal;

                EXIT WHEN c_detalle_facturas%NOTFOUND;

                IF v_df_cod_fac = v_fac_cod_fac THEN
                    v_total := v_total + v_df_subtotal;
                END IF;

        END LOOP;

        CLOSE c_detalle_facturas;

        UPDATE facturas 
        SET importe_total = v_total 
        WHERE cod_factura = v_fac_cod_fac;

        DBMS_OUTPUT.PUT_LINE('(' || v_fac_cod_fac || ') Importe actualizado a $' || v_total || ' correctamente.');

    END LOOP;

    CLOSE c_facturas;
END;
/

 

BEGIN
    actualizar_importe_facturas();
END;
/

 

-- 4. Hacer un listado de los alumnos en el que figure de cada uno su apellido, nombre y, si su edad fuese mayor 
-- o igual a 21, indicarlo mediante un mensaje (por ejemplo, ‘Mayor de edad’). Caso contrario colocar una 
-- leyenda con 5 guiones altos '-----’. NOTA: utilizar la función DIF_FECHAS del punto C1.  

 

 

-- 5. Devolver un reporte con la lista de todas facturas agrupadas de un cliente e indique el monto total facturado.

 

 

-- 6. Calcular el total que se le ha facturado a cada una de las empresas clientes, desde una fecha dada hasta el 
-- presente.

 



