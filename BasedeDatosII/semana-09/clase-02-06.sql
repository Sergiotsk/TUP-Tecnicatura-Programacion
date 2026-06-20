--Crear un paquete que sirva para la administracion de los cursos de un profesor
--Debera permitir el alta de notas al sistema
--Calcular la edad de un alumno
--Devolver la cantidad de materias que cursa un alumno 
--Listar los alumnos dando la materia, y el profesor (esto puede ser apellido y DNI o mail)



create or replace package ADMINISTRACION_PROFESORES
IS 
    PI CONSTANT NUMBER (5,4) := 3.1416;
    ERROR_APP EXCEPTION;
    PROCEDURE ALTA_NOTAS(P_ID_MATERIA IN NOTAS)