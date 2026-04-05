# Matemática con Python — Mapa de Aprendizaje

Proyecto personal para repasar y aprender matemáticas **mientras aprendo Python y sus librerías**.
Cada módulo combina teoría matemática con código Python real que la implementa.

---

## Filosofía del proyecto

> "No alcanza con saber la fórmula. Hay que programarla para entenderla de verdad."

- **Matemáticas** como herramienta, no como fin en sí mismo.
- **Python** aprendido en contexto, no en el vacío.
- Cada librería se introduce cuando el problema la necesita.

---

## Módulos

| # | Tema | Librerías Python | Estado |
|---|------|-----------------|--------|
| 01 | [Aritmética](#01-aritmética) | `math`, `fractions`, `decimal` | ⬜ En progreso |
| 02 | [Álgebra y Funciones](#02-álgebra-y-funciones) | `sympy` | ⬜ Pendiente |
| 03 | [Álgebra Lineal](#03-álgebra-lineal) | `numpy` | ⬜ Pendiente |
| 04 | [Cálculo](#04-cálculo) | `sympy`, `matplotlib` | ⬜ Pendiente |
| 05 | [Estadística y Probabilidad](#05-estadística-y-probabilidad) | `numpy`, `scipy`, `matplotlib` | ⬜ Pendiente |
| 06 | [Matemática Discreta](#06-matemática-discreta) | Python puro, `itertools` | ⬜ Pendiente |

---

## 01 Aritmética

**¿Por qué importa?** Base de todo. Fracciones, potencias, raíces, porcentajes. Cosas que se dan por sabidas pero muchas veces tienen huecos.

**¿Qué aprendo de Python?** Tipos numéricos (`int`, `float`, `Fraction`, `Decimal`), precisión de punto flotante, módulo `math`.

Archivos:
- `01_Aritmetica/aritmetica_basica.py` — operaciones, fracciones, potencias, porcentajes

---

## 02 Álgebra y Funciones

**¿Por qué importa?** Modelar problemas como ecuaciones. Las funciones son la base de la programación funcional, los algoritmos de búsqueda, la complejidad computacional.

**¿Qué aprendo de Python?** Introducción a `sympy`: matemática simbólica, resolver ecuaciones, graficar funciones.

Archivos:
- `02_Algebra/ecuaciones_lineales.py` — ecuaciones de 1° y 2° grado, sistemas
- `02_Algebra/funciones.py` — dominio, imagen, composición, tipos de funciones

---

## 03 Álgebra Lineal

**¿Por qué importa?** Vectores y matrices son fundamentales para: gráficos 3D, machine learning, procesamiento de imágenes, sistemas de ecuaciones, criptografía.

**¿Qué aprendo de Python?** `numpy`: el array, operaciones vectorizadas, broadcasting. La librería más importante para cómputo científico.

Archivos:
- `03_AlgebraLineal/vectores_y_matrices.py` — operaciones básicas con numpy
- `03_AlgebraLineal/sistemas_de_ecuaciones.py` — resolver Ax=b con numpy.linalg

---

## 04 Cálculo

**¿Por qué importa?** Los algoritmos de optimización (como los que usa Machine Learning) se basan en derivadas. Las integrales aparecen en probabilidad y física.

**¿Qué aprendo de Python?** `sympy` para cálculo simbólico. `matplotlib` para visualizar funciones y sus derivadas.

Archivos:
- `04_Calculo/limites_y_derivadas.py` — límites, derivadas, reglas
- `04_Calculo/integrales.py` — integrales definidas e indefinidas

---

## 05 Estadística y Probabilidad

**¿Por qué importa?** Materia aprobada, pero se puede profundizar. Está en todo: análisis de datos, IA, tests de software, métricas.

**¿Qué aprendo de Python?** `numpy` para estadística descriptiva, `scipy.stats` para distribuciones, `matplotlib` para histogramas y gráficos.

Archivos:
- `05_EstadisticaYProbabilidad/estadistica_descriptiva.py` — media, mediana, varianza, desvío
- `05_EstadisticaYProbabilidad/distribuciones.py` — normal, binomial, Poisson

---

## 06 Matemática Discreta

**¿Por qué importa?** Es la matemática de la programación. Lógica proposicional, teoría de conjuntos, combinatoria, grafos. Aparece en algoritmos, bases de datos, criptografía.

**¿Qué aprendo de Python?** `set`, `frozenset`, `itertools`, lógica con booleanos, grafos con diccionarios.

Archivos:
- `06_MatematicaDiscreta/logica_y_conjuntos.py` — operaciones lógicas, conjuntos en Python
- `06_MatematicaDiscreta/combinatoria.py` — permutaciones, combinaciones, factorial

---

## Roadmap de librerías Python

```
Python puro
    └── math, fractions, decimal (stdlib — módulo 01)
        └── sympy (álgebra simbólica — módulos 02 y 04)
        └── numpy (vectores, matrices, estadística — módulos 03 y 05)
            └── matplotlib (visualización — módulos 04 y 05)
            └── scipy (estadística avanzada — módulo 05)
                └── [Futuro] Flask/FastAPI → WebApp interactiva
```

## Cómo instalar las librerías

```bash
pip install numpy sympy matplotlib scipy
```

---

## Cómo usar este material

1. Leer el script de arriba hacia abajo, como si fuera un apunte.
2. Ejecutar y observar el output.
3. Modificar los valores y ver qué cambia.
4. Resolver los ejercicios marcados con `# EJERCICIO:` en el código.

