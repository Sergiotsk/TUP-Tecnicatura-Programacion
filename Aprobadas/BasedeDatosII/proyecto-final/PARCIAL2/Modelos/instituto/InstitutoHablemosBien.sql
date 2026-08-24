
/* 1. PROCEDIMIENTO AUXILIAR — RESTRICCION POR DIA DE SEMANA */

-- Procedimiento reutilizable: lanza error si se ejecuta sabado (1) o domingo (7)
CREATE OR REPLACE PROCEDURE VALIDAR_DIA_SEMANA AS
BEGIN
    IF TO_CHAR(SYSDATE, 'D') IN ('1', '7') THEN
        RAISE_APPLICATION_ERROR(-20001, 'No se permiten modificaciones de empleados los fines de semana');
    END IF;
END VALIDAR_DIA_SEMANA;
/

-- Trigger: bloquea INSERT en CURSOS los fines de semana
CREATE OR REPLACE TRIGGER TRG_CURSO
BEFORE INSERT ON CURSOS
BEGIN
    VALIDAR_DIA_SEMANA;
END TRG_CURSO;
/

-- Trigger: bloquea INSERT en ESTUDIANTES los fines de semana
CREATE OR REPLACE TRIGGER TRG_ALUMNOS
BEFORE INSERT ON ESTUDIANTES
BEGIN
    VALIDAR_DIA_SEMANA;
END TRG_ALUMNOS;
/

-- Trigger: bloquea INSERT en PROFESORES los fines de semana
CREATE OR REPLACE TRIGGER TRG_DOCENTES
BEFORE INSERT ON PROFESORES
BEGIN
    VALIDAR_DIA_SEMANA;
END TRG_DOCENTES;
/

/* BLOQUE DE PRUEBA - RESTRICCION DIA DE SEMANA */

BEGIN
    INSERT INTO CURSOS(CURSO_ID, NOMBRE, CARRERA) VALUES (102, 'FILOSOFIA', 1);
END;
/

/*==========================================================================*/

/* 2. PROCEDIMIENTO Y TRIGGER — VALIDACION DE EMAIL */

-- Valida formato de email con expresion regular:
-- usuario: primera letra [a-z], luego letras/numeros/punto, no termina en punto
-- dominio:  solo letras/numeros/guion, guion no al inicio ni al final
CREATE OR REPLACE PROCEDURE VALIDAR_MAIL(p_email IN VARCHAR2) IS
    mail BOOLEAN;
BEGIN
    IF p_email IS NOT NULL THEN
        mail := REGEXP_LIKE(p_email, '^[a-z][a-z0-9\.]*[a-z0-9][@][a-z0-9]*[a-z0-9-\.]*[a-z0-9]$');

        IF mail THEN
            DBMS_OUTPUT.PUT_LINE('Mail ingresado correctamente');
        ELSE
            RAISE_APPLICATION_ERROR(-20001, 'Formato de email NO permitido');
        END IF;
    ELSE
        DBMS_OUTPUT.PUT_LINE('No se detecto ingreso');
    END IF;
END VALIDAR_MAIL;
/

-- Trigger: invoca VALIDAR_MAIL antes de insertar o actualizar el email de un estudiante
CREATE OR REPLACE TRIGGER TRG_VALIDAR_MAIL
BEFORE INSERT OR UPDATE OF EMAIL ON ESTUDIANTES
FOR EACH ROW
BEGIN
    VALIDAR_MAIL(:NEW.EMAIL);
END TRG_VALIDAR_MAIL;
/

/* BLOQUE DE PRUEBA - VALIDACION DE EMAIL */

-- Prueba con email invalido (sin @): debe lanzar error -20001
BEGIN
    INSERT INTO ESTUDIANTES(NOMBRE, APELLIDO, FECHA_NACIMIENTO, EMAIL, CARRERA)
    VALUES ('SERTO', 'Tschehek', TO_DATE('01-07-1986'), 'serjito86gmail.com', 5);
END;
/

/*==========================================================================*/

/* 3. ESPECIFICACION DEL PAQUETE */

CREATE OR REPLACE PACKAGE PKG_ADMINISTRAR_TAREAS AS

    PROCEDURE ALTA_NOTA           (p_profesor_id IN NUMBER,  p_legajo     IN NUMBER,
                                   p_materia_id  IN NUMBER,  p_nota       IN NUMBER);

    FUNCTION  OBTENER_EDAD        (p_legajo      IN NUMBER)  RETURN NUMBER;

    FUNCTION  CANTIDAD_MATERIAS   (p_legajo      IN NUMBER)  RETURN NUMBER;

    PROCEDURE VISUALIZAR_ESTUDIANTES (p_docente_id IN VARCHAR2, p_materia_id IN NUMBER);

END PKG_ADMINISTRAR_TAREAS;
/

/*==========================================================================*/

/* 4. CUERPO DEL PAQUETE */

CREATE OR REPLACE PACKAGE BODY PKG_ADMINISTRAR_TAREAS AS

    -- a) Alta de nota: valida que el docente dicte la materia y que el alumno la curse
    PROCEDURE ALTA_NOTA(p_profesor_id IN NUMBER, p_legajo IN NUMBER,
                        p_materia_id  IN NUMBER, p_nota   IN NUMBER) IS
        v_count NUMBER;
    BEGIN
        -- Validar que la materia este activa y dictada por el docente
        SELECT COUNT(*) INTO v_count
        FROM   MATERIAS
        WHERE  MATERIA_ID = p_materia_id
          AND  PROFESOR   = p_profesor_id
          AND  ESTADO     = 'activo';

        IF v_count = 0 THEN
            RAISE_APPLICATION_ERROR(-20001, 'La materia no existe o no esta siendo dictada actualmente');
        END IF;

        -- Validar que el alumno este matriculado en esa materia
        SELECT COUNT(*) INTO v_count
        FROM   MATRICULAS
        WHERE  ESTUDIANTE = p_legajo
          AND  MATERIA    = p_materia_id;

        IF v_count = 0 THEN
            RAISE_APPLICATION_ERROR(-20002, 'El alumno NO esta matriculado en la materia seleccionada');
        END IF;

        -- Registrar la nota del alumno
        INSERT INTO NOTAS(ESTUDIANTE, MATERIA, VALOR)
        VALUES (p_legajo, p_materia_id, p_nota);

    END ALTA_NOTA;

/*==========================================================================*/

    -- b) Devuelve la edad del alumno en años completos a partir de su legajo
    FUNCTION OBTENER_EDAD(p_legajo IN NUMBER) RETURN NUMBER IS
        v_edad             NUMBER;
        v_fecha_nacimiento DATE;
    BEGIN
        SELECT FECHA_NACIMIENTO INTO v_fecha_nacimiento
        FROM   ESTUDIANTES
        WHERE  ESTUDIANTE_ID = p_legajo;

        v_edad := TRUNC(MONTHS_BETWEEN(SYSDATE, v_fecha_nacimiento) / 12);
        RETURN v_edad;

    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RAISE_APPLICATION_ERROR(-20003, 'ERROR, no se encontro dato asociado');
    END OBTENER_EDAD;

/*==========================================================================*/

    -- c) Devuelve la cantidad de materias que cursa un alumno; 0 si no cursa ninguna
    FUNCTION CANTIDAD_MATERIAS(p_legajo IN NUMBER) RETURN NUMBER IS
        v_count NUMBER;
    BEGIN
        SELECT COUNT(MATERIA) INTO v_count
        FROM   MATRICULAS
        WHERE  ESTUDIANTE = p_legajo;

        RETURN v_count;
    END CANTIDAD_MATERIAS;

/*==========================================================================*/

    -- d) Lista estudiantes de una materia con su edad
    -- Resolucion del docente: numero = legajo, @ = email, texto = apellido
    PROCEDURE VISUALIZAR_ESTUDIANTES(p_docente_id IN VARCHAR2, p_materia_id IN NUMBER) IS
        v_docente   NUMBER;
        SIN_ALUMNOS BOOLEAN := TRUE;
    BEGIN
        -- Resolver identidad del docente
        IF REGEXP_LIKE(p_docente_id, '@') THEN
            -- Identificacion por email
            SELECT PROFESOR_ID INTO v_docente
            FROM   PROFESORES
            WHERE  EMAIL = p_docente_id;

        ELSIF REGEXP_LIKE(p_docente_id, '^[0-9]+$') THEN
            -- Identificacion por legajo (numero)
            v_docente := TO_NUMBER(p_docente_id);

        ELSE
            -- Identificacion por apellido
            SELECT PROFESOR_ID INTO v_docente
            FROM   PROFESORES
            WHERE  UPPER(APELLIDO) = UPPER(p_docente_id);
        END IF;

        -- Encabezado de la lista
        DBMS_OUTPUT.PUT_LINE(RPAD('NOMBRE', 30) || RPAD('APELLIDO', 30) || 'EDAD');
        DBMS_OUTPUT.PUT_LINE(RPAD('-', 70, '-'));

        -- Recorrer y mostrar los estudiantes de la materia dictada por el docente
        FOR reg IN (
            SELECT E.ESTUDIANTE_ID, E.NOMBRE, E.APELLIDO
            FROM   MATRICULAS  M
            JOIN   ESTUDIANTES E  ON E.ESTUDIANTE_ID = M.ESTUDIANTE
            JOIN   MATERIAS    MT ON MT.MATERIA_ID   = M.MATERIA
            WHERE  M.MATERIA    = p_materia_id
              AND  MT.PROFESOR  = v_docente
        ) LOOP
            DBMS_OUTPUT.PUT_LINE(
                RPAD(reg.NOMBRE,    30) ||
                RPAD(reg.APELLIDO,  30) ||
                OBTENER_EDAD(reg.ESTUDIANTE_ID)
            );
            SIN_ALUMNOS := FALSE;
        END LOOP;

        IF SIN_ALUMNOS THEN
            DBMS_OUTPUT.PUT_LINE('MATERIA SIN ALUMNOS INSCRIPTOS');
        END IF;

    END VISUALIZAR_ESTUDIANTES;

END PKG_ADMINISTRAR_TAREAS;
/

SET SERVEROUTPUT ON;
/

/*==========================================================================*/

/* BLOQUES DE PRUEBA - ALTA_NOTA */

-- Prueba: docente 1 registra nota 9 al alumno 1 en la materia 202
BEGIN
    PKG_ADMINISTRAR_TAREAS.ALTA_NOTA(1, 1, 202, 9);
END;
/
COMMIT;

/*==========================================================================*/

/* BLOQUES DE PRUEBA - OBTENER_EDAD */

-- Prueba: obtener la edad del alumno con legajo 1
DECLARE
    v_edad NUMBER;
BEGIN
    v_edad := PKG_ADMINISTRAR_TAREAS.OBTENER_EDAD(1);
    DBMS_OUTPUT.PUT_LINE('La edad del alumno es: ' || v_edad);
END;
/

/*==========================================================================*/

/* BLOQUES DE PRUEBA - CANTIDAD_MATERIAS */

-- Prueba: cantidad de materias cursando el alumno con legajo 1
DECLARE
    v_materias NUMBER;
BEGIN
    v_materias := PKG_ADMINISTRAR_TAREAS.CANTIDAD_MATERIAS(1);
    DBMS_OUTPUT.PUT_LINE('El alumno esta inscripto en: ' || v_materias || ' materias');
END;
/

/*==========================================================================*/

/* BLOQUES DE PRUEBA - VISUALIZAR_ESTUDIANTES */

-- Prueba por legajo (numero)
BEGIN
    PKG_ADMINISTRAR_TAREAS.VISUALIZAR_ESTUDIANTES(2, 204);
END;
/

-- Prueba por email
BEGIN
    PKG_ADMINISTRAR_TAREAS.VISUALIZAR_ESTUDIANTES('mlopez@instituto.edu', 204);
END;
/

-- Prueba por apellido
BEGIN
    PKG_ADMINISTRAR_TAREAS.VISUALIZAR_ESTUDIANTES('lopez', 204);
END;
/
