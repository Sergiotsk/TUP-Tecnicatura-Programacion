-- =============================================
-- Ejercicios Semana 05: Cursores Explícitos y SYS_REFCURSOR
-- Fuente: Apunte Parte 3 — "Los Cursores Explícitos", "Usando el Bucle FOR del Cursor", "Variables de cursor"
-- Ejercicios 6 al 10 de "Ejercicios de Cursores" (Parte 3)
-- =============================================

-- EJERCICIO 1: Cursor explícito básico (OPEN, FETCH, CLOSE)
/*
DECLARE
  CURSOR c_empleados IS
    SELECT employee_id, first_name, salary FROM employees WHERE department_id = 50;
  l_emp c_empleados%ROWTYPE;
BEGIN
  OPEN c_empleados;
  LOOP
    FETCH c_empleados INTO l_emp;
    EXIT WHEN c_empleados%NOTFOUND;
    DBMS_OUTPUT.put_line(l_emp.first_name || ' - ' || l_emp.salary);
  END LOOP;
  CLOSE c_empleados;
END;
/
*/

-- EJERCICIO 2: Bucle FOR de cursor (abre y cierra automáticamente)
/*
BEGIN
  FOR r_emp IN (SELECT first_name, salary FROM employees WHERE department_id = 50) LOOP
    DBMS_OUTPUT.put_line(r_emp.first_name || ': ' || r_emp.salary);
  END LOOP;
END;
/
*/

-- EJERCICIO 3: Cursor con parámetro
/*
DECLARE
  CURSOR c_dept(p_dept_id NUMBER) IS
    SELECT first_name, salary FROM employees WHERE department_id = p_dept_id;
BEGIN
  FOR r_emp IN c_dept(50) LOOP
    DBMS_OUTPUT.put_line(r_emp.first_name || ' - ' || r_emp.salary);
  END LOOP;
END;
/
*/

-- EJERCICIO 4: Variable de cursor SYS_REFCURSOR
/*
DECLARE
  v_cursor SYS_REFCURSOR;
  l_nombre employees.first_name%TYPE;
  l_salario employees.salary%TYPE;
BEGIN
  OPEN v_cursor FOR SELECT first_name, salary FROM employees WHERE department_id = 50;
  LOOP
    FETCH v_cursor INTO l_nombre, l_salario;
    EXIT WHEN v_cursor%NOTFOUND;
    DBMS_OUTPUT.put_line(l_nombre || ': ' || l_salario);
  END LOOP;
  CLOSE v_cursor;
END;
/
*/

-- EJERCICIO 5: Cursor FOR con consulta compleja
/*
BEGIN
  FOR r IN (
    SELECT d.department_name, COUNT(e.employee_id) AS cantidad
    FROM departments d
    LEFT JOIN employees e ON d.department_id = e.department_id
    GROUP BY d.department_name
    HAVING COUNT(e.employee_id) > 0
  ) LOOP
    DBMS_OUTPUT.put_line(r.department_name || ': ' || r.cantidad || ' empleados');
  END LOOP;
END;
/
*/
