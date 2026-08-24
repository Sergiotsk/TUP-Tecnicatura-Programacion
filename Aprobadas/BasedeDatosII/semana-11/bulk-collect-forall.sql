-- =============================================
-- Ejercicios Semana 11: BULK COLLECT y FORALL
-- Fuente: Apunte Parte 7 — "BULK COLLECT y FORALL", "Cambios de contexto y rendimiento"
-- Ejercicios 4 y 5 de Paquetes + ejemplos de BULK COLLECT y FORALL
-- =============================================

-- EJERCICIO 1: BULK COLLECT básico (recuperar múltiples filas en una colección)
/*
DECLARE
  TYPE t_emp_ids IS TABLE OF employees.employee_id%TYPE;
  TYPE t_salarios IS TABLE OF employees.salary%TYPE;
  
  l_ids t_emp_ids;
  l_salarios t_salarios;
BEGIN
  SELECT employee_id, salary
  BULK COLLECT INTO l_ids, l_salarios
  FROM employees
  WHERE department_id = 50;
  
  DBMS_OUTPUT.put_line('Filas recuperadas: ' || l_ids.COUNT);
  
  FOR i IN 1..l_ids.COUNT LOOP
    DBMS_OUTPUT.put_line('Emp: ' || l_ids(i) || ' - Salario: ' || l_salarios(i));
  END LOOP;
END;
/
*/

-- EJERCICIO 2: FORALL para DML masivo
/*
DECLARE
  TYPE t_ids IS TABLE OF employees.employee_id%TYPE;
  l_ids t_ids;
BEGIN
  SELECT employee_id
  BULK COLLECT INTO l_ids
  FROM employees
  WHERE department_id = 50;
  
  FORALL i IN 1..l_ids.COUNT
    UPDATE employees
    SET salary = salary * 1.05
    WHERE employee_id = l_ids(i);
  
  DBMS_OUTPUT.put_line('Filas actualizadas: ' || SQL%ROWCOUNT);
END;
/
*/

-- EJERCICIO 3: BULK COLLECT con LIMIT (para conjuntos grandes)
/*
DECLARE
  CURSOR c_emps IS SELECT employee_id, first_name, salary FROM employees;
  TYPE t_emp_rec IS TABLE OF c_emps%ROWTYPE;
  l_emps t_emp_rec;
BEGIN
  OPEN c_emps;
  LOOP
    FETCH c_emps BULK COLLECT INTO l_emps LIMIT 10;
    EXIT WHEN l_emps.COUNT = 0;
    
    FOR i IN 1..l_emps.COUNT LOOP
      DBMS_OUTPUT.put_line(l_emps(i).first_name || ': ' || l_emps(i).salary);
    END LOOP;
  END LOOP;
  CLOSE c_emps;
END;
/
*/

-- EJERCICIO 4: FORALL con INDICES OF (manejar colecciones dispersas)
/*
DECLARE
  TYPE t_ids IS TABLE OF NUMBER;
  l_ids t_ids := t_ids(100, 101, 102, 103);
BEGIN
  FORALL i IN INDICES OF l_ids
    UPDATE employees
    SET salary = salary * 1.10
    WHERE employee_id = l_ids(i);
  
  DBMS_OUTPUT.put_line('Actualizados: ' || SQL%ROWCOUNT);
END;
/
*/

-- EJERCICIO 5: Medir rendimiento con DBMS_UTILITY
/*
DECLARE
  l_start NUMBER;
  l_end NUMBER;
BEGIN
  l_start := DBMS_UTILITY.get_time;
  
  -- Código a medir
  FOR i IN 1..1000 LOOP
    UPDATE employees SET salary = salary WHERE employee_id = 100;
  END LOOP;
  
  l_end := DBMS_UTILITY.get_time;
  DBMS_OUTPUT.put_line('Tiempo: ' || (l_end - l_start) || ' centésimas');
END;
/
*/

-- CAMBIOS DE CONTEXTO (PL/SQL ↔ SQL)
-- Cada vez que hay un SQL statement dentro de PL/SQL hay un cambio de contexto
-- BULK COLLECT y FORALL reducen drásticamente estos cambios de contexto
-- mejorando el rendimiento en operaciones masivas
