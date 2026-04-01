-- EJERCICIO: [nombre del ejercicio]
-- MATERIA: BasedeDatosII
-- FECHA: [fecha]
--
-- NOTAS DEL EJERCICIO:
-- ¿Qué aprendí?
-- - 
--
-- Errores comunes:
-- - 
--
-- Conceptos clave:
-- - 

SET SERVEROUTPUT ON;

DECLARE
    -- Declaraciones de variables
BEGIN
    -- Lógica del ejercicio
    NULL;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Error: No se encontraron datos');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/
