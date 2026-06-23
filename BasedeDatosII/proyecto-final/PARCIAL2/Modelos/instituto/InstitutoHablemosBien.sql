/*1. No se permite dar de alta ni cursos, ni alumnos, ni docentes los fines de semana.*/

--1)
create or replace PROCEDURE validar_dia_semana AS
BEGIN
     if to_char(sysdate, 'D') in ('1','7')
 then 
    RAISE_APPLICATION_ERROR(-20001,'No se permiten modificaciones de empleados los fines de semana');
    end if;
END;
/
    create or replace trigger trg_curso
    before INSERT on CURSOS
    BEGIN
        validar_dia_semana;
END;
/
 create or replace trigger trg_alumnos
    before INSERT on ESTUDIANTES
    BEGIN
        validar_dia_semana;
END;
/

 create or replace trigger trg_docentes
    before INSERT on PROFESORES
    BEGIN
        validar_dia_semana;
END;
/

--BLOQUE DE PRUEBA
BEGIN
    insert into CURSOS(CURSO_ID,NOMBRE,CARRERA) values(102,'FILOSOFIA',1);
END;
/    

/*2. Realizar un procedimiento que permita validar el email de un alumno.

El formato de un email correcto contiene un nombre de usuario seguido de una "@" y un dominio.
Los nombres de los usuarios sólo pueden contener letras (a-z), números (0-9), y punto (.) el que no puede estar al final.
Además el primer carácter debe ser una letra.
Los nombres de dominio sólo pueden contener letras (a-z), números (0-9) y el guion menos (-).
El guion (-) sólo es permitido si no está al principio o al final del nombre de dominio.*/




create or replace procedure validar_mail (p_email IN VARCHAR2) IS
mail boolean; 
BEGIN
    IF p_email is not null then
        mail := REGEXP_LIKE(p_email, '^[a-z][a-z0-9\.]*[a-z0-9][@][a-z0-9]*[a-z0-9-\.]*[a-z0-9]$');
        if mail THEN
        DBMS_OUTPUT.PUT_LINE('Mail ingresado correctamente'); 
        else
        RAISE_APPLICATION_ERROR(-20001,'Formato de email NO permitido');
        end if;
    ELSE
        DBMS_OUTPUT.PUT_LINE('No se detecto ingreso');
    end if;    
END;
/

create or replace trigger trg_validar_mail
before INSERT or UPDATE OF EMAIL ON ESTUDIANTES
for each ROW
BEGIN
    validar_mail(:new.email);
END;    
/    
--BLOQUE DE PRUEBA
BEGIN
 insert INTO ESTUDIANTES(NOMBRE,apellido,FECHA_NACIMIENTO,email,CARRERA)
 values('SERTO','Tschehek',TO_DATE('01-07-1986'),'serjito86gmail.com',5);
END;
/ 



/*3. Crear un paquete para que los profesores puedan administrar sus tareas en el aula, o sea debe permitir que:

a). El docente dé de alta las notas de un alumno para una actividad en una de sus materias. 
Se deberá controlar que dicho docente esté actualmente dictando la materia solicitada y que el alumno la esté cursando.

b). Mediante una función, se obtendrá la edad de un alumno ingresando su número de legajo. Se devolverá un número entero.

c). Mediante una función, se pueda obtener la cantidad de materias que un alumno dado está cursando actualmente.
     Si no cursa ninguna materia, devolverá cero.

d). Un profesor pueda visualizar la lista de los estudiantes, cada uno con su edad, de una materia que dicta.
    Además de una identificación personal deberá ingresar al procedimiento el código de la materia. 
    Este procedimiento debe aceptar que se le ingrese como identificación del docente: el legajo, su apellido y DNI, o su mail. 
    Se deberá controlar que la materia solicitada sea una materia que el profesor en cuestión esté dictando actualmente
     y se validará que el docente sea un docente del Instituto.

Nota: todas las consignas deben llevar los bloques anónimos de prueba.*/

create or replace PACKAGE PKG_ADMINISTRAR_TAREAS AS 
procedure alta_nota(p_profesor_id IN NUMBER, p_legajo IN NUMBER, p_materia_id IN NUMBER, p_nota IN NUMBER);
function obtener_edad(p_legajo IN NUMBER) RETURN NUMBER;
function cantidad_materias(p_legajo IN NUMBER) RETURN NUMBER;
procedure visualizar_estudiantes(p_docente_id IN VARCHAR2, p_materia_id IN NUMBER);
END PKG_ADMINISTRAR_TAREAS;
/

create or replace PACKAGE BODY PKG_ADMINISTRAR_TAREAS AS

procedure alta_nota(p_profesor_id IN NUMBER, p_legajo IN NUMBER, p_materia_id IN NUMBER, p_nota IN NUMBER) IS
v_count NUMBER;
BEGIN


--validar que la meteria este activa(docente dictandola)
SELECT count(*) into v_count
FROM    MATERIAS
WHERE materia_id = p_materia_id AND PROFESOR = p_profesor_id AND estado = 'activo';


IF v_count = 0 THEN
    RAISE_APPLICATION_ERROR(-20001,'La materia no existe o no esta siendo dictada actualmente');
END IF;    


--Validar que el alumno este cursando esa materia
SELECT count(*) into v_count
FROM    MATRICULAS
WHERE ESTUDIANTE = p_legajo AND materia = p_materia_id;


IF v_count = 0 THEN
    RAISE_APPLICATION_ERROR(-20002,'El alumno NO esta matriculado en la materia seleccionada');
END IF;  

--dar de alta la NOTA del alumno

INSERT INTO NOTAS(ESTUDIANTE,MATERIA,VALOR)
values(p_legajo,p_materia_id,p_nota);

END alta_nota;

/*==========================================================================*/


function obtener_edad(p_legajo IN NUMBER) RETURN NUMBER IS
v_edad NUMBER;
v_fecha_nacimiento DATE;
BEGIN
SELECT  FECHA_NACIMIENTO INTO v_fecha_nacimiento
FROM ESTUDIANTES
WHERE ESTUDIANTE_ID = p_legajo;  

v_edad := trunc((MONTHS_BETWEEN(SYSDATE,v_fecha_nacimiento)/12));
RETURN v_edad;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        RAISE_APPLICATION_ERROR(-20003,'ERROR, no se encontro dato asociado');
END obtener_edad;


/*==========================================================================*/


function cantidad_materias(p_legajo IN NUMBER) RETURN NUMBER IS
v_count NUMBER;
BEGIN
    SELECT count(MATERIA) into v_count
    FROM  MATRICULAS
    WHERE ESTUDIANTE = p_legajo;

RETURN v_count;
END cantidad_materias;


/*==========================================================================*/


procedure visualizar_estudiantes(p_docente_id IN VARCHAR2, p_materia_id IN NUMBER) IS
v_docente NUMBER;
SIN_ALUMNOS BOOLEAN := TRUE;
BEGIN
    --1.resuelvo quien es el docente
    IF REGEXP_LIKE(p_docente_id,'@') THEN  --es un mail
        SELECT profesor_id INTO v_docente
        FROM PROFESORES
        WHERE email = p_docente_id;

    ELSIF REGEXP_LIKE(p_docente_id,'^[0-9]+$') THEN --es un numero
        v_docente  := TO_NUMBER(p_docente_id);

    ELSE
        SELECT PROFESOR_ID INTO v_docente   --es un apellido
        FROM PROFESORES
        WHERE UPPER(APELLIDO) = UPPER(p_docente_id);
    END IF;    

    --2.Recorro el cursor y muestro
    DBMS_OUTPUT.PUT_LINE(RPAD('NOMBRE', 30) || RPAD('APELLIDO', 30) || 'EDAD');
    DBMS_OUTPUT.PUT_LINE(RPAD('-', 70, '-')); -- línea separadora
    
    FOR reg IN (
    SELECT E.ESTUDIANTE_ID, E.NOMBRE, E.APELLIDO
    FROM MATRICULAS M
    JOIN ESTUDIANTES E ON E.ESTUDIANTE_ID = M.ESTUDIANTE
    JOIN MATERIAS MT ON MT.MATERIA_ID = M.MATERIA
    WHERE M.MATERIA = p_materia_id
    AND MT.PROFESOR = v_docente
) LOOP
        DBMS_OUTPUT.PUT_LINE(
        RPAD(reg.nombre, 30) || 
        RPAD(reg.apellido, 30) || 
         obtener_edad(reg.estudiante_id));  
        SIN_ALUMNOS:=FALSE;  
    
    END LOOP;
IF SIN_ALUMNOS THEN
    DBMS_OUTPUT.PUT_LINE('MATERIA SIN ALUMNOS INSCRIPTOS');
END IF;        

END visualizar_estudiantes;

END PKG_ADMINISTRAR_TAREAS;
/

/*==========================================================================*/


--BLOQUE DE PRUEBA ALTA_NOTA

BEGIN
    PKG_ADMINISTRAR_TAREAS.ALTA_NOTA(1,1,202,9);
END;
/    
commit;

--BLOQUE DE PRUEBA OBTENER_EDAD
DECLARE
v_edad NUMBER;
BEGIN
    v_edad := PKG_ADMINISTRAR_TAREAS.obtener_edad(1);
    DBMS_OUTPUT.PUT_LINE('La edad del alumno es :'||v_edad);
END;
/   

--BLOQUE DE PRUEBA cantidad_materias
DECLARE
v_materias NUMBER;
BEGIN
    v_materias := PKG_ADMINISTRAR_TAREAS.CANTIDAD_MATERIAS(1);
    DBMS_OUTPUT.PUT_LINE('El alumno esta inscripto en :'||v_materias||' materias');
END;
/ 

--BLOQUE DE PRUEBA visualizar_estudiantes

BEGIN
 PKG_ADMINISTRAR_TAREAS.VISUALIZAR_ESTUDIANTES(2,204);
END;
/ 

BEGIN
 PKG_ADMINISTRAR_TAREAS.VISUALIZAR_ESTUDIANTES('mlopez@instituto.edu',204);
END;
/ 

BEGIN
 PKG_ADMINISTRAR_TAREAS.VISUALIZAR_ESTUDIANTES('lopez',204);
END;
/ 
