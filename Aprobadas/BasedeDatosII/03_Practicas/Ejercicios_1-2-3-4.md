# Base de Datos II — Ejercicios PL/SQL

**Tecnicatura Universitaria en Programación — UTN FRH**
**Docente:** Lic. Vilma Giudice

---

## Clase 1 — Bloques Anónimos

1. Definir la salida por consola de los bloques anónimos de la sesión.
2. Realizar un bloque anónimo que salude a todos.
3. Mediante un bloque anónimo dar el resultado de una suma, por ejemplo: `5 + 3`. Verificar qué pasa con los números cuando al pedido se le agrega, concatena un conjunto de literales como por ejemplo `'EL RESULTADO ES: '`.
4. Realizar el bloque anónimo anterior con la leyenda adecuada utilizando la conversión a caracteres de la operación.
5. Mediante la declaración de una variable numérica a la que se le asignará el resultado de la operación, mostrar el contenido de la variable junto a la leyenda correspondiente.
6. Declarar en un bloque anónimo dos variables y controlar cómo y cuándo se realiza la conversión implícita de variables en la salida por consola.
7. Declarar, en un bloque anónimo, dos variables numéricas de tres dígitos y una variable numérica de cuatro; asignarle el resultado de la suma de dichas variables del mismo tipo a la variable de mayor tamaño. Mostrar por consola el resultado.
8. Declarar una constante en un bloque anónimo y mostrar su contenido por consola con una leyenda adecuada. Comprobar qué pasa si a una constante se le cambia el contenido en la sección ejecutable.
9. Desarrollar un bloque anónimo que tenga declarada una variable numérica y comprobar si ese valor es mayor a 18.
10. Crear un bloque anónimo que permita controlar si un número es múltiplo de 3 o no.
11. Crear un bloque anónimo que permita controlar si un número es múltiplo de 6 o no.
12. Mediante un bloque anónimo, mostrar el doble de un número si el número es múltiplo de dos; caso contrario, mostrar su triplo.
13. Mediante un bloque anónimo, dado un número entero, mostrar el anterior y el posterior.
14. Mediante un bloque anónimo mostrar la fecha actual del servidor Oracle.

---

## Clase 2 — Procedimientos y Funciones

1. Desarrollar un bloque que dado un valor numérico indique si el mismo es positivo.
2. Desarrollar un bloque que dado un valor numérico indique si el mismo es positivo, negativo o cero.
3. Escribir un programa que declare un número entero y muestre por pantalla si es par o impar.
4. Escribir un bloque que declare un número entero y muestre por pantalla si es múltiplo de 3 o no.
5. Escribir un bloque que declare un número entero y muestre por pantalla si es múltiplo de 3; caso contrario, mostrar el número múltiplo de tres anterior al dado.
6. Realizar un bloque anónimo que declare dos variables numéricas cuyo valor inicial sea cero, se le asigne su valor en el procedimiento y muestre el resultado de la suma.
7. Realizar un bloque anónimo que declare dos variables numéricas con sus valores iniciales en la declaración. En la sección ejecutable se deberán comparar las variables indicando si la primera es mayor, menor o igual a la segunda mediante una leyenda adecuada.
8. Crear un bloque PL que, dado un nombre y un apellido, devuelva las iniciales de la persona.
9. Escribir un bloque con dos variables numéricas que muestre la división del mayor con el menor de los valores. Si el divisor es cero, el programa debe mostrar un error.
10. Para tributar un determinado impuesto se debe ser mayor de 18 años y tener ingresos iguales o superiores a $800.000 mensuales. Escribir un bloque que controle edad e ingresos mensuales y muestre por pantalla si se tiene que tributar impuestos o no.
11. Crear un bloque PL/SQL que muestre un comentario acorde a la nota que ha sacado un alumno: `10` Sobresaliente, `9` Excelente, `8` Muy Bueno, `7` Bueno, `6` Aprobado, debajo de `6` Reprobado. *(Resolverlo con `CASE`.)*
12. Escribir los 10 primeros números pares de menor a mayor.
13. Escribir los 10 primeros números impares de mayor a menor.
14. Escribir un procedimiento que muestre la tabla de multiplicar deseada (del 1 al 12). Crear el bloque anónimo para probarlo.
15. Armar un bloque que escriba en pantalla la cadena `'BASE DE DATOS II'` de atrás para adelante (`'II SOTAD ED ESAB'`).
16. Armar un procedimiento que escriba los 10 primeros números pares ya sea de menor a mayor (ascendente) o de mayor a menor (descendente). Crear el bloque anónimo para probarlo.
17. Crear una función PL/SQL que, al ingresar una fecha, devuelva cuál es el trimestre del año al cual pertenece. Crear el bloque anónimo para probarla.
18. Crear una función que, dada una frase, indique cuántas palabras la forman. Considerar que las palabras se separan por espacio; no considerar los espacios finales de la frase dada.
19. Armar un bloque que, al pedir una palabra, le dé vuelta solo si es una palabra. En caso de que sea una frase (contenga uno o más espacios, pero no al final), indicar que no se cumple con la consigna.
20. Armar una función que, dada la fecha de nacimiento de una persona, indique cuál es su edad. Crear el bloque anónimo para probarla.

---

## Clase 3 — Cursores

1. Crear una función que permita contar los empleados de un departamento específico al pasárselo como parámetro. Crear el bloque anónimo para probarla.
2. Armar una función que, con la fecha de nacimiento de una persona, indique cuántos días faltan para su cumpleaños.
3. Actualizar el precio de un determinado producto dado el código y precio del producto.
4. Mostrar el precio de venta de un artículo indicado.
5. Mostrar cuántos empleados ingresaron este año y cuántos de ellos trabajan en RRHH.
6. Devolver los nombres de los tres productos más vendidos.
7. Realizar el aumento a todos los productos de acuerdo con un porcentaje pedido.
8. Crear un procedimiento almacenado que devuelva la lista de la razón social de los clientes que no tienen facturas emitidas.
9. Crear un procedimiento almacenado para actualizar el precio de un producto que se envíe como parámetro de entrada junto con el código de este.
10. Hacer, por departamento, el reporte de los empleados que tienen un salario menor o igual a $88.800,00.

---

## Clase 4 — Triggers

1. De acuerdo con los procedimientos del negocio, no se permiten realizar modificaciones de los registros de empleados los fines de semana. Realizar el disparador para hacer cumplir esta regla de negocio.
2. Crear un disparador que no permita insertar registros en la tabla de empleados entre las 18 hs y las 22 hs.
3. Realizar un único disparador para hacer cumplir ambas reglas de negocio.
4. Realizar un disparador que registre el usuario y la fecha de cualquier actividad de cambio que se realice sobre la tabla de departamentos (actualizaciones, eliminaciones o inserciones de registros). Registrar esto en la tabla de LOGS_DEPARTAMENTOS (tiene tres campos: ID, USUARIO, FECHA).
5. La empresa debe controlar las actualizaciones de los precios de los productos almacenados en la tabla denominada "PRODUCTOS" para ellos se debe registrar en la tabla "control" el nombre del usuario, la fecha, el precio anterior y el nuevo. Crear un disparador para dejar registradas las modificaciones.
6. Una empresa almacena los datos de sus empleados en una tabla denominada "empleados". En una tabla denominada "controlCambios" guarda los cambios que se realizan en la tabla "empleados", en ella almacena el nombre del usuario que realiza la acción y la fecha en que la llevó a cabo. Crear los siguientes disparadores: a. un disparador para el alta,  b. un disparador para las modificaciones y  c. otro para registrar las bajas. d. Un disparador que permita registrar cualquiera de las actividades planteadas en los puntos anteriores.
7. Construir un disparador que permita auditar las operaciones de modificación, inserción o borrado de datos que se realicen en la tabla departamentos según las siguientes especificaciones: a. Cuando se produzca cualquier modificación, inserción o borrado se insertará una fila en la tabla LOGS_DEPARTAMENTOS que contendrá: - - - Fecha y hora ID y nombre del departamento insertado o borrado El tipo de operación de actualización que se realizó ‘MODIFICACION’, ‘INSERCIÓN’ o ‘BORRADO’
8. Escribir un disparador que no permita realizar la modificación del apellido de un empleado.
9. Escribir un disparador que no permita aumentar el salario mínimo de un empleado por encima del 10% ni que supere el salario máximo.
10. Escribir un disparador que no permita realizar la modificación del número de un empleado.

## Para la realización de estos ejercicios ejecutar el ‘Script Trabajo Practico 3’ A. Uso de Cursores Implícitos.  Crear los siguientes bloques en PL/SQL:

1. En función de un código, realizar los siguientes procedimientos. Si el código es:
   1 – Mostrar el menor precio de los artículos existentes.
   2 – Mostrar cuál es el valor del precio máximo de todos los productos.
   3 – Mostrar cuántos clientes tiene la empresa.
   4 – Mostrar cuántas facturas se emitieron este mes.
   5 – Mostrar la media del precio unitario de los ofrecidos. Para cualquier otro valor ingresado hay que indicar que el código no es válido.
   Lic. Vilma Giudice

   2. Dar de alta una Localidad del Municipio de La Matanza, ID 20, con todos sus datos. (Municipios de La Matanza: San Justo, Ramos Mejía, Aldo Bonzi, Rafael Castillo, Ciudad Evita, Gonzalez Catán, Gregorio de Laferrere, La Tablada, Lomas del Mirador, Isidro Casanova, Tapiales, 20 de Junio, Villa Eduardo Madero, Villa Luzuriaga, y Virrey del Pino.)
   3. 3. Mostrar la superficie y el nombre de la capital de la provincia de Buenos Aires. (El código de la provincia de Buenos Aires es 1).
   4. 4. Crear un procedimiento, de nombre BORRAR_CLIENTE, que permita borrar el registro de un cliente, cuyo número se pasará en la llamada de la tabla clientes.
   5. 5. Escribir un procedimiento almacenado que permita actualizar el importe total de una factura, según el detalle que tenga asignado. El código que identifica la factura debe enviarse como parámetro de entrada.
   6. 6. Crear un procedimiento que permita insertar información al detalle de una factura existente (el producto vendido, su cantidad y el subtotal de la venta). Considere que la Factura existe.
   7. B. Uso de Cursores Explícitos.  Crear los siguientes bloques en PL/SQL:
   8. 1. Muestre cuál sería el mail institucional de cada alumno cuyo usuario se forma con la inicial de su primer nombre adicionándole su apellido y los tres últimos dígitos de su legajo, usando como dominio ‘frh.utn.edu.ar’. (Por ejemplo, Aida Irene Blat, legajo 123456, el mail será ablat456@frh.utn.edu.ar)
   9. 2. Mostrar de cada provincia la cantidad de municipios que tiene.
   10. 3. Escribir un procedimiento almacenado que actualice el importe total de todas las facturas, según el detalle que tengan asignadas.
   11. 4. Hacer un listado de los alumnos en el que figure de cada uno su apellido, nombre y, si su edad fuese mayor o igual a 21, indicarlo mediante un mensaje (por ejemplo, ‘Mayor de edad’). Caso contrario colocar una leyenda con 5 guiones altos '-----’. NOTA: utilizar la función DIF_FECHAS del punto C1.
   12. 5. Devolver un reporte con la lista de todas facturas agrupadas de un cliente e indique el monto total facturado.
   13.  6. Calcular el total que se le ha facturado a cada una de las empresas clientes, desde una fecha dada hasta el presente.
