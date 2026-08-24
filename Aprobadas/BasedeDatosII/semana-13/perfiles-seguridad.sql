-- =============================================
-- Ejercicios Semana 13: Administración Avanzada - Perfiles y Seguridad
-- Fuente: Apunte Parte 8 — "Crear un Perfil", "Seguridad y Acceso"
-- Ejercicios 9 al 16 de "Ejercicios de Administración" (Parte 8)
-- =============================================

-- EJERCICIO 9: Modificar perfil existente
/*
ALTER PROFILE perfil_bdii LIMIT
  IDLE_TIME 30
  CONNECT_TIME 1440;
*/

-- EJERCICIO 10: Habilitar traza de auditoría (conceptos DBA)
/*
AUDIT SELECT TABLE BY ACCESS WHENEVER NOT SUCCESSFUL;
*/

-- EJERCICIO 11: Consultar tablaspace y cuotas
/*
SELECT tablespace_name, username, bytes/1024/1024 AS mb
FROM dba_ts_quotas WHERE username = 'ESTUDIANTE';
*/

-- EJERCICIO 12: Cambiar contraseña de usuario
/*
ALTER USER estudiante IDENTIFIED BY nueva_clave123;
*/

-- EJERCICIO 13: Bloquear/Desbloquear cuenta
/*
ALTER USER estudiante ACCOUNT LOCK;
ALTER USER estudiante ACCOUNT UNLOCK;
*/

-- EJERCICIO 14: Eliminar usuario con objetos (CASCADE)
/*
DROP USER estudiante CASCADE;
*/

-- EJERCICIO 15: Eliminar rol
/*
DROP ROLE rol_bdii;
*/

-- EJERCICIO 16: Eliminar perfil
/*
DROP PROFILE perfil_bdii CASCADE;
*/

-- Consultas de verificación final
/*
SELECT * FROM dba_profiles WHERE profile = 'PERFIL_BDII';
SELECT username, profile FROM dba_users WHERE username LIKE 'ESTUDIANTE%';
*/
