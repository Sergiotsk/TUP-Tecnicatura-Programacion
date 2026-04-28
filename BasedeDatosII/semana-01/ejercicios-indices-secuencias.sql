-- =============================================
-- Ejercicios Semana 01: Repaso SQL + Índices + Secuencias
-- Fuente: Apunte Parte 1 — sección "¿Qué es PL/SQL?" y "Componentes básicos"
-- Objetivo: Crear índices sobre tablas HR, crear secuencia para IDs automáticos
-- =============================================

-- EJERCICIO 1: Repaso SELECT básico
-- SELECT * FROM employees WHERE department_id = 50;

-- EJERCICIO 2: Repaso INSERT
-- INSERT INTO departments (department_id, department_name) VALUES (999, 'TEST_DEPT');

-- EJERCICIO 3: Crear índice simple
-- CREATE INDEX idx_emp_last_name ON employees(last_name);

-- EJERCICIO 4: Crear índice compuesto
-- CREATE INDEX idx_emp_dept_id ON employees(department_id, job_id);

-- EJERCICIO 5: Crear secuencia para generación automática de IDs
-- CREATE SEQUENCE seq_employee_id
--   START WITH 300
--   INCREMENT BY 1
--   NOCACHE
--   NOCYCLE;

-- EJERCICIO 6: Usar la secuencia
-- SELECT seq_employee_id.NEXTVAL FROM dual;

-- EJERCICIO 7: Insertar usando la secuencia
-- INSERT INTO employees (employee_id, first_name, last_name, email, hire_date, job_id)
-- VALUES (seq_employee_id.NEXTVAL, 'JUAN', 'PEREZ', 'JPER', SYSDATE, 'IT_PROG');

-- EJERCICIO 8: Repaso UPDATE
-- UPDATE employees SET salary = salary * 1.10 WHERE department_id = 50;

-- EJERCICIO 9: Repaso DELETE
-- DELETE FROM departments WHERE department_id = 999;

-- EJERCICIO 10: Eliminar índice (para limpiar)
-- DROP INDEX idx_emp_last_name;
