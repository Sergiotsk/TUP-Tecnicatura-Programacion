
-- Trabajo Práctico N° 2 - Base de Datos 1
-- Alumno: Sergio Tschernitschek



-- 1. Agregar artículo ALTAVOCES
INSERT INTO articulos VALUES('P0011', 'ALTAVOCES', 7000);
/

-- 2. Cambiar nombre del artículo cuyo código termina en 8
UPDATE articulos
SET descripcion = 'Impresora Láser'
WHERE codigo LIKE '%8';
/

-- 3. Aplicar un 10% de descuento a todos los precios
UPDATE articulos
SET precio = precio * 0.9;
/

-- 4. Obtener la descripción de todos los artículos
SELECT descripcion FROM articulos;
/

-- 5. Código y descripción de artículos con precio < 2000
SELECT codigo, descripcion
FROM articulos
WHERE precio < 2000;
/

-- 6. Artículos con precio entre 600 y 1200
SELECT *
FROM articulos
WHERE precio BETWEEN 600 AND 1200;
/

-- 7. Descuento de $150 a artículos con precio < 1200
UPDATE articulos
SET precio = precio - 150
WHERE precio < 1200;
/

-- 8. Descripción y precio en dólares (1 USD = 450)
SELECT descripcion, ROUND(precio / 450, 2) AS precio_usd
FROM articulos;
/

-- 9. Artículos con precio >= 1800, orden descendente por precio y ascendente por nombre
SELECT descripcion, ROUND(precio / 450, 2) AS precio_usd
FROM articulos
WHERE precio >= 1800
ORDER BY precio DESC, descripcion ASC;
/


