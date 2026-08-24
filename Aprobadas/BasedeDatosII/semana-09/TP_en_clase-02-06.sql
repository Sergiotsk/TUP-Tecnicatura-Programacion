--1. Crear un paquete de sobrecarga que contenga tres procedimientos llamados ‘que_soy’. El primer
-- procedimiento debe aceptar un VARCHAR2 como parámetro de entrada, el segundo un NÚMERO y el
-- tercero una FECHA. Cada procedimiento debe mostrar un mensaje simple para mostrar qué tipo de datos
-- se le pasó. Por ejemplo, el primer procedimiento podría ser "Aquí soy un Varchar2". Escribir el bloque
-- anónimo para poder probar el paquete. 


create or replace package que_soy_pkg
IS 
    PROCEDURE que_soy(p_texto IN VARCHAR2);
    PROCEDURE que_soy(p_num IN NUMBER);
    PROCEDURE que_soy(p_fecha IN DATE);
END que_soy_pkg;
/

CREATE OR REPLACE PACKAGE BODY que_soy_pkg AS
  PROCEDURE que_soy(p_texto IN VARCHAR2) IS
  BEGIN
    DBMS_OUTPUT.put_line('Aca soy un VARCHAR2: ' || p_texto);
  END;
  
  PROCEDURE que_soy(p_num IN NUMBER) IS
  BEGIN
    DBMS_OUTPUT.put_line('Aca soy un NUMBER: ' || p_num);
  END;
  
  PROCEDURE que_soy(p_fecha IN DATE) IS
  BEGIN
    DBMS_OUTPUT.put_line('aca soy una fecha : ' || TO_CHAR(p_fecha, 'DD/MM/YYYY'));
  END;
END que_soy_pkg;
/


begin
  que_soy_pkg.que_soy('Hola Mundo');
  que_soy_pkg.que_soy(12345);
  que_soy_pkg.que_soy(SYSDATE);
end;
/


--2. Modificar el paquete de sobrecarga creado en el punto 1 para que tenga un cuarto procedimiento, también
--   llamado ‘que_soy’, que acepte dos parámetros de entrada: uno de tipo NUMBER y el otro VARCHAR2. 



create or replace package que_soy_pkg
IS 
    PROCEDURE que_soy(p_texto IN VARCHAR2);
    PROCEDURE que_soy(p_num IN NUMBER);
    PROCEDURE que_soy(p_fecha IN DATE);
    PROCEDURE que_soy(p_num IN NUMBER, p_texto IN VARCHAR2);
END que_soy_pkg;

CREATE OR REPLACE PACKAGE BODY que_soy_pkg AS
  PROCEDURE que_soy(p_texto IN VARCHAR2) IS
  BEGIN
    DBMS_OUTPUT.put_line('Aca soy un VARCHAR2: ' || p_texto);
  END;
  
  PROCEDURE que_soy(p_num IN NUMBER) IS
  BEGIN
    DBMS_OUTPUT.put_line('Aca soy un NUMBER: ' || p_num);
  END;
  
  PROCEDURE que_soy(p_fecha IN DATE) IS
  BEGIN
    DBMS_OUTPUT.put_line('aca soy una fecha : ' || TO_CHAR(p_fecha, 'DD/MM/YYYY'));
  END;

  PROCEDURE que_soy(p_num IN NUMBER, p_texto IN VARCHAR2) IS
  BEGIN
    DBMS_OUTPUT.put_line('Aca soy un NUMBER: ' || p_num || ' y un VARCHAR2: ' || p_texto);
  END;
END que_soy_pkg;












