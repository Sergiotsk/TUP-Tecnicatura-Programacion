# Ejercicios de práctica — Introducción al Análisis de Datos

Enunciado de la cátedra ordenado. Implementalos en `main.py`, donde están las funciones esqueleto con las pistas.

## Cómo trabajar

1. Completá el cuerpo de cada función en `main.py` según la consigna de su ejercicio.
2. Descomentá en `main()` el ejercicio que vayas terminando.
3. Probalo con: `uv run python main.py`
4. Marcá el checklist de abajo cuando esté funcionando.

---

## Ejercicio 1 — Calculadora básica

**Consignas:**

- Leer dos números y una operación (+, -, *, /)
- Mostrar el resultado
- Validar la **división por cero** con `if`

**Conceptos que toca:** `input()`, conversión de tipos, operadores aritméticos, condicional `if`.

## Ejercicio 2 — Clasificador de notas

**Consignas:**

- Leer una nota (0–10) y categorizarla en: **Insuficiente / Aprobado / Bueno / Muy Bueno / Sobresaliente**
- Usar `if` / `elif` / `else` con rangos

**Conceptos que toca:** condicionales encadenados, rangos.

> Ojo: definí vos los límites de cada categoría. ¿Qué nota es "Aprobado"? ¿Y "Sobresaliente"? Es una decisión de diseño tuya — anotá la que uses.

Update del ejercicio 2:
Reformar el código para aplicar la clasificación de notas a esta lista de notas_
notas = [1,10,3,7,7,6,8,4,2,9]

## Ejercicio 3 — Tabla de multiplicar

**Consignas:**

- Pedir un número y mostrar su tabla del 1 al 10
- Usar un bucle `for`

**Conceptos que toca:** bucle `for`, `range()`, f-strings.

## Ejercicio 4 — Número primo

**Consignas:**

- Determinar si un número ingresado es primo o no
- Implementarlo como **función con parámetro y retorno booleano**

**Conceptos que toca:** funciones, parámetros, retorno `bool`, operador módulo (`%`).

---

## Checklist de avance

- [ ] Ejercicio 1 — Calculadora básica
- [ ] Ejercicio 2 — Clasificador de notas
- [ ] Ejercicio 3 — Tabla de multiplicar
- [ ] Ejercicio 4 — Número primo
