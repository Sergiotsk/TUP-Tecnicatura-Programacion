-- =============================================
-- Ejercicios Semana 08: Excepciones Avanzadas + Repaso Fases 1-3
-- Fuente: Apunte Parte 5 — "Volver a Lanzar Excepciones", "Excepciones y Reversiones"
-- Ejercicios 6 al 10 de "Ejercicios de Excepciones" + Repaso general
-- =============================================

-- EJERCICIO 6: Volver a lanzar excepción (RAISE sin argumento)
/*
CREATE OR REPLACE PROCEDURE procesar_emp(p_emp_id NUMBER) AS
  l_salario NUMBER;
BEGIN
  BEGIN
    SELECT salary INTO l_salario FROM employees WHERE employee_id = p_emp_id;
  EXCEPTION
    WHEN NO_DATA_FOUND THEN
      DBMS_OUTPUT.put_line('Advertencia: empleado no encontrado');
      RAISE; -- Vuelve a lanzar la excepción al llamador
  END;
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line('Error final: ' || SQLERRM);
END procesar_emp;
/
*/

-- EJERCICIO 7: Excepción generada durante la declaración
/*
DECLARE
  l_valor NUMBER;
  l_resultado NUMBER;
BEGIN
  l_valor := 'xyz'; -- Error de conversión en asignación
  l_resultado := 100 / l_valor;
EXCEPTION
  WHEN VALUE_ERROR THEN
    DBMS_OUTPUT.put_line('Error de valor en la asignación');
END;
/
*/

-- EJERCICIO 8: Relación excepciones-transacciones y ROLLBACK
/*
BEGIN
  SAVEPOINT sp1;
  INSERT INTO departments VALUES (998, 'TEST_DEPT', NULL, NULL);
  UPDATE employees SET department_id = 998 WHERE employee_id = 100;
  RAISE_APPLICATION_ERROR(-20004, 'Error de prueba');
EXCEPTION
  WHEN OTHERS THEN
    ROLLBACK TO sp1;
    DBMS_OUTPUT.put_line('Rollback hasta savepoint sp1');
END;
/
*/

-- EJERCICIO 9: Manejador OTHERS capturando todo
/*
BEGIN
  DECLARE
    l_num NUMBER := 10 / 0;
  BEGIN
    NULL;
  END;
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line('Capturado por OTHERS: ' || SQLCODE);
END;
/
*/

-- EJERCICIO 10: Repaso - Bloque completo con manejo robusto
/*
DECLARE
  l_emp employees%ROWTYPE;
BEGIN
  SELECT * INTO l_emp FROM employees WHERE employee_id = 100;
  DBMS_OUTPUT.put_line('Empleado: ' || l_emp.first_name);
  UPDATE employees SET salary = salary * 1.05 WHERE employee_id = 100;
  COMMIT;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.put_line('Empleado no existe');
    ROLLBACK;
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line('Error inesperado: ' || SQLERRM);
    ROLLBACK;
END;
/
*/

-- REPASO FASES 1-3: Ejercicios combinados
-- 1. Bloque anónimo con cursor explícito
-- 2. Procedimiento con parámetros y excepciones
-- 3. Trigger con :NEW/:OLD y RAISE_APPLICATION_ERROR
