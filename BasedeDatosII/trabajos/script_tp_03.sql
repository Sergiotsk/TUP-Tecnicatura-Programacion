DROP TABLE LOCALIDADES;
DROP TABLE municipios;
DROP TABLE PROVINCIAS;


CREATE TABLE provincias (
	id NUMBER(2) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	nombre VARCHAR2(60) NOT NULL,
    capital VARCHAR2(50) NOT NULL,
    fundacion NUMBER(4),
    superficie NUMBER(6)
);

CREATE TABLE municipios (
	id NUMBER(3) GENERATED ALWAYS AS IDENTITY PRIMARY KEY ,
	provincia_id NUMBER(2) NOT NULL ,
	nombre VARCHAR2(100) NOT NULL,
    FOREIGN KEY (provincia_id) REFERENCES provincias(ID) 
);

CREATE TABLE localidades (
	id NUMBER(4) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	municipio_id NUMBER(3) NOT NULL ,
	nombre VARCHAR2(100) NOT NULL,
    FOREIGN KEY (municipio_id) REFERENCES municipios(ID)     
);


INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Buenos Aires','La Plata',1820,307571);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Catamarca','San Fernando del Valle de Catamarca',1821,102602);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Chaco','Resistencia',1951,99633);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Chubut','Rawson',1955,224686);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Córdoba','Córdoba',1820,165321);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Corrientes','Corrientes',1814,88199);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Entre Ríos','Paraná',1814,78781);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Formosa','Formosa',1955,72066);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Jujuy','San Salvador de Jujuy',1836,53219);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('La Pampa','Santa Rosa',1951,143440);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('La Rioja','La Rioja',1820,89680);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Mendoza','Mendoza',1820,148827);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Misiones','Posadas',1953,29801);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Neuquén','Neuquén',1955,94078);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Río Negro','Viedma',1955,203013);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Salta','Salta',1836,155488);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('San Juan','San Juan',1820,89651);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('San Luis','San Luis',1820,76748);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Santa Cruz','Río Gallegos',1956,243943);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Santa Fe','Santa Fe',1816,133007);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Santiago del Estero','Santiago del Estero',1820,136351);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Tierra del Fuego, Antártida e Islas del Atlántico Sur','Ushuaia',1990,215716);
INSERT INTO provincias (nombre,capital,fundacion,superficie) VALUES ('Tucumán','San Miguel de Tucumán',1825,22524);


insert into municipios(provincia_id,nombre) values(1,'Almirante Brown');
insert into municipios(provincia_id,nombre) values(1,'Avellaneda');
insert into municipios(provincia_id,nombre) values(1,'Berazategui');
insert into municipios(provincia_id,nombre) values(1,'Berisso');
insert into municipios(provincia_id,nombre) values(1,'Brandsen');
insert into municipios(provincia_id,nombre) values(1,'Campana');
insert into municipios(provincia_id,nombre) values(1,'Cañuelas');
insert into municipios(provincia_id,nombre) values(1,'Ensenada');
insert into municipios(provincia_id,nombre) values(1,'Escobar');
insert into municipios(provincia_id,nombre) values(1,'Esteban Echeverría');
insert into municipios(provincia_id,nombre) values(1,'Exaltación de la Cruz');
insert into municipios(provincia_id,nombre) values(1,'Ezeiza');
insert into municipios(provincia_id,nombre) values(1,'Florencio Varela');
insert into municipios(provincia_id,nombre) values(1,'General Las Heras');
insert into municipios(provincia_id,nombre) values(1,'General Rodríguez');
insert into municipios(provincia_id,nombre) values(1,'General San Martín');
insert into municipios(provincia_id,nombre) values(1,'Hurlingham');
insert into municipios(provincia_id,nombre) values(1,'Ituzaingó');
insert into municipios(provincia_id,nombre) values(1,'José C. Paz');
insert into municipios(provincia_id,nombre) values(1,'La Matanza');
insert into municipios(provincia_id,nombre) values(1,'La Plata');
insert into municipios(provincia_id,nombre) values(1,'Lanús');
insert into municipios(provincia_id,nombre) values(1,'Lomas de Zamora');
insert into municipios(provincia_id,nombre) values(1,'Luján');
insert into municipios(provincia_id,nombre) values(1,'Malvinas Argentinas');
insert into municipios(provincia_id,nombre) values(1,'Marcos Paz');
insert into municipios(provincia_id,nombre) values(1,'Merlo');
insert into municipios(provincia_id,nombre) values(1,'Moreno');
insert into municipios(provincia_id,nombre) values(1,'Morón');
insert into municipios(provincia_id,nombre) values(1,'Pilar');
insert into municipios(provincia_id,nombre) values(1,'Presidente Perón');
insert into municipios(provincia_id,nombre) values(1,'Quilmes');
insert into municipios(provincia_id,nombre) values(1,'San Fernando');
insert into municipios(provincia_id,nombre) values(1,'San Isidro');
insert into municipios(provincia_id,nombre) values(1,'San Miguel');
insert into municipios(provincia_id,nombre) values(1,'San Vicente');
insert into municipios(provincia_id,nombre) values(1,'Tigre');
insert into municipios(provincia_id,nombre) values(1,'Tres de Febrero');
insert into municipios(provincia_id,nombre) values(1,'Vicente López');
insert into municipios(provincia_id,nombre) values(1,'Zárate');

-- Hacemos COMMIT para persistir los inserts en la base de datos
COMMIT;