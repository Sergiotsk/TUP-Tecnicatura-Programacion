# Trabajo Práctico N° 3 — Ejercicios de PL/SQL

**Tecnicatura Universitaria en Programación — UTN FRH**  
**Base de Datos II — Lic. Vilma Giudice**

> Para la realización de estos ejercicios ejecutar el *Script Trabajo Practico 3*

---

## A. Uso de Cursores Implícitos

Crear los siguientes bloques en PL/SQL:

1. En función de un código, realizar los siguientes procedimientos. Si el código es:
   - `1` → Mostrar el menor precio de los artículos existentes.
   - `2` → Mostrar cuál es el valor del precio máximo de todos los productos.
   - `3` → Mostrar cuántos clientes tiene la empresa.
   - `4` → Mostrar cuántas facturas se emitieron este mes.
   - `5` → Mostrar la media del precio unitario de los ofrecidos.

   Para cualquier otro valor ingresado hay que indicar que el código no es válido.

2. Dar de alta una Localidad del Municipio de La Matanza, ID `20`, con todos sus datos.  
   *(Municipios de La Matanza: San Justo, Ramos Mejía, Aldo Bonzi, Rafael Castillo, Ciudad Evita, Gonzalez Catán, Gregorio de Laferrere, La Tablada, Lomas del Mirador, Isidro Casanova, Tapiales, 20 de Junio, Villa Eduardo Madero, Villa Luzuriaga, y Virrey del Pino.)*

3. Mostrar la superficie y el nombre de la capital de la provincia de Buenos Aires. *(El código de la provincia de Buenos Aires es 1).*

4. Crear un procedimiento, de nombre `BORRAR_CLIENTE`, que permita borrar el registro de un cliente, cuyo número se pasará en la llamada de la tabla **clientes**.

5. Escribir un procedimiento almacenado que permita actualizar el importe total de una factura, según el detalle que tenga asignado. El código que identifica la factura debe enviarse como parámetro de entrada.

6. Crear un procedimiento que permita insertar información al detalle de una factura existente *(el producto vendido, su cantidad y el subtotal de la venta)*. Considere que la Factura existe.

---

## B. Uso de Cursores Explícitos

Crear los siguientes bloques en PL/SQL:

1. Muestre cuál sería el mail institucional de cada alumno cuyo usuario se forma con la inicial de su primer nombre adicionándole su apellido y los tres últimos dígitos de su legajo, usando como dominio `frh.utn.edu.ar`.  
   *(Por ejemplo, Aida Irene Blat, legajo 123456, el mail será `ablat456@frh.utn.edu.ar`).*

2. Mostrar de cada **provincia** la cantidad de **municipios** que tiene.

3. Escribir un procedimiento almacenado que actualice el importe total de todas las facturas, según el detalle que tengan asignadas.

4. Hacer un listado de los alumnos en el que figure de cada uno su apellido, nombre y, si su edad fuese mayor o igual a 21, indicarlo mediante un mensaje *(por ejemplo, `'Mayor de edad'`)*. Caso contrario colocar una leyenda con 5 guiones `'-----'`.  
   > NOTA: utilizar la función `DIF_FECHAS` del TP2 C1.

5. Devolver un reporte con la lista de todas las facturas agrupadas de un cliente e indique el monto total facturado.

6. Calcular el total que se le ha facturado a cada una de las empresas clientes, desde una fecha dada hasta el presente.
