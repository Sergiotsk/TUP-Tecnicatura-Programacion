"""
MÓDULO 04: Cálculo — Límites y Derivadas
PROYECTO: Matemática con Python
LIBRERÍAS: sympy, numpy, matplotlib

=== ¿QUÉ APRENDO DE MATEMÁTICA? ===
- Concepto de límite (intuitivo, no formal)
- Derivada: qué es, para qué sirve, reglas básicas
- Derivadas en puntos: la pendiente en un punto de la curva
- Máximos y mínimos (optimización)
- Conexión con algoritmos: gradient descent (Machine Learning)

=== ¿QUÉ APRENDO DE PYTHON? ===
- sympy: derivadas simbólicas (diff), límites (limit), sustitución (subs)
- numpy: aproximación numérica de derivadas
- matplotlib: graficar funciones y sus derivadas
- Tuplas en Python

INSTALACIÓN:
  pip install sympy numpy matplotlib
"""

import numpy as np
from sympy import symbols, diff, limit, oo, sin, cos, exp, ln, sqrt
from sympy import Rational, pi, simplify, factor, expand


# ============================================================
# SECCIÓN 1: Límites (intuición)
# ============================================================

def seccion_limites():
    print("=" * 60)
    print("SECCIÓN 1: Límites")
    print("=" * 60)

    print("Un límite responde: ¿hacia qué valor se acerca f(x) cuando x → a?")
    print("No importa qué pasa EN x=a, sino QUÉ PASA CERCA de a.")
    print()

    x = symbols('x')

    # Límite sencillo
    f1 = 2*x + 3
    lim1 = limit(f1, x, 4)
    print(f"lim(x→4) de 2x+3 = {lim1}  (simplemente sustituís: 2*4+3=11)")
    print()

    # Límite indeterminado — la forma clásica 0/0
    print("El caso interesante: forma indeterminada 0/0")
    print()
    f2 = (x**2 - 1) / (x - 1)
    print(f"f(x) = (x²-1)/(x-1)")
    print(f"  Si x=1: f(1) = 0/0  → no está definida (división por cero)")
    print(f"  Pero podemos factorizar: (x²-1) = (x+1)(x-1)")
    print(f"  Entonces: (x+1)(x-1)/(x-1) = x+1 (para x≠1)")
    lim2 = limit(f2, x, 1)
    print(f"  lim(x→1) = {lim2}  (sympy lo resuelve automáticamente)")
    print()

    # Límite al infinito
    f3 = (3*x**2 + 2*x) / (x**2 - 5)
    lim3 = limit(f3, x, oo)
    print(f"lim(x→∞) de (3x²+2x)/(x²-5) = {lim3}")
    print("  Cuando x→∞, dominan los términos de mayor grado: 3x²/x² = 3")
    print()

    # Límite fundamental: seno/x
    f4 = sin(x) / x
    lim4 = limit(f4, x, 0)
    print(f"lim(x→0) de sen(x)/x = {lim4}  (límite fundamental del cálculo)")


# ============================================================
# SECCIÓN 2: La derivada — concepto
# ============================================================

def seccion_concepto_derivada():
    print("\n" + "=" * 60)
    print("SECCIÓN 2: Concepto de Derivada")
    print("=" * 60)

    print("La derivada f'(x) mide la TASA DE CAMBIO de f(x).")
    print("Geométricamente: es la PENDIENTE de la recta tangente en cada punto.")
    print()
    print("¿Para qué sirve?")
    print("  - Optimización: encontrar mínimos y máximos")
    print("  - Velocidad/Aceleración (la derivada de la posición es la velocidad)")
    print("  - Machine Learning: el Gradient Descent usa derivadas para entrenar modelos")
    print("  - Economía: costo marginal, ingreso marginal")
    print()

    # Aproximación numérica de la derivada (diferencias finitas)
    print("Aproximación numérica de la derivada (cómo la calcula la computadora):")
    print("  f'(x) ≈ [f(x+h) - f(x)] / h  para h muy pequeño")
    print()

    def f(x):
        return x**2

    def derivada_numerica(f, x, h=1e-7):
        return (f(x + h) - f(x)) / h

    print("f(x) = x²  →  f'(x) = 2x  (exacta)")
    for punto in [0, 1, 2, 3, -2]:
        aprox = derivada_numerica(f, punto)
        exacta = 2 * punto
        print(f"  f'({punto}): exacta={exacta},  numérica≈{aprox:.6f}")
    print()
    print("Las librerías de Deep Learning (PyTorch, TensorFlow) hacen esto")
    print("en millones de parámetros para entrenar redes neuronales.")


# ============================================================
# SECCIÓN 3: Derivadas simbólicas con SymPy
# ============================================================

def seccion_derivadas_sympy():
    print("\n" + "=" * 60)
    print("SECCIÓN 3: Derivadas Simbólicas con SymPy")
    print("=" * 60)

    x = symbols('x')

    print("Reglas básicas de derivación:")
    print()

    # Regla de la potencia: d/dx(x^n) = n*x^(n-1)
    f1 = x**5
    df1 = diff(f1, x)
    print(f"Regla de la potencia: d/dx(x⁵) = {df1}")
    print(f"  Regla: d/dx(xⁿ) = n·xⁿ⁻¹  →  5x⁴")
    print()

    # Constante
    f2 = 7 * x**3
    df2 = diff(f2, x)
    print(f"Constante por función: d/dx(7x³) = {df2}")
    print()

    # Suma de funciones
    f3 = x**3 - 4*x**2 + 2*x - 8
    df3 = diff(f3, x)
    print(f"Suma: d/dx(x³ - 4x² + 2x - 8) = {df3}")
    print()

    # Funciones trigonométricas
    f4 = sin(x)
    f5 = cos(x)
    print(f"d/dx(sin(x)) = {diff(f4, x)}")
    print(f"d/dx(cos(x)) = {diff(f5, x)}")
    print()

    # Función exponencial y logaritmo
    f6 = exp(x)
    f7 = ln(x)
    print(f"d/dx(eˣ)    = {diff(f6, x)}  (eˣ es su propia derivada — propiedad única)")
    print(f"d/dx(ln(x)) = {diff(f7, x)}")
    print()

    # Regla de la cadena
    f8 = sin(x**2)
    df8 = diff(f8, x)
    print(f"Regla de la cadena: d/dx(sin(x²)) = {df8}")
    print(f"  d/dx(sin(u)) = cos(u)·u'  donde u=x², u'=2x")
    print()

    # Derivadas de orden superior
    g = x**4 - 3*x**3 + 2
    dg1 = diff(g, x)           # Primera derivada
    dg2 = diff(g, x, 2)        # Segunda derivada
    dg3 = diff(g, x, 3)        # Tercera derivada
    print(f"g(x) = x⁴ - 3x³ + 2")
    print(f"g'(x)   = {dg1}")
    print(f"g''(x)  = {dg2}")
    print(f"g'''(x) = {dg3}")


# ============================================================
# SECCIÓN 4: Máximos y mínimos (optimización)
# ============================================================

def seccion_optimizacion():
    print("\n" + "=" * 60)
    print("SECCIÓN 4: Máximos y Mínimos — Optimización")
    print("=" * 60)

    x = symbols('x')

    print("Los máximos y mínimos de f(x) ocurren donde f'(x) = 0.")
    print("Si f''(x) > 0 en ese punto → mínimo local")
    print("Si f''(x) < 0 en ese punto → máximo local")
    print()

    # Función con mínimo y máximo
    f = x**3 - 6*x**2 + 9*x + 1
    df = diff(f, x)
    d2f = diff(f, x, 2)

    print(f"f(x) = x³ - 6x² + 9x + 1")
    print(f"f'(x) = {df}")
    print(f"f''(x) = {d2f}")
    print()

    # Encontrar puntos críticos (donde f'=0)
    from sympy import solve
    puntos_criticos = solve(df, x)
    print(f"Puntos críticos (f'=0): x = {puntos_criticos}")
    print()

    for pc in puntos_criticos:
        valor_f = f.subs(x, pc)
        valor_d2f = d2f.subs(x, pc)
        tipo = "mínimo local" if valor_d2f > 0 else "máximo local"
        print(f"  x = {pc}: f({pc}) = {valor_f}, f''({pc}) = {valor_d2f} → {tipo}")
    print()

    # Conexión con Machine Learning
    print("Conexión con Machine Learning — Gradient Descent:")
    print()
    print("  El Gradient Descent es básicamente: encontrar el mínimo de una función")
    print("  de error (loss function) actualizando los parámetros del modelo:")
    print()
    print("    parámetro = parámetro - learning_rate * derivada")
    print()
    print("  Ejemplo simplificado (minimizar f(x) = x² con Gradient Descent):")

    def gradient_descent_demo(x_inicio, learning_rate, iteraciones):
        x_val = x_inicio
        print(f"  Inicio: x = {x_val:.4f}")
        for i in range(iteraciones):
            gradiente = 2 * x_val    # derivada de x² es 2x
            x_val = x_val - learning_rate * gradiente
            if i < 5 or i == iteraciones - 1:
                print(f"  Iter {i+1:3}: x = {x_val:.6f}, f(x) = {x_val**2:.8f}")
        print(f"  Mínimo encontrado: x ≈ {x_val:.8f}  (el mínimo real de x² es x=0)")

    gradient_descent_demo(x_inicio=5.0, learning_rate=0.1, iteraciones=30)


# ============================================================
# SECCIÓN 5: Derivadas parciales (preview de cálculo multivariable)
# ============================================================

def seccion_derivadas_parciales():
    print("\n" + "=" * 60)
    print("SECCIÓN 5: Preview — Derivadas Parciales")
    print("=" * 60)

    x, y = symbols('x y')

    print("Si una función tiene múltiples variables f(x,y,...), se calculan")
    print("las derivadas parciales: ∂f/∂x (derivar respecto a x, y constante)")
    print("y ∂f/∂y (derivar respecto a y, x constante).")
    print()

    f = x**2 + 3*x*y + y**2

    df_dx = diff(f, x)   # Derivada parcial respecto a x
    df_dy = diff(f, y)   # Derivada parcial respecto a y

    print(f"f(x,y) = x² + 3xy + y²")
    print(f"∂f/∂x = {df_dx}  (y se trata como constante)")
    print(f"∂f/∂y = {df_dy}  (x se trata como constante)")
    print()
    print("El gradiente ∇f = (∂f/∂x, ∂f/∂y) es un vector que apunta en la")
    print("dirección de mayor crecimiento de f. El Gradient Descent va en")
    print("la dirección OPUESTA para encontrar el mínimo.")
    print()
    print("En una red neuronal con millones de parámetros, se calcula")
    print("el gradiente respecto a todos ellos. A eso se llama backpropagation.")


# ============================================================
# MAIN
# ============================================================

def main():
    print("\n" + "#" * 60)
    print("  MÓDULO 04: CÁLCULO — LÍMITES Y DERIVADAS CON PYTHON")
    print("#" * 60)

    seccion_limites()
    seccion_concepto_derivada()
    seccion_derivadas_sympy()
    seccion_optimizacion()
    seccion_derivadas_parciales()

    print("\n" + "=" * 60)
    print("FIN DEL MÓDULO 04")
    print("Siguiente: 05_EstadisticaYProbabilidad/estadistica_descriptiva.py")
    print("=" * 60)


if __name__ == "__main__":
    main()
