-- BORRADO  DE TABLAS
-- ELIMINAR TABLAS SI EXISTEN
/*
DROP TABLE detalle_facturas;
DROP TABLE facturas; 
DROP TABLE clientes;
DROP TABLE notas;
DROP TABLE matriculas;
DROP TABLE materias;
DROP TABLE cursos;
DROP TABLE estudiantes;
DROP TABLE profesores;
DROP TABLE carreras;
DROP TABLE directores;
drop table control_libro;
drop table departamentos;
drop table libros;
drop table empleados;
drop table categoria_docente;
drop table categorias;
drop table productos;
DROP TABLE detalle_recetas CASCADE CONSTRAINTS;
DROP TABLE recetas CASCADE CONSTRAINTS;
DROP TABLE medicamentos CASCADE CONSTRAINTS;
DROP TABLE diagnosticos CASCADE CONSTRAINTS;
DROP TABLE citas CASCADE CONSTRAINTS;
DROP TABLE internaciones CASCADE CONSTRAINTS;
DROP TABLE habitaciones CASCADE CONSTRAINTS;
DROP TABLE especialidades CASCADE CONSTRAINTS;
DROP TABLE doctores CASCADE CONSTRAINTS;
DROP TABLE pacientes;
DROP TABLE obras_sociales;
drop table auditoria;
*/

-- CREANDO TABLA CLIENTES
 
CREATE TABLE clientes (
  cod_cliente CHAR(5) NOT NULL PRIMARY KEY,
  nombres VARCHAR2(30) NOT NULL,
  distrito VARCHAR2(30) NULL,
  telefono VARCHAR2(10) NULL
);
 

-- CREANDO TABLA FACTURAS
CREATE TABLE facturas (
  cod_factura CHAR(5) NOT NULL PRIMARY KEY,
  cod_cliente CHAR(5) NOT NULL,
  fecha_emision DATE NULL,
  importe_total DECIMAL(9,2) NULL
);

CREATE TABLE PRODUCTOS 
(	COD_PRODUCTO CHAR(5 BYTE) PRIMARY KEY, 
	DESCRIPCION VARCHAR2(30 BYTE) NOT NULL, 
	PRECIO_UNITARIO NUMBER(9,2)
);

-- CREANDO TABLA DETALLE_FACTURAS
CREATE TABLE detalle_facturas (
  cod_factura CHAR(5) NOT NULL,
  cod_producto CHAR(5) NOT NULL,
  cantidad SMALLINT NOT NULL,
  subtotal DECIMAL(9,2) NOT NULL
);
 
-- AGREGANDO RELACIONES Y CLAVES PRIMARIAS
 
ALTER TABLE facturas ADD FOREIGN KEY (cod_cliente) REFERENCES clientes(cod_cliente);
 
ALTER TABLE detalle_facturas ADD PRIMARY KEY (cod_factura,cod_producto);
 
ALTER TABLE detalle_facturas ADD FOREIGN KEY (cod_factura) REFERENCES facturas(cod_factura);
 
ALTER TABLE detalle_facturas ADD FOREIGN KEY (cod_producto) REFERENCES productos(cod_producto);
 
-- INSERTANDO REGISTROS A LA TABLA CLIENTES
 
INSERT INTO clientes VALUES('C0001','Juli n P rez','Lince','3214568');
INSERT INTO clientes VALUES('C0002','Maria Chavez','Jesus Maria','4215678');
INSERT INTO clientes VALUES('C0003','Juan Chacaltana','Comas','5416321');
INSERT INTO clientes VALUES('C0004','Guadalupe Fern ndez','Cercado','5216364');
INSERT INTO clientes VALUES('C0005','Jos  G mez','Lince','3458974');
INSERT INTO clientes VALUES('C0006','Carlos Segura','Rimac','4562312');
INSERT INTO clientes VALUES('C0007','Javier Buleje','Lince','3218974');
INSERT INTO clientes VALUES('C0008','Mary Huaman','Cercado','5631278');
INSERT INTO clientes VALUES('C0009','Cristian S nchez','Cercado','5410591');
INSERT INTO clientes VALUES('C0010','Flor Paz','Lince','3564165');
 
  
-- INSERTANDO REGISTROS A TABLA FACTURAS
INSERT INTO facturas VALUES('F0001','C0004',SYSDATE,0);
INSERT INTO facturas VALUES('F0002','C0006',SYSDATE,0);
INSERT INTO facturas VALUES('F0003','C0007',SYSDATE,0);
INSERT INTO facturas VALUES('F0004','C0004',SYSDATE,0);
INSERT INTO facturas VALUES('F0005','C0008',SYSDATE,0);
INSERT INTO facturas VALUES('F0006','C0002',SYSDATE,0);
INSERT INTO facturas VALUES('F0007','C0006',SYSDATE,0);
INSERT INTO facturas VALUES('F0008','C0009',SYSDATE,0);
INSERT INTO facturas VALUES('F0009','C0010',SYSDATE,0);
INSERT INTO facturas VALUES('F0010','C0004',SYSDATE,0);


Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0001','Memoria DDR 256 Mb',1120);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0002','Memoria DDR 500 Mb',1190);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0003','Mainboard PcChip v25',1280);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0004','Mainboard Intel V101',1320);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0005','Procesador Intel 3.6',1390);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0006','Procesador Intel 2.6',1340);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0007','Procesador Celeron 3.2',1320);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0008','Disco Duro SATA 80 GB',1180);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0009','Disco Duro SATA 120 GB',1220);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0010','Case Prezcom 500 Wats',1120);
Insert into PRODUCTOS (COD_PRODUCTO,DESCRIPCION,PRECIO_UNITARIO) values ('P0011','ALTAVOCES',1500); 
-- INSERTANDO REGISTROS A LA TABLA DETALLE FACTURAS
INSERT INTO detalle_facturas VALUES('F0001','P0003',3,840.00);
INSERT INTO detalle_facturas VALUES('F0001','P0005',5,1950.00);
INSERT INTO detalle_facturas VALUES('F0001','P0006',2,680.00);
INSERT INTO detalle_facturas VALUES('F0001','P0009',1,220.00);
INSERT INTO detalle_facturas VALUES('F0002','P0009',3,660.00);
INSERT INTO detalle_facturas VALUES('F0002','P0005',8,3120.00);
INSERT INTO detalle_facturas VALUES('F0002','P0002',2,380.00);
INSERT INTO detalle_facturas VALUES('F0002','P0007',3,960.00);
INSERT INTO detalle_facturas VALUES('F0002','P0010',1,120.00);
INSERT INTO detalle_facturas VALUES('F0003','P0010',4,480.00);
INSERT INTO detalle_facturas VALUES('F0003','P0003',7,1960.00);
INSERT INTO detalle_facturas VALUES('F0003','P0006',2,680.00);
INSERT INTO detalle_facturas VALUES('F0003','P0009',1,220.00);
INSERT INTO detalle_facturas VALUES('F0004','P0005',3,1170.00);
INSERT INTO detalle_facturas VALUES('F0004','P0006',6,2040.00);
INSERT INTO detalle_facturas VALUES('F0004','P0007',8,2560.00);
INSERT INTO detalle_facturas VALUES('F0005','P0003',3,840.00);
INSERT INTO detalle_facturas VALUES('F0005','P0005',5,1950.00);
INSERT INTO detalle_facturas VALUES('F0005','P0002',1,190.00);
INSERT INTO detalle_facturas VALUES('F0006','P0007',3,960.00);
INSERT INTO detalle_facturas VALUES('F0006','P0002',2,380.00);
INSERT INTO detalle_facturas VALUES('F0007','P0003',3,840.00);
INSERT INTO detalle_facturas VALUES('F0007','P0008',4,720.00);
INSERT INTO detalle_facturas VALUES('F0008','P0003',3,840.00);
INSERT INTO detalle_facturas VALUES('F0008','P0006',1,340.00);
INSERT INTO detalle_facturas VALUES('F0009','P0003',3,840.00);
INSERT INTO detalle_facturas VALUES('F0010','P0009',5,1100.00);

CREATE TABLE DEPARTAMENTOS
(
	DPTO_ID NUMBER(4,0) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY, 
	NOMBRE VARCHAR2(30 BYTE)
);

CREATE TABLE CATEGORIAS
(
	CODIGO NUMBER(4,0) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY, 
	DESCRIPCION VARCHAR2(60) NOT NULL, 
	SALARIO_MIN NUMBER(7,0), 
	SALARIO_MAX NUMBER(7,0)
);

CREATE TABLE EMPLEADOS 
(
	ID NUMBER(6,0) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY, 
	NOMBRE VARCHAR2(20), 
	APELLIDO VARCHAR2(25), 
	EMAIL VARCHAR2(25), 
	TELEFONO VARCHAR2(20), 
	FECHA_ALTA DATE DEFAULT SYSDATE, 
	CUIL NUMBER(11,0), 
	CATEGORIA_CODIGO NUMBER(3,0), 
	DEPARTAMENTO_ID NUMBER(4,0) 
);


Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('10','Administracion');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('20','Marketing');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('50','Entregas');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('60','IT');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('80','Ventas - Argentina');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('85','Ventas - Region');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('90','Legales');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('110','Contabilidad');
Insert into DEPARTAMENTOS (DPTO_ID,NOMBRE) values ('190','RRHH');


Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('1','Presidente','2000000','3000000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('10','Gerente Administracion','320000','390000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('11','Jefe de Administracion','280000','310000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('15','Administracion Asistante','150000','280000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('20','Gerente Contaduria','820000','960000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('25','Jefe de Contaduria','520000','560000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('30','Administrativo Contable','320000','390000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('40','Gerente de Ventas','500000','620000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('45','Jefe de Ventas','300000','420000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('50','Representante de Ventas','220000','290000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('60','Gerente de Almacenes','550000','608000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('65','Jefe de Almacenes','450000','508000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('70','Empleado de Almacen','310000','370000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('80','Gerente IT','970000','1000000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('85','Programador','400000','900000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('90','Gerente de Marketing','830000','970000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('91','Jefe de Marketing','530000','670000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('95','Representante de Marketing ','310000','385000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('190','Gerente de RRHH','830000','970000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('191','Jefe de RRHH','530000','670000');
Insert into CATEGORIAS (CODIGO,DESCRIPCION,SALARIO_MIN,SALARIO_MAX) values ('195','Representante de RRHH ','310000','385000');


Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('100','Steven','King','SKING','515.123.4567',to_date('17/06/2002','DD/MM/RRRR'),'27123456781','10','90');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('101','Neena','Kochhar','NKOCHHAR','515.123.4568',to_date('21/09/2004','DD/MM/RRRR'),'20987465162','11','90');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('102','Lex','De Haan','LDEHAAN','515.123.4569',to_date('13/01/2008','DD/MM/RRRR'),'27912985162','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('200','Jennifer','Whalen','JWHALEN','515.123.4444',to_date('17/09/2002','DD/MM/RRRR'),'23654759162','15','10');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('205','Shelley','Higgins','SHIGGINS','515.123.8080',to_date('07/06/2009','DD/MM/RRRR'),'24996365162','20','110');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('206','William','Gietz','WGIETZ','515.123.8181',to_date('07/06/2009','DD/MM/RRRR'),'27654235162','25','110');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('149','Eleni','Zlotkey','EZLOTKEY','011.44.1344.429018',to_date('29/01/2015','DD/MM/RRRR'),'20932145162','40','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('174','Ellen','Abel','EABEL','011.44.1644.429267',to_date('11/05/2011','DD/MM/RRRR'),'27258784162','45','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('176','Jonathon','Taylor','JTAYLOR','011.44.1644.429265',to_date('24/03/2013','DD/MM/RRRR'),'24659265162','50','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('178','Kimberely','Grant','KGRANT','011.44.1644.429263',to_date('24/05/2014','DD/MM/RRRR'),'23198926162','1',null);
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('124','Kevin','Mourgos','KMOURGOS','650.123.5234',to_date('16/11/2014','DD/MM/RRRR'),'23194445162','50','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('141','Trenna','Rajs','TRAJS','650.121.8009',to_date('17/10/2010','DD/MM/RRRR'),'27476456781','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('142','Curtis','Davies','CDAVIES','650.121.2994',to_date('29/01/2012','DD/MM/RRRR'),'27455556787','50','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('143','Randall','Matos','RMATOS','650.121.2874',to_date('15/03/2013','DD/MM/RRRR'),'20123456778','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('144','Peter','Vargas','PVARGAS','650.121.2004',to_date('09/07/2013','DD/MM/RRRR'),'24987654321','50','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('103','Alexander','Hunold','AHUNOLD','590.423.4567',to_date('03/01/2005','DD/MM/RRRR'),'27651984512','80','60');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('104','Bruce','Ernst','BERNST','590.423.4568',to_date('21/05/2006','DD/MM/RRRR'),'24123654780','85','60');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('107','Diana','Lorentz','DLORENTZ','590.423.5567',to_date('07/02/2014','DD/MM/RRRR'),'27122652780','85','60');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('201','Michael','Hartstein','MHARTSTE','515.123.5555',to_date('17/02/2011','DD/MM/RRRR'),'20321654987','90','20');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('202','Pat','Fay','PFAY','603.123.6666',to_date('17/08/2013','DD/MM/RRRR'),'27258741369','91','20');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('207','Sophia','Barbosa Souza','SBARBOSASOUZA','55.24.6280.6935',to_date('12/03/2009','DD/MM/RRRR'),'27741965832','40','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('208','Diego','Silva Pinto','DSILVAPINTO','55.24.8806.9837',to_date('25/10/2009','DD/MM/RRRR'),'20667755898','45','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('209','Sarah','Alves Rocha','SALVESROCHA','55.24.9381.2160',to_date('06/02/2011','DD/MM/RRRR'),'20741966872','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('210','Lucas','Almeida Castro','ALMEIDACASTRO','55.24.6514-5378',to_date('16/08/2012','DD/MM/RRRR'),'20987466162','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('212','Nick','Hooper','NHOOPER','011.44.1886 6663',to_date('01/09/2012','DD/MM/RRRR'),'27912986162','50','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('215','Donna','Steiner','DSTEINER','843.452.5959',to_date('02/11/2004','DD/MM/RRRR'),'27664769162','95','20');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('216','George','Bell','GBELL','724.647.4299',to_date('01/04/2014','DD/MM/RRRR'),'24996766162','50','80');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('217','Lisa','TAYLOR','LTAYLOR','417.730.8202',to_date('09/02/2013','DD/MM/RRRR'),'27664276162','95','20');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('219','Michael','Stocks','MSTOCKS','662.314.6844',to_date('16/12/2015','DD/MM/RRRR'),'20667766898','95','20');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('220','Tiffany','Heiden','THEIDEN','413.251.0684',to_date('06/07/2015','DD/MM/RRRR'),'27268784162','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('222','Chen','Li','CLI','423.817.1481',to_date('29/08/2008','DD/MM/RRRR'),'24669266162','85','60');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('223','Alain','Fontaine','AFONTAINE','601.424.8816',to_date('18/11/2013','DD/MM/RRRR'),'27198926162','85','60');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('224','Matthias','Reinhard','MREINHARD','315.496.2466',to_date('25/07/2007','DD/MM/RRRR'),'27194446162','30','110');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('225','Katia','Hernandez','KHERNANDEZ','214.350.4575',to_date('13/06/2011','DD/MM/RRRR'),'27476466781','10','10');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('226','Guido','Ricci','GRICCI','305.269.9415',to_date('17/05/2015','DD/MM/RRRR'),'27466666787','11','10');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('227','Mizuto','Saikawa','MSAIKAWA','541.831.2444',to_date('01/02/2012','DD/MM/RRRR'),'20721664987','15','10');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('228','Nabil','Safwah','NSAFWAH','720.863.0485',to_date('06/01/1997','DD/MM/RRRR'),'24987664721','50','85');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('231','Jelena','Duric','JDURIC','505.514.1583',to_date('11/05/2009','DD/MM/RRRR'),'27667984612','30','110');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('232','Jennifer','Loermans','JLOERMANS','213.447.9053',to_date('14/04/2013','DD/MM/RRRR'),'24127664780','30','110');
Insert into EMPLEADOS (ID,NOMBRE,APELLIDO,EMAIL,TELEFONO,FECHA_ALTA,CUIL,CATEGORIA_CODIGO,DEPARTAMENTO_ID) values ('235','Alice','Newton','ANEWTON','314.248.7709',to_date('16/12/2015','DD/MM/RRRR'),'27122662780','50','85');



-- ================================================
-- BASE DE DATOS DE UN INSTITUTO
-- ================================================

CREATE TABLE CATEGORIA_DOCENTE
(
	CODIGO NUMBER(4,0) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY, 
	DESCRIPCION VARCHAR2(40) NOT NULL, 
	SUELDO NUMBER(6,0)
);

CREATE TABLE profesores (
    profesor_id NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    nombre      VARCHAR2(50) NOT NULL,
    apellido    VARCHAR2(50) NOT NULL,
    fecha_alta  DATE DEFAULT (SYSDATE),
    email       VARCHAR2(100) UNIQUE,
    categoria NUMBER(4),
    DNI         number(8),
    FOREIGN KEY (categoria) REFERENCES categoria_docente(codigo)
);

CREATE TABLE directores (
    director_id NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    nombre      VARCHAR2(50) NOT NULL,
    apellido    VARCHAR2(50) NOT NULL,
    fecha_alta  DATE DEFAULT (SYSDATE),
    email       VARCHAR2(100) UNIQUE,
    DNI         number(8)
);

CREATE TABLE carreras (
    carrera_id NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY, 
	nombre VARCHAR2(40) NOT NULL,
    director number(4),
    FOREIGN KEY (director) REFERENCES directores(director_id)    
);

CREATE TABLE estudiantes (
    estudiante_id    NUMBER(6) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    nombre      VARCHAR2(50) NOT NULL,
    apellido    VARCHAR2(50) NOT NULL,
    fecha_nacimiento DATE NOT NULL,
    email            VARCHAR2(100) UNIQUE,
    carrera     NUMBER(4),
    FOREIGN KEY (carrera) REFERENCES carreras(carrera_id)
);

CREATE TABLE cursos (
    curso_id    NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    nombre      VARCHAR2(100) NOT NULL,
    carrera    NUMBER(4),
    FOREIGN KEY (carrera) REFERENCES carreras(carrera_id)
);

CREATE TABLE materias (
    materia_id    NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    nombre      VARCHAR2(100) NOT NULL,
    profesor NUMBER(4) NOT NULL,
    curso       NUMBER(4) NOT NULL,
    estado      VARCHAR2(10) DEFAULT 'activo',
    FOREIGN KEY (profesor) REFERENCES profesores(profesor_id),
    FOREIGN KEY (curso) REFERENCES cursos(curso_id)
);

CREATE TABLE matriculas (
    matricula_id   NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    estudiante  NUMBER NOT NULL,
    materia       NUMBER NOT NULL,
    fecha_matricula DATE DEFAULT SYSDATE,
    FOREIGN KEY (estudiante) REFERENCES estudiantes(estudiante_id),
    FOREIGN KEY (materia) REFERENCES materias(materia_id)
);

CREATE TABLE notas (
    nota_id       NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    estudiante NUMBER(4) NOT NULL,
    materia      NUMBER(4) NOT NULL,
    valor         NUMBER(5,2) NOT NULL,
    FOREIGN KEY (estudiante) REFERENCES estudiantes(estudiante_id),
    FOREIGN KEY (materia) REFERENCES materias(materia_id)
);

-- ==========================
-- DATOS DEL INSTITUTO
-- ==========================


-- Directores
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (1,'Perez','Gustavo','gperez@instituto.edu',TO_DATE('01/04/2000','DD/MM/RRRR'),21082366);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (2,'Sucre','Antonio','asucre@instituto.edu',TO_DATE('01/07/2019','DD/MM/RRRR'), 51654045);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (3,'Garcia','Pedro','pgarcia@instituto.edu',TO_DATE('01/04/2021','DD/MM/RRRR'), 18620319);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (4,'Fernandez','Luis','lfernandez@instituto.edu',TO_DATE('01/04/2025','DD/MM/RRRR'), 97520959);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (5,'Rivadavia','Bernandino','brivadavia@instituto.edu',TO_DATE('12/02/2025','DD/MM/RRRR'), 62041075);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (6,'Moreno','Mariano','mmoreno@instituto.edu',TO_DATE('12/02/2025','DD/MM/RRRR'), 48418248);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (7,'Urquiza','Justo Jose','jurquiza@instituto.edu',TO_DATE('12/02/2025','DD/MM/RRRR'), 68327516);
INSERT INTO directores (director_id,apellido,nombre,email,fecha_alta, DNI) VALUES (8,'Lorca','Federico','floca@instituto.edu',TO_DATE('12/02/2025','DD/MM/RRRR'), 88691164);

-- Categorias Docentes
Insert into CATEGORIA_DOCENTE (CODIGO,DESCRIPCION,SUELDO) values ('1','Titular','82000');
Insert into CATEGORIA_DOCENTE (CODIGO,DESCRIPCION,SUELDO) values ('2','Adjunto','58000');
Insert into CATEGORIA_DOCENTE (CODIGO,DESCRIPCION,SUELDO) values ('3','Jefe de Trabajos Practicos','46000');
Insert into CATEGORIA_DOCENTE (CODIGO,DESCRIPCION,SUELDO) values ('4','Ayudante de Primera','35500');
Insert into CATEGORIA_DOCENTE (CODIGO,DESCRIPCION,SUELDO) values ('5','Ayudante de Segunda','28500');
Insert into CATEGORIA_DOCENTE (CODIGO,DESCRIPCION,SUELDO) values ('6','Asistente','19500');

-- Profesores
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (1, 'Carlos', 'Gomez', 'cgomez@instituto.edu',TO_DATE('02/02/2025','DD/MM/RRRR'), 21082366,1);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (2, 'Maria', 'Lopez', 'mlopez@instituto.edu',TO_DATE('01/12/2020','DD/MM/RRRR'), 51654045,2);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (3, 'Ricardo', 'Vega', 'rvega@instituto.edu',TO_DATE('03/11/2022','DD/MM/RRRR'), 18620319,2);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (4, 'Ana', 'Salazar', 'asalazar@instituto.edu',TO_DATE('05/11/2021','DD/MM/RRRR'), 97520959,2);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (5, 'Jorge', 'Herrera', 'jherrera@instituto.edu',TO_DATE('01/02/2025','DD/MM/RRRR'), 62041075,2);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (6, 'Luisa', 'Fernandez', 'lfernandez@instituto.edu',TO_DATE('01/02/2021','DD/MM/RRRR'), 48418248,3);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (7, 'Esteban', 'Rios', 'erios@instituto.edu',TO_DATE('01/02/2021','DD/MM/RRRR'), 68327516,3);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (8, 'Marta', 'Ramirez', 'mramirez@instituto.edu',TO_DATE('04/03/2020','DD/MM/RRRR'), 88691164,4);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (9, 'Pedro', 'Sanchez', 'psanchez@instituto.edu',TO_DATE('01/06/2021','DD/MM/RRRR'), 37848529,5);
INSERT INTO profesores (profesor_id, nombre, apellido, email, fecha_alta, DNI, categoria) VALUES (10, 'Lucas', 'Mendez', 'lmendez@instituto.edu',TO_DATE('18/07/2025','DD/MM/RRRR'), 43683166,6);

-- Carreras
INSERT INTO carreras (carrera_id,nombre,director) VALUES (1,'INGENIERIA INDUSTRIAL',4);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (2,'INGENIERIA AERONAUTICA',5);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (3,'INGENIERIA EN SISTEMAS',2);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (4,'INGENIERIA CIVIL',1);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (5,'INGENIERIA QUIMICA',3);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (6,'INGENIERIA ELECTRONICA',8);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (7,'TECNICATURA EN PROGRAMACION',7);
INSERT INTO carreras (carrera_id,nombre,director) VALUES (8,'TECNICATURA FERROVIARIA',6);

-- Estudiantes
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (1,'Albarran','Maximiliano',TO_DATE('12/10/1991','DD/MM/RRRR'),'malbarran1@alumnos.frh.utn.edu.ar','4');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (2,'Catalano','Francisco Joaquin',TO_DATE('02/12/1975','DD/MM/RRRR'),'fcatalano2@alumnos.frh.utn.edu.ar','3');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (3,'Lawaisse','Lisandro',TO_DATE('07/09/1998','DD/MM/RRRR'),'llawaisse3@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (4,'Ponce','Paola Natalia',TO_DATE('03/01/1991','DD/MM/RRRR'),'pponce4@alumnos.frh.utn.edu.ar','5');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (5,'Yedro','Fernando Sebastian',TO_DATE('17/04/1987','DD/MM/RRRR'),'fyedro5@alumnos.frh.utn.edu.ar','2');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (6,'Boiveau','Ignacio',TO_DATE('06/12/1976','DD/MM/RRRR'),'iboiveau6@alumnos.frh.utn.edu.ar','4');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (7,'Bruzzese','Ignacio',TO_DATE('12/09/1984','DD/MM/RRRR'),'ibruzzese7@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (8,'Esquer','Natalin',TO_DATE('03/07/2001','DD/MM/RRRR'),'nesquer8@alumnos.frh.utn.edu.ar','3');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (9,'Grande','Lautaro',TO_DATE('01/10/1998','DD/MM/RRRR'),'lgrande9@alumnos.frh.utn.edu.ar','3');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (10,'Rodriguez','Ignacio',TO_DATE('16/07/2000','DD/MM/RRRR'),'irodriguez10@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (11,'Martinez','Juan Segundo',TO_DATE('09/12/1999','DD/MM/RRRR'),'jmartinez11@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (12,'Melotta','Gabriel',TO_DATE('11/01/2001','DD/MM/RRRR'),'gmelotta12@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (13,'Ponce','Viviana Sofia',TO_DATE('03/01/1991','DD/MM/RRRR'),'vponce13@alumnos.frh.utn.edu.ar','5');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (14,'Kolque Cardoso','Antonella Belen',TO_DATE('18/09/1987','DD/MM/RRRR'),'akolque14@alumnos.frh.utn.edu.ar','2');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (15,'Giudice','Vilma',TO_DATE('16/07/2000','DD/MM/RRRR'),'vgiudice15@alumnos.frh.utn.edu.ar','7');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (16,'Perez','Luisa',TO_DATE('01/12/2000','DD/MM/RRRR'),'lperez16@alumnos.frh.utn.edu.ar','7');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (17,'Garcia','Luis',TO_DATE('06/03/2000','DD/MM/RRRR'),'igarcia17@alumnos.frh.utn.edu.ar','8');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (18,'Rodriguez','Victoria',TO_DATE('26/08/2001','DD/MM/RRRR'),'jrodrigueze18@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (19,'Ibarrola Portillo','Mathias Fernando',TO_DATE('04/02/1992','DD/MM/RRRR'),'mibarrola19@alumnos.frh.utn.edu.ar','1');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (20,'Cardoso','Belen',TO_DATE('18/09/1987','DD/MM/RRRR'),'bcardoso20@alumnos.frh.utn.edu.ar','8');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (21,'Giudice','Valeria',TO_DATE('16/07/2000','DD/MM/RRRR'),'vgiudice21@alumnos.frh.utn.edu.ar','7');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (22,'Perez','Luisa',TO_DATE('01/12/2000','DD/MM/RRRR'),'lperez22@alumnos.frh.utn.edu.ar','7');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (23,'Garcia','Irene',TO_DATE('06/03/2000','DD/MM/RRRR'),'igarcia23@alumnos.frh.utn.edu.ar','7');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (24,'Rodriguez','Federico',TO_DATE('26/08/2001','DD/MM/RRRR'),'frodriguez24@alumnos.frh.utn.edu.ar','6');
INSERT INTO estudiantes (estudiante_id,apellido,nombre,fecha_nacimiento,email,carrera) VALUES (25,'Portello','Fernando',TO_DATE('04/02/1992','DD/MM/RRRR'),'fportelo25@alumnos.frh.utn.edu.ar','6');

-- Cursos
INSERT INTO cursos (curso_id, nombre, carrera) values (1,'1ro 1ra', 1);
INSERT INTO cursos (curso_id, nombre, carrera) values (2,'1ro 2da', 1);
INSERT INTO cursos (curso_id, nombre, carrera) values (3,'2do 1ra', 2);
INSERT INTO cursos (curso_id, nombre, carrera) values (4,'2do 2da', 2);
INSERT INTO cursos (curso_id, nombre, carrera) values (5,'3ra 1ra', 3);
INSERT INTO cursos (curso_id, nombre, carrera) values (6,'3ra 2da', 3);
INSERT INTO cursos (curso_id, nombre, carrera) values (7,'4ta 1ra', 4);
INSERT INTO cursos (curso_id, nombre, carrera) values (8,'4ta 2da', 4);
INSERT INTO cursos (curso_id, nombre, carrera) values (9,'5ta 1ra', 5);
INSERT INTO cursos (curso_id, nombre, carrera) values (10,'5ta 2da',5);
INSERT INTO cursos (curso_id, nombre, carrera) values (11,'TUP',7);
INSERT INTO cursos (curso_id, nombre, carrera) values (12,'TUF',8);


-- Materias
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (301, 'Matematica I',  1,1, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (302, 'Matematica II',  2,1, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (303, 'Fisica I',  3,2, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (304, 'Fisica II',  4,3, 'no activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (305, 'Ingles I',  5,4, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (306, 'Algebra',  6,5, 'no activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (307, 'Matematica I',  7,1, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (308, 'Informatica I',  8,6, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (309, 'Informatica II',  8,6, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (310, 'Algebra',  10,5, 'no activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (201, 'Matematica I',  2, 1,'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (202, 'Matematica II',  1,1, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (203, 'Algebra',  3,5, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (204, 'Fisica II',  4,2, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (205, 'Ingles I',  5,8, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (206, 'Ingles II',  6,7, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (207, 'Algebra',  7,5, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (208, 'Informatica I',  9, 6,'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (209, 'Informatica II',  9, 6,'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (210, 'Fisica I', 10,2, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (401, 'Matematica I',  11,1, 'activo');
INSERT INTO materias (materia_id, nombre, curso, profesor, estado) VALUES (402, 'Matematica I',  12,1, 'activo');

-- Matriculas y notas
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (100,1,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (101,1,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (102,2,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (103,2,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (104,3,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (105,3,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (106,4,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (107,4,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (108,5,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (109,5,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (110,6,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (111,6,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (112,7,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (113,7,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (114,8,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (115,8,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (116,9,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (117,9,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (118,10,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (119,10,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (120,11,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (121,11,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (122,12,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (123,12,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (124,13,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (125,13,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (126,14,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (127,14,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (128,15,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (129,15,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (130,16,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (131,16,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (132,17,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (133,17,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (134,18,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (135,18,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (136,19,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (137,19,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (138,20,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (139,20,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (140,21,202,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (141,21,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (142,22,203,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (143,22,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (144,23,204,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (145,23,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (146,24,205,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (147,24,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (148,25,201,TO_DATE('06/06/2025','DD/MM/RRRR'));
INSERT INTO matriculas (matricula_id,estudiante,materia,fecha_matricula) VALUES (149,25,202,TO_DATE('06/06/2025','DD/MM/RRRR'));

INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (100,1,202,5.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (101,1,203,7.2);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (102,2,203,9.7);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (103,2,204,9.4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (104,3,204,5.1);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (105,3,205,4.6);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (106,4,205,8.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (107,4,201,5.5);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (108,5,201,9.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (109,5,202,9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (110,6,202,7.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (111,6,203,9.2);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (112,7,203,4.4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (113,7,204,1.7);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (114,8,204,7.3);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (115,8,205,5.8);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (116,9,205,6.8);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (117,9,201,3.6);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (118,10,201,3.4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (119,10,202,7.3);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (120,11,202,2.3);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (121,11,203,3.4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (122,12,203,4.1);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (123,12,204,10);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (124,13,204,3.6);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (125,13,205,9.3);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (126,14,205,7.2);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (127,14,201,2.5);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (128,15,201,1.6);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (129,15,202,3.3);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (130,16,202,10);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (131,16,203,1.4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (132,17,203,1.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (133,17,204,4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (134,18,204,8.1);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (135,18,205,3.8);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (136,19,205,2.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (137,19,201,3.7);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (138,20,201,8.1);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (139,20,202,3.9);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (140,21,202,8.8);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (141,21,203,7.4);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (142,22,203,2.5);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (143,22,204,4.1);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (144,23,204,7.8);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (145,23,205,4.3);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (146,24,205,7.8);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (147,24,201,7.2);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (148,25,201,2.1);
INSERT INTO notas (nota_id,estudiante,materia,valor) VALUES (149,25,202,1.1);


CREATE TABLE libros(
    codigo NUMBER (6) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
    titulo VARCHAR2(40),
    autor VARCHAR2(30),
    editorial VARCHAR2(20),
    precio NUMBER(6,2)
);

INSERT INTO libros VALUES(100,'Uno','Richard Bach','Planeta',25);
INSERT INTO libros VALUES(103,'El aleph','Borges','Emece',28);
INSERT INTO libros VALUES(105,'Matematica estas ahi','Paenza','Nuevo siglo',12);
INSERT INTO libros VALUES(120,'Aprenda PHP','Molina Mario','Nuevo siglo',55);
INSERT INTO libros VALUES(145,'Alicia en el pais de las maravillas','Carroll','Planeta',35);

ALTER TABLE libros MODIFY codigo NUMBER(6) GENERATED ALWAYS AS IDENTITY START WITH 146;

INSERT INTO libros (titulo, autor, editorial, precio) VALUES('Base de Datos - Avanzado','Molina Mario','Planeta',135);

CREATE TABLE control_libro(
    ID NUMBER (6) GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    usuario VARCHAR2(30),
    fecha DATE,
    codigo_libro NUMBER(6),
    precioanterior NUMBER(6,2),
    precionuevo NUMBER(6,2)
);

--Pacientes
CREATE TABLE obras_sociales (
  id_obra_social NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  nombre VARCHAR2(100) NOT NULL,
  telefono VARCHAR2(20),
  direccion VARCHAR2(150),
  email VARCHAR2(100),
  estado VARCHAR2(10)
);

INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Salud Total', '011-4000-1234', 'Av. Siempre Viva 742, CABA', 'contacto@saludtotal.com.ar', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('MediPlus', '011-4321-9876', 'Calle Falsa 123, CABA', 'info@mediplus.com.ar', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Union Medica', '0221-555-2323', 'Diagonal 80 Nro 567, La Plata', 'atencion@unionmedica.org', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Vida Sana', '0341-789-4567', 'Bv. Oronio 345, Rosario', 'consultas@vidasana.com', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Salud y Vida', '011-6543-2100', 'Av. Corrientes 1000, CABA', 'servicios@saludyvida.ar', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Prevencion Salud', '0351-123-4567', 'Colon 432, Cordoba', 'contacto@prevencionsalud.com', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Red Medica Argentina', '011-3333-4444', 'Av. Belgrano 2300, CABA', 'rma@salud.com.ar', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Cobertura Integral', '011-9090-8080', 'Thames 1500, CABA', 'soporte@coberturaintegral.ar', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Plan Medico XXI', '0381-567-0987', '25 de Mayo 450, Tucuman', 'clientes@planmedicoxxi.com', 'Inactiva');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Salud Norte', '0299-678-1234', 'Av. Argentina 789, Neuquen', 'info@saludnorte.com', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Bienestar Plus', '011-2222-3344', 'Libertador 6500, CABA', 'bienestar@plus.com.ar', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Amparo Salud', '0261-456-7890', 'San Martin 1234, Mendoza', 'amparo@salud.org', 'Inactiva');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Sanar Ya', '0297-123-4567', 'Rivadavia 900, Comodoro Rivadavia', 'sanarya@servicios.com', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Vida Familiar', '0379-456-2345', 'Junin 432, Corrientes', 'info@vidafamiliar.org', 'Activa');
INSERT INTO obras_sociales (nombre, telefono, direccion, email, estado) VALUES 
('Solidaria Medica', '011-1111-2222', 'Av. Roca 1010, CABA', 'solidaria@medica.com.ar', 'Inactiva');


CREATE TABLE pacientes (
  id_paciente       NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  nombre            VARCHAR2(50),
  apellido          VARCHAR2(50),
  dni               VARCHAR2(20) ,
  fecha_nacimiento  DATE,
  direccion         VARCHAR2(150),
  telefono          VARCHAR2(20),
  email             VARCHAR2(100)UNIQUE,
  id_obra_social    NUMBER(4)
);

ALTER TABLE pacientes ADD CONSTRAINT fk_paciente_obra_social FOREIGN KEY (id_obra_social) REFERENCES obras_sociales(id_obra_social);

INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Juan', 'Perez', '12345678', TO_DATE('1980-05-10','YYYY-MM-DD'), 'Av. Siempre Viva 742', '1134567890', 'juan.perez@email.com',1);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Mar a', 'Gomez', '23456789', TO_DATE('1990-03-22','YYYY-MM-DD'), 'Calle Falsa 123', '1145678901', 'maria.gomez@email.com',1);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Carlos', 'Lopez', '34567890', TO_DATE('1975-11-15','YYYY-MM-DD'), 'Pasaje Esperanza 45', '1156789012', 'carlos.lopez@email.com',1);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Laura', 'Diaz', '45678901', TO_DATE('1985-07-30','YYYY-MM-DD'), 'Calle Sarmiento 123', '1167890123', 'laura.diaz@email.com',4);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Luis', 'Fernandez', '56789012', TO_DATE('1992-12-12','YYYY-MM-DD'), 'Av. Mitre 456', '1178901234', 'luis.fernandez@email.com',4);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Sof a', 'Martinez', '67890123', TO_DATE('1999-09-15','YYYY-MM-DD'), 'Calle C rdoba 789', '1189012345', 'sofia.martinez@email.com',3);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Diego', 'Romero', '78901234', TO_DATE('1988-06-25','YYYY-MM-DD'), 'Calle Mendoza 321', '1190123456', 'diego.romero@email.com',3);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Camila', 'Torres', '89012345', TO_DATE('1972-04-10','YYYY-MM-DD'), 'Av. Rivadavia 234', '1101234567', 'camila.torres@email.com',4);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Gustavo', 'Alvarez', '90123456', TO_DATE('1983-08-19','YYYY-MM-DD'), 'Calle Lavalle 567', '1112345678', 'gustavo.alvarez@email.com',5);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Veronica', 'Silva', '01234567', TO_DATE('1991-11-22','YYYY-MM-DD'), 'Calle Belgrano 890', '1123456789', 'veronica.silva@email.com',4);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Martin', 'Ortega', '13579135', TO_DATE('1986-02-02','YYYY-MM-DD'), 'Calle San Mart n 123', '1134567890', 'martin.ortega@email.com',5);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Carla', 'Varela', '24680246', TO_DATE('1993-03-03','YYYY-MM-DD'), 'Calle Santa Fe 456', '1145678901', 'carla.varela@email.com',2);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Nicolas', 'Mendez', '11223344', TO_DATE('1984-04-04','YYYY-MM-DD'), 'Calle Tucum n 789', '1156789012', 'nicolas.mendez@email.com',2);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Julia', 'Navarro', '55667788', TO_DATE('1987-05-05','YYYY-MM-DD'), 'Calle Catamarca 321', '1167890123', 'julia.navarro@email.com',3);
INSERT INTO pacientes (nombre, apellido, dni, fecha_nacimiento, direccion, telefono, email,id_obra_social) VALUES ('Agustin', 'Molina', '99887766', TO_DATE('1990-06-06','YYYY-MM-DD'), 'Calle Entre R os 654', '1178901234', 'agustin.molina@email.com',5);


-- Especialidades
CREATE TABLE especialidades (
  id_especialidad NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  nombre VARCHAR2(100) NOT NULL,
  descripcion VARCHAR2(255)
);

INSERT INTO especialidades (nombre, descripcion) VALUES ('Cardiologia', 'Diagnostico y tratamiento de enfermedades del corazon y sistema circulatorio.');
INSERT INTO especialidades (nombre, descripcion) VALUES ('Pediatria', 'Atencion medica integral de ninios desde el nacimiento hasta la adolescencia.');
INSERT INTO especialidades (nombre, descripcion) VALUES ('Dermatologia', 'Tratamiento de enfermedades de la piel, cabello y unias.');
INSERT INTO especialidades (nombre, descripcion) VALUES ('Neurologia', 'Estudio y tratamiento de trastornos del sistema nervioso.');
INSERT INTO especialidades (nombre, descripcion) VALUES ('Traumatologia', 'Atencion de lesiones del sistema musculoesqueletico y ortopedia.');


-- Doctores,
CREATE TABLE doctores (
  id_doctor         NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  apellido          VARCHAR2(50),
  nombre            VARCHAR2(50),
  ID_especialidad      NUMBER(4),
  matricula         VARCHAR2(20) UNIQUE,
  telefono          VARCHAR2(20),
  email             VARCHAR2(100)
);

ALTER TABLE doctores ADD CONSTRAINT fk_especial FOREIGN KEY (id_especialidad) REFERENCES especialidades(id_especialidad);

INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Ana', 'Ruiz',  'MAT001', '1132123456', 'ana.ruiz@hospital.com',2);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Pablo', 'Marquez',  'MAT002', '1143234567', 'pablo.marquez@hospital.com',2);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Lucia', 'Ferreyra',  'MAT003', '1154345678', 'lucia.ferreyra@hospital.com',1);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Hector', 'Morales',  'MAT004', '1165456789', 'hector.morales@hospital.com',4);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Elena', 'Suarez',  'MAT005', '1176567890', 'elena.suarez@hospital.com',3);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Ramiro', 'Gil',  'MAT006', '1187678901', 'ramiro.gil@hospital.com',2);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Patricia', 'Rojas',  'MAT007', '1198789012', 'patricia.rojas@hospital.com',4);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Martin', 'Godoy',  'MAT008', '1109890123', 'martin.godoy@hospital.com',5);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Laura', 'Sosa',  'MAT009', '1110901234', 'laura.sosa@hospital.com',4);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Gabriel', 'Vera',  'MAT010', '1121012345', 'gabriel.vera@hospital.com',5);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Julian', 'Ibanez',  'MAT011', '1132123456', 'julian.ibanez@hospital.com',3);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Valeria', 'Campos',  'MAT012', '1143234567', 'valeria.campos@hospital.com',5);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Andres', 'Mena',  'MAT013', '1154345678', 'andres.mena@hospital.com',3);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Diana', 'Paz',  'MAT014', '1165456789', 'diana.paz@hospital.com',2);
INSERT INTO doctores (nombre, apellido, matricula, telefono, email, id_especialidad) VALUES ('Roberto', 'Salas',  'MAT015', '1176567890', 'roberto.salas@hospital.com',1);

-- Habitaciones
CREATE TABLE habitaciones (
  id_habitacion     NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  numero            VARCHAR2(10) UNIQUE,
  piso              NUMBER(2),
  tipo              VARCHAR2(50)
);


INSERT INTO habitaciones (numero, piso, tipo) VALUES ('101', 1, 'Individual');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('102', 1, 'Individual');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('103', 1, 'Compartida');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('201', 2, 'UCI');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('202', 2, 'Individual'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('203', 2, 'UCI');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('301', 3, 'Individual'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('302', 3, 'Compartida'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('303', 3, 'Compartida');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('401', 4, 'Individual'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('402', 4, 'Compartida'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('403', 4, 'Individual');
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('501', 5, 'UCI'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('502', 5, 'UCI'); 
INSERT INTO habitaciones (numero, piso, tipo) VALUES ('503', 5, 'Individual');

-- Internaciones
CREATE TABLE internaciones (
  id_internacion    NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  id_paciente       NUMBER(4),
  id_habitacion     NUMBER(4),
  fecha_ingreso     DATE,
  fecha_egreso      DATE,
  motivo            VARCHAR2(40)    
);

ALTER TABLE internaciones ADD CONSTRAINT fk_interpac FOREIGN KEY (id_paciente) REFERENCES pacientes(id_paciente);
ALTER TABLE internaciones ADD CONSTRAINT fk_interhab FOREIGN KEY (id_habitacion) REFERENCES habitaciones(id_habitacion);

INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (1, 1, TO_DATE('2024-01-01','YYYY-MM-DD'), TO_DATE('2024-01-10','YYYY-MM-DD'), 'Infarto leve');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (2, 2, TO_DATE('2024-01-05','YYYY-MM-DD'), TO_DATE('2024-01-12','YYYY-MM-DD'), 'Neumonia');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (3, 3, TO_DATE('2024-02-01','YYYY-MM-DD'), TO_DATE('2024-02-07','YYYY-MM-DD'), 'Postoperatorio');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (4, 4, TO_DATE('2024-02-15','YYYY-MM-DD'), TO_DATE('2024-02-28','YYYY-MM-DD'), 'Accidente domestico');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (5, 5, TO_DATE('2024-03-01','YYYY-MM-DD'), NULL, 'ACV');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (6, 6, TO_DATE('2024-03-10','YYYY-MM-DD'), NULL, 'Quemaduras leves');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (7, 7, TO_DATE('2024-03-20','YYYY-MM-DD'), TO_DATE('2024-03-25','YYYY-MM-DD'), 'Crisis emocional');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (8, 8, TO_DATE('2024-03-26','YYYY-MM-DD'), NULL, 'Caancer en tratamiento');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (9, 9, TO_DATE('2024-04-01','YYYY-MM-DD'), TO_DATE('2024-04-07','YYYY-MM-DD'), 'Parto programado');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (10, 10, TO_DATE('2024-04-10','YYYY-MM-DD'), TO_DATE('2024-04-14','YYYY-MM-DD'), 'Cirugia');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (11, 11, TO_DATE('2024-04-20','YYYY-MM-DD'), NULL, 'Endocrinopatia');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (12, 12, TO_DATE('2024-04-25','YYYY-MM-DD'), NULL, 'Cirugia ocular');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (13, 13, TO_DATE('2024-05-01','YYYY-MM-DD'), NULL, 'Dolores cronicos');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (14, 14, TO_DATE('2024-05-10','YYYY-MM-DD'), TO_DATE('2024-05-12','YYYY-MM-DD'), 'Shock alergico');
INSERT INTO internaciones (id_paciente, id_habitacion, fecha_ingreso, fecha_egreso, motivo) VALUES (15, 15, TO_DATE('2024-05-15','YYYY-MM-DD'), TO_DATE('2024-05-25','YYYY-MM-DD'), 'Infeccion respiratoria');


-- Citas m dicas
CREATE TABLE citas (
  id_cita           NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  id_paciente       NUMBER(4),
  id_doctor         NUMBER(4),
  fecha_cita        DATE,
  motivo            VARCHAR2(200),
  estado            VARCHAR2(50) -- Confirmada, Cancelada, Realizada
);
ALTER TABLE citas ADD CONSTRAINT fk_pac FOREIGN KEY (id_paciente) REFERENCES pacientes(id_paciente);
ALTER TABLE citas ADD CONSTRAINT fk_doc FOREIGN KEY (id_doctor) REFERENCES doctores(id_doctor);


INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (1, 1, TO_DATE('2024-01-15','YYYY-MM-DD'), 'Chequeo cardiologico', 'Realizada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (2, 2, TO_DATE('2024-01-16','YYYY-MM-DD'), 'Control pediatrico', 'Realizada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (3, 3, TO_DATE('2024-02-10','YYYY-MM-DD'), 'Consulta general', 'Cancelada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (4, 4, TO_DATE('2024-03-05','YYYY-MM-DD'), 'Dolor de espalda', 'Pendiente');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (5, 5, TO_DATE('2024-03-20','YYYY-MM-DD'), 'Mareos frecuentes', 'Realizada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (6, 6, TO_DATE('2024-04-02','YYYY-MM-DD'), 'Erupcion cutanea', 'Realizada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (7, 7, TO_DATE('2024-04-10','YYYY-MM-DD'), 'Evaluacion psicologica', 'Pendiente');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (8, 8, TO_DATE('2024-04-15','YYYY-MM-DD'), 'Estudio oncologico', 'Pendiente');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (9, 9, TO_DATE('2024-05-01','YYYY-MM-DD'), 'Control ginecologico', 'Realizada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (10, 10, TO_DATE('2024-05-12','YYYY-MM-DD'), 'Dolor urinario', 'Cancelada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (11, 11, TO_DATE('2024-05-20','YYYY-MM-DD'), 'Consulta hormonal', 'Pendiente');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (12, 12, TO_DATE('2024-06-01','YYYY-MM-DD'), 'Problemas de vision', 'Pendiente');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (13, 13, TO_DATE('2024-06-10','YYYY-MM-DD'), 'Dolores articulares', 'Pendiente');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (14, 14, TO_DATE('2024-06-15','YYYY-MM-DD'), 'Reaccion alergica', 'Realizada');
INSERT INTO citas (id_paciente, id_doctor, fecha_cita, motivo, estado) VALUES (15, 15, TO_DATE('2024-06-20','YYYY-MM-DD'), 'Fiebre persistente', 'Realizada');

--Diagn sticos
CREATE TABLE diagnosticos (
  id_diagnostico    NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  id_cita           NUMBER ,
  descripcion       VARCHAR2(500),
  fecha             DATE DEFAULT SYSDATE
);
ALTER TABLE diagnosticos ADD CONSTRAINT fk_diagn FOREIGN KEY (id_cita) REFERENCES citas(id_cita);


INSERT INTO diagnosticos (id_cita, descripcion) VALUES (1, 'Arritmia leve');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (2, 'Crecimiento adecuado');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (3, 'Hipertension arterial');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (4, 'Lumbalgia aguda');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (5, 'Vertigo vestibular');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (6, 'Dermatitis por contacto');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (7, 'Ansiedad generalizada');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (8, 'Linfoma en evaluacion');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (9, 'Control postparto normal');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (10, 'Infeccion urinaria');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (11, 'Hipotiroidismo');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (12, 'Astigmatismo y presbicia');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (13, 'Artritis reumatoide');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (14, 'Rinitis alergica');
INSERT INTO diagnosticos (id_cita, descripcion) VALUES (15, 'Faringitis aguda');


-- Medicamentos
CREATE TABLE medicamentos (
  id_medicamento    NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  nombre            VARCHAR2(100),
  descripcion       VARCHAR2(300)
);

INSERT INTO medicamentos (nombre, descripcion) VALUES ('Ibuprofeno 400mg', 'Antiinflamatorio y analgesico');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Paracetamol 500mg', 'Analgesico y antipiretico');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Amoxicilina 500mg', 'Antibiotico de amplio espectro');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Losartan 50mg', 'Antihipertensivo');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Atorvastatina 20mg', 'Reductor de colesterol');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Omeprazol 20mg', 'Protector gastrico');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Metformina 850mg', 'Antidiabetico oral');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Clonazepam 2mg', 'Ansiolitico');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Salbutamol inhalador', 'Broncodilatador');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Azitromicina 500mg', 'Antibiotico');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Diclofenac 75mg', 'Antiinflamatorio');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Enalapril 10mg', 'Antihipertensivo');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Loratadina 10mg', 'Antialergico');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Fluoxetina 20mg', 'Antidepresivo');
INSERT INTO medicamentos (nombre, descripcion) VALUES ('Furosemida 40mg', 'Diurutico');

-- Recetas
CREATE TABLE recetas (
  id_receta         NUMBER(4) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  id_diagnostico    NUMBER(4),
  fecha_receta      DATE DEFAULT SYSDATE
);

ALTER TABLE recetas ADD CONSTRAINT fk_diag FOREIGN KEY (id_diagnostico) REFERENCES diagnosticos(id_diagnostico);

INSERT INTO recetas (id_diagnostico) VALUES (1); 
INSERT INTO recetas (id_diagnostico) VALUES (2); 
INSERT INTO recetas (id_diagnostico) VALUES (3); 
INSERT INTO recetas (id_diagnostico) VALUES (4); 
INSERT INTO recetas (id_diagnostico) VALUES (5); 
INSERT INTO recetas (id_diagnostico) VALUES (6); 
INSERT INTO recetas (id_diagnostico) VALUES (7); 
INSERT INTO recetas (id_diagnostico) VALUES (8); 
INSERT INTO recetas (id_diagnostico) VALUES (9); 
INSERT INTO recetas (id_diagnostico) VALUES (10); 
INSERT INTO recetas (id_diagnostico) VALUES (11); 
INSERT INTO recetas (id_diagnostico) VALUES (12); 
INSERT INTO recetas (id_diagnostico) VALUES (13); 
INSERT INTO recetas (id_diagnostico) VALUES (14);
INSERT INTO recetas (id_diagnostico) VALUES (15);

-- Detalle de recetas
CREATE TABLE detalle_recetas (
  id_receta         NUMBER(4),
  id_medicamento    NUMBER(4),
  dosis             VARCHAR2(100),
  PRIMARY KEY (id_receta, id_medicamento)
);

ALTER TABLE detalle_recetas ADD CONSTRAINT fk_receta FOREIGN KEY (id_receta) REFERENCES recetas(id_receta);
ALTER TABLE detalle_recetas ADD CONSTRAINT fk_medicamento FOREIGN KEY (id_medicamento) REFERENCES medicamentos(id_medicamento);


INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (1, 1, '1 cada 8h');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (2, 2, '1 cada 6h');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (3, 4, '1 diaria');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (4, 11, '1 cada 12h');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (5, 5, '1 diaria por la noche');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (6, 6, '1 diaria en ayunas');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (7, 8, '0.5mg diaria');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (8, 10, '1 diaria por 3 d as');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (9, 9, '2 inhalaciones cada 8h');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (10, 12, '1 diaria');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (11, 7, '1 cada 12h con comida');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (12, 13, '1 diaria por la manana');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (13, 3, '1 cada 8h por 7 dias');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (14, 14, '1 cada 24h');
INSERT INTO detalle_recetas (id_receta, id_medicamento, dosis) VALUES (15, 15, '1 cada 12h');

CREATE TABLE auditoria (
  id_auditoria NUMBER(6) GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  usuario VARCHAR2(30) NOT NULL,
  fecha TIMESTAMP DEFAULT SYSTIMESTAMP NOT NULL,
  motivo VARCHAR2(255) NOT NULL,
  tabla VARCHAR2(30)
);

CREATE TABLE regiones (
    id_region NUMBER(3) PRIMARY KEY,
    nombre_region VARCHAR2(50) NOT NULL,
    pais_principal VARCHAR2(50),
    superficie_km2 NUMBER(10),
    poblacion_millones NUMBER(8,2)
);

INSERT INTO regiones VALUES (1, 'Am�rica del Norte', 'Estados Unidos', 24709000, 579);
INSERT INTO regiones VALUES (2, 'Am�rica del Sur', 'Brasil', 17840000, 430);
INSERT INTO regiones VALUES (3, 'Europa', 'Alemania', 10180000, 748);
INSERT INTO regiones VALUES (4, '�frica', 'Nigeria', 30370000, 1340);
INSERT INTO regiones VALUES (5, 'Asia', 'China', 44579000, 4640);
INSERT INTO regiones VALUES (6, 'Ocean�a', 'Australia', 8500000, 44);
INSERT INTO regiones VALUES (7, 'Ant�rtida', '�', 14000000, 0.01);
INSERT INTO regiones VALUES (8, 'Medio Oriente', 'Arabia Saudita', 7200000, 270);
INSERT INTO regiones VALUES (9, 'Europa del Este', 'Polonia', 1900000, 295);
INSERT INTO regiones VALUES (10, 'Centroam�rica y Caribe', 'M�xico', 5200000, 220);
INSERT INTO regiones VALUES (11, 'Sudeste Asi�tico', 'Indonesia', 4800000, 680);
INSERT INTO regiones VALUES (12, 'Escandinavia', 'Suecia', 1250000, 27);
INSERT INTO regiones VALUES (13, '�frica del Norte', 'Egipto', 9600000, 260);
INSERT INTO regiones VALUES (14, 'Asia Central', 'Kazajist�n', 4000000, 75);
INSERT INTO regiones VALUES (15, 'Europa Occidental', 'Francia', 5000000, 420);

COMMIT;