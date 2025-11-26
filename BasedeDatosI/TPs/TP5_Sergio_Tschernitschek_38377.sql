/*1. Armar una consulta almacenada que permita visualizar los apellidos y nombres de los alumnos inscriptos en cada
uno de los cursos con sus notas que hayan promocionado o regularizado la materia (en el campo Promociona
podrá figurar: P – ‘PROMOCIONADO’, R – ‘REGULAR’).*/

CREATE OR REPLACE VIEW lista_alumnos_inscriptos AS
SELECT mt.nombre materia,A.apellido || ',' || A.nombre alumno FROM alumno A
JOIN matricula M ON A.legajo = M.alumno
JOIN curso C ON M.curso=C.ID
JOIN materia mt ON mt.ID=C.materia
WHERE M.promociona = 'P' OR M.promociona ='R'
ORDER BY mt.nombre,A.apellido;

SELECT * FROM lista_alumnos_inscriptos;
SELECT DISTINCT materia FROM lista_alumnos_inscriptos;
SELECT COUNT (DISTINCT materia) FROM lista_alumnos_inscriptos;
SELECT COUNT (materia) FROM lista_alumnos_inscriptos;







--2. Modificar el nombre del Campo observaciones de la tabla curso por CONSIDERACIONES.







/*3. Los mails de los profesores se han modificado por la primera letra de su nombre junto a su apellido y su número
de legajo (identificación) siendo el dominio de la institución @profesores.frh.utn.edu.ar. Antes de hacer la
actualización verificar que la cantidad de caracteres mínimos necesarios para este campo sea suficiente en la
estructura de la tabla.*/







/*4. Agregarle un campo a la tabla de profesores para registrar la fecha de alta de cada profesor, que tenga como valor
base la fecha del día de la inserción.*/








--5. Eliminar los registros de los cursos que no poseen alumnos inscriptos.






--6. Listar los datos de los profesores que no están dictando ninguna materia.


--7. Listar los nombres de las materias que tienen más de tres alumnos inscriptos.


/*8. Identificar de los alumnos inscriptos en algún curso sus edades, colocando una leyenda de menor de edad a
  aquellos alumnos con menos de 18 años.   */


/*9. Indicar en un listado por alumno inscriptos a cursos (contando su apellido y nombre) la cantidad de cursos en los
 que están inscriptos actualmente.*/




--10. Listar de cada materia la cantidad de cursos que hay para cada una de ellas.






--11. Por carrera, indicar cuántos alumnos están cursando actualmente alguna materia.





--12. Por carrera indicar cuántos alumnos no están cursando materia alguna.