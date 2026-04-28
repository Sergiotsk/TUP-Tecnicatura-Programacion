-- =============================================
-- Ejercicios Semana 14: Optimización, Índices y Vistas
-- Fuente: Documentación Oracle — sección sobre índices y optimización
-- =============================================

-- EJERCICIO 1: Crear índice B-tree (por defecto)
/*
CREATE INDEX idx_emp_last_name ON employees(last_name);
*/

-- EJERCICIO 2: Crear índice bitmap (para columnas con pocos valores distintos)
/*
CREATE BITMAP INDEX idx_emp_gender ON employees(gender); -- Asumiendo que existe
*/

-- EJERCICIO 3: Crear índice compuesto
/*
CREATE INDEX idx_emp_dept_job ON employees(department_id, job_id);
*/

-- EJERCICIO 4: Crear vista simple
/*
CREATE VIEW v_empleados_salario AS
  SELECT first_name, last_name, salary, department_id
  FROM employees
  WHERE salary > 5000;
*/

-- EJERCICIO 5: Crear vista con funciones de agregación
/*
CREATE VIEW v_dept_salarios AS
  SELECT d.department_name,
         COUNT(e.employee_id) AS cantidad,
         AVG(e.salary) AS promedio
  FROM departments d
  LEFT JOIN employees e ON d.department_id = e.department_id
  GROUP BY d.department_name;
*/

-- EJERCICIO 6: Analizar plan de ejecución con EXPLAIN PLAN
/*
EXPLAIN PLAN FOR
  SELECT * FROM employees WHERE last_name = 'King';

SELECT * FROM TABLE(DBMS_XPLAN.DISPLAY);
*/

-- EJERCICIO 7: Reconstruir índice (mantenimiento)
/*
ALTER INDEX idx_emp_last_name REBUILD;
*/

-- EJERCICIO 8: Consultar índices en el diccionario
/*
SELECT index_name, table_name, uniqueness
FROM user_indexes
WHERE table_name = 'EMPLOYEES';
*/

-- EJERCICIO 9: Crear vista materializada (si corresponde)
/*
CREATE MATERIALIZED VIEW mv_dept_summary
  BUILD IMMEDIATE
  REFRESH ON COMMIT
  AS
  SELECT department_id, COUNT(*) AS emp_count, AVG(salary) AS avg_salary
  FROM employees
  GROUP BY department_id;
*/

-- EJERCICIO 10: Eliminar objetos de práctica
/*
DROP VIEW v_empleados_salario;
DROP INDEX idx_emp_last_name;
*/
