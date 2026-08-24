-- =============================================
-- Ejercicios Semana 03: %TYPE y %ROWTYPE
-- Fuente: Apunte Parte 2 — "Más sobre Declaración de Variables"
-- Reescribir 3 procedimientos usando %TYPE y %ROWTYPE
-- =============================================

-- EJERCICIO 1: Usar %TYPE para anclar variable al tipo de columna
/*
DECLARE
  l_nombre employees.first_name%TYPE;
  l_salario employees.salary%TYPE;
BEGIN
  SELECT first_name, salary INTO l_nombre, l_salario
  FROM employees WHERE employee_id = 100;
  DBMS_OUTPUT.put_line(l_nombre || ' gana ' || l_salario);
END;
/
*/

-- EJERCICIO 2: Usar %ROWTYPE para registro completo
/*
DECLARE
  l_emp employees%ROWTYPE;
BEGIN
  SELECT * INTO l_emp FROM employees WHERE employee_id = 100;
  DBMS_OUTPUT.put_line(l_emp.first_name || ' ' || l_emp.last_name);
  DBMS_OUTPUT.put_line('Salario: ' || l_emp.salary);
END;
/
*/

-- EJERCICIO 3: Procedimiento con %TYPE y %ROWTYPE combinados
/*
CREATE OR REPLACE PROCEDURE mostrar_emp(p_emp_id IN employees.employee_id%TYPE) AS
  l_emp employees%ROWTYPE;
BEGIN
  SELECT * INTO l_emp FROM employees WHERE employee_id = p_emp_id;
  DBMS_OUTPUT.put_line('Empleado: ' || l_emp.first_name || ' ' || l_emp.last_name);
  DBMS_OUTPUT.put_line('Email: ' || l_emp.email);
END mostrar_emp;
/
*/
