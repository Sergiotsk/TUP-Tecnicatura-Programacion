-- =============================================
-- Ejercicios Semana 12: Administración - Usuarios, Privilegios y Roles
-- Fuente: Apunte Parte 8 — "Administración de Bases de Datos", "Los Usuarios"
-- Ejercicios 1 al 8 de "Ejercicios de Administración" (Parte 8)
-- =============================================

-- EJERCICIO 1: Crear usuario de prueba
/*
CREATE USER estudiante IDENTIFIED BY oracle
  DEFAULT TABLESPACE users
  QUOTA UNLIMITED ON users;
*/

-- EJERCICIO 2: Otorgar privilegios de sistema
/*
GRANT CREATE SESSION, CREATE TABLE, CREATE VIEW TO estudiante;
*/

-- EJERCICIO 3: Crear un rol
/*
CREATE ROLE rol_bdii;
GRANT CREATE PROCEDURE, CREATE SEQUENCE TO rol_bdii;
GRANT rol_bdii TO estudiante;
*/

-- EJERCICIO 4: Privilegios de objeto (SELECT, INSERT en tablas específicas)
/*
GRANT SELECT, INSERT ON employees TO estudiante;
GRANT SELECT ON departments TO estudiante;
*/

-- EJERCICIO 5: Revocar privilegios
/*
REVOKE INSERT ON employees FROM estudiante;
*/

-- EJERCICIO 6: Crear perfil personalizado
/*
CREATE PROFILE perfil_bdii LIMIT
  SESSIONS_PER_USER 2
  FAILED_LOGIN_ATTEMPTS 3
  PASSWORD_LIFE_TIME 90;
*/

-- EJERCICIO 7: Asignar perfil a usuario
/*
ALTER USER estudiante PROFILE perfil_bdii;
*/

-- EJERCICIO 8: Consultar usuarios y privilegios en el diccionario
/*
SELECT username, account_status FROM dba_users WHERE username = 'ESTUDIANTE';
SELECT * FROM dba_role_privs WHERE grantee = 'ESTUDIANTE';
SELECT * FROM dba_tab_privs WHERE grantee = 'ESTUDIANTE';
*/
