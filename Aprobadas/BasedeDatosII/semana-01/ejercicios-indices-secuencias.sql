-- =============================================
-- Ejercicios Semana 01: Repaso SQL + Índices + Secuencias
-- Fuente: Apunte Parte 1 — sección "¿Qué es PL/SQL?" y "Componentes básicos"
-- Objetivo: Crear índices sobre tablas HR, crear secuencia para IDs automáticos
-- =============================================

-- EJERCICIO 1: Repaso SELECT básico
SELECT * FROM empleados where departamento_id = 85;

-- EJERCICIO 2: Repaso INSERT
INSERT INTO departamentos (dpto_id, nombre) VALUES (999, 'TEST_DEPT');
select * from departamentos;

-- EJERCICIO 3: Crear índice simple
 CREATE INDEX idx_emp_last_name ON empleados(apellido);

-- EJERCICIO 4: Crear índice compuesto
 CREATE INDEX idx_emp_dept_id ON empleados(departamento_id, categoria_codigo);

-- EJERCICIO 5: Crear secuencia para generación automática de IDs
  CREATE SEQUENCE seq_employee_id
   START WITH 300
   INCREMENT BY 1
   NOCACHE
   NOCYCLE;

-- EJERCICIO 6: Usar la secuencia
 SELECT seq_employee_id.NEXTVAL FROM dual;

-- EJERCICIO 7: Insertar usando la secuencia
INSERT INTO empleados (id, nombre, apellido, email, fecha_alta, categoria_codigo)
VALUES (seq_employee_id.NEXTVAL, 'JUAN', 'PEREZ', 'JPER', current_date, 1); --current_date (solo fecha de mi zona horaria /  current_timestamp (fecha y hora completa))

--consulta datos cargados
select * from empleados;

-- EJERCICIO 8: Repaso UPDATE
 UPDATE categorias SET salario_min = salario_min * 0.50 WHERE codigo = 10;

-- EJERCICIO 9: Repaso DELETE
 DELETE departamentos WHERE dpto_id = 999;

-- EJERCICIO 10: Eliminar índice (para limpiar)
 DROP INDEX idx_emp_last_name;
