--1. De acuerdo con los procedimientos del negocio, no se permiten realizar modificaciones de los registros de empleados los fines de semana.
--   Realizar el disparador para hacer cumplir esta regla de negocio.


/*
create or replace trigger no_mod
before insert or update or delete  on empleados
for each row 
begin

 if to_char(sysdate, 'D') in ('1', '7')

 then 
    RAISE_APPLICATION_ERROR(-20001,'No se permiten modificaciones de empleados los fines de semana');
    end if;
end;


--2. Crear un disparador que no permita insertar registros en la tabla de empleados entre las 18 hs y las 22 hs.

create or replace trigger no_insert
before insert on empleados
for each row 
begin

 if to_char(sysdate, 'HH24') between '18' and '21'

 then 
    RAISE_APPLICATION_ERROR(-20001,'No se permiten inserciones de empleados entre las 18 y las 22 hs');
    end if;
end;




--3. Realizar un único disparador para hacer cumplir ambas reglas de negocio.

create or replace trigger no_mod_completo
before insert or update or delete  on empleados
for each row 
begin

 if to_char(sysdate, 'D') in ('1', '7') 
 then 
    RAISE_APPLICATION_ERROR(-20001,'No se permiten modificaciones de empleados los fines de semana');
    elsif to_char(sysdate, 'HH24') between '18' and '21'
    then
    RAISE_APPLICATION_ERROR(-20002,'No se permiten inserciones de empleados entre las 18 y las 22 hs');
    end if;
end;



--4. Realizar un disparador que registre el usuario y la fecha de cualquier actividad de cambio que se realice sobre la tabla de departamentos 
-- (actualizaciones, eliminaciones o inserciones de registros).
--   Registrar esto en la tabla de LOGS_DEPARTAMENTOS (tiene tres campos: ID, USUARIO, FECHA).



CREATE TABLE logs_departamentos (
    id NUMBER PRIMARY KEY,
    usuario VARCHAR2(30),
    fecha DATE
);

CREATE SEQUENCE logs_departamentos_seq
START WITH 1;


create or replace trigger log_departamentos
after insert or update or delete on DEPARTAMENTOS
for each row
begin

 insert into logs_departamentos (id, usuario, fecha) values (logs_departamentos_seq.nextval, user, sysdate);

end;
/



--5. La empresa debe controlar las actualizaciones de los precios de los productos almacenados en la tabla denominada
--   "PRODUCTOS" para ellos se debe registrar en la tabla "control" el nombre del usuario, la fecha, 
--    el precio anterior y el nuevo. Crear un disparador para dejar registradas las modificaciones.


CREATE TABLE control (
    id NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    usuario VARCHAR2(30),
    fecha DATE,
    precio_anterior NUMBER,
    precio_nuevo NUMBER
);

create or replace trigger reg_modificaciones_precio
after update of precio on productos    --solo se dispara si cambia el precio
for each row
WHEN (old.precio != new.precio)  
begin
insert into control (usuario,fecha, precio_anterior,precio_nuevo)
values(user, sysdate, :old.precio, :new.precio);

end;
/
-- CONCEPTOS CLAVE:
-- WHEN (afuera del BEGIN): condicion evaluada por Oracle ANTES de entrar al bloque PL/SQL.
--   Si no se cumple, el cuerpo del trigger no se ejecuta. Mas eficiente.
--   Sintaxis: WHEN (old.precio != new.precio)  --> SIN dos puntos
--
-- IF (adentro del BEGIN): siempre entra al bloque, controla el flujo con logica PL/SQL.
--   Sintaxis: IF :old.precio != :new.precio THEN  --> CON dos puntos (:old, :new)
--
-- Ambas formas son validas. WHEN es mas eficiente porque Oracle ni entra al bloque si no se cumple.

*/

--6. Una empresa almacena los datos de sus empleados en una tabla denominada "empleados".
--   En una tabla denominada "controlCambios" guarda los cambios que se realizan en la tabla "empleados",
--   en ella almacena el nombre del usuario que realiza la acción y la fecha en que la llevó a cabo.
--   Crear los siguientes disparadores:
    --    a. un disparador para el alta, 
    --    b. un disparador para las modificaciones 
    --    c. otro para registrar las bajas.
    --    d. Un disparador que permita registrar cualquiera de las actividades planteadas en los puntos anteriores.

--A)
        create table controlcambios( 
            usuario VARCHAR2 (50),
            fecha date

        );


        create or replace trigger alta
        after insert on empleados
        for each row
        begin
            insert into controlcambios (usuario,fecha) values(user,sysdate);

        end;
        /


--B)
        create or replace trigger modificaciones
        after update on empleados
        for each row
        begin
            insert into controlcambios (usuario,fecha) values(user,sysdate);

        end;
        /

--c)
        create or replace trigger bajas
        after delete on empleados
        for each row
        begin
            insert into controlcambios (usuario,fecha) values(user,sysdate);

        end;
        /

--d)
        create or replace trigger any_mod
        after insert or update or delete on empleados
        for each row
        begin
            insert into controlcambios (usuario,fecha) values(user,sysdate);

        end;
        /       