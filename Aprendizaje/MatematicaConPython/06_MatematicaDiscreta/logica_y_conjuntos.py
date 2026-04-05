"""
MÓDULO 06: Matemática Discreta — Lógica y Conjuntos
PROYECTO: Matemática con Python
LIBRERÍAS: Python puro (set, frozenset), itertools, math

=== ¿QUÉ APRENDO DE MATEMÁTICA? ===
- Lógica proposicional: AND, OR, NOT, XOR, implicación
- Tablas de verdad
- Teoría de conjuntos: unión, intersección, diferencia, complemento
- Combinatoria: permutaciones, combinaciones, factorial
- Relación con algoritmos y estructuras de datos

=== ¿QUÉ APRENDO DE PYTHON? ===
- Operadores booleanos (and, or, not) y sus equivalentes bit a bit (&, |, ^, ~)
- Tipo `set` y `frozenset`: conjuntos en Python
  - Operaciones: | (unión), & (intersección), - (diferencia), ^ (diferencia simétrica)
- Módulo `itertools`: permutaciones, combinaciones, producto cartesiano
- Módulo `math`: factorial, combinatoria
- Comprensiones de conjuntos {x for x in ...}

Sin instalaciones adicionales — todo usa la librería estándar de Python.
"""

import math
import itertools
from functools import reduce


# ============================================================
# SECCIÓN 1: Lógica Proposicional
# ============================================================

def seccion_logica():
    print("=" * 60)
    print("SECCIÓN 1: Lógica Proposicional")
    print("=" * 60)

    print("Una proposición es una afirmación que puede ser Verdadera (True) o Falsa (False).")
    print("Conectivos lógicos: AND (∧), OR (∨), NOT (¬), XOR (⊕), Implicación (→)")
    print()

    # Tabla de verdad para AND, OR, NOT
    print("Tabla de verdad:")
    print(f"{'P':^5} {'Q':^5} | {'P AND Q':^9} | {'P OR Q':^8} | {'NOT P':^7} | {'P XOR Q':^9}")
    print("-" * 55)
    for p in [True, False]:
        for q in [True, False]:
            and_result = p and q
            or_result = p or q
            not_p = not p
            xor_result = p ^ q      # XOR: True si exactamente uno es True
            print(f"{str(p):^5} {str(q):^5} | {str(and_result):^9} | {str(or_result):^8} | {str(not_p):^7} | {str(xor_result):^9}")
    print()

    # Leyes de De Morgan (importantísimas en programación)
    print("Leyes de De Morgan:")
    print("  NOT (P AND Q) = (NOT P) OR  (NOT Q)")
    print("  NOT (P OR Q)  = (NOT P) AND (NOT Q)")
    print()
    print("Esto es fundamental en programación para simplificar condiciones:")
    print("  if not (edad >= 18 and tiene_dni):  →  puede reescribirse como")
    print("  if edad < 18 or not tiene_dni:")
    print()

    # Implicación lógica P → Q (si P entonces Q)
    print("Implicación P → Q ('si P entonces Q'):")
    print("  Solo es False cuando P=True y Q=False")
    print(f"{'P':^5} {'Q':^5} | {'P → Q':^7}")
    print("-" * 20)
    for p in [True, False]:
        for q in [True, False]:
            # P → Q es equivalente a (NOT P) OR Q
            implicacion = (not p) or q
            print(f"{str(p):^5} {str(q):^5} | {str(implicacion):^7}")
    print()

    # Aplicación en código
    print("Aplicación en código — validaciones:")
    print()

    def validar_usuario(edad, tiene_email, saldo):
        """Puede registrarse si es mayor de 18 Y tiene email, O si tiene saldo > 0"""
        condicion = (edad >= 18 and tiene_email) or saldo > 0
        return condicion

    casos = [
        (20, True, 0,    "adulto con email, sin saldo"),
        (16, False, 100, "menor sin email, con saldo"),
        (15, False, 0,   "menor sin email ni saldo"),
        (25, True, 500,  "adulto con email y saldo"),
    ]
    for edad, email, saldo, desc in casos:
        resultado = validar_usuario(edad, email, saldo)
        print(f"  {desc:<30} → puede registrarse: {resultado}")


# ============================================================
# SECCIÓN 2: Teoría de Conjuntos con set
# ============================================================

def seccion_conjuntos():
    print("\n" + "=" * 60)
    print("SECCIÓN 2: Teoría de Conjuntos — el tipo set de Python")
    print("=" * 60)

    print("Un conjunto es una colección de elementos únicos y sin orden.")
    print("Python tiene el tipo `set` que implementa conjuntos matemáticos.")
    print()

    A = {1, 2, 3, 4, 5}
    B = {3, 4, 5, 6, 7}
    C = {1, 2}

    print(f"A = {A}")
    print(f"B = {B}")
    print(f"C = {C}")
    print()

    # Operaciones de conjuntos
    print("Operaciones:")
    print(f"  A ∪ B (unión):          A | B = {A | B}")
    print(f"  A ∩ B (intersección):   A & B = {A & B}")
    print(f"  A - B (diferencia):     A - B = {A - B}")
    print(f"  B - A (diferencia):     B - A = {B - A}")
    print(f"  A △ B (dif. simétrica): A ^ B = {A ^ B}  (en uno u otro, no en ambos)")
    print()

    # Relaciones entre conjuntos
    print("Relaciones:")
    print(f"  C ⊆ A (C subconjunto de A): {C.issubset(A)}    C = {C}, A = {A}")
    print(f"  A ⊇ C (A superconjunto): {A.issuperset(C)}")
    print(f"  A y B son disjuntos: {A.isdisjoint(B)}")
    print()

    # Propiedades que se usan en programación
    print("Propiedades importantes del set:")
    lista_con_duplicados = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
    sin_duplicados = set(lista_con_duplicados)
    print(f"  Eliminar duplicados: {lista_con_duplicados} → {sin_duplicados}")
    print(f"  Pertenencia O(1): 3 in A → {3 in A}  (mucho más rápido que en una lista)")
    print()

    # Comprensión de conjuntos
    cuadrados_pares = {x**2 for x in range(1, 11) if x % 2 == 0}
    print(f"  Set comprehension — cuadrados de pares del 1 al 10:")
    print(f"  {{x**2 for x in range(1,11) if x%2==0}} = {cuadrados_pares}")
    print()

    # Aplicación real: encontrar palabras comunes
    texto1 = set("python es un lenguaje versatil".split())
    texto2 = set("java es un lenguaje orientado a objetos".split())
    print(f"Palabras únicas en texto1: {texto1}")
    print(f"Palabras únicas en texto2: {texto2}")
    print(f"Palabras en común:         {texto1 & texto2}")
    print(f"Solo en texto1:            {texto1 - texto2}")


# ============================================================
# SECCIÓN 3: Combinatoria
# ============================================================

def seccion_combinatoria():
    print("\n" + "=" * 60)
    print("SECCIÓN 3: Combinatoria")
    print("=" * 60)

    print("Combinatoria: cuántas formas hay de ordenar o elegir elementos.")
    print("Aparece en: criptografía, algoritmos, probabilidad, juegos.")
    print()

    # Factorial
    print("Factorial n! = n × (n-1) × ... × 2 × 1")
    for n in [0, 1, 5, 10, 20]:
        print(f"  {n:2}! = {math.factorial(n):,}")
    print()

    # Permutaciones P(n, r): ordenar r elementos de n, el ORDEN importa
    print("Permutaciones P(n,r): elegir r de n donde el ORDEN importa")
    print("  P(n,r) = n! / (n-r)!")
    print()
    print("  Ejemplo: ¿De cuántas formas puedo asignar los cargos")
    print("  Presidente, Vice y Secretario entre 8 candidatos?")
    n, r = 8, 3
    perm = math.perm(n, r)    # Python 3.8+
    print(f"  P({n},{r}) = {n}! / ({n}-{r})! = {math.factorial(n)} / {math.factorial(n-r)} = {perm}")
    print()

    # Con itertools
    print("  Con itertools.permutations — ver las permutaciones reales:")
    letras = ['A', 'B', 'C', 'D']
    perms = list(itertools.permutations(letras, 2))
    print(f"  Permutaciones de 2 en {letras}:")
    print(f"  {perms}")
    print(f"  Total: {len(perms)}  (P(4,2) = {math.perm(4,2)})")
    print()

    # Combinaciones C(n, r): elegir r de n, el ORDEN no importa
    print("Combinaciones C(n,r): elegir r de n donde el ORDEN NO importa")
    print("  C(n,r) = n! / (r! × (n-r)!)  — también escrito (n sobre r)")
    print()
    print("  Ejemplo: ¿Cuántas manos de 5 cartas hay en un mazo de 52?")
    n, r = 52, 5
    comb = math.comb(n, r)
    print(f"  C({n},{r}) = {comb:,}")
    print()

    print("  Diferencia clave Permutaciones vs Combinaciones:")
    print("  {A,B,C}: ABC, ACB, BAC, BCA, CAB, CBA son 6 PERMUTACIONES")
    print("  pero solo 1 COMBINACIÓN (son el mismo grupo, distinto orden)")
    n, r = 5, 3
    p = math.perm(n, r)
    c = math.comb(n, r)
    print(f"  De 5 elementos tomados de a 3:")
    print(f"    P(5,3) = {p}  (el orden importa)")
    print(f"    C(5,3) = {c}   (el orden no importa)")
    print(f"    Diferencia: {p} / {c} = {p // c} = 3! (los {c} grupos, cada uno en {p//c} órdenes)")
    print()

    # Combinaciones con itertools
    print("  itertools.combinations — ver las combinaciones reales:")
    elementos = [1, 2, 3, 4]
    combs = list(itertools.combinations(elementos, 2))
    print(f"  Combinaciones de 2 en {elementos}: {combs}")
    print(f"  Total: {len(combs)}  (C(4,2) = {math.comb(4,2)})")


# ============================================================
# SECCIÓN 4: Producto cartesiano
# ============================================================

def seccion_producto_cartesiano():
    print("\n" + "=" * 60)
    print("SECCIÓN 4: Producto Cartesiano")
    print("=" * 60)

    print("El producto cartesiano A × B es el conjunto de todos los pares (a,b)")
    print("donde a ∈ A y b ∈ B.")
    print()

    A = {1, 2, 3}
    B = {'a', 'b'}

    prod = list(itertools.product(sorted(A), sorted(B)))
    print(f"A = {A}, B = {B}")
    print(f"A × B = {prod}")
    print(f"|A × B| = |A| × |B| = {len(A)} × {len(B)} = {len(prod)}")
    print()

    print("Aplicaciones:")
    print("  - Los pares de coordenadas en una grilla (x,y) son un producto cartesiano")
    print("  - Las combinaciones de parámetros en un grid search de ML")
    print("  - Las filas de un JOIN en SQL (antes de filtrar con WHERE)")
    print()

    # Grid search demo
    learning_rates = [0.001, 0.01, 0.1]
    batch_sizes = [32, 64, 128]
    print("Grid Search de hiperparámetros (Machine Learning):")
    print(f"  Learning rates: {learning_rates}")
    print(f"  Batch sizes:    {batch_sizes}")
    combinaciones = list(itertools.product(learning_rates, batch_sizes))
    print(f"  Combinaciones a probar ({len(combinaciones)} en total):")
    for lr, bs in combinaciones:
        print(f"    lr={lr}, batch_size={bs}")


# ============================================================
# SECCIÓN 5: Recursión y relación con algoritmos
# ============================================================

def seccion_recursion():
    print("\n" + "=" * 60)
    print("SECCIÓN 5: Recursión — Matemática y Algoritmos")
    print("=" * 60)

    print("La recursión es cuando una función se llama a sí misma.")
    print("En matemáticas: n! = n × (n-1)! y 0! = 1  ← definición recursiva")
    print()

    def factorial_recursivo(n):
        if n == 0:           # Caso base — termina la recursión
            return 1
        return n * factorial_recursivo(n - 1)   # Llamada recursiva

    print("def factorial_recursivo(n):")
    print("    if n == 0: return 1")
    print("    return n * factorial_recursivo(n - 1)")
    print()
    for n in [0, 1, 5, 7]:
        print(f"  factorial_recursivo({n}) = {factorial_recursivo(n)}")
    print()

    # Fibonacci
    print("Sucesión de Fibonacci: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)")
    print("  Aparece en naturaleza, arte, y en algoritmos de complejidad.")

    def fibonacci(n, memo={}):
        if n in memo:
            return memo[n]
        if n <= 1:
            return n
        memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo)
        return memo[n]

    fib_lista = [fibonacci(i) for i in range(15)]
    print(f"  Primeros 15 términos: {fib_lista}")
    print()

    # La razón áurea
    razon_aurea = fibonacci(50) / fibonacci(49)
    print(f"  F(50)/F(49) = {razon_aurea:.10f}")
    print(f"  φ (razón áurea) = {(1 + math.sqrt(5)) / 2:.10f}")
    print(f"  Los cocientes de Fibonacci convergen a la razón áurea φ ≈ 1.618")


# ============================================================
# MAIN
# ============================================================

def main():
    print("\n" + "#" * 60)
    print("  MÓDULO 06: MATEMÁTICA DISCRETA CON PYTHON")
    print("#" * 60)

    seccion_logica()
    seccion_conjuntos()
    seccion_combinatoria()
    seccion_producto_cartesiano()
    seccion_recursion()

    print("\n" + "=" * 60)
    print("FIN DEL MÓDULO 06")
    print()
    print("¡Completaste los 6 módulos básicos!")
    print("Próximos pasos sugeridos:")
    print("  1. Instalar matplotlib y agregar gráficos a los módulos 04 y 05")
    print("  2. Profundizar álgebra lineal con numpy (autovalores, SVD)")
    print("  3. Comenzar con la webapp Flask/FastAPI para visualizar los conceptos")
    print("=" * 60)


if __name__ == "__main__":
    main()
