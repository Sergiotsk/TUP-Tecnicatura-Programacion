-- Trabajo Práctico N° 3- Base de Datos 1
-- Alumno: Sergio Tschernitschek
-- Legajo:37738


SELECT * FROM ARTICULOS;--SOLO PARA CHECKEAR QUE LA TABLA Y LOS CAMBIO


--3)Actualizar precios entre 1500 y 38000 a 56000

UPDATE ARTICULOS 
SET PRECIO = 56000
WHERE PRECIO BETWEEN 12500 AND  38000;
COMMIT;

--4)listar articulos con precios menores a 15000

select * from articulos
where precio < 15000;

--5)eliminar articulos con precios mayores a 2.000.000 y del fabricante codigo 4

delete from articulos
where precio>2000000  and  fabricante=4;
commit;

--6)listar articulos que contengan la palabra "ropa"

select * from articulos
where descripcion like '%ropa%';

--7) listar fabricantes que comiencen con FR

select * from fabricantes
where razon_social like 'FR%';

--8) aumentar los precio de los articulos un 5%

update articulos
set precio= precio*1.05;
commit;

--9)aumentar 15% a los articulos de los fabricante 2 y 3

update articulos
set precio = precio * 1.15
where fabricante=2 or fabricante=3; 
commit;

--10)indicar el mayor precio de cada fabricante

SELECT FABRICANTE, MAX(PRECIO) AS PRECIO_MAXIMO
FROM ARTICULOS
GROUP BY FABRICANTE;

--11)obtener los nombres de los fabricantes que ofrezcan productos con precio medio mayor a 8500

SELECT f.razon_social as FABRICANTE, ROUND( AVG(a.precio),2) AS PRECIO_MEDIO
FROM articulos a
join fabricantes f ON a.fabricante = f.codigo
group by f.razon_social
having avg(a.precio)>8500;


--12)Mostrar promedio de precios de todos los articulos de cada uno de los fabricantes

SELECT FABRICANTE,ROUND( AVG(PRECIO),2) AS PRECIO_MEDIO
FROM ARTICULOS
GROUP BY articulos.fabricante
order by articulos.fabricante asc;

--13)Obtener el precio medio de los productos  de cada fabricante mostrando el nombre del fabricante


SELECT f.razon_social as FABRICANTE, ROUND( AVG(a.precio),2) AS PRECIO_MEDIO
FROM articulos a
join fabricantes f ON a.fabricante = f.codigo
group by f.razon_social;



--14)mostrar cual es la cantidad de proveedores, fabricantes ,que tiene la empresa


select count(*) as TOTAL_FABRICANTES
FROM fabricantes;

--15) cunatos productos provee cada faarbicante


SELECT f.razon_social as FABRICANTE,count(*) AS CANT_ARTICULOS
FROM ARTICULOS a
JOIN fabricantes f on a.fabricante = f.codigo
GROUP BY f.razon_social;

--16)listar nombres y precios de los articulos mas caros de cada fabricante con el nombre de este

SELECT f.razon_social AS FABRICANTE, a.descripcion AS ARTICULO, a.precio
FROM articulos a
JOIN FABRICANTES f ON a.fabricante = f.codigo
WHERE a.precio = (
    SELECT MAX(b.precio)
    FROM articulos b
    WHERE b.fabricante = a.fabricante
);


--17) Listar razon social de los fabricantes que no nos proveen articulos actualmente

SELECT f.razon_social
FROM fabricantes f
LEFT JOIN articulos a ON f.codigo = a.fabricante
WHERE a.fabricante IS NULL;


--18)Listar fabrricantes que nos proveen mas de 3 articulos


SELECT f.razon_social as FABRICANTE,count(*) AS CANT_ARTICULOS 
FROM ARTICULOS a
JOIN fabricantes f on a.fabricante = f.codigo
GROUP BY f.razon_social
having count(*)>3;

--19)Obtener los nombres de los productos que nos proveen el fabricante 'Kerflex'



SELECT a.descripcion as PROD_Kerflex
FROM ARTICULOS a
JOIN fabricantes f on a.fabricante = f.codigo
where f.razon_social = 'Kerflex';




