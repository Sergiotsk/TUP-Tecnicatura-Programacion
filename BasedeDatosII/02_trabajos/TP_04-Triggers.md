# Trabajo Práctico N° 4 — Triggers

**Tecnicatura Universitaria en Programación — UTN FRH**  
**Base de Datos II — Lic. Vilma Giudice**

> Para la realización de estos ejercicios ejecutar el *Script Trabajo Practico 4*

---

1. De acuerdo con los procedimientos del negocio, no se permiten realizar modificaciones de los registros de empleados los **fines de semana**. Realizar el disparador para hacer cumplir esta regla de negocio.

2. Crear un disparador que **no permita insertar** registros en la tabla de empleados **entre las 18 hs y las 22 hs**.

3. Realizar un **único disparador** para hacer cumplir ambas reglas de negocio *(puntos 1 y 2)*.

4. Realizar un disparador que registre el **usuario** y la **fecha** de cualquier actividad de cambio que se realice sobre la tabla de departamentos *(actualizaciones, eliminaciones o inserciones de registros)*. Registrar esto en la tabla `LOGS_DEPARTAMENTOS` *(campos: ID, USUARIO, FECHA)*.

5. Una librería almacena los datos de sus libros en una tabla denominada `"libros"` y controla las actualizaciones del precio almacenando en la tabla `"control"` el nombre del usuario, la fecha, el precio anterior y el nuevo. Crear un disparador para dejar registradas las modificaciones.

6. Una empresa almacena los datos de sus empleados en una tabla `"empleados"`. En una tabla `"controlCambios"` guarda los cambios realizados, almacenando el nombre del usuario y la fecha. Crear los siguientes disparadores:

   a. Un disparador para el **alta**.  
   b. Un disparador para las **modificaciones**.  
   c. Un disparador para las **bajas**.  
   d. Un disparador que permita registrar **cualquiera** de las actividades de los puntos anteriores.

7. Construir un disparador que permita auditar las operaciones de modificación, inserción o borrado sobre la tabla `departamentos`. Cuando se produzca cualquier operación, insertar una fila en `LOGS_DEPARTAMENTOS` que contenga:
   - Fecha y hora
   - ID y nombre del departamento insertado o borrado
   - El tipo de operación: `'MODIFICACION'`, `'INSERCIÓN'` o `'BORRADO'`

8. Escribir un disparador que **no permita modificar el apellido** de un empleado.

9. Escribir un disparador que **no permita aumentar el sueldo** de un empleado **por encima del 10%**.

10. Escribir un disparador que **no permita modificar el número** de un empleado.
