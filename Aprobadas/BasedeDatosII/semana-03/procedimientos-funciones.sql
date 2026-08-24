-- =============================================
-- Ejercicios Semana 03: Procedimientos y Funciones
-- Fuente: Apunte Parte 2 — "Bloques Almacenados", "Procedimientos con parámetros"
-- Ejercicios 6 al 10 de "Ejercicios de Bloques Almacenados"
-- =============================================

-- EJERCICIO 1: Crear procedimiento SALUDOS (Parte 2)
/*
CREATE OR REPLACE PROCEDURE saludos AS
BEGIN
  DBMS_OUTPUT.put_line('¡Hola desde un procedimiento!');
END saludos;
/
EXEC saludos;


-- EJERCICIO 2: Crear procedimiento SALUDAR con parámetro

CREATE OR REPLACE PROCEDURE saludar(p_nombre IN VARCHAR2) AS
BEGIN  
  DBMS_OUTPUT.put_line('Hola ' || p_nombre);
END saludar;
/
 EXEC saludar('&Nombre');

*/

-- EJERCICIO 3: Función que retorna un valor

CREATE OR REPLACE FUNCTION obtener_salario(p_emp_id IN NUMBER)
  RETURN NUMBER IS
  v_salario NUMBER;
BEGIN
  SELECT salary INTO v_salario FROM employees WHERE employee_id = p_emp_id;
  RETURN v_salario;
END obtener_salario;
/
-- Ejecutar: SELECT obtener_salario(100) FROM dual;


-- EJERCICIO 4: Procedimiento con parámetros OUT
/*
CREATE OR REPLACE PROCEDURE obtener_datos_emp(
  p_emp_id IN  NUMBER,
  p_nombre OUT VARCHAR2,
  p_salario OUT NUMBER
) AS
BEGIN
  SELECT first_name || ' ' || last_name, salary
  INTO p_nombre, p_salario
  FROM employees
  WHERE employee_id = p_emp_id;
END obtener_datos_emp;
/
*/

-- EJERCICIO 5: Procedimiento con IN OUT
/*
CREATE OR REPLACE PROCEDURE incrementar_salario(
  p_emp_id IN OUT NUMBER,
  p_porcentaje IN NUMBER
) AS
BEGIN
  UPDATE employees SET salary = salary * (1 + p_porcentaje/100)
  WHERE employee_id = p_emp_id;
END incrementar_salario;
/
*/
