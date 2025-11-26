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

 select M.ID, m.nombre,count(mt.alumno) as cant_alumnos FROM MATERIA M 
 JOIN CURSO C on C.MATERIA = M.ID
 JOIN MATRICULA MT ON MT.CURSO = C.ID
 GROUP BY M.ID, M.NOMBRE
 having count (mt.alumno)>3; 
 

/*8. Identificar de los alumnos inscriptos en algún curso sus edades, colocando una leyenda de menor de edad a
  aquellos alumnos con menos de 18 años.   */


select
a.legajo,
a.apellido || ',' || a.nombre as ALUMNO,
a.fecha_nacimiento,
trunc((sysdate -a.fecha_nacimiento)/365) as EDAD,
case 
    when (sysdate - a.fecha_nacimiento )/365 < 18 then 'MENOR_DE_EDAD'
    else ' '
end as cat_edad
from alumno a
join matricula m on a.legajo = m.alumno
order by
        a.apellido,a.nombre;



/*9. Indicar en un listado por alumno inscriptos a cursos (contando su apellido y nombre) la cantidad de cursos en los
 que están inscriptos actualmente.*/
select 
    a.apellido || ',' || a.nombre as ALUMNO,
    count(m.alumno) as cursos_tomados
    from alumno a
    join matricula m on a.legajo = m.alumno
    group by
    a.apellido,a.nombre
    order by
    a.apellido,a.nombre;


--10. Listar de cada materia la cantidad de cursos que hay para cada una de ellas 

select
    m.nombre as materia,
    count(c.materia) as cant_cursos
    from materia m
    join curso c on c.materia = m.id
    group by
    c.materia,m.nombre
    order by
    m.nombre;


--11. Por carrera, indicar cuántos alumnos están cursando actualmente alguna materia.

select 
    c.nombre as CARRERA,
    count (m.alumno) as CANTIDAD_INSCRIPTOS
    FROM carrera c
    join alumno a on a.carrera = c.id
    join matricula m on m.alumno = a.legajo
    group by 
        m.alumno,c.nombre
    order by
        c.nombre;

--12. Por carrera indicar cuántos alumnos no están cursando materia alguna.


select 
    c.nombre as CARRERA,
    count (a.legajo) as CANT_alumnos_sin_materia
    FROM carrera c
    join alumno a on a.carrera = c.id
    left join matricula m on m.alumno = a.legajo
    where m.curso is null
    group by 
        c.nombre
    order by
        c.nombre;





