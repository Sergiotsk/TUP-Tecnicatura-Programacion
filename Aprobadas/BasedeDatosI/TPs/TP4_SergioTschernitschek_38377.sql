--2. En la Tabla Libro agregar dos columnas: Fecha_Alta cuyo valor predeterminado sea ‘01/04/2010’ y Cantidad
 ALTER TABLE LIBRO
 ADD (
 Fecha_alta date default '01/04/2010',
 cantidad number(4)
 );
 
/*3. En la tabla de CARRERAS se han encontrado que la carrera de ‘INGENIERIA QUIMICA’ está repetida, identificar el
código de una de ellas para luego eliminar uno de los registros en función de su código*/

select ID,NOMBRE
from CARRERA         
WHERE NOMBRE = 'INGENIERIA QUIMICA';

--4. Eliminar de la tabla de materias la que lleva como nombre ‘INGLES III’ por no existir. 

DELETE FROM materias
WHERE nombre = 'INGLES III';

COMMIT;

--5. La carrera ingeniería Civil lleva por error el nombre de ingeniería CIVICA, realizar el cambio de nombre

UPDATE CARRERA
SET nombre = 'INGENIERIA CIVIL'
WHERE nombre = 'INGENIERIA CIVICA';
COMMIT;


--6. Indicar cuántos alumnos hay inscriptos en cada uno de los cursos activos.


SELECT m.curso AS codigo_curso,
COUNT(m.alumno) AS cantidad_alumnos
FROM  matricula m
GROUP BY m.curso
ORDER BY m.curso;

--7. Listar todos los datos del alumno junto con el nombre de la carrera que sigue

SELECT a.legajo as Legajo,
        a.apellido || ',' || a.nombre as Nombre,
        a.fecha_nacimiento as fechas_nac,
        a.mail as mail,
        c.nombre as CARRERA
FROM ALUMNO a
 JOIN CARRERA c ON a.carrera =c.id;   
 
 
-- 8.Listar los datos de los alumnos que no están inscriptos en ninguna materia
SELECT 
    a.legajo AS Legajo,
    a.apellido || ', ' || a.nombre AS Nombre,
    a.fecha_nacimiento AS Fecha_Nac,
    a.mail AS Mail
FROM 
    alumno a
    LEFT JOIN matricula m ON a.legajo = m.alumno
WHERE 
    m.curso IS NULL
ORDER BY 
    a.apellido;

-- 9) Listar los nombres de las materias que no tienen alumnos inscriptos

SELECT m.nombre AS Materia_Sin_Alumnos
FROM MATERIA m
LEFT JOIN MATRICULA ma ON m.id = ma.curso
WHERE ma.alumno IS NULL
ORDER BY m.nombre;




/* 10.Listar cada curso con la materia y sus alumnos, mostrando legajo, apellido,
nombre y condición ante la materia: P – ‘PROMOCIONADO’, R – ‘REGULAR’, L – ‘LIBRE’, A – ‘ABANDONO’*/


SELECT 
    c.nombre AS Materia,
    a.legajo AS Legajo,
    a.apellido || ', ' || a.nombre AS Alumno,
    m.promociona AS Condicion
FROM 
    materia c
    JOIN matricula m ON c.id = m.curso
    JOIN alumno a ON a.legajo = m.alumno
ORDER BY 
    c.nombre, a.apellido;


--11.No debe existir ningún libro cuyo precio supere los $13500. Controlarlos y si es necesario modificar esos registros.

SELECT L.TITULO AS LIBRO,
       L.precio AS PRECIO
        
FROM LIBRO L 
WHERE L.PRECIO > 13500;

UPDATE libro
SET precio = 13500
WHERE precio > 13500;

COMMIT;

--12. Aumentar $1000 el precio de cada libro y luego, los que sean inferiores a la media, aumentarlos en $1200.

UPDATE LIBRO
SET precio = precio +1000;
commit;

UPDATE LIBRO
SET PRECIO = PRECIO+1200
WHERE PRECIO < (
        select avg(precio)
        from libro
        
);
commit;

--13. Armar un listado de docentes indicando de cada uno su antigüedad. 
--no existia el campo fecha de ingreso por eso la cree

ALTER TABLE PROFESOR
ADD fecha_ingreso DATE;
commit;
UPDATE profesor SET fecha_ingreso = TO_DATE('2015-03-12', 'YYYY-MM-DD') WHERE id = 1;
UPDATE profesor SET fecha_ingreso = TO_DATE('2018-07-23', 'YYYY-MM-DD') WHERE id = 2;
UPDATE profesor SET fecha_ingreso = TO_DATE('2020-02-10', 'YYYY-MM-DD') WHERE id = 3;
UPDATE profesor SET fecha_ingreso = TO_DATE('2021-09-05', 'YYYY-MM-DD') WHERE id = 4;
UPDATE profesor SET fecha_ingreso = TO_DATE('2017-11-19', 'YYYY-MM-DD') WHERE id= 5;
UPDATE profesor SET fecha_ingreso = TO_DATE('2017-11-19', 'YYYY-MM-DD') WHERE id = 6;
UPDATE profesor SET fecha_ingreso = TO_DATE('2017-11-19', 'YYYY-MM-DD') WHERE id = 7;
UPDATE profesor SET fecha_ingreso = TO_DATE('2017-11-19', 'YYYY-MM-DD') WHERE id = 8;
COMMIT;


select P.APELLIDO || ','|| P.NOMBRE AS DOCENTE,
TRUNC(MONTHS_BETWEEN(SYSDATE, P.fecha_ingreso) / 12) AS Antiguedad_Años
FROM PROFESOR P
order by Antiguedad_Años desc;




--14. Listar de cada docente la cantidad de cursos en los que está dictando clase.


SELECT 
    P.apellido || ', ' || P.nombre AS docente,
    COUNT(C.profesor) AS cantidad_cursos
FROM 
    profesor P
    LEFT JOIN curso C ON C.profesor = p.id
GROUP BY 
    P.apellido, P.nombre
ORDER BY 
    cantidad_cursos DESC;
    
/*15. Listar los nombres de todos los profesores de cada curso, indicando el cargo que cada uno ejerce allí ordenado por
curso y dentro de cada curso por profesor.*/

--agregue 'titular' por que no existe el campo cargo
SELECT 
    c.id AS Curso,
--m.nombre AS Materia,
    p.apellido || ', ' || p.nombre AS Profesor,
    'Titular' AS Cargo
FROM 
    curso c
    --JOIN materia m ON c.materia = m.id
    JOIN profesor p ON c.profesor = p.id
ORDER BY 
    c.id,
    p.apellido,
    p.nombre;

/*16. Armar un listado de profesores en los que figuren los sueldos de cada docente existente, ordenados por
Apellido. Tener en cuenta que el sueldo estará dado por el básico de cada categoría y la cantidad de
cargos que cada profesor tenga asignados en la actualidad.*/

select 
    p.apellido || ',' || p.nombre  as PROFESOR,
    sum(c.sueldo_basico) as SUELDO
    FROM profesor p
    left join cat_doc cd on p.id = cd.docente
    left join categorias c on c.codigo = cd.categoria
    group by
            p.apellido,p.nombre
    order by 
            p.apellido;
    



