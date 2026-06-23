Desarrollar todas las consignas pedidas y con cada una de las sentencias que responden 
a ellas armar un archivo que lleve el siguiente formato BII_Apellido_Legajo.sql 
En el instituto Superior “Hablemos Bien” han creado una Base de Datos con las tablas 
que encontrará en el script adjunto.  Además de crear las tablas, los roles y los usuarios 
correspondientes aún no se han creado los objetos necesarios para cumplir con ciertas 
reglas de negocio.  Usted como administrador de la Base de Datos deberá desarrollar los 
disparadores, procedimientos, funciones y paquetes necesarios que permitirán cumplir 
con aquellas tareas del negocio solicitadas para administrativos, profesores, directores 
de carrera u otros colaboradores del Instituto.  
 
**1**. No se permite dar de alta ni cursos, ni alumnos, ni docentes los fines de semana. 
**2**. Realizar un procedimiento que permita validar el email de un alumno.
* El formato de un email correcto contiene un nombre de usuario seguido de una "@" y un dominio.
* Los nombres de los usuarios sólo pueden contener letras (a-z), números (0-9), y punto (.) el que no puede estar al final.
* Además el primer carácter debe ser una letra.
* Los nombres de dominio sólo pueden contener letras (a-z), números (0-9) y el guion menos (-).
* El guion (-) sólo es permitido si no está al principio o al final del nombre de dominio. 

**3**. Crear un paquete para que los profesores puedan administrar sus tareas en el aula, 
o sea debe permitir que: 

**a)**. El docente dé de alta las notas de un alumno para una actividad en una de sus materias.
 Se deberá controlar que dicho docente esté actualmente dictando la materia solicitada y que el alumno la esté cursando. 

**b)**. Mediante una función, se obtendrá la edad de un alumno ingresando su número de legajo. Se devolverá un número entero.  

**c)**. Mediante una función, se pueda obtener la cantidad de materias que un alumno dado está cursando actualmente.  Si no cursa ninguna materia, devolverá cero. 

**d)**. Un profesor pueda visualizar la lista de los estudiantes, cada uno con su edad, de una materia que dicta. Además de una identificación personal deberá ingresar al 
procedimiento el código de la materia.  Este procedimiento debe aceptar que se le ingrese como identificación del docente: el legajo, su apellido y DNI, o su mail. 
Se deberá controlar que la materia solicitada sea una materia que el profesor en cuestión esté dictando actualmente y se validará que el docente sea un docente 
del Instituto.

Nota: todas las consignas deben llevar los bloques anónimos de prueba.