-- =============================================
-- Ejercicios Semana 16: BD Móviles y Repaso Final
-- Fuente: Material de la cátedra + SQLite docs
-- =============================================

-- Parte BD Móviles: SQLite y Room (Android)

-- Ejemplo de creación de tabla en SQLite
/*
CREATE TABLE empleados_movil (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  nombre TEXT NOT NULL,
  salario REAL,
  fecha_ingreso TEXT DEFAULT CURRENT_TIMESTAMP
);
*/

-- Ejemplo de consulta en SQLite
/*
SELECT * FROM empleados_movil WHERE salario > 5000;
*/

-- Diferencias SQLite vs Oracle:
-- 1. SQLite es serverless (archivo local)
-- 2. Oracle es cliente-servidor (más robusto)
-- 3. SQLite soporta tipos dinámicos
-- 4. Oracle tiene PL/SQL (procedimientos almacenados)

-- Parte Repaso Final: Ejercicios combinados

-- EJERCICIO 1: Bloque anónimo completo con manejo de excepciones
/*
DECLARE
  l_emp employees%ROWTYPE;
  l_nuevo_salario NUMBER;
BEGIN
  -- Obtener empleado
  SELECT * INTO l_emp FROM employees WHERE employee_id = 100;
  
  -- Incrementar salario
  l_nuevo_salario := l_emp.salary * 1.10;
  
  -- Actualizar
  UPDATE employees SET salary = l_nuevo_salario WHERE employee_id = 100;
  
  -- Log
  DBMS_OUTPUT.put_line('Salario actualizado de ' || l_emp.salary || ' a ' || l_nuevo_salario);
  COMMIT;
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.put_line('Empleado no encontrado');
    ROLLBACK;
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line('Error: ' || SQLERRM);
    ROLLBACK;
END;
/
*/

-- EJERCICIO 2: Procedimiento con cursor y exception
/*
CREATE OR REPLACE PROCEDURE aumentar_salario_dept(
  p_dept_id IN NUMBER,
  p_porcentaje IN NUMBER
) AS
  CURSOR c_emps IS
    SELECT employee_id, salary FROM employees WHERE department_id = p_dept_id;
  l_emp c_emps%ROWTYPE;
BEGIN
  OPEN c_emps;
  LOOP
    FETCH c_emps INTO l_emp;
    EXIT WHEN c_emps%NOTFOUND;
    
    UPDATE employees
    SET salary = salary * (1 + p_porcentaje/100)
    WHERE employee_id = l_emp.employee_id;
  END LOOP;
  CLOSE c_emps;
  COMMIT;
EXCEPTION
  WHEN OTHERS THEN
    IF c_emps%ISOPEN THEN
      CLOSE c_emps;
    END IF;
    RAISE_APPLICATION_ERROR(-20005, 'Error: ' || SQLERRM);
END aumentar_salario_dept;
/
*/

-- EJERCICIO 3: Trigger con validación compleja
/*
CREATE OR REPLACE TRIGGER trg_validar_emp
  BEFORE INSERT OR UPDATE ON employees
  FOR EACH ROW
DECLARE
  l_count NUMBER;
BEGIN
  -- Validar que el salario no sea negativo
  IF :NEW.salary < 0 THEN
    RAISE_APPLICATION_ERROR(-20006, 'Salario no puede ser negativo');
  END IF;
  
  -- Validar email único
  SELECT COUNT(*) INTO l_count
  FROM employees
  WHERE email = :NEW.email AND employee_id != NVL(:NEW.employee_id, -1);
  
  IF l_count > 0 THEN
    RAISE_APPLICATION_ERROR(-20007, 'Email ya existe');
  END IF;
END trg_validar_emp;
/
*/

-- EJERCICIO 4: Paquete completo (especificación + cuerpo)
/*
CREATE OR REPLACE PACKAGE rrhh_pkg AS
  PROCEDURE contratar_emp(
    p_nombre IN VARCHAR2,
    p_apellido IN VARCHAR2,
    p_salario IN NUMBER,
    p_dept_id IN NUMBER
  );
  FUNCTION calcular_bonus(p_emp_id IN NUMBER) RETURN NUMBER;
END rrhh_pkg;
/

CREATE OR REPLACE PACKAGE BODY rrhh_pkg AS
  PROCEDURE contratar_emp(
    p_nombre IN VARCHAR2,
    p_apellido IN VARCHAR2,
    p_salario IN NUMBER,
    p_dept_id IN NUMBER
  ) AS
    v_new_id NUMBER;
  BEGIN
    SELECT NVL(MAX(employee_id), 0) + 1 INTO v_new_id FROM employees;
    INSERT INTO employees (employee_id, first_name, last_name, salary, department_id, email, hire_date)
    VALUES (v_new_id, p_nombre, p_apellido, p_salario, p_dept_id, 
            SUBSTR(p_nombre,1,1) || SUBSTR(p_apellido,1,7), SYSDATE);
  END;

  FUNCTION calcular_bonus(p_emp_id IN NUMBER) RETURN NUMBER IS
    v_salario NUMBER;
  BEGIN
    SELECT salary * 0.15 INTO v_salario FROM employees WHERE employee_id = p_emp_id;
    RETURN v_salario;
  END;
END rrhh_pkg;
/
*/

-- REPASO GENERAL: Recordar todos los conceptos
-- 1. Bloques anónimos, variables, %TYPE, %ROWTYPE
-- 2. Procedimientos, funciones, parámetros IN/OUT/IN OUT
-- 3. Cursores implícitos (SELECT INTO) y explícitos (OPEN/FETCH/CLOSE)
-- 4. Cursores con FOR, SYS_REFCURSOR
-- 5. Triggers DML (BEFORE/AFTER, FOR EACH ROW, :NEW/:OLD)
-- 6. Excepciones predefinidas, definidas por usuario, RAISE_APPLICATION_ERROR
-- 7. Paquetes (especificación, cuerpo, variables de paquete, sobrecarga)
-- 8. Colecciones (VARRAY, tablas anidadas, matrices asociativas)
-- 9. BULK COLLECT y FORALL para procesamiento masivo
-- 10. Administración: usuarios, roles, perfiles, privilegios
-- 11. Índices, vistas, optimización básica
-- 12. Normalización hasta 5FN, introducción a NoSQL
