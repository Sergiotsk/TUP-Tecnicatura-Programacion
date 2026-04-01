-- ===============================================
-- CREAR VISTA DE RESERVAS ACTIVAS
-- ===============================================

CREATE OR REPLACE VIEW vista_reservas_activas AS
SELECT 
    
    i.apellido || ', ' || i.nombre AS investigador,
    e.marca || ' ' || e.modelo AS equipo,
    r.fecha AS fecha_inicio,
    r.fecha_fin AS fecha_fin
FROM 
    reservas r
    JOIN investigadores i ON r.investigador_id = i.id
    JOIN equipos e ON r.equipo_id = e.id
WHERE 
    r.fecha_fin IS NULL;

COMMIT;

-- ===============================================
-- CONSULTAR LA VISTA
-- ===============================================
SELECT * FROM vista_reservas_activas;

-- ===============================================
-- VERIFICAR QUE SE CREÓ CORRECTAMENTE
-- ===============================================
SELECT view_name FROM user_views WHERE view_name = 'VISTA_RESERVAS_ACTIVAS';

-- ===============================================
-- ELIMINAR LA VISTA (si necesitás volver a crearla)
-- ===============================================
-- DROP VIEW vista_reservas_activas;
