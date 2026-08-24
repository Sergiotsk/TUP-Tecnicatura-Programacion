-- =============================================
-- Ejercicios Semana 15: Normalización Avanzada y NoSQL
-- Fuente: Material de la cátedra + MongoDB docs
-- =============================================

-- Parte SQL: Normalización hasta 5FN

-- EJERCICIO 1: Verificar 1FN (atomicidad)
-- Tabla original (no 1FN):
/*
CREATE TABLE empleados_no_1fn (
  emp_id NUMBER,
  telefonos VARCHAR2(100) -- Viola 1FN: múltiples valores
);
*/

-- Corrección a 1FN:
/*
CREATE TABLE emp_telefonos (
  emp_id NUMBER,
  telefono VARCHAR2(20),
  PRIMARY KEY (emp_id, telefono)
);
*/

-- EJERCICIO 2: Verificar 2FN (sin dependencias parciales)
-- Tabla con violación de 2FN:
/*
CREATE TABLE emp_dept_no_2fn (
  emp_id NUMBER,
  dept_id NUMBER,
  emp_name VARCHAR2(100),
  dept_name VARCHAR2(50), -- Depende de dept_id, no de emp_id
  PRIMARY KEY (emp_id)
);
*/

-- Corrección a 2FN: separar en dos tablas
/*
CREATE TABLE departamentos (
  dept_id NUMBER PRIMARY KEY,
  dept_name VARCHAR2(50)
);

CREATE TABLE empleados_2fn (
  emp_id NUMBER PRIMARY KEY,
  dept_id NUMBER,
  emp_name VARCHAR2(100),
  FOREIGN KEY (dept_id) REFERENCES departamentos(dept_id)
);
*/

-- EJERCICIO 3: Verificar 3FN (sin dependencias transitivas)
-- Tabla con violación de 3FN:
/*
CREATE TABLE empleados_no_3fn (
  emp_id NUMBER PRIMARY KEY,
  dept_id NUMBER,
  dept_name VARCHAR2(50), -- Transitiva: emp_id → dept_id → dept_name
  salary NUMBER
);
*/

-- EJERCICIO 4: 4FN (independencia de relaciones multivaluadas)
-- Ejemplo: empleado tiene múltiples habilidades y múltiples idiomas
-- No debe haber combinaciones cruzadas espurias

-- EJERCICIO 5: 5FN (descomposición de relaciones join
-- Cada relación representa un hecho independiente

-- Parte NoSQL: Conceptos básicos MongoDB

-- EJERCICIO 6: Estructura de documento en MongoDB (ejemplo conceptual)
/*
{
  "_id": ObjectId("..."),
  "nombre": "Juan Pérez",
  "email": "juan@email.com",
  "telefonos": ["123-4567", "987-6543"],
  "direccion": {
    "calle": "Av. Principal 123",
    "ciudad": "Buenos Aires"
  },
  "habilidades": ["Java", "PL/SQL", "SQL"]
}
*/

-- EJERCICIO 7: Comparación modelo relacional vs documental
-- Relacional: tablas con claves foráneas
-- Documental: documentos JSON anidados, sin JOINs costosos

-- Explorar MongoDB Atlas (free tier) para practicar
-- URL: https://www.mongodb.com/cloud/atlas/register
