select a.apellido,a.nombre FROM alumno a
JOIN CARRERA C ON a.carrera = c.id;

select pepe.apellido,pepe.nombre carrera FROM alumno pepe
JOIN carrera  ON pepe.carrera = carrera.id;

select c.nombre,a.legajo from carrera c
LEFT JOIN alumno a ON a.carrera=c.id
where a.carrera is null;

select c.nombre,a.legajo from carrera c
RIGHT JOIN alumno a ON a.carrera=c.id;


--10)Armar un listado de cada curso mostrando el nombre de la materia y los alumnos 
--con su apellido, nombre, legajo, y condición ante la materia: 
--P – ‘PROMOCIONADO’, R – ‘REGULAR’, L – ‘LIBRE’, A – ‘ABANDONO’.

SELECT m.nombre,a.legajo,a.apellido,a.nombre,mt.promociona from materia m
join curso c on c.materia = m.id
join matricula mt on mt.curso=c.id
join alumno a on a.legajo = mt.alumno;


UPDATE matricula SET promociona = 'P' where id < 5;
commit;
UPDATE matricula SET promociona = 'R' where id >= 5 and id < 8;
commit;
UPDATE matricula SET promociona = 'L' where id >= 8 and id < 11;

UPDATE matricula SET promociona = 'A' where id >= 11 and id < 22;
UPDATE matricula SET promociona = 'P' where id >= 22;


commit;

SELECT m.nombre,a.legajo,a.apellido,a.nombre,
    case mt.promociona
        when 'p' then 'PROMOCIONADO'
        when 'R' then 'REGULAR'
        when 'L' then 'LIBRE'
        when 'A' then 'ABANDONO'
        else '******'
    end condicion --, a.fecha_nacimiento        
      
from materia m
join curso c on c.materia = m.id
join matricula mt on mt.curso=c.id
join alumno a on a.legajo = mt.alumno;

--6 Indicar cuántos alumnos hay inscriptos en cada uno de los cursos activos.
select m.nombre,count (mt.alumno)
from materia m
join curso c on c.materia = m.id
join matricula mt on mt.curso=c.id
group by m.nombre;

update curso set fecha_inicio= to_date ('18/03/2024','dd/mm/yyyy')where id BETWEEN 4 and 8;
update curso set fecha_inicio= to_date ('18/03/2025','dd/mm/yyyy')where id BETWEEN 9 and 12;

commit;

--6 Indicar cuántos alumnos hay inscriptos en cada uno de los cursos activos.
select m.nombre,count (mt.alumno)
from materia m
join curso c on c.materia = m.id
join matricula mt on mt.curso=c.id
where extract (year from fecha_inicio)= extract(year from sysdate)
group by m.nombre
having count (mt.alumno)>2;















