-- =============================================
-- Ejercicios Semana 07: Manejo de Excepciones (continuación)
-- Fuente: Apunte Parte 5 — "Las Excepciones"
-- Ejercicios 1 al 5 de "Ejercicios de Excepciones" (Parte 5)
-- =============================================

-- EJERCICIO 1: Excepción DUP_VAL_ON_INDEX
/*
DECLARE
  l_dept_id NUMBER := 999;
BEGIN
  INSERT INTO departments (department_id, department_name) VALUES (l_dept_id, 'TEST1');
  INSERT INTO departments (department_id, department_name) VALUES (l_dept_id, 'TEST2');
EXCEPTION
  WHEN DUP_VAL_ON_INDEX THEN
    DBMS_OUTPUT.put_line('Error: clave duplicada en departments');
END;
/
*/

-- EJERCICIO 2: Excepción definida por usuario con RAISE_APPLICATION_ERROR
/*
DECLARE
  l_email VARCHAR2(100) := 'no-es-email';
  e_email_invalido EXCEPTION;
  PRAGMA EXCEPTION_INIT(e_email_invalido, -20002);
BEGIN
  IF INSTR(l_email, '@') = 0 THEN
    RAISE_APPLICATION_ERROR(-20002, 'Formato de email inválido');
  END IF;
EXCEPTION
  WHEN e_email_invalido THEN
    DBMS_OUTPUT.put_line('Error: ' || SQLERRM);
END;
/
*/

-- EJERCICIO 3: Transacción autónoma (PRAGMA AUTONOMOUS_TRANSACTION)
/*
CREATE OR REPLACE PROCEDURE log_error(p_msg VARCHAR2) AS
  PRAGMA AUTONOMOUS_TRANSACTION;
BEGIN
  INSERT INTO control VALUES (USER, SYSDATE, p_msg);
  COMMIT;
END log_error;
/
*/

-- EJERCICIO 4: Manejo con WHEN OTHERS y ROLLBACK
/*
BEGIN
  SAVEPOINT antes_update;
  UPDATE employees SET salary = salary * 1.1 WHERE department_id = 50;
  -- Simular error
  RAISE_APPLICATION_ERROR(-20003, 'Error simulado');
EXCEPTION
  WHEN OTHERS THEN
    ROLLBACK TO antes_update;
    DBMS_OUTPUT.put_line('Se hizo rollback de la transacción');
END;
/
*/

-- EJERCICIO 5: Excepciones en sección de declaración
/*
DECLARE
  l_variable NUMBER := 'abc'; -- Error en declaración
BEGIN
  DBMS_OUTPUT.put_line(l_variable);
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line('Error en declaración: ' || SQLERRM);
END;
/
*/
