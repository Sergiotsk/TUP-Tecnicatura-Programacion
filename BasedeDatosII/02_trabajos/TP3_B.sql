--1)Muestre cuál sería el mail institucional de cada alumno cuyo usuario se forma con:
--- la inicial de su primer nombre adicionándole su apellido y los tres últimos dígitos de su legajo, usando como dominio `frh.utn.edu.ar`.
---*(Por ejemplo, Aida Irene Blat, legajo 123456, el mail será `ablat456@frh.utn.edu.ar`).*
/*
DECLARE
  
    CURSOR c_mails IS
        SELECT
            LOWER(
                SUBSTR(nombre, 1, 1) || apellido || SUBSTR(TO_CHAR(id), -3)
            ) || '@frh.utn.edu.ar' AS mail_institucional
        FROM empleados;

BEGIN
    
    FOR r IN c_mails LOOP
        DBMS_OUTPUT.PUT_LINE(r.mail_institucional);
    END LOOP;
END;
/


--2)Mostrar de cada **provincia** la cantidad de **municipios** que tiene.



DECLARE
    CURSOR c_municipios IS 
        SELECT id,nombre    
        from provincias;
l_id_prov provincias.id%type;
l_nombre_prov provincias.nombre%type;
l_cant_muni  number(3);

begin
  for r in c_municipios loop
    select COUNT(*)
      into l_cant_muni
      from municipios    
     where r.id = provincia_id;

     DBMS_OUTPUT.PUT_LINE(r.nombre||'tiene '||l_cant_muni||' municipios');

    
  end loop;
end;
/

*/

--3)Escribir un procedimiento almacenado que actualice el importe total de todas las facturas, según el detalle que tengan asignadas.


CREATE OR REPLACE PROCEDURE actualizar_importes AS
    -- Cursor que recorre todas las facturas
    CURSOR c_facturas IS
        SELECT cod_factura FROM facturas;
    l_total detalle_facturas.subtotal%TYPE;
BEGIN
    FOR r IN c_facturas LOOP
        -- Por cada factura, calculamos la suma de cantidad * precio de su detalle
        SELECT SUM(df.cantidad * p.precio_unitario)
          INTO l_total
          FROM detalle_facturas df
          JOIN productos p ON df.cod_producto = p.cod_producto
         WHERE df.cod_factura = r.cod_factura;

        -- Actualizamos el importe total de esa factura
        UPDATE facturas
           SET importe_total = l_total
         WHERE cod_factura = r.cod_factura;

        DBMS_OUTPUT.PUT_LINE('Factura ' || r.cod_factura || ' actualizada a: ' || l_total);
    END LOOP;
    COMMIT;
END actualizar_importes;
/

-- Ejecutar
EXEC actualizar_importes;
