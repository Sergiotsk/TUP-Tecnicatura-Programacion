# Progreso: Matemática + Python

Combina el repaso de matemáticas con el aprendizaje de Python y sus librerías.
Ver: `Aprendizaje/MatematicaConPython/`

---

## Módulo 01 — Aritmética (`01_Aritmetica/`)
**Librerías:** `math`, `fractions`, `decimal`

- [ ] Operadores aritméticos y jerarquía (PEMDAS)
- [ ] El problema del punto flotante (`math.isclose`)
- [ ] Fracciones exactas (`Fraction`)
- [ ] Potencias, raíces y módulo `math`
- [ ] Porcentajes y variación porcentual
- [ ] Notación científica y números grandes
- [ ] Resolver ejercicios marcados con `# EJERCICIO:` en el script

---

## Módulo 02 — Álgebra (`02_Algebra/`)
**Librerías:** `sympy`

- [ ] Variables simbólicas con `sympy.symbols`
- [ ] Ecuaciones de 1° grado (`solve`, `Eq`)
- [ ] Ecuaciones de 2° grado (fórmula cuadrática, `factor`)
- [ ] Sistemas de ecuaciones (2 y 3 incógnitas)
- [ ] Funciones matemáticas como funciones Python
- [ ] Composición de funciones
- [ ] Resolver ejercicios marcados en el script

---

## Módulo 03 — Álgebra Lineal (`03_AlgebraLineal/`)
**Librerías:** `numpy`

- [ ] Arrays de NumPy vs listas de Python
- [ ] Vectores: suma, escalar, norma, producto punto, ángulo
- [ ] Matrices: creación, suma, multiplicación `@`, transpuesta
- [ ] Determinante e inversa (`np.linalg`)
- [ ] Sistemas lineales con matrices (`np.linalg.solve`)
- [ ] Matrices especiales: zeros, ones, eye, arange, linspace, reshape

---

## Módulo 04 — Cálculo (`04_Calculo/`)
**Librerías:** `sympy`, `numpy`, `matplotlib`

- [ ] Límites: concepto intuitivo, formas indeterminadas, al infinito
- [ ] Derivada: concepto, aproximación numérica
- [ ] Reglas de derivación con `sympy.diff`
- [ ] Derivadas de orden superior
- [ ] Máximos y mínimos (puntos críticos)
- [ ] Gradient Descent simplificado en Python
- [ ] Preview: derivadas parciales

---

## Módulo 05 — Estadística y Probabilidad (`05_EstadisticaYProbabilidad/`)
**Librerías:** `numpy`, `scipy`, `matplotlib`

- [ ] Media, mediana, moda (`np.mean`, `np.median`, `scipy.stats.mode`)
- [ ] Varianza y desvío estándar (`np.var`, `np.std`)
- [ ] Percentiles y cuartiles, detección de outliers con IQR
- [ ] Probabilidad básica, complementaria, condicional
- [ ] Simulación Monte Carlo
- [ ] Distribución normal: `scipy.stats.norm`, CDF, PPF
- [ ] Z-score y estandarización

---

## Módulo 06 — Matemática Discreta (`06_MatematicaDiscreta/`)
**Librerías:** Python puro, `itertools`, `math`

- [ ] Lógica proposicional: AND, OR, NOT, XOR, implicación
- [ ] Tablas de verdad
- [ ] Leyes de De Morgan (aplicación en código)
- [ ] Conjuntos con `set`: unión, intersección, diferencia
- [ ] Comprensiones de conjuntos
- [ ] Factorial, permutaciones, combinaciones (`math.perm`, `math.comb`)
- [ ] Producto cartesiano (`itertools.product`)
- [ ] Recursión: factorial y Fibonacci, memoización

---

## Instalación de librerías

```bash
pip install numpy sympy matplotlib scipy
```

---

## Ejercicios Completados

| # | Módulo | Ejercicio | Fecha | Notas |
|---|--------|-----------|-------|-------|
|   |        |           |       |       |

---

## Errores Comunes

- Los floats NO se comparan con `==`, usar `math.isclose()`
- `*` en NumPy es producto elemento a elemento, `@` es producto matricial
- `Fraction(0.1)` muestra que 0.1 no es exacto en binario
- En sympy, `diff(f, x, 2)` es la segunda derivada (no `diff(diff(f))`)

---

## Recursos

- [SymPy docs](https://docs.sympy.org)
- [NumPy docs](https://numpy.org/doc)
- [SciPy stats](https://docs.scipy.org/doc/scipy/reference/stats.html)
- [3Blue1Brown — Essence of Linear Algebra](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
- [3Blue1Brown — Essence of Calculus](https://www.youtube.com/playlist?list=PLZHQObOWTQDMsr9K-rj53DwVRMYO3t5Yr)
