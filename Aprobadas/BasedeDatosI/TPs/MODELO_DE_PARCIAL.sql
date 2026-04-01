-- ===============================================
-- Pregunta 5 - Aumentar 10% el sueldo de las categorías asociadas a investigadores activos
-- ===============================================

UPDATE categorias c
SET c.sueldo_basico = c.sueldo_basico * 1.10
WHERE c.codigo IN (
    SELECT DISTINCT i.codigo
    FROM investigadores i
    WHERE i.codigo IS NOT NULL
);

COMMIT;

-- Verificación del resultado
SELECT c.codigo, c.descripcion, c.sueldo_basico
FROM categorias c
WHERE c.codigo IN (SELECT DISTINCT codigo FROM investigadores);

--6)Armar un listado de las reservas activas (las que no tienen fecha de finalización) indicando cuál es el equipo reservado, quién lo ha reservado y desde cuándo poseen dicha reserva 


SELECT 
    e.modelo AS Equipo,
    p.nombre || p.apellido AS Reservado_por,
    r.fecha AS Fecha_de_reserva
FROM 
    reservas r
    JOIN equipos e ON r.equipo_id = e.id
    JOIN investigadores p ON r.investigador_id = p.id
WHERE 
    r.fecha_fin IS NULL;
    
    
--7)Hacer un listado de aquellas reservas que deberían haber finalizado pero que aún se encuentran activas. Tener en cuenta que la cantidad de días de reserva corresponden a una semana laboral de lunes a viernes. 



SELECT 
    e.modelo AS Equipo,
    p.nombre || ',' || p.apellido AS Reservado_por,
    r.fecha AS Fecha_de_inicio,
    SYSDATE AS Fecha_actual
FROM 
    reservas r
    JOIN equipos e ON r.equipo_id= e.id
    JOIN investigadores p ON r.investigador_id = p.id
WHERE 
    r.fecha_fin IS NULL
    AND(sysdate - r.fecha) > 5;
    
    
--8)Hacer un listado de los números de serie, la marca y el modelo de todos los equipos en préstamo y a qué investigador se lo han entregado. 


SELECT 
    e.num_serie AS "Número de Serie",
    e.marca AS "Marca",
    e.modelo AS "Modelo",
    i.nombre || ' ' || i.apellido AS "Investigador",
    r.fecha as "desde"
FROM 
    reservas r
    JOIN equipos e ON r.equipo_id = e.id
    JOIN investigadores i ON r.investigador_id = i.id
WHERE 
    r.fecha_fin IS NULL;


--9)Emitir un listado de las facultades que no tienen ninguna reserva hecha. 

SELECT 
    f.nombre AS "Facultad sin reservas"
FROM 
    facultades f
    LEFT JOIN investigadores i 
        ON f.codigo = i.facultad_codigo
    LEFT JOIN reservas r 
        ON i.id = r.investigador_id
WHERE 
    r.fecha IS NULL;


--10)Emitir un listado en la que se muestren las facultades que no cuentan con Investigadores registrados. 


SELECT 
    f.nombre AS "Facultad sin Investigadores"
FROM 
    facultades f
    LEFT JOIN investigadores i 
        ON f.codigo = i.facultad_codigo
   
WHERE 
    i.facultad_codigo IS NULL;

--11)Emitir un listado en la que se muestren las facultades que tienen más de dos investigadores que no hayan realizado ninguna reserva. 


SELECT 
    f.nombre AS "Facultad",
    COUNT(i.id) AS "Cantidad de investigadores sin reservas"
FROM 
    facultades f
    JOIN investigadores i 
        ON f.codigo = i.facultad_codigo
    LEFT JOIN reservas r 
        ON i.id = r.investigador_id
WHERE 
    r.fecha IS NULL
GROUP BY 
    f.nombre
HAVING 
    COUNT(i.id) > 2;

--12)Realizar un informe de aquellos investigadores, con su apellido, nombre y DNI, que tengan más de dos reservas activas. 

-- 12) Investigadores con más de dos reservas activas
SELECT 
    i.apellido || ', ' || i.nombre AS "Apellido y Nombre",
    i.dni AS "DNI",
    COUNT(r.equipo_id) AS "Cantidad de Reservas"
FROM 
    reservas r
    JOIN investigadores i ON r.investigador_id = i.id

GROUP BY 
    i.apellido, i.nombre, i.dni
HAVING 
    COUNT(r.equipo_id) > 2
ORDER BY 
    i.apellido;


