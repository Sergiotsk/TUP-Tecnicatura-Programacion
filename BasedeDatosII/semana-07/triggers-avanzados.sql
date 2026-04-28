-- =============================================
-- Ejercicios Semana 07: Triggers Avanzados + Excepciones
-- Fuente: Apunte Parte 4 — "Creación de un Disparador INSTEAD OF", "Habilitar y Deshabilitar"
--         Apunte Parte 5 — "Las Excepciones", "Manejo de Excepciones"
-- Ejercicios 6 al 10 de "Ejercicios de Disparadores" + 1 al 5 de "Ejercicios de Excepciones"
-- =============================================

-- TRIGGERS AVANZADOS

-- EJERCICIO 6: Trigger INSTEAD OF sobre vista
/*
CREATE VIEW v_empleados_dept AS
  SELECT e.employee_id, e.first_name, e.last_name, d.department_name
  FROM employees e JOIN departments d ON e.department_id = d.department_id;

CREATE OR REPLACE TRIGGER trg_vista_empleados
  INSTEAD OF INSERT ON v_empleados_dept
BEGIN
  -- Lógica para manejar el INSERT en la vista
  DBMS_OUTPUT.put_line('INSERT via vista no permitido directamente');
END trg_vista_empleados;
/
*/

-- EJERCICIO 7: Habilitar/Deshabilitar trigger
/*
ALTER TRIGGER trg_emp_insert DISABLE;
ALTER TRIGGER trg_emp_insert ENABLE;
*/

-- EJERCICIO 8: Consultar triggers en el diccionario de datos
/*
SELECT trigger_name, status FROM user_triggers;
SELECT object_name FROM user_objects WHERE object_type = 'TRIGGER';
*/

-- EJERCICIO 9: Drop trigger
/*
DROP TRIGGER trg_emp_stmt;
*/

-- EJERCICIO 10: Trigger con múltiples eventos
/*
CREATE OR REPLACE TRIGGER trg_emp_all
  BEFORE INSERT OR UPDATE OR DELETE ON employees
  FOR EACH ROW
BEGIN
  IF INSERTING THEN
    DBMS_OUTPUT.put_line('Insertando empleado');
  ELSIF UPDATING THEN
    DBMS_OUTPUT.put_line('Actualizando empleado');
  ELSIF DELETING THEN
    DBMS_OUTPUT.put_line('Borrando empleado');
  END IF;
END trg_emp_all;
/
*/

-- EXCEPCIONES (Parte 5)

-- EJERCICIO 1: Excepción predefinida NO_DATA_FOUND
/*
DECLARE
  l_nombre employees.first_name%TYPE;
BEGIN
  SELECT first_name INTO l_nombre FROM employees WHERE employee_id = 9999;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.put_line('No se encontró el empleado');
END;
/
*/

-- EJERCICIO 2: Excepción predefinida ZERO_DIVIDE
/*
DECLARE
  l_resultado NUMBER;
BEGIN
  l_resultado := 10 / 0;
EXCEPTION
  WHEN ZERO_DIVIDE THEN
    DBMS_OUTPUT.put_line('Error: división por cero');
END;
/
*/

-- EJERCICIO 3: Excepción definida por el usuario con RAISE
/*
DECLARE
  e_salario_invalido EXCEPTION;
  l_salario NUMBER := -1000;
BEGIN
  IF l_salario < 0 THEN
    RAISE e_salario_invalido;
  END IF;
EXCEPTION
  WHEN e_salario_invalido THEN
    DBMS_OUTPUT.put_line('Salario inválido');
END;
/
*/

-- EJERCICIO 4: RAISE_APPLICATION_ERROR
/*
BEGIN
  UPDATE employees SET salary = -500 WHERE employee_id = 100;
  IF SQL%ROWCOUNT > 0 THEN
    RAISE_APPLICATION_ERROR(-20001, 'No se permiten salarios negativos');
  END IF;
END;
/
*/

-- EJERCICIO 5: WHEN OTHERS y SQLCODE/SQLERRM
/*
BEGIN
  SELECT columna_inexistente FROM employees;
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line('Error: ' || SQLERRM);
    DBMS_OUTPUT.put_line('Código: ' || SQLCODE);
END;
/
*/
