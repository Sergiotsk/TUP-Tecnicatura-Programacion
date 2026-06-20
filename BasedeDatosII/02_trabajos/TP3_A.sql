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

*/


--5)Escribir un procedimiento almacenado que permita actualizar el importe total de una factura, según el detalle que tenga asignado.
--- El código que identifica la factura debe enviarse como parámetro de entrada.



CREATE OR REPLACE PROCEDURE actualizar_factura(p_codigo detalle_facturas.cod_factura%type) AS
  l_nuevoInporte detalle_facturas.subtotal%type;
  begin
  if p_codigo is not null then

  SELECT SUM(df.cantidad * p.precio_unitario) 
      INTO l_nuevoInporte
      FROM detalle_facturas df
      JOIN productos p ON df.cod_producto = p.cod_producto
     WHERE df.cod_factura = p_codigo;

    if l_nuevoInporte IS NULL then        
        DBMS_OUTPUT.PUT_LINE('Codigo de factura inexistente');
      else
        update facturas
           set importe_total=l_nuevoInporte
         where p_codigo = cod_factura;
         DBMS_OUTPUT.PUT_LINE('Importe de factura '||p_codigo||' actualizado a: '||l_nuevoInporte);
        commit;
           
    end if;
  else 
        DBMS_OUTPUT.PUT_LINE('eL CODIGO NO PUEDE SER NULO');   
   end if;    

end;
/

DECLARE
v_CodigoFactura detalle_facturas.cod_factura%type:= '&Ingrese_codigo_de_factura';
begin
  
  actualizar_factura(v_CodigoFactura);
 

end;
/

/*
--6)Crear un procedimiento que permita insertar información al detalle de una factura existente
--- *(el producto vendido, su cantidad y el subtotal de la venta)*. Considere que la Factura existe.

CREATE OR REPLACE PROCEDURE new_detalle_factura(
  p_cod_factura in detalle_facturas.cod_factura%type,
  p_cod_prod in detalle_facturas.cod_producto%TYPE,
  p_cant in detalle_facturas.cantidad%type) AS
    l_precio productos.precio_unitario%type;
    l_subtotal detalle_facturas.subtotal%type;
  begin
      if p_cod_factura is null then
        DBMS_OUTPUT.PUT_LINE('Falta codigo factura');
      elsif p_cod_prod is null then
        DBMS_OUTPUT.PUT_LINE('Falta codigo producto');
      elsif p_cant is null then
        DBMS_OUTPUT.PUT_LINE('Falta cantidad producto');  
    
      else
      select precio_unitario
        into l_precio
        from productos
       where p_cod_prod = cod_producto;

       l_subtotal:= l_precio * p_cant;

       insert into detalle_facturas (cod_factura,cod_producto,cantidad,subtotal)
       values (p_cod_factura,p_cod_prod,p_cant,l_subtotal);


        DBMS_OUTPUT.PUT_LINE('Falta codigo producto o cantidad');
      end if;
  end;

*/


/*
================================================================================
  FUNCIONES BUILT-IN DE ORACLE USADAS EN ESTE TP
================================================================================

--- FUNCIONES DE AGREGACION (GROUP FUNCTIONS) ---
  Operan sobre un conjunto de filas y devuelven un solo valor.
  Se usan con SELECT ... INTO en PL/SQL.

  MIN(expr)       → Valor mínimo del conjunto
                    SELECT MIN(precio_unitario) INTO l_precio FROM productos;

  MAX(expr)       → Valor máximo del conjunto
                    SELECT MAX(precio_unitario) INTO l_precio FROM productos;

  COUNT(expr|*)   → Cantidad de filas (COUNT(*) cuenta nulls; COUNT(col) no)
                    SELECT COUNT(*) INTO l_n FROM clientes;

  SUM(expr)       → Suma de todos los valores del conjunto
                    SELECT SUM(df.cantidad * p.precio_unitario) INTO l_total ...

  AVG(expr)       → Promedio aritmético del conjunto (ignora NULLs)
                    SELECT AVG(importe_total) INTO l_prom FROM facturas;

--- FUNCIONES DE FECHA ---

  EXTRACT(campo FROM fecha)
                  → Extrae parte de una fecha: YEAR, MONTH, DAY, HOUR, etc.
                    EXTRACT(MONTH FROM fecha_emision)
                    EXTRACT(YEAR  FROM CURRENT_DATE)

  CURRENT_DATE    → Fecha actual del servidor (con zona horaria de sesión)
                    Alternativa más común: SYSDATE (sin zona horaria)
                    SYSDATE devuelve DATE; CURRENT_DATE devuelve TIMESTAMP WITH TIME ZONE

--- ATRIBUTOS DE CURSOR IMPLICITO ---
  Disponibles después de un DML (INSERT, UPDATE, DELETE, MERGE)

  SQL%ROWCOUNT    → Cantidad de filas afectadas por el último DML
                    IF SQL%ROWCOUNT > 0 THEN ...
  SQL%FOUND       → TRUE si el DML afectó al menos 1 fila
  SQL%NOTFOUND    → TRUE si el DML no afectó ninguna fila

================================================================================
  FUNCIONES RECOMENDADAS (no usadas acá pero muy útiles en este contexto)
================================================================================

--- MANEJO DE NULLS ---

  NVL(expr, valor_si_null)
                  → Si expr es NULL, devuelve valor_si_null
                    NVL(precio_unitario, 0)

  NVL2(expr, val_no_null, val_null)
                  → Si expr NO es NULL → val_no_null; si es NULL → val_null
                    NVL2(email, 'Tiene email', 'Sin email')

  COALESCE(e1, e2, ..., eN)
                  → Devuelve el primer valor no NULL de la lista
                    COALESCE(telefono_cel, telefono_fijo, 'Sin contacto')

  NULLIF(e1, e2)  → Si e1 = e2 devuelve NULL; si no, devuelve e1
                    Útil para evitar divisiones por cero: NULLIF(cantidad, 0)

--- FORMATEO Y CONVERSION ---

  TO_CHAR(valor, formato)
                  → Convierte DATE o NUMBER a VARCHAR2
                    TO_CHAR(SYSDATE,    'DD/MM/YYYY')
                    TO_CHAR(precio,     '999,990.00')
                    TO_CHAR(importe,    'L999G990D00')  -- con símbolo de moneda

  TO_NUMBER(cadena, formato)
                  → Convierte VARCHAR2 a NUMBER
                    TO_NUMBER('1.500,50', '9G999D99')

  TO_DATE(cadena, formato)
                  → Convierte VARCHAR2 a DATE
                    TO_DATE('27/04/2026', 'DD/MM/YYYY')

  ROUND(n, decimales)
                  → Redondea n a la cantidad de decimales indicada
                    ROUND(AVG(precio_unitario), 2)

  TRUNC(n|fecha, unidad)
                  → Trunca sin redondear. En fechas trunca a la unidad dada
                    TRUNC(3.987)          →  3
                    TRUNC(SYSDATE, 'MM')  →  primer día del mes actual

--- FUNCIONES DE FECHA ADICIONALES ---

  SYSDATE         → Fecha y hora del servidor (tipo DATE, sin zona horaria)
                    WHERE fecha_emision >= TRUNC(SYSDATE, 'MM')

  ADD_MONTHS(fecha, n)
                  → Suma o resta n meses a una fecha
                    ADD_MONTHS(SYSDATE, -1)  -- hace un mes

  MONTHS_BETWEEN(f1, f2)
                  → Cantidad de meses entre dos fechas (puede ser decimal)
                    MONTHS_BETWEEN(SYSDATE, fecha_alta)

  LAST_DAY(fecha) → Último día del mes de la fecha dada
                    LAST_DAY(SYSDATE)

--- FUNCIONES DE CADENA ---

  LENGTH(cadena)  → Longitud en caracteres
                    LENGTH(nombre)

  UPPER(cadena) / LOWER(cadena) / INITCAP(cadena)
                  → Convierte a mayúsculas / minúsculas / Capitalizado
                    UPPER(apellido) = UPPER(p_apellido)  -- comparación case-insensitive

  SUBSTR(cadena, inicio, longitud)
                  → Extrae subcadena (posición base 1)
                    SUBSTR(nombre, 1, 3)

  INSTR(cadena, subcadena)
                  → Posición de la primera ocurrencia (0 si no existe)
                    INSTR(email, '@')

  TRIM(cadena) / LTRIM / RTRIM
                  → Elimina espacios (o caracteres) de ambos lados / izquierda / derecha
                    TRIM(p_nombre)

  REPLACE(cadena, buscar, reemplazar)
                  → Reemplaza todas las ocurrencias
                    REPLACE(descripcion, 'kg', 'kilogramos')

  LPAD(cadena, n, relleno) / RPAD(cadena, n, relleno)
                  → Rellena a la izquierda / derecha hasta llegar a longitud n
                    LPAD(cod_factura, 6, '0')  →  '000042'

================================================================================
*/

