"""
MÓDULO 01: Aritmética Básica
PROYECTO: Matemática con Python
LIBRERÍAS: math, fractions, decimal (todas de la librería estándar, sin instalar nada)

=== ¿QUÉ APRENDO DE MATEMÁTICA? ===
- Operaciones básicas y su jerarquía (PEMDAS/BODMAS)
- Fracciones y números racionales
- Potencias y raíces
- Porcentajes
- Notación científica
- El problema de la precisión en punto flotante (¡trampa famosa!)

=== ¿QUÉ APRENDO DE PYTHON? ===
- Tipos numéricos: int, float, complex
- Operadores: +, -, *, /, //, %, **
- Módulo `math`: funciones matemáticas estándar
- Clase `Fraction`: fracciones exactas sin error de redondeo
- Clase `Decimal`: precisión controlada
- f-strings para mostrar resultados con formato

=== EJERCICIOS AL FINAL DE CADA SECCIÓN ===
Buscá los comentarios marcados con # EJERCICIO:
"""

import math
from fractions import Fraction
from decimal import Decimal, getcontext


# ============================================================
# SECCIÓN 1: Operadores aritméticos en Python
# ============================================================

def seccion_operadores():
    print("=" * 60)
    print("SECCIÓN 1: Operadores Aritméticos")
    print("=" * 60)

    a = 17
    b = 5

    print(f"a = {a}, b = {b}")
    print(f"Suma:              a + b  = {a + b}")
    print(f"Resta:             a - b  = {a - b}")
    print(f"Multiplicación:    a * b  = {a * b}")
    print(f"División real:     a / b  = {a / b}")       # Siempre da float
    print(f"División entera:   a // b = {a // b}")      # Cociente sin resto
    print(f"Módulo (resto):    a % b  = {a % b}")       # El resto de la división
    print(f"Potencia:          a ** b = {a ** b}")      # 17^5

    print()
    print("--- Jerarquía de operaciones (PEMDAS) ---")
    # Paréntesis → Exponentes → Mult/Div → Suma/Resta
    expr1 = 2 + 3 * 4        # Primero la multiplicación
    expr2 = (2 + 3) * 4      # Primero el paréntesis
    expr3 = 2 ** 3 ** 2      # Las potencias se evalúan de derecha a izquierda: 2^(3^2) = 2^9
    print(f"2 + 3 * 4   = {expr1}   (no es 20, es 14 — primero se multiplica)")
    print(f"(2 + 3) * 4 = {expr2}   (ahora sí es 20 — el paréntesis fuerza el orden)")
    print(f"2 ** 3 ** 2 = {expr3}  (es 2^9=512, no (2^3)^2=64 — las potencias van de derecha a izquierda)")

    print()
    # EJERCICIO 1: ¿Qué da esto sin calculadora? Luego verificá con Python.
    # resultado = 100 - 4 * (3 + 2) ** 2 / 5
    # EJERCICIO: descomentá la línea de abajo y corré el script.
    # print(f"100 - 4 * (3 + 2) ** 2 / 5 = {100 - 4 * (3 + 2) ** 2 / 5}")


# ============================================================
# SECCIÓN 2: El problema del punto flotante (¡importante!)
# ============================================================

def seccion_punto_flotante():
    print("\n" + "=" * 60)
    print("SECCIÓN 2: El Problema del Punto Flotante")
    print("=" * 60)

    print("Los float tienen precisión limitada (64 bits según IEEE 754).")
    print("Esto genera errores de redondeo que parecen raros:")
    print()

    # El clásico ejemplo
    resultado = 0.1 + 0.2
    print(f"0.1 + 0.2 = {resultado}")                    # No da 0.3!
    print(f"0.1 + 0.2 == 0.3 → {0.1 + 0.2 == 0.3}")    # False!
    print()

    print("¿Por qué pasa esto?")
    print("  0.1 en binario es 0.00011001100110011... (infinito repetido)")
    print("  La computadora lo redondea, y el error se acumula.")
    print()

    print("Solución 1: round() para mostrar resultados")
    print(f"  round(0.1 + 0.2, 10) = {round(0.1 + 0.2, 10)}")
    print()

    print("Solución 2: Usar Decimal para precisión exacta")
    getcontext().prec = 28  # 28 dígitos de precisión
    d1 = Decimal("0.1")
    d2 = Decimal("0.2")
    print(f"  Decimal('0.1') + Decimal('0.2') = {d1 + d2}")
    print()

    print("Solución 3: Usar math.isclose() para comparar floats")
    print(f"  math.isclose(0.1 + 0.2, 0.3) → {math.isclose(0.1 + 0.2, 0.3)}")
    print("  Nunca compares floats con ==, usá math.isclose()")


# ============================================================
# SECCIÓN 3: Fracciones exactas con Fraction
# ============================================================

def seccion_fracciones():
    print("\n" + "=" * 60)
    print("SECCIÓN 3: Fracciones con la clase Fraction")
    print("=" * 60)

    print("Repaso: una fracción a/b tiene numerador 'a' y denominador 'b'.")
    print("Python tiene la clase Fraction que maneja fracciones sin error de redondeo.")
    print()

    # Crear fracciones
    f1 = Fraction(1, 3)    # 1/3
    f2 = Fraction(1, 6)    # 1/6
    f3 = Fraction(3, 4)    # 3/4

    print(f"f1 = {f1}  (1/3)")
    print(f"f2 = {f2}  (1/6)")
    print(f"f3 = {f3}  (3/4)")
    print()

    print("Operaciones:")
    print(f"  f1 + f2 = {f1 + f2}   (1/3 + 1/6 = 2/6 + 1/6 = 3/6 = 1/2)")
    print(f"  f1 - f2 = {f1 - f2}   (1/3 - 1/6 = 2/6 - 1/6 = 1/6)")
    print(f"  f1 * f3 = {f1 * f3}   (1/3 * 3/4 = 3/12 = 1/4)")
    print(f"  f1 / f3 = {f1 / f3}   (1/3 ÷ 3/4 = 1/3 * 4/3 = 4/9)")
    print()

    print("Fraction se simplifica automáticamente:")
    print(f"  Fraction(6, 8) = {Fraction(6, 8)}  (simplifica a 3/4)")
    print(f"  Fraction(10, 4) = {Fraction(10, 4)}  (simplifica a 5/2)")
    print()

    print("Convertir float a fracción (útil para entender el error de punto flotante):")
    print(f"  Fraction(0.1) = {Fraction(0.1)}")
    print("  ¡Ese numerador enorme explica el error! 0.1 no se representa exacto en binario.")

    # EJERCICIO: ¿Cuánto es 2/3 + 5/9 - 1/6? Calculalo a mano y verificá:
    # print(f"  2/3 + 5/9 - 1/6 = {Fraction(2,3) + Fraction(5,9) - Fraction(1,6)}")


# ============================================================
# SECCIÓN 4: Potencias y raíces con el módulo math
# ============================================================

def seccion_potencias_y_raices():
    print("\n" + "=" * 60)
    print("SECCIÓN 4: Potencias y Raíces — módulo math")
    print("=" * 60)

    print("Potencias: base ** exponente")
    print(f"  2**10  = {2**10}   (2 elevado a la 10 = 1024, la base de la informática)")
    print(f"  10**3  = {10**3}   (10^3 = 1000 = 1 kilo)")
    print(f"  2**8   = {2**8}   (un byte = 8 bits = 256 valores posibles)")
    print()

    print("Raíces: son potencias fraccionarias")
    print(f"  √9     = 9**0.5  = {9**0.5}   (raíz cuadrada)")
    print(f"  ∛27    = 27**(1/3) = {27**(1/3):.6f}  (raíz cúbica)")
    print()

    print("Módulo math — funciones matemáticas estándar:")
    print(f"  math.sqrt(144)   = {math.sqrt(144)}   (raíz cuadrada, más legible que **0.5)")
    print(f"  math.pow(2, 10)  = {math.pow(2, 10)}  (2^10, siempre devuelve float)")
    print(f"  math.log(100)    = {math.log(100):.6f}  (logaritmo natural, base e)")
    print(f"  math.log(100, 10)= {math.log(100, 10)}    (logaritmo base 10)")
    print(f"  math.log2(1024)  = {math.log2(1024)}   (logaritmo base 2 — útil en algoritmos)")
    print()

    print("Constantes matemáticas:")
    print(f"  math.pi  = {math.pi:.10f}  (π)")
    print(f"  math.e   = {math.e:.10f}  (número de Euler, base del logaritmo natural)")
    print(f"  math.tau = {math.tau:.10f}  (τ = 2π)")
    print()

    print("Funciones de redondeo:")
    x = 3.7
    print(f"  x = {x}")
    print(f"  math.floor({x}) = {math.floor(x)}   (piso: redondea hacia abajo)")
    print(f"  math.ceil({x})  = {math.ceil(x)}    (techo: redondea hacia arriba)")
    print(f"  round({x})      = {round(x)}    (redondeo normal)")
    print(f"  round({x}, 0)   = {round(x, 0)}  (redondeo a N decimales)")

    # EJERCICIO: La hipotenusa de un triángulo rectángulo con catetos 3 y 4 es:
    # h = math.sqrt(3**2 + 4**2)
    # print(f"  Hipotenusa (3,4): {h}")


# ============================================================
# SECCIÓN 5: Porcentajes — aplicación práctica
# ============================================================

def seccion_porcentajes():
    print("\n" + "=" * 60)
    print("SECCIÓN 5: Porcentajes")
    print("=" * 60)

    print("Un porcentaje es una fracción con denominador 100.")
    print("  30% = 30/100 = 0.30")
    print()

    precio_original = 15000
    descuento_pct = 25       # 25%
    iva_pct = 21             # 21%

    # Calcular descuento
    descuento = precio_original * (descuento_pct / 100)
    precio_con_descuento = precio_original - descuento
    print(f"Precio original: ${precio_original:,.2f}")
    print(f"Descuento {descuento_pct}%:   ${descuento:,.2f}")
    print(f"Precio con descuento: ${precio_con_descuento:,.2f}")
    print()

    # Aplicar IVA
    iva = precio_con_descuento * (iva_pct / 100)
    precio_final = precio_con_descuento + iva
    print(f"IVA ({iva_pct}%) sobre precio con descuento: ${iva:,.2f}")
    print(f"Precio final: ${precio_final:,.2f}")
    print()

    # Calcular qué porcentaje es A de B
    parcial = 340
    total = 800
    porcentaje = (parcial / total) * 100
    print(f"¿Qué porcentaje es {parcial} de {total}?")
    print(f"  ({parcial} / {total}) * 100 = {porcentaje:.2f}%")
    print()

    # Variación porcentual (muy usado en estadística y finanzas)
    valor_inicial = 250
    valor_final = 310
    variacion = ((valor_final - valor_inicial) / valor_inicial) * 100
    print(f"Variación porcentual de {valor_inicial} a {valor_final}:")
    print(f"  ((310 - 250) / 250) * 100 = {variacion:.2f}%")

    # EJERCICIO: Si un producto cuesta $4500 y tiene 18% de descuento y luego 10.5% de IVA,
    # ¿cuál es el precio final? Implementalo acá:
    # precio = 4500
    # descuento = ...
    # ...


# ============================================================
# SECCIÓN 6: Notación científica y números grandes
# ============================================================

def seccion_notacion_cientifica():
    print("\n" + "=" * 60)
    print("SECCIÓN 6: Notación Científica y Números Grandes")
    print("=" * 60)

    print("Python maneja enteros de tamaño arbitrario (a diferencia de C/C++).")
    print()

    # Python maneja enteros enormes sin overflow
    factorial_20 = math.factorial(20)
    print(f"20! = {factorial_20}")
    print(f"    = {factorial_20:.4e}  (notación científica)")
    print()

    # Números en notación científica
    velocidad_luz = 3e8          # 3 × 10^8 m/s
    masa_electron = 9.11e-31     # 9.11 × 10^-31 kg
    print(f"Velocidad de la luz: {velocidad_luz:.2e} m/s")
    print(f"Masa del electrón:   {masa_electron:.2e} kg")
    print()

    # Prefijos del sistema internacional (útiles para informática)
    kilo = 1e3
    mega = 1e6
    giga = 1e9
    tera = 1e12
    print("Prefijos del SI (base 10 — usados en disco duro, velocidad de red):")
    print(f"  1 KB = {kilo:,.0f} bytes")
    print(f"  1 MB = {mega:,.0f} bytes")
    print(f"  1 GB = {giga:,.0f} bytes")
    print(f"  1 TB = {tera:,.0f} bytes")
    print()

    # Diferencia entre base 10 y base 2 en informática
    gib = 2**30
    print("Pero en RAM, los fabricantes usan base 2 (IEC):")
    print(f"  1 GiB = 2^30 = {gib:,} bytes ≠ 1,000,000,000")
    print("  Por eso 1GB de RAM en el SO aparece como ~0.93 GB.")


# ============================================================
# MAIN — ejecutar todo en orden
# ============================================================

def main():
    print("\n" + "#" * 60)
    print("  MÓDULO 01: ARITMÉTICA BÁSICA CON PYTHON")
    print("#" * 60)

    seccion_operadores()
    seccion_punto_flotante()
    seccion_fracciones()
    seccion_potencias_y_raices()
    seccion_porcentajes()
    seccion_notacion_cientifica()

    print("\n" + "=" * 60)
    print("FIN DEL MÓDULO 01")
    print("Siguiente: 02_Algebra/ecuaciones_lineales.py")
    print("=" * 60)


if __name__ == "__main__":
    main()
