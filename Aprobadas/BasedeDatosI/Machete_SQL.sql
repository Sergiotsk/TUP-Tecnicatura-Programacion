--------------------------------------------------------------------------------
-- 📘 UTN Machete SQL Completo – CHAD-GPTUP Edition
-- Incluye: DDL, DML, DQL, JOINs, VISTAS, CASE, GROUP BY, HAVING, ORDER BY
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
-- 🔹 CREAR TABLAS (DDL)
--------------------------------------------------------------------------------
-- Teoría: CREATE TABLE define una nueva tabla en la base de datos.
-- Sintaxis:
-- CREATE TABLE nombre (
--     columna1 tipo [restricciones],
--     columna2 tipo,
--     ...
-- );

CREATE TABLE ejemplo (
    id NUMBER(4) PRIMARY KEY,
    nombre VARCHAR2(50),
    fecha DATE DEFAULT SYSDATE,
    sueldo NUMBER(10,2)
);

--------------------------------------------------------------------------------
-- 🔹 AGREGAR COLUMNAS
--------------------------------------------------------------------------------
-- Teoría: ALTER TABLE modifica una tabla ya creada.
-- Sintaxis:
-- ALTER TABLE tabla ADD (columna tipo);

ALTER TABLE ejemplo ADD (direccion VARCHAR2(100));

--------------------------------------------------------------------------------
-- 🔹 MODIFICAR TIPO DE DATO DE UNA COLUMNA
--------------------------------------------------------------------------------
-- Sintaxis:
-- ALTER TABLE tabla MODIFY (columna nuevo_tipo);

ALTER TABLE ejemplo MODIFY (sueldo NUMBER(12,2));

--------------------------------------------------------------------------------
-- 🔹 CAMBIAR EL NOMBRE DE UNA COLUMNA
--------------------------------------------------------------------------------
-- Sintaxis:
-- ALTER TABLE tabla RENAME COLUMN viejo_nombre TO nuevo_nombre;

ALTER TABLE ejemplo RENAME COLUMN nombre TO nombre_completo;

--------------------------------------------------------------------------------
-- 🔹 ELIMINAR UNA COLUMNA
--------------------------------------------------------------------------------
ALTER TABLE ejemplo DROP COLUMN direccion;

--------------------------------------------------------------------------------
-- 🔹 INSERTAR REGISTROS (DML)
--------------------------------------------------------------------------------
-- Sintaxis:
-- INSERT INTO tabla (col1, col2, ...) VALUES (val1, val2, ...);

INSERT INTO ejemplo (id, nombre_completo, sueldo) 
VALUES (1, 'Juan Pérez', 65000);

--------------------------------------------------------------------------------
-- 🔹 ACTUALIZAR DATOS EXISTENTES
--------------------------------------------------------------------------------
-- Sintaxis:
-- UPDATE tabla SET columna = valor WHERE condición;

UPDATE ejemplo 
SET sueldo = sueldo + 10000 
WHERE id = 1;

--------------------------------------------------------------------------------
-- 🔹 ELIMINAR REGISTROS
--------------------------------------------------------------------------------
-- Sintaxis:
-- DELETE FROM tabla WHERE condición;

DELETE FROM ejemplo WHERE id = 1;

--------------------------------------------------------------------------------
-- 🔹 CONSULTAS BÁSICAS (DQL)
--------------------------------------------------------------------------------
-- Sintaxis:
-- SELECT columnas FROM tabla [WHERE condición] [ORDER BY columna];

SELECT * FROM ejemplo ORDER BY nombre_completo;

--------------------------------------------------------------------------------
-- 🔹 FILTRAR DATOS (WHERE)
--------------------------------------------------------------------------------
-- Operadores: =, <>, >, <, >=, <=, BETWEEN, IN, LIKE, IS NULL
SELECT * FROM ejemplo WHERE sueldo BETWEEN 50000 AND 80000;
SELECT * FROM ejemplo WHERE nombre_completo LIKE 'J%';
SELECT * FROM ejemplo WHERE sueldo IS NOT NULL;

--------------------------------------------------------------------------------
-- 🔹 AGRUPAMIENTO Y AGREGACIÓN
--------------------------------------------------------------------------------
-- COUNT, SUM, AVG, MAX, MIN
SELECT 
    COUNT(*) AS cantidad, 
    ROUND(AVG(sueldo),2) AS promedio
FROM ejemplo;

-- GROUP BY agrupa por valores comunes
-- HAVING filtra los resultados agrupados
SELECT 
    depto, COUNT(*) AS empleados
FROM empleados
GROUP BY depto
HAVING COUNT(*) > 5;

--------------------------------------------------------------------------------
-- 🔹 JOINs
--------------------------------------------------------------------------------
-- INNER JOIN: devuelve coincidencias
-- LEFT JOIN: incluye los registros de la izquierda aunque no tengan coincidencia

SELECT 
    a.nombre, c.nombre_curso
FROM alumno a
JOIN matricula m ON a.legajo = m.alumno
JOIN curso c ON m.curso = c.id;

--------------------------------------------------------------------------------
-- 🔹 FUNCIONES DE TEXTO
--------------------------------------------------------------------------------
SELECT 
    UPPER(nombre_completo) AS MAYUS,
    LOWER(nombre_completo) AS MINUS,
    LENGTH(nombre_completo) AS LONGITUD
FROM ejemplo;

--------------------------------------------------------------------------------
-- 🔹 FUNCIONES DE FECHA
--------------------------------------------------------------------------------
-- SYSDATE: fecha actual
-- ADD_MONTHS, MONTHS_BETWEEN, NEXT_DAY

SELECT 
    SYSDATE AS hoy,
    ADD_MONTHS(SYSDATE, 6) AS dentro_6_meses,
    TRUNC(MONTHS_BETWEEN(SYSDATE, TO_DATE('2020-01-01', 'YYYY-MM-DD'))) AS meses_diff
FROM dual;

--------------------------------------------------------------------------------
-- 🔹 FUNCIONES NUMÉRICAS
--------------------------------------------------------------------------------
-- ROUND (redondea), TRUNC (trunca), MOD (resto)
SELECT 
    ROUND(123.456, 2) AS redondeado,
    TRUNC(123.456, 2) AS truncado,
    MOD(10, 3) AS resto
FROM dual;

--------------------------------------------------------------------------------
-- 🔹 CASE (CONDICIONES DENTRO DE UN SELECT)
--------------------------------------------------------------------------------
-- Teoría: CASE evalúa condiciones y devuelve valores distintos según el resultado.

SELECT 
    nombre_completo,
    sueldo,
    CASE 
        WHEN sueldo < 50000 THEN 'BAJO'
        WHEN sueldo BETWEEN 50000 AND 80000 THEN 'MEDIO'
        ELSE 'ALTO'
    END AS nivel_salarial
FROM ejemplo;

--------------------------------------------------------------------------------
-- 🔹 VISTAS
--------------------------------------------------------------------------------
-- Teoría: Una vista es una consulta guardada como una tabla virtual.
-- Sintaxis:
-- CREATE OR REPLACE VIEW nombre AS SELECT ...

CREATE OR REPLACE VIEW vista_empleados AS
SELECT 
    nombre_completo, 
    sueldo, 
    CASE 
        WHEN sueldo > 80000 THEN 'ALTO'
        ELSE 'NORMAL'
    END AS categoria
FROM ejemplo;

-- Consultar vista
SELECT * FROM vista_empleados;

--------------------------------------------------------------------------------
-- 🔹 SUBCONSULTAS
--------------------------------------------------------------------------------
-- Teoría: una consulta dentro de otra.
SELECT nombre_completo, sueldo 
FROM ejemplo
WHERE sueldo > (SELECT AVG(sueldo) FROM ejemplo);

--------------------------------------------------------------------------------
-- 🔹 ORDER BY
--------------------------------------------------------------------------------
-- Ordena resultados de menor a mayor (ASC) o mayor a menor (DESC)
SELECT * FROM ejemplo ORDER BY sueldo DESC;

--------------------------------------------------------------------------------
-- 🔹 TRANSACCIONES
--------------------------------------------------------------------------------
-- COMMIT confirma cambios, ROLLBACK revierte.
UPDATE ejemplo SET sueldo = sueldo - 5000 WHERE id = 1;
ROLLBACK;
COMMIT;

--------------------------------------------------------------------------------
-- 🔹 FUNCIONES DE CONTEO Y AGRUPACIÓN CON HAVING
--------------------------------------------------------------------------------
SELECT 
    c.nombre AS carrera,
    COUNT(a.legajo) AS cant_alumnos
FROM carrera c
JOIN alumno a ON a.carrera = c.id
LEFT JOIN matricula m ON m.alumno = a.legajo
WHERE m.curso IS NULL
GROUP BY c.nombre
ORDER BY c.nombre;

--------------------------------------------------------------------------------
-- 🔹 JOINS MÚLTIPLES CON CONDICIONES
--------------------------------------------------------------------------------
SELECT 
    m.nombre AS materia,
    COUNT(mt.alumno) AS inscriptos
FROM materia m
JOIN curso c ON c.materia = m.id
JOIN matricula mt ON mt.curso = c.id
GROUP BY m.nombre
HAVING COUNT(mt.alumno) > 3
ORDER BY m.nombre;

--------------------------------------------------------------------------------
-- 🔹 EJEMPLO DE CALCULAR SUELDO TOTAL DE DOCENTES
--------------------------------------------------------------------------------
SELECT 
    p.apellido || ', ' || p.nombre AS profesor,
    ROUND(SUM(c.sueldo_basico)) AS sueldo_total
FROM profesor p
JOIN cat_doc cd ON p.id = cd.docente
JOIN categorias c ON c.codigo = cd.categoria
GROUP BY p.apellido, p.nombre
ORDER BY p.apellido;

--------------------------------------------------------------------------------
-- 🔹 ELIMINAR UNA TABLA
--------------------------------------------------------------------------------
DROP TABLE ejemplo;

--------------------------------------------------------------------------------
-- 🔹 CONSULTAR OBJETOS PROPIOS (VISTAS, TABLAS)
--------------------------------------------------------------------------------
SELECT table_name FROM user_tables;
SELECT view_name FROM user_views;

--------------------------------------------------------------------------------
-- FIN DEL Machete SQL UTN 💪
--------------------------------------------------------------------------------
