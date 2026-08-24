-- =============================================
-- Ejercicios Semana 09: Paquetes PL/SQL
-- Fuente: Apunte Parte 6 — "Los Paquetes", "Especificación", "Cuerpo", "Sobrecarga"
-- Ejercicios 1 y 2 de "Ejercicios de Paquetes" + empleado_pkg y timer_pkg
-- =============================================

-- EJERCICIO 1: Crear especificación del paquete empleado_pkg
/*
CREATE OR REPLACE PACKAGE empleado_pkg AS
  -- Especificación (interfaz pública)
  PROCEDURE obtener_salario(p_emp_id IN NUMBER, p_salario OUT NUMBER);
  FUNCTION calcular_bonus(p_emp_id IN NUMBER) RETURN NUMBER;
  PROCEDURE listar_departamento(p_dept_id IN NUMBER);
END empleado_pkg;
/
*/

-- EJERCICIO 2: Crear cuerpo del paquete empleado_pkg
/*
CREATE OR REPLACE PACKAGE BODY empleado_pkg AS
  
  PROCEDURE obtener_salario(p_emp_id IN NUMBER, p_salario OUT NUMBER) IS
  BEGIN
    SELECT salary INTO p_salario FROM employees WHERE employee_id = p_emp_id;
  EXCEPTION
    WHEN NO_DATA_FOUND THEN
      p_salario := NULL;
  END obtener_salario;

  FUNCTION calcular_bonus(p_emp_id IN NUMBER) RETURN NUMBER IS
    v_salario NUMBER;
  BEGIN
    SELECT salary * 0.10 INTO v_salario FROM employees WHERE employee_id = p_emp_id;
    RETURN v_salario;
  END calcular_bonus;

  PROCEDURE listar_departamento(p_dept_id IN NUMBER) IS
  BEGIN
    FOR r IN (SELECT first_name FROM employees WHERE department_id = p_dept_id) LOOP
      DBMS_OUTPUT.put_line(r.first_name);
    END LOOP;
  END listar_departamento;

END empleado_pkg;
/
-- Ejecutar: EXEC empleado_pkg.listar_departamento(50);
*/

-- EJERCICIO 3: Paquete timer_pkg (del apunte)
/*
CREATE OR REPLACE PACKAGE timer_pkg AS
  PROCEDURE start_timer;
  PROCEDURE stop_timer;
  FUNCTION elapsed_time RETURN NUMBER;
END timer_pkg;
/

CREATE OR REPLACE PACKAGE BODY timer_pkg AS
  g_start_time NUMBER;
  
  PROCEDURE start_timer IS
  BEGIN
    g_start_time := DBMS_UTILITY.get_time;
  END start_timer;

  PROCEDURE stop_timer IS
  BEGIN
    DBMS_OUTPUT.put_line('Tiempo: ' || (DBMS_UTILITY.get_time - g_start_time) || ' centésimas');
  END stop_timer;

  FUNCTION elapsed_time RETURN NUMBER IS
  BEGIN
    RETURN DBMS_UTILITY.get_time - g_start_time;
  END elapsed_time;
END timer_pkg;
/
-- Uso: EXEC timer_pkg.start_timer; ... código ... EXEC timer_pkg.stop_timer;
*/

-- EJERCICIO 4: Sobrecarga de subprogramas en paquete
/*
CREATE OR REPLACE PACKAGE sobrecarga_pkg AS
  FUNCTION calcular(p_num NUMBER) RETURN NUMBER;
  FUNCTION calcular(p_texto VARCHAR2) RETURN NUMBER;
END sobrecarga_pkg;
/

CREATE OR REPLACE PACKAGE BODY sobrecarga_pkg AS
  FUNCTION calcular(p_num NUMBER) RETURN NUMBER IS
  BEGIN
    RETURN p_num * 2;
  END;
  
  FUNCTION calcular(p_texto VARCHAR2) RETURN NUMBER IS
  BEGIN
    RETURN LENGTH(p_texto);
  END;
END sobrecarga_pkg;
/
*/

-- EJERCICIO 5: Variables a nivel de paquete (persisten en sesión)
/*
CREATE OR REPLACE PACKAGE estado_pkg AS
  g_contador NUMBER := 0;
  PROCEDURE incrementar;
  FUNCTION obtener_contador RETURN NUMBER;
END estado_pkg;
/

CREATE OR REPLACE PACKAGE BODY estado_pkg AS
  PROCEDURE incrementar IS
  BEGIN
    g_contador := g_contador + 1;
  END;
  
  FUNCTION obtener_contador RETURN NUMBER IS
  BEGIN
    RETURN g_contador;
  END;
END estado_pkg;
/
*/
