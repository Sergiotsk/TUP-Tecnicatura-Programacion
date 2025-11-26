/*1. Armar una consulta almacenada que permita visualizar los apellidos y nombres de los alumnos inscriptos en cada
uno de los cursos con sus notas que hayan promocionado o regularizado la materia (en el campo Promociona
podrá figurar: P – ‘PROMOCIONADO’, R – ‘REGULAR’).*/

CREATE OR REPLACE VIEW lista_alumnos_inscriptos AS
SELECT 
    mt.nombre AS materia,
    A.apellido || ', ' || A.nombre AS alumno,
    M.nota1,
    M.nota2,
    M.notaf,
    CASE 
        WHEN M.promociona = 'P' THEN 'PROMOCIONADO'
        WHEN M.promociona = 'R' THEN 'REGULAR'
    END AS condicion
FROM 
    alumno A
    JOIN matricula M ON A.legajo = M.alumno
    JOIN curso C ON M.curso = C.id
    JOIN materia mt ON mt.id = C.materia
WHERE 
    M.promociona IN ('P', 'R');


--2. Modificar el nombre del Campo observaciones de la tabla curso por CONSIDERACIONES.


ALTER TABLE curso 
RENAME COLUMN observaciones TO consideraciones;


/*3. Los mails de los profesores se han modificado por la primera letra de su nombre junto a su apellido y su número
de legajo (identificación) siendo el dominio de la institución @profesores.frh.utn.edu.ar. Antes de hacer la
actualización verificar que la cantidad de caracteres mínimos necesarios para este campo sea suficiente en la
estructura de la tabla.*/


ALTER TABLE profesor MODIFY mail VARCHAR(60);
UPDATE profesor SET mail = LOWER(substr(nombre,1,1) || apellido || TRIM(to_char(ID)) || '@profesores.frh.edu.ar');
COMMIT;

/*4. Agregarle un campo a la tabla de profesores para registrar la fecha de alta de cada profesor, que tenga como valor
base la fecha del día de la inserción.*/


 ALTER TABLE profesor ADD fecha_alta DATE DEFAULT sysdate;
 commit;


--5. Eliminar los registros de los cursos que no poseen alumnos inscriptos.

 SELECT C.ID FROM curso C 
 LEFT JOIN matricula M ON M.curso= C.ID
 WHERE M.curso IS NULL;
  DELETE FROM curso
  WHERE ID IN
            ( SELECT C.ID FROM curso C 
             LEFT JOIN matricula M ON M.curso= C.ID
             WHERE M.curso IS NULL);
ROLLBACK;


--6. Listar los datos de los profesores que no están dictando ninguna materia.

select P.id, p.apellido || ',' || p.nombre PROFESOR
FROM PROFESOR P
left join curso C on c.profesor=p.id
where c.profesor is null;

--7. Listar los nombres de las materias que tienen más de tres alumnos inscriptos.

select M.ID,m.nombre  ,   COUNT(MT.ALUMNO)   FROM MATERIA M 
 JOIN CURSO C on C.MATERIA = M.ID
 JOIN MATRICULA MT ON MT.CURSO = C.ID
where MT.ALUMNO NOT LIKE "%organica%"
  GROUP BY M.ID, M.NOMBRE

 having count (mt.alumno)>3--despues del group by
 GROUP BY M.NOMBRE;
 

/*8. Identificar de los alumnos inscriptos en algún curso sus edades, colocando una leyenda de menor de edad a
  aquellos alumnos con menos de 18 años.   */


/*9. Indicar en un listado por alumno inscriptos a cursos (contando su apellido y nombre) la cantidad de cursos en los
 que están inscriptos actualmente.*/




--10. Listar de cada materia la cantidad de cursos que hay para cada una de ellas.






--11. Por carrera, indicar cuántos alumnos están cursando actualmente alguna materia.





--12. Por carrera indicar cuántos alumnos no están cursando materia alguna.