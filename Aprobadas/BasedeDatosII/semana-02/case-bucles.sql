-- =============================================
-- Ejercicios Semana 02: CASE y Bucles (FOR, WHILE, LOOP)
-- Fuente: Apunte Parte 1 — "CASE" y "Procesamiento Iterativo con Bucles"
--         Apunte Parte 2 — "Conversión de Datos"
-- Ejercicios 6 al 10 de Bloques Anónimos + 1 al 5 de Bloques Almacenados
-- =============================================

-- EJERCICIOS DE CASE

-- EJERCICIO 6: CASE simple

DECLARE
  l_dia NUMBER := 5;
  l_nombre_dia VARCHAR2(20);
BEGIN
  CASE l_dia
    WHEN 1 THEN l_nombre_dia := 'Lunes';
    WHEN 2 THEN l_nombre_dia := 'Martes';
    WHEN 3 THEN l_nombre_dia := 'Miércoles';
    ELSE l_nombre_dia := 'Otro día';
  END CASE;
  DBMS_OUTPUT.put_line('El día es: ' || l_nombre_dia);
END;
/


-- EJERCICIO 7: CASE de búsqueda

DECLARE
  l_salario NUMBER :=3003;
BEGIN
  CASE
    WHEN l_salario >= 10000 THEN DBMS_OUTPUT.put_line('Gerente');
    WHEN l_salario >= 6000 THEN DBMS_OUTPUT.put_line('Senior');
    WHEN l_salario >= 3000 THEN DBMS_OUTPUT.put_line('Junior');
    ELSE DBMS_OUTPUT.put_line('Practicante');
  END CASE;
END;
/


-- EJERCICIOS DE BUCLES

-- EJERCICIO 8: Bucle FOR numérico

BEGIN
  FOR i IN 1..5 LOOP
    DBMS_OUTPUT.put_line('Iteración: ' || i);
  END LOOP;
END;
/


-- EJERCICIO 9: Bucle WHILE
/*
DECLARE
  l_contador NUMBER := 1;
BEGIN
  WHILE l_contador <= 5 LOOP
    DBMS_OUTPUT.put_line('Contador: ' || l_contador);
    l_contador := l_contador + 1;
  END LOOP;
END;
/
*/

-- EJERCICIO 10: Bucle LOOP con EXIT WHEN
/*
DECLARE
  l_contador NUMBER := 1;
BEGIN
  LOOP
    DBMS_OUTPUT.put_line('Loop: ' || l_contador);
    l_contador := l_contador + 1;
    EXIT WHEN l_contador > 5;
  END LOOP;
END;
/
*/
