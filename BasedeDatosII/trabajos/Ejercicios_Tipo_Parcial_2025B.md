# Ejercicios Tipo Parcial 2025 B

**Tecnicatura Universitaria en Programación — UTN FRH**  
**Base de Datos II — Lic. Vilma Giudice**

---

1. Desarrollar un procedimiento que permita insertar nuevos departamentos según las siguientes especificaciones:

   a. Se pasará al procedimiento el **nombre del departamento**.  
   b. El procedimiento insertará la fila nueva asignando como número de departamento la **decena siguiente al número mayor** de la tabla.  
   c. No se permitirá la inserción del nuevo departamento si el **nombre ya existe**.  
   d. No se permitirá la inserción si el **número de departamento ya existe**.

2. Codificar un procedimiento que permita **subir los salarios** de todos los empleados de un departamento, el cual se indica en la llamada. El aumento de salario será mediante un **porcentaje**.

3. Crear una función que devuelva `VERDADERO` si un **CUIT o CUIL es válido**, caso contrario que devuelva `FALSO`.  
   > NOTA: Se adjunta cómo se forma el dígito verificador del CUIT o del CUIL.

4. Realizar un procedimiento que permita listar, **por departamento**, los sueldos mínimo y máximo de cada empleado de acuerdo con su categoría. El informe tendrá:
   - Encabezado con el **código y nombre del departamento**
   - Lista de empleados: **apellido y nombre, sueldo máximo, sueldo mínimo**
   - Al finalizar cada departamento: **cantidad de empleados** y **suma de salarios máximo** a pagar en dicho departamento

5. Realizar una función que reciba una fecha y retorne si se encuentra en el **1°, 2°, 3° o 4° trimestre** del año. Utilizar esta función para indicar en un listado en qué trimestre se deberá aplicar el cambio de antigüedad a cada empleado. Listar **apellido, nombre** y el **trimestre** en que se cambiará su antigüedad.
