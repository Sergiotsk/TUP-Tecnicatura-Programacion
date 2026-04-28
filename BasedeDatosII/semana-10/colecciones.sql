-- =============================================
-- Ejercicios Semana 10: Variables de sustitución, bind y Colecciones
-- Fuente: Apunte Parte 7 — "Ingresar un Dato por Teclado", "Trabajando con Colecciones"
-- Ejercicios 3 al 5 de Paquetes (Parte 6) + ejemplos de colecciones
-- =============================================

-- VARIABLES DE SUSTITUCIÓN Y BIND

-- EJERCICIO 1: Variable de sustitución (&)
/*
SELECT first_name, salary FROM employees WHERE department_id = &dept_id;
*/

-- EJERCICIO 2: Variable de sustitución persistente (&&)
/*
SELECT first_name FROM employees WHERE department_id = &&dept_id;
-- Luego usar &dept_id no vuelve a preguntar
*/

-- EJERCICIO 3: Variable de enlace/bind (VARIABLE, EXEC)
/*
VARIABLE b_emp_id NUMBER;
EXEC :b_emp_id := 100;
SELECT first_name FROM employees WHERE employee_id = :b_emp_id;
*/

-- COLECCIONES PL/SQL

-- EJERCICIO 4: VARRAY (tamaño fijo, denso)
/*
DECLARE
  TYPE t_nombres IS VARRAY(5) OF VARCHAR2(50);
  l_nombres t_nombres := t_nombres('Juan', 'María', 'Pedro');
BEGIN
  FOR i IN 1..l_nombres.COUNT LOOP
    DBMS_OUTPUT.put_line(l_nombres(i));
  END LOOP;
END;
/
*/

-- EJERCICIO 5: Tabla anidada (asociativa o densa)
/*
DECLARE
  TYPE t_emp_list IS TABLE OF VARCHAR2(100);
  l_empleados t_emp_list := t_emp_list('Emp1', 'Emp2', 'Emp3');
BEGIN
  l_empleados.EXTEND; -- Agregar espacio
  l_empleados(4) := 'Emp4';
  
  FOR i IN l_empleados.FIRST..l_empleados.LAST LOOP
    IF l_empleados.EXISTS(i) THEN
      DBMS_OUTPUT.put_line(l_empleados(i));
    END IF;
  END LOOP;
END;
/
*/

-- EJERCICIO 6: Matriz asociativa (INDEX BY)
/*
DECLARE
  TYPE t_salarios IS TABLE OF NUMBER INDEX BY VARCHAR2(50);
  l_salarios t_salarios;
  l_nombre VARCHAR2(50);
BEGIN
  l_salarios('Juan') := 5000;
  l_salarios('Ana') := 6000;
  
  l_nombre := l_salarios.FIRST;
  WHILE l_nombre IS NOT NULL LOOP
    DBMS_OUTPUT.put_line(l_nombre || ': ' || l_salarios(l_nombre));
    l_nombre := l_salarios.NEXT(l_nombre);
  END LOOP;
END;
/
*/

-- EJERCICIO 7: Operadores MULTISET con tablas anidadas
/*
DECLARE
  TYPE t_nums IS TABLE OF NUMBER;
  l_set1 t_nums := t_nums(1,2,3,4);
  l_set2 t_nums := t_nums(3,4,5,6);
BEGIN
  -- MULTISET UNION
  DECLARE
    l_result t_nums := l_set1 MULTISET UNION l_set2;
  BEGIN
    DBMS_OUTPUT.put_line('Unión: ' || l_result.COUNT || ' elementos');
  END;
END;
/
*/
