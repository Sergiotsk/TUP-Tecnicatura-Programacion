/*
Crear los siguientes bloques en PL/SQL:

1. En función de un código, realizar los siguientes procedimientos. Si el código es:

   - `1` → Mostrar el menor precio de los artículos existentes.
   - `2` → Mostrar cuál es el valor del precio máximo de todos los productos.
   - `3` → Mostrar cuántos clientes tiene la empresa.
   - `4` → Mostrar cuántas facturas se emitieron este mes.
   - `5` → Mostrar la media del precio unitario de los ofrecidos.

   Para cualquier otro valor ingresado hay que indicar que el código no es válido.*/
/*   
   DECLARE
    v_code number(1) := &Ingrese_numero_1_2_3_4_5;
    l_precio productos.precio_unitario%type;
    l_clientes clientes.cod_cliente%type;
    l_facturas facturas.cod_factura%type;


  begin
    case 
      when v_code = 1 then
        select MIN (precio_unitario)
          into l_precio
          from productos;
         
          DBMS_OUTPUT.PUT_LINE('El menor precio es: '||l_precio);

      when v_code = 2 then 
       select MAX (precio_unitario)
          into l_precio
          from productos;
        
          DBMS_OUTPUT.PUT_LINE('El mayor precio es: '||l_precio);

      when v_code = 3 then 
       select count(*)
          into l_clientes
          from clientes;
         
          DBMS_OUTPUT.PUT_LINE('La cantidad de clientes es: '||l_clientes);

      when v_code = 4 then 
       select count(*)
          into l_facturas
          from facturas;
         
          DBMS_OUTPUT.PUT_LINE('Facturas emitidas este mes: '||l_facturas);

      when v_code = 5 then 
          select AVG(importe_total)
          into l_precio
          from facturas
          where EXTRACT(month from fecha_emision)= EXTRACT(month from current_date)
          and EXTRACT(year from fecha_emision) = EXTRACT(year from current_date);
         
          DBMS_OUTPUT.PUT_LINE('El promedio es: '||l_precio);

      else 
      DBMS_OUTPUT.PUT_LINE('CODIGO INCORRECTO');
    end case;
    end;
  / 

--2)Dar de alta una Localidad del Municipio de La Matanza, ID `20`, con todos sus datos.

---(Municipios de La Matanza: San Justo, Ramos Mejía, Aldo Bonzi, Rafael Castillo, Ciudad Evita, 
---Gonzalez Catán, Gregorio de Laferrere, La Tablada, Lomas del Mirador, Isidro Casanova, Tapiales,
---20 de Junio, Villa Eduardo Madero, Villa Luzuriaga, y Virrey del Pino.)

INSERT INTO localidades (municipio_id, nombre)
VALUES (20, 'San Justo');

   


--3)Mostrar la superficie y el nombre de la capital de la provincia de Buenos Aires.
--- *(El código de la provincia de Buenos Aires es 1).*

    SELECT superficie, capital
    FROM provincias
    WHERE id = 1 ;

*/

-- 4. Crear un procedimiento, de nombre BORRAR_CLIENTE, que permita borrar el registro de un cliente, cuyo 
-- número se pasará en la llamada de la tabla clientes. 

create or REPLACE PROCEDURE BORRAR_CLIENTE(p_ncliente clientes.cod_cliente%type) AS

begin
 
  if p_ncliente is not null then   
        DELETE FROM clientes WHERE cod_cliente = p_ncliente;
        
    if  SQL%ROWCOUNT > 0 then
        DBMS_OUTPUT.PUT_LINE('Cliente borrado exitosamente');
        commit;
    else
        DBMS_OUTPUT.PUT_LINE('El ID no coincide con ningun registro');
           
    end if;
else
    DBMS_OUTPUT.PUT_LINE('eL CODIGO NO PUEDE SER NULO');

end if;

end borrar_cliente;
/


DECLARE
  v_num_cliente clientes.cod_cliente%type:= '&Codigo_cliente';
begin
 
 BORRAR_CLIENTE(v_num_cliente);
  
end;
/
ROLLBACK;   


--5)Escribir un procedimiento almacenado que permita actualizar el importe total de una factura, según el detalle que tenga asignado.
--- El código que identifica la factura debe enviarse como parámetro de entrada.

