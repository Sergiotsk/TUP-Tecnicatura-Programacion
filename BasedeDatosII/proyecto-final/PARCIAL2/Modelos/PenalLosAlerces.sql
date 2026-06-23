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



PROCEDURE  sospechosos_x_detective (p_detective_id IN DETECTIVES.ID%TYPE)IS
BEGIN
 NULL;

END sospechosos_x_detective ;


PROCEDURE  sospechosos_x_detective (p_detective_apellido IN DETECTIVES.APELLIDO%TYPE,
 p_detective_nombre IN DETECTIVES.NOMBRE%TYPE)IS
BEGIN
 NULL;

END sospechosos_x_detective ;

PROCEDURE  sospechosos_x_detective (p_detective_apellido IN DETECTIVES.APELLIDO%TYPE,
p_fecha_alta IN DETECTIVES.FECHA_ALTA%TYPE)IS
BEGIN
 NULL;

END sospechosos_x_detective ;
END PKG_TAREAS_DIARIAS;
/







--3. Trigger — Control de aumento de sueldos

CREATE OR REPLACE PROCEDURE REG_AUDITORIA_ALTA (p_motivo IN VARCHAR2,p_tabla IN VARCHAR2)
IS
    PRAGMA AUTONOMUS_TRANSACTION;
BEGIN
    INSERT INTO AUDITORIA(ID_AUDITORIA,USUARIO,FECHA,MOTIVO,TABLA)
            VALUES(ISEQ$$_178846.nextval,USER,SYSDATE,p_motivo,p_tabla);
    COMMIT;
END;
/                