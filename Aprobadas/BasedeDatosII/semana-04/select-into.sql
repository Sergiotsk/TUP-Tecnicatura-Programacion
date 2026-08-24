-- =============================================
-- Ejercicios Semana 04: SELECT INTO y Cursores Implícitos
-- Fuente: Apunte Parte 3 — "Introducción", "El Cursor SELECT-INTO", "Cursores Implícitos"
-- Ejercicios 1 al 5 de "Ejercicios de Cursores" (Parte 3)
-- =============================================

-- EJERCICIO 1: SELECT INTO básico (recupera exactamente una fila)
/*
DECLARE
  l_nombre employees.first_name%TYPE;
BEGIN
  SELECT first_name INTO l_nombre FROM employees WHERE employee_id = 100;
  DBMS_OUTPUT.put_line('Nombre: ' || l_nombre);
END;
/
*/

-- EJERCICIO 2: Manejo de NO_DATA_FOUND con SELECT INTO
/*
DECLARE
  l_salario employees.salary%TYPE;
BEGIN
  SELECT salary INTO l_salario FROM employees WHERE employee_id = 9999;
  DBMS_OUTPUT.put_line('Salario: ' || l_salario);
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.put_line('No se encontró el empleado');
END;
/
*/

-- EJERCICIO 3: Manejo de TOO_MANY_ROWS
/*
DECLARE
  l_nombre employees.first_name%TYPE;
BEGIN
  SELECT first_name INTO l_nombre FROM employees WHERE department_id = 50;
EXCEPTION
  WHEN TOO_MANY_ROWS THEN
    DBMS_OUTPUT.put_line('Hay más de una fila, usar un cursor');
END;
/
*/

-- EJERCICIO 4: Atributos de cursor implícito SQL%FOUND
/*
BEGIN
  UPDATE employees SET salary = salary * 1.1 WHERE employee_id = 100;
  IF SQL%FOUND THEN
    DBMS_OUTPUT.put_line('Se actualizó un empleado');
  ELSE
    DBMS_OUTPUT.put_line('No se actualizó ninguno');
  END IF;
END;
/
*/

-- EJERCICIO 5: Atributos SQL%ROWCOUNT y SQL%NOTFOUND
/*
BEGIN
  DELETE FROM employees WHERE employee_id = 9999;
  IF SQL%NOTFOUND THEN
    DBMS_OUTPUT.put_line('No se encontró el registro para borrar');
  ELSE
    DBMS_OUTPUT.put_line('Filas borradas: ' || SQL%ROWCOUNT);
  END IF;
END;
/
*/
