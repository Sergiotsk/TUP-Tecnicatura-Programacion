/*
Crear un **paquete** para que el personal del penal pueda llevar a cabo las tareas diarias.
 Debe permitir:

### 1. Función — Clasificar reincidencia criminal

Determinar si un criminal que aún está en la cárcel ha tenido más de 3 entradas a la cárcel en los últimos 180 días, devolviendo:

| Cantidad de ingresos | Mensaje |
|-----------------------|---------|
| Más de 3             | `'GRAN REINCIDENTE'` |
| 2 veces              | `'REINCIDENTE'` |
| 1 vez                | `'PRIMERA VEZ'` |

Dar un mensaje coherente en cualquier caso de error o situación no contemplada.*/

create or replace PACKAGE PKG_TAREAS_DIARIAS AS
FUNCTION reincidencias (p_criminal_id IN CRIMINALES.ID%TYPE) RETURN VARCHAR2;
PROCEDURE  sospechosos_x_detective (p_detective_id IN DETECTIVES.ID%TYPE);
PROCEDURE  sospechosos_x_detective (p_detective_apellido IN DETECTIVES.APELLIDO%TYPE,
                                        p_detective_nombre IN DETECTIVES.NOMBRE%TYPE);
PROCEDURE  sospechosos_x_detective (p_detective_apellido IN DETECTIVES.APELLIDO%TYPE,
                                       p_fecha_alta IN DETECTIVES.FECHA_ALTA%TYPE);
END PKG_TAREAS_DIARIAS;
/


create or replace PACKAGE BODY PKG_TAREAS_DIARIAS AS

    CURSOR C_SOSPECHOSOS (p_detective_id DETECTIVES.ID%TYPE)IS
            SELECT C.NOMBRE CRIMINAL ,CR.FECHA_CRIMEN FECHA, CR.D_APELLIDO || ','|| CR.D_NOMBRE DAMNIFICADO
            FROM CRIMINALES C
            JOIN SOSPECHOSOS_CRIMEN SC  ON C.ID  = SC.SOSPECHOSO
            JOIN CRIMENES CR ON SC.CRIMEN= CR.ID
            WHERE CR.DETECTIVE = p_detective_id;

BD BOOLEAN; --BANDERA DETECTIVE
BC BOOLEAN; --BANDERA CRIMINAL
BCC BOOLEAN; --BANDERA CRIMINAL EN LA CARCEL
FUNCTION reincidencias (p_criminal_id IN CRIMINALES.ID%TYPE)RETURN VARCHAR2 
IS
    CURSOR CRIMINAL IS SELECT * FROM CRIMINALES WHERE p_criminal_id =ID;
    CURSOR CRIMINAL_CARCEL IS SELECT * FROM CRIMINALES_PRISION
                WHERE CRIMINAL=p_criminal_id AND FECHA_EGRESO IS NULL;
v_cantidad NUMBER:=0;                 
BEGIN
    BC:=FALSE;
    BCC:=FALSE;
    FOR reg IN CRIMINAL LOOP
        BC:=TRUE;
    END LOOP;

     FOR reg IN CRIMINAL_CARCEL LOOP
        BCC:=TRUE;
    END LOOP;

    IF BC AND BCC THEN
    SELECT COUNT(*) INTO v_cantidad
    FROM CRIMINALES_PRISION
    WHERE CRIMINAL=p_criminal_id AND SYSDATE-FECHA_INGRESO > 180;
    CASE v_cantidad
        WHEN 0 THEN RETURN 'SE DEBE ESTUDIAR EL ESTADO DEL REGISTRO';
        WHEN 1 THEN RETURN 'PRIMERA VEZ';
        WHEN 2 THEN RETURN 'REINCIDENTE';
        ELSE RETURN 'GRAN REINCIDENTE';
        END CASE;
    ELSIF BCC=FALSE AND BC THEN
    RETURN 'EL CRIMINAL O ESTA EN LA CARCEL';
        ELSE
        RETURN 'LA IDENTIFICACION NO CORRESPONDE A UN CRIMINAL REGISTRADO';
    END IF;
EXCEPTION
    WHEN OTHERS THEN 
    RETURN NULL;

END reincidencias;



PROCEDURE  sospechosos_x_detective (p_detective_id IN DETECTIVES.ID%TYPE)
IS
    CURSOR DETECTIVE_DATOS IS SELECT * FROM DETECTIVES WHERE ID = p_detective_id;

BEGIN
    BD := FALSE;
    BC := FALSE;

    FOR reg_d IN DETECTIVE_DATOS LOOP
        BD := TRUE;

        DBMS_OUTPUT.PUT_LINE('DETECTIVE: ' || reg_d.APELLIDO || ', ' || reg_d.NOMBRE);
        DBMS_OUTPUT.PUT_LINE(RPAD('=', 72, '='));
        DBMS_OUTPUT.PUT_LINE(
            RPAD('CRIMINAL',    30) ||
            RPAD('FECHA CRIMEN', 15) ||
            RPAD('DAMNIFICADO', 27)
        );
        DBMS_OUTPUT.PUT_LINE(
            RPAD('-', 29, '-') || ' ' ||
            RPAD('-', 14, '-') || ' ' ||
            RPAD('-', 26, '-')
        );

        FOR reg_c IN C_SOSPECHOSOS(reg_d.ID) LOOP
            BC := TRUE;
            DBMS_OUTPUT.PUT_LINE(
                RPAD(reg_c.CRIMINAL,                         30) ||
                RPAD(TO_CHAR(reg_c.FECHA, 'DD/MM/YYYY'),    15) ||
                RPAD(reg_c.DAMNIFICADO,                      27)
            );
        END LOOP;

        IF NOT BC THEN
            DBMS_OUTPUT.PUT_LINE('SIN SOSPECHOSOS REGISTRADOS');
        END IF;
    END LOOP;

    IF NOT BD THEN
        DBMS_OUTPUT.PUT_LINE('NO EXISTE EL DETECTIVE INDICADO');
    ELSIF NOT BC THEN
        DBMS_OUTPUT.PUT_LINE('EL DETECTIVE NO ESTA A CARGO DE NINGUN CASO');    
    END IF;
    

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('ERROR: ' || SQLERRM);
END sospechosos_x_detective ;


PROCEDURE  sospechosos_x_detective (p_detective_apellido IN DETECTIVES.APELLIDO%TYPE,
 p_detective_nombre IN DETECTIVES.NOMBRE%TYPE)
 IS
    CURSOR DETECTIVE_DATOS IS SELECT * FROM DETECTIVES WHERE APELLIDO=p_detective_apellido AND
    NOMBRE = p_detective_nombre;
BEGIN
    BD := FALSE;
    BC := FALSE;

    FOR reg_d IN DETECTIVE_DATOS LOOP
        BD := TRUE;

        DBMS_OUTPUT.PUT_LINE('DETECTIVE: ' || reg_d.APELLIDO || ', ' || reg_d.NOMBRE);
        DBMS_OUTPUT.PUT_LINE(RPAD('=', 72, '='));
        DBMS_OUTPUT.PUT_LINE(
            RPAD('CRIMINAL',     30) ||
            RPAD('FECHA CRIMEN', 15) ||
            RPAD('DAMNIFICADO',  27)
        );
        DBMS_OUTPUT.PUT_LINE(
            RPAD('-', 29, '-') || ' ' ||
            RPAD('-', 14, '-') || ' ' ||
            RPAD('-', 26, '-')
        );

        FOR reg_c IN C_SOSPECHOSOS(reg_d.ID) LOOP
            BC := TRUE;
            DBMS_OUTPUT.PUT_LINE(
                RPAD(reg_c.CRIMINAL,                      30) ||
                RPAD(TO_CHAR(reg_c.FECHA, 'DD/MM/YYYY'), 15) ||
                RPAD(reg_c.DAMNIFICADO,                   27)
            );
        END LOOP;

        IF NOT BC THEN
            DBMS_OUTPUT.PUT_LINE('SIN SOSPECHOSOS REGISTRADOS');
        END IF;
    END LOOP;

    IF NOT BD THEN
        DBMS_OUTPUT.PUT_LINE('NO EXISTE EL DETECTIVE INDICADO');
    ELSIF NOT BC THEN
        DBMS_OUTPUT.PUT_LINE('EL DETECTIVE NO ESTA A CARGO DE NINGUN CASO');
    END IF;

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('ERROR: ' || SQLERRM);
END sospechosos_x_detective ;

PROCEDURE  sospechosos_x_detective (p_detective_apellido IN DETECTIVES.APELLIDO%TYPE,
p_fecha_alta IN DETECTIVES.FECHA_ALTA%TYPE)
IS
    CURSOR DETECTIVE_DATOS IS SELECT * FROM DETECTIVES WHERE APELLIDO= p_detective_apellido AND
    FECHA_ALTA=p_fecha_alta;

BEGIN
    BD := FALSE;
    BC := FALSE;

    FOR reg_d IN DETECTIVE_DATOS LOOP
        BD := TRUE;

        DBMS_OUTPUT.PUT_LINE('DETECTIVE: ' || reg_d.APELLIDO || ', ' || reg_d.NOMBRE);
        DBMS_OUTPUT.PUT_LINE(RPAD('=', 72, '='));
        DBMS_OUTPUT.PUT_LINE(
            RPAD('CRIMINAL',     30) ||
            RPAD('FECHA CRIMEN', 15) ||
            RPAD('DAMNIFICADO',  27)
        );
        DBMS_OUTPUT.PUT_LINE(
            RPAD('-', 29, '-') || ' ' ||
            RPAD('-', 14, '-') || ' ' ||
            RPAD('-', 26, '-')
        );

        FOR reg_c IN C_SOSPECHOSOS(reg_d.ID) LOOP
            BC := TRUE;
            DBMS_OUTPUT.PUT_LINE(
                RPAD(reg_c.CRIMINAL,                      30) ||
                RPAD(TO_CHAR(reg_c.FECHA, 'DD/MM/YYYY'), 15) ||
                RPAD(reg_c.DAMNIFICADO,                   27)
            );
        END LOOP;

        IF NOT BC THEN
            DBMS_OUTPUT.PUT_LINE('SIN SOSPECHOSOS REGISTRADOS');
        END IF;
    END LOOP;

    IF NOT BD THEN
        DBMS_OUTPUT.PUT_LINE('NO EXISTE EL DETECTIVE INDICADO');
    ELSIF NOT BC THEN
        DBMS_OUTPUT.PUT_LINE('EL DETECTIVE NO ESTA A CARGO DE NINGUN CASO');
    END IF;

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('ERROR: ' || SQLERRM);
END sospechosos_x_detective ;
END PKG_TAREAS_DIARIAS;
/







--3. Trigger — Control de aumento de sueldos y AUDITORIA

--procedimiento para insertar en AUDITORIA
CREATE OR REPLACE PROCEDURE REG_AUDITORIA_ALTA (p_motivo IN VARCHAR2,p_tabla IN VARCHAR2)
IS
    PRAGMA AUTONOMOUS_TRANSACTION;
BEGIN
    INSERT INTO AUDITORIA(ID_AUDITORIA,USUARIO,FECHA,MOTIVO,TABLA)
            VALUES(ISEQ$$_178846.nextval,USER,SYSDATE,p_motivo,p_tabla);
    COMMIT;
END;
/                
/
SET SERVEROUTPUT ON;
/
--trigger CONTROL DE AUMENTO DE SUELDO

CREATE OR REPLACE TRIGGER TRG_CONTROL_SUELDO
BEFORE UPDATE OF SUELDO ON CATEGORIAS_PENITENCIARIOS FOR EACH ROW
DECLARE
    v_sueldo_actual CATEGORIAS_PENITENCIARIOS.SUELDO%TYPE := :OLD.SUELDO;
    v_sueldo_nuevo CATEGORIAS_PENITENCIARIOS.SUELDO%TYPE := :NEW.SUELDO;
BEGIN
IF v_sueldo_nuevo > v_sueldo_actual * 1.15 THEN
        :NEW.SUELDO := v_sueldo_actual;
        REG_AUDITORIA_ALTA('AUMENTO NO AUTORIZADO','CATEGORIAS_PENITENCIARIOS');
    ELSE
         REG_AUDITORIA_ALTA('SUELDO AUTORIZADO','CATEGORIAS_PENITENCIARIOS');
END IF;

EXCEPTION
        WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('ERROR EN EL SISTEMA');
END TRG_CONTROL_SUELDO;
/

--BLOQUE DE PRUEBA TRIGGER
BEGIN
    UPDATE CATEGORIAS_PENITENCIARIOS SET SUELDO = SUELDO * 1.10;
    COMMIT;
END;
/

--BLOQUES DE PRUEBA SOBRECARGAS sospechosos_x_detective

-- Sobrecarga 1: por ID
BEGIN
    PKG_TAREAS_DIARIAS.sospechosos_x_detective(174); --205
END;
/

-- Sobrecarga 2: por apellido y nombre
BEGIN
    PKG_TAREAS_DIARIAS.sospechosos_x_detective('GOMEZ','JUAN');
END;
/

-- Sobrecarga 3: por apellido y fecha de alta
BEGIN
    PKG_TAREAS_DIARIAS.sospechosos_x_detective('GOMEZ', TO_DATE('01/01/2020','DD/MM/YYYY'));
END;
/


