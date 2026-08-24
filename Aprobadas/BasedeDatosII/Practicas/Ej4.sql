--1. De acuerdo con los procedimientos del negocio, no se permiten realizar modificaciones de los registros de empleados los fines de semana. 
--Realizar el disparador para hacer cumplir esta regla de negocio.

create or replace trigger no_mod
before insert or update or delete  on empleados
for each row 
begin

 if to_char(sysdate, 'DY','NLS_DATE_LANGUAGE=SPANISH') in ('SAB', 'DOM')

 then 
    DBMS_OUTPUT.PUT_LINE('No se permiten modificaciones de empleados los fines de semana');
    RAISE_APPLICATION_ERROR(-20001,'Operacion eliminada');
    end if;
end;
/    
