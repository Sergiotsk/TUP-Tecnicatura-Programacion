# Ejercicio 2º Parcial — 2º Semestre 2025

**Penal "Los Alerces"**

Se ha creado una Base de Datos con las tablas que encontrará en el script adjunto. Sólo se han creado tablas pero no los objetos necesarios para cumplir con ciertas reglas de negocio. Usted como administrador de la Base de Datos deberá desarrollar los disparadores, procedimientos, funciones y paquetes necesarios que permitirán cumplir con aquellas tareas del negocio solicitadas por el personal del penitenciario.

---

## Requerimientos

Crear un **paquete** para que el personal del penal pueda llevar a cabo las tareas diarias. Debe permitir:

### 1. Función — Clasificar reincidencia criminal

Determinar si un criminal que aún está en la cárcel ha tenido más de 3 entradas a la cárcel en los últimos 180 días, devolviendo:

| Cantidad de ingresos | Mensaje |
|-----------------------|---------|
| Más de 3             | `'GRAN REINCIDENTE'` |
| 2 veces              | `'REINCIDENTE'` |
| 1 vez                | `'PRIMERA VEZ'` |

Dar un mensaje coherente en cualquier caso de error o situación no contemplada.

### 2. Procedimiento — Listar sospechosos por detective

Listar los datos de los criminales sospechosos de un crimen junto con la fecha de éste y el apellido del damnificado que son investigados por un detective en particular.

Al detective se lo puede indicar por:
- Su identificación (ID), **o**
- Su apellido y nombre, **o**
- Su apellido y fecha de alta.

### 3. Trigger — Control de aumento de sueldos

No permitir que aumenten los sueldos del personal de los servicios penitenciarios por encima de un **15%** del valor registrado.

Dejar constancia tanto de:
- Los cambios de sueldo exitosos, **como**
- Cualquier intento fallido de modificación de éstos

en la tabla de auditoría.

Emitir un mensaje de error acorde a la acción denegada en caso de que así sea.
