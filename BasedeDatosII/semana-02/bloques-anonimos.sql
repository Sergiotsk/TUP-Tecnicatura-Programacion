-- =============================================
-- Ejercicios Semana 02: Bloques anónimos, variables y condicionales
-- Fuente: Apunte Parte 1 — "Ejercicios de Bloques Anónimos" (Ejercicios 1 al 5)
-- =============================================

-- EJERCICIO 1: Bloque anónimo básico con DBMS_OUTPUT

SET SERVEROUTPUT ON;
DECLARE
  l_mensaje VARCHAR2(50) := 'Hola PL/SQL';
BEGIN
  DBMS_OUTPUT.put_line(l_mensaje);
END;
/


-- EJERCICIO 2: Variables con prefijo l_ y g_
/*
DECLARE
  l_nombre VARCHAR2(100) := 'Sergio';
  g_contador NUMBER := 0; -- g_ para global (en un paquete sería)
BEGIN
  DBMS_OUTPUT.put_line('Nombre: ' || l_nombre);
END;
/
*/

-- EJERCICIO 3: IF-THEN simple
/*
DECLARE
  l_salario NUMBER := 5000;
BEGIN
  IF l_salario > 4000 THEN
    DBMS_OUTPUT.put_line('Salario alto');
  END IF;
END;
/
*/

-- EJERCICIO 4: IF-THEN-ELSE
/*
DECLARE
  l_nota NUMBER := 7;
BEGIN
  IF l_nota >= 6 THEN
    DBMS_OUTPUT.put_line('Aprobado');
  ELSE
    DBMS_OUTPUT.put_line('Desaprobado');
  END IF;
END;
/
*/

-- EJERCICIO 5: IF-ELSIF-ELSE
/*
DECLARE
  l_calificacion NUMBER := 9;
BEGIN
  IF l_calificacion >= 9 THEN
    DBMS_OUTPUT.put_line('Excelente');
  ELSIF l_calificacion >= 7 THEN
    DBMS_OUTPUT.put_line('Muy bueno');
  ELSIF l_calificacion >= 6 THEN
    DBMS_OUTPUT.put_line('Bueno');
  ELSE
    DBMS_OUTPUT.put_line('Insuficiente');
  END IF;
END;
/
*/
