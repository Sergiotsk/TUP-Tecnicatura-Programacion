"""
MÓDULO 02: Álgebra — Ecuaciones y Funciones
PROYECTO: Matemática con Python
LIBRERÍAS: sympy (matemática simbólica — pip install sympy)

=== ¿QUÉ APRENDO DE MATEMÁTICA? ===
- Ecuaciones de 1° grado (lineales): ax + b = 0
- Ecuaciones de 2° grado (cuadráticas): ax² + bx + c = 0
- Sistemas de ecuaciones lineales (2 ecuaciones, 2 incógnitas)
- Funciones: concepto, dominio, imagen, evaluación

=== ¿QUÉ APRENDO DE PYTHON? ===
- Librería sympy: matemática simbólica en Python
  - symbols(): crear variables simbólicas (como "x" en álgebra)
  - solve(): resolver ecuaciones
  - Eq(): definir una ecuación
  - expand(), factor(), simplify(): manipulación algebraica
- Funciones de Python como representación de funciones matemáticas
- Comprensión de listas para evaluar funciones en un rango

INSTALACIÓN:
  pip install sympy
"""

from sympy import symbols, solve, Eq, expand, factor, simplify, sqrt, Rational
from sympy import Function, plot as sym_plot


# ============================================================
# SECCIÓN 1: Variables simbólicas — qué es sympy
# ============================================================

def seccion_intro_sympy():
    print("=" * 60)
    print("SECCIÓN 1: Introducción a SymPy")
    print("=" * 60)

    print("En álgebra trabajamos con letras (incógnitas) que representan números.")
    print("SymPy permite hacer lo mismo en Python: definir variables simbólicas")
    print("y operar con ellas como si fueran una calculadora algebraica.")
    print()

    # Crear variable simbólica
    x = symbols('x')

    # Expresiones simbólicas
    expr = 3*x + 5
    print(f"x = symbols('x')   → crea la variable simbólica x")
    print(f"expr = 3*x + 5     → {expr}  (no calcula, guarda la expresión)")
    print(f"expr con x=2       → {expr.subs(x, 2)}  (sustituye x por 2)")
    print(f"expr con x=0       → {expr.subs(x, 0)}  (sustituye x por 0)")
    print()

    # Manipulación algebraica
    expr2 = (x + 1) * (x - 1)
    print(f"(x+1)(x-1)         → {expr2}  (guardado sin expandir)")
    print(f"expand(...)        → {expand(expr2)}  (distribuye: x²-1)")
    print(f"factor(x**2 - 1)   → {factor(x**2 - 1)}  (factoriza)")
    print()
    print("¡SymPy sabe álgebra! La diferencia de cuadrados: (a+b)(a-b) = a²-b²")


# ============================================================
# SECCIÓN 2: Ecuaciones de 1° grado
# ============================================================

def seccion_ecuaciones_lineales():
    print("\n" + "=" * 60)
    print("SECCIÓN 2: Ecuaciones de 1° Grado (Lineales)")
    print("=" * 60)

    x = symbols('x')

    print("Una ecuación lineal tiene la forma: ax + b = 0")
    print("Se resuelve despejando x: x = -b/a")
    print()

    # Ejemplo 1: ecuación simple
    ecuacion1 = Eq(3*x + 9, 0)
    solucion1 = solve(ecuacion1, x)
    print(f"Ecuación: 3x + 9 = 0")
    print(f"Solución: x = {solucion1[0]}")
    print(f"Verificación: 3*({solucion1[0]}) + 9 = {3*solucion1[0] + 9}")
    print()

    # Ejemplo 2: con términos a ambos lados
    ecuacion2 = Eq(2*x - 5, 3*x + 1)
    solucion2 = solve(ecuacion2, x)
    print(f"Ecuación: 2x - 5 = 3x + 1")
    print(f"  Paso 1: 2x - 3x = 1 + 5  → -x = 6  → x = -6")
    print(f"  SymPy:  x = {solucion2[0]}")
    print()

    # Ejemplo 3: problema de texto → ecuación
    print("Ejemplo 3 — Problema en palabras:")
    print("  'El triple de un número más 8 es igual al doble de ese número menos 4.'")
    print("  Si llamamos 'x' al número: 3x + 8 = 2x - 4")
    ecuacion3 = Eq(3*x + 8, 2*x - 4)
    solucion3 = solve(ecuacion3, x)
    print(f"  Solución: x = {solucion3[0]}")
    print()

    # EJERCICIO: Resolver: 5(x - 2) = 3(x + 4) - 2
    # Tip: sympy maneja el expand automáticamente
    # ecuacion_ej = Eq(5*(x-2), 3*(x+4) - 2)
    # print(f"Ejercicio: x = {solve(ecuacion_ej, x)}")


# ============================================================
# SECCIÓN 3: Ecuaciones de 2° grado
# ============================================================

def seccion_ecuaciones_cuadraticas():
    print("\n" + "=" * 60)
    print("SECCIÓN 3: Ecuaciones de 2° Grado (Cuadráticas)")
    print("=" * 60)

    x = symbols('x')

    print("Una ecuación cuadrática: ax² + bx + c = 0")
    print("Solución: x = (-b ± √(b²-4ac)) / 2a  ← fórmula cuadrática")
    print("El discriminante Δ = b²-4ac determina cuántas soluciones hay:")
    print("  Δ > 0 → 2 soluciones reales")
    print("  Δ = 0 → 1 solución (raíz doble)")
    print("  Δ < 0 → sin soluciones reales (soluciones complejas)")
    print()

    # La fórmula cuadrática implementada manualmente
    def formula_cuadratica(a, b, c):
        discriminante = b**2 - 4*a*c
        if discriminante > 0:
            x1 = (-b + discriminante**0.5) / (2*a)
            x2 = (-b - discriminante**0.5) / (2*a)
            return x1, x2
        elif discriminante == 0:
            x1 = -b / (2*a)
            return (x1,)
        else:
            return ()  # Sin soluciones reales

    # Ejemplo 1: x² - 5x + 6 = 0  → (x-2)(x-3) = 0  → x=2, x=3
    a, b, c = 1, -5, 6
    ecuacion1 = Eq(x**2 - 5*x + 6, 0)
    sol_manual = formula_cuadratica(a, b, c)
    sol_sympy = solve(ecuacion1, x)
    print(f"Ecuación: x² - 5x + 6 = 0")
    print(f"  Discriminante: {b}² - 4*{a}*{c} = {b**2 - 4*a*c}")
    print(f"  Solución (fórmula manual): x = {sol_manual}")
    print(f"  Solución (SymPy):          x = {sol_sympy}")
    print(f"  Factorización: {factor(x**2 - 5*x + 6)}")
    print()

    # Ejemplo 2: raíz doble
    ecuacion2 = Eq(x**2 - 4*x + 4, 0)
    print(f"Ecuación: x² - 4x + 4 = 0")
    print(f"  Discriminante: (-4)² - 4*4 = {(-4)**2 - 4*4}  → raíz doble")
    print(f"  Solución: x = {solve(ecuacion2, x)}")
    print(f"  Factorización: {factor(x**2 - 4*x + 4)}")
    print()

    # EJERCICIO: Resolver x² + x - 6 = 0
    # Tip: factorizá mentalmente primero, luego verificá con SymPy
    # ecuacion_ej = Eq(x**2 + x - 6, 0)
    # print(f"Ejercicio: {solve(ecuacion_ej, x)}")


# ============================================================
# SECCIÓN 4: Sistemas de ecuaciones
# ============================================================

def seccion_sistemas():
    print("\n" + "=" * 60)
    print("SECCIÓN 4: Sistemas de Ecuaciones")
    print("=" * 60)

    x, y = symbols('x y')

    print("Un sistema 2x2: dos ecuaciones, dos incógnitas.")
    print("Se puede resolver por sustitución, eliminación, o con SymPy.")
    print()

    # Sistema 1: solución única
    sistema1 = [
        Eq(2*x + y, 7),
        Eq(x - y, 2)
    ]
    solucion1 = solve(sistema1, [x, y])
    print("Sistema 1:")
    print("  2x + y = 7")
    print("  x  - y = 2")
    print(f"  Solución: x={solucion1[x]}, y={solucion1[y]}")
    print()

    # Verificación
    print("  Verificación:")
    print(f"  2*{solucion1[x]} + {solucion1[y]} = {2*solucion1[x] + solucion1[y]}  (debe ser 7)")
    print(f"  {solucion1[x]} - {solucion1[y]} = {solucion1[x] - solucion1[y]}    (debe ser 2)")
    print()

    # Sistema 2 — aplicación: problema de texto
    print("Sistema 2 — Problema en palabras:")
    print("  'Tengo 10 monedas entre monedas de $5 y de $10. En total son $75.'")
    print("  Sea x = monedas de $5, y = monedas de $10:")
    print("  x + y = 10")
    print("  5x + 10y = 75")

    m5, m10 = symbols('m5 m10')
    sistema2 = [
        Eq(m5 + m10, 10),
        Eq(5*m5 + 10*m10, 75)
    ]
    sol2 = solve(sistema2, [m5, m10])
    print(f"  Solución: {sol2[m5]} monedas de $5 y {sol2[m10]} monedas de $10")


# ============================================================
# SECCIÓN 5: Funciones matemáticas en Python
# ============================================================

def seccion_funciones():
    print("\n" + "=" * 60)
    print("SECCIÓN 5: Funciones Matemáticas")
    print("=" * 60)

    print("Una función f(x) asocia a cada valor de x un único valor de f(x).")
    print("En Python, una función matemática se puede representar con def:")
    print()

    # Función lineal f(x) = 2x + 1
    def f_lineal(x):
        return 2 * x + 1

    print("Función lineal: f(x) = 2x + 1")
    for val in [-3, -1, 0, 1, 3, 5]:
        print(f"  f({val:2}) = {f_lineal(val):4}")
    print()

    # Función cuadrática g(x) = x² - 4
    def g_cuadratica(x):
        return x**2 - 4

    print("Función cuadrática: g(x) = x² - 4")
    for val in [-3, -2, -1, 0, 1, 2, 3]:
        print(f"  g({val:2}) = {g_cuadratica(val):4}")
    print()

    # Composición de funciones: h(x) = f(g(x))
    def h_compuesta(x):
        return f_lineal(g_cuadratica(x))

    print("Composición h(x) = f(g(x)) = 2(x²-4) + 1 = 2x² - 7")
    print(f"  h(0) = f(g(0)) = f({g_cuadratica(0)}) = {h_compuesta(0)}")
    print(f"  h(3) = f(g(3)) = f({g_cuadratica(3)}) = {h_compuesta(3)}")
    print()

    # Evaluación en un rango — listas por comprensión
    xs = list(range(-5, 6))
    ys = [f_lineal(x) for x in xs]
    print("Evaluación de f(x)=2x+1 en [-5, 5] (lista por comprensión):")
    print(f"  x:    {xs}")
    print(f"  f(x): {ys}")
    print()
    print("Las listas por comprensión [f(x) for x in xs] son una forma")
    print("muy pythónica de evaluar una función en un conjunto de valores.")


# ============================================================
# MAIN
# ============================================================

def main():
    print("\n" + "#" * 60)
    print("  MÓDULO 02: ÁLGEBRA Y ECUACIONES CON PYTHON")
    print("#" * 60)

    seccion_intro_sympy()
    seccion_ecuaciones_lineales()
    seccion_ecuaciones_cuadraticas()
    seccion_sistemas()
    seccion_funciones()

    print("\n" + "=" * 60)
    print("FIN DEL MÓDULO 02")
    print("Siguiente: 03_AlgebraLineal/vectores_y_matrices.py")
    print("=" * 60)


if __name__ == "__main__":
    main()
