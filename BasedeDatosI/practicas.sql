/*scenario de Práctica 💻

Imagina que tenemos dos tablas en Oracle Cloud:

PRODUCTOS (alias P): con columnas ID_PRODUCTO (PK) y NOMBRE_PRODUCTO.

CATEGORIAS (alias C): con columnas ID_CATEGORIA (PK) y NOMBRE_CATEGORIA.

La relación es que la tabla PRODUCTOS tiene una columna de clave foránea llamada ID_CATEGORIA que se relaciona con el ID_CATEGORIA (PK) de la tabla CATEGORIAS.

Tu turno: ¿Cómo escribirías una consulta usando un INNER JOIN para obtener el Nombre del Producto y el Nombre de su Categoría para todos los productos que tienen una categoría asignada?*/



SELECT
P.NOMBRE_PRODUCTO,
C.NOMBRE_CATEGORIA
FROM
PRODUCTOS P
LEFT JOIN
CATEGORIAS C
ON
P.ID_CATEGORIA = C.ID_CATEGORIA;


/*Las funciones como COUNT(), SUM(), AVG(), MIN(), y MAX() nos permiten operar sobre conjuntos de filas y devolver un único valor, en lugar de una lista de filas detalladas.

Pregunta de Práctica (Función de Agregación):

Volvamos a nuestra tabla EMPLEADOS que tiene una columna ID_EMPLEADO.

¿Cómo escribirías una consulta SQL para saber el número total de empleados que hay en la empresa? (Solo necesitas la función de agregación).*/



SELECT COUNT(ID_EMPLEADO)
FROM EMPLEADOS;


/*
Pregunta de Práctica (GROUP BY):

Si la tabla EMPLEADOS tiene una columna DEPARTAMENTO_ID, ¿cómo escribirías una consulta para mostrar el ID del Departamento y el número total de empleados que trabajan 
en cada uno de esos departamentos? (Ahora necesitas la función COUNT y la cláusula GROUP BY).
*/


SELECT DEPAARTAMENTO_ID ,COUNT(ID_EMPLEADO)
FROM EMPLEADOS
GROUP BY DEPARTAMENTO_ID;
HAVING COUNT(ID_EMPLEADO) > 10;



/*
Usando la consulta que acabas de escribir, ¿cómo la modificarías para mostrar solo aquellos departamentos que tienen más de 10 empleados?
 (Aquí debes usar la función agregada dentro de la cláusula de filtrado).


*/


SELECT DEPAARTAMENTO_ID ,COUNT(ID_EMPLEADO)
FROM EMPLEADOS
GROUP BY DEPARTAMENTO_ID;
HAVING COUNT(ID_EMPLEADO) > 10;






