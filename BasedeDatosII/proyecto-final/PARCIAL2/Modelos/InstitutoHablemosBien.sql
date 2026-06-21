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

BEGIN
 insert INTO ESTUDIANTES(NOMBRE,apellido,FECHA_NACIMIENTO,email,CARRERA)
 values('SERTO','Tschehek',TO_DATE('01-07-1986'),'serjito86gmail.com',5);
END;
/ 



/*3. Crear un paquete para que los profesores puedan administrar sus tareas en el aula, o sea debe permitir que:

a). El docente dé de alta las notas de un alumno para una actividad en una de sus materias. 
Se deberá controlar que dicho docente esté actualmente dictando la materia solicitada y que el alumno la esté cursando.
b). Mediante una función, se obtendrá la edad de un alumno ingresando su número de legajo. Se devolverá un número entero.

c). Mediante una función, se pueda obtener la cantidad de materias que un alumno dado está cursando actualmente. Si no cursa ninguna materia, devolverá cero.

d). Un profesor pueda visualizar la lista de los estudiantes, cada uno con su edad, de una materia que dicta. Además de una identificación personal deberá ingresar al procedimiento el código de la materia. Este procedimiento debe aceptar que se le ingrese como identificación del docente: el legajo, su apellido y DNI, o su mail. Se deberá controlar que la materia solicitada sea una materia que el profesor en cuestión esté dictando actualmente y se validará que el docente sea un docente del Instituto.

Nota: todas las consignas deben llevar los bloques anónimos de prueba.*/

create or replace PACKAGE PKG_ADMINISTRAR_TAREAS AS 
procedure alta_nota(p_legajo IN NUMBER, p_curso_id IN NUMBER, p_nota IN NUMBER);
function obtener_edad(p_legajo IN NUMBER) RETURN NUMBER;