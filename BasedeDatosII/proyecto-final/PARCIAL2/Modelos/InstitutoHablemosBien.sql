/*1. No se permite dar de alta ni cursos, ni alumnos, ni docentes los fines de semana.
  2. Realizar un procedimiento que permita validar el email de un alumno.

El formato de un email correcto contiene un nombre de usuario seguido de una "@" y un dominio.
Los nombres de los usuarios sólo pueden contener letras (a-z), números (0-9), y punto (.) el que no puede estar al final.
Además el primer carácter debe ser una letra.
Los nombres de dominio sólo pueden contener letras (a-z), números (0-9) y el guion menos (-).
El guion (-) sólo es permitido si no está al principio o al final del nombre de dominio.*/

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





