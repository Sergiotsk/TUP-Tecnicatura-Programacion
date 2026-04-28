-- =============================================
-- Ejercicios Semana 06: Triggers DML Básicos
-- Fuente: Apunte Parte 4 — "Los Disparadores – Los Triggers", "Sintaxis de un Disparador"
-- Ejercicios 1 al 5 de "Ejercicios de Disparadores" (Parte 4)
-- =============================================

-- Crear tabla de control para auditoría (necesaria para los ejercicios)
/*
CREATE TABLE control (
  usuario VARCHAR2(50),
  fecha DATE,
  accion VARCHAR2(50)
);
*/

-- EJERCICIO 1: Trigger BEFORE INSERT a nivel de fila
/*
CREATE OR REPLACE TRIGGER trg_emp_insert
  BEFORE INSERT ON employees
  FOR EACH ROW
BEGIN
  INSERT INTO control VALUES (USER, SYSDATE, 'INSERT en employees');
END trg_emp_insert;
/
*/

-- EJERCICIO 2: Trigger BEFORE UPDATE con :OLD y :NEW
/*
CREATE OR REPLACE TRIGGER trg_emp_update
  BEFORE UPDATE OF salary ON employees
  FOR EACH ROW
BEGIN
  INSERT INTO control VALUES (
    USER, SYSDATE,
    'Salario cambió de ' || :OLD.salary || ' a ' || :NEW.salary
  );
END trg_emp_update;
/
*/

-- EJERCICIO 3: Trigger AFTER DELETE
/*
CREATE OR REPLACE TRIGGER trg_emp_delete
  AFTER DELETE ON employees
  FOR EACH ROW
BEGIN
  INSERT INTO control VALUES (USER, SYSDATE, 'Borró empleado: ' || :OLD.first_name);
END trg_emp_delete;
/
*/

-- EJERCICIO 4: Trigger con RAISE_APPLICATION_ERROR
/*
CREATE OR REPLACE TRIGGER trg_validar_salario
  BEFORE INSERT OR UPDATE OF salary ON employees
  FOR EACH ROW
BEGIN
  IF :NEW.salary < 0 THEN
    RAISE_APPLICATION_ERROR(-20001, 'El salario no puede ser negativo');
  END IF;
END trg_validar_salario;
/
*/

-- EJERCICIO 5: Trigger a nivel de sentencia (STATEMENT)
/*
CREATE OR REPLACE TRIGGER trg_emp_stmt
  AFTER INSERT OR UPDATE OR DELETE ON employees
BEGIN
  IF INSERTING THEN
    DBMS_OUTPUT.put_line('Se insertaron datos en employees');
  ELSIF UPDATING THEN
    DBMS_OUTPUT.put_line('Se actualizaron datos en employees');
  ELSIF DELETING THEN
    DBMS_OUTPUT.put_line('Se borraron datos de employees');
  END IF;
END trg_emp_stmt;
/
*/
