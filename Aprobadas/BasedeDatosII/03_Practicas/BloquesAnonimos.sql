--1. Definir la salida por consola de los bloques anónimos de la sesión.
--En Oracle PL/SQL, antes de ejecutar cualquier bloque anónimo que use DBMS_OUTPUT.PUT_LINE
SET SERVEROUTPUT ON;

--2. Realizar un bloque anónimo que salude a todos

BEGIN
    DBMS_OUTPUT.PUT_LINE('Hola a todos');
END;
/


