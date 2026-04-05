"""
MÓDULO 03: Álgebra Lineal — Vectores y Matrices
PROYECTO: Matemática con Python
LIBRERÍAS: numpy (computación numérica — pip install numpy)

=== ¿QUÉ APRENDO DE MATEMÁTICA? ===
- Vectores: qué son, operaciones (suma, producto escalar, norma)
- Matrices: qué son, operaciones (suma, multiplicación, transpuesta)
- Determinante e inversa de una matriz
- Resolver sistemas de ecuaciones con matrices (Ax = b)
- Conexión con algoritmos y programación

=== ¿QUÉ APRENDO DE PYTHON? ===
- NumPy: LA librería de cómputo numérico en Python
  - np.array(): crear vectores y matrices
  - Operaciones vectorizadas (sin loops explícitos)
  - np.dot(): producto punto (y multiplicación de matrices)
  - np.linalg: submódulo de álgebra lineal
    - np.linalg.norm(): norma de un vector
    - np.linalg.det(): determinante
    - np.linalg.inv(): inversa
    - np.linalg.solve(): resolver sistemas lineales
- Diferencia entre array de NumPy y lista de Python

INSTALACIÓN:
  pip install numpy
"""

import numpy as np


# ============================================================
# SECCIÓN 1: NumPy — por qué no usar listas de Python
# ============================================================

def seccion_intro_numpy():
    print("=" * 60)
    print("SECCIÓN 1: NumPy vs Listas de Python")
    print("=" * 60)

    print("Una lista de Python puede guardar números, pero no está optimizada")
    print("para matemáticas. NumPy introduce el 'array': una lista homogénea")
    print("altamente optimizada para cómputo numérico.")
    print()

    # Diferencia de sintaxis
    lista_python = [1, 2, 3, 4]
    array_numpy = np.array([1, 2, 3, 4])

    print(f"Lista Python:  {lista_python}")
    print(f"Array NumPy:   {array_numpy}")
    print()

    # Diferencia en operaciones
    print("¿Por qué no usar listas para matemáticas?")
    print(f"  lista * 3  = {lista_python * 3}  ← ¡repite la lista!")
    print(f"  array * 3  = {array_numpy * 3}       ← multiplica cada elemento")
    print()

    # Operaciones elemento a elemento
    a = np.array([1, 2, 3])
    b = np.array([4, 5, 6])
    print(f"a = {a}, b = {b}")
    print(f"a + b = {a + b}  (suma elemento a elemento)")
    print(f"a * b = {a * b}  (producto elemento a elemento — NO es el producto punto)")
    print(f"a ** 2 = {a ** 2}  (cuadrado de cada elemento)")
    print()

    print("Tipos y forma del array:")
    mat = np.array([[1, 2, 3], [4, 5, 6]])
    print(f"  array 2D: {mat}")
    print(f"  .shape:   {mat.shape}  (2 filas, 3 columnas)")
    print(f"  .dtype:   {mat.dtype}  (tipo de dato)")
    print(f"  .ndim:    {mat.ndim}   (número de dimensiones)")


# ============================================================
# SECCIÓN 2: Vectores
# ============================================================

def seccion_vectores():
    print("\n" + "=" * 60)
    print("SECCIÓN 2: Vectores")
    print("=" * 60)

    print("Un vector es una lista ordenada de números (componentes).")
    print("En geometría: tiene módulo (longitud) y dirección.")
    print("En programación: sirve para representar características, estados, colores...")
    print()

    v1 = np.array([3, 4])
    v2 = np.array([1, -2])

    print(f"v1 = {v1}  (vector en el plano)")
    print(f"v2 = {v2}")
    print()

    # Operaciones básicas
    print("Suma de vectores (suma componente a componente):")
    print(f"  v1 + v2 = {v1 + v2}")
    print()

    print("Producto por escalar (escala el vector):")
    print(f"  3 * v1 = {3 * v1}  (triplica cada componente)")
    print()

    # Norma (módulo, longitud)
    norma_v1 = np.linalg.norm(v1)
    print(f"Norma (módulo) de v1 = ||v1|| = √(3² + 4²) = √{3**2 + 4**2} = {norma_v1}")
    print("  La norma es la longitud del vector (Teorema de Pitágoras en 2D)")
    print()

    # Producto punto (dot product)
    dot = np.dot(v1, v2)
    print(f"Producto punto: v1 · v2 = {v1[0]}*{v2[0]} + {v1[1]}*{v2[1]} = {dot}")
    print("  Si v1 · v2 = 0 → los vectores son perpendiculares (ortogonales)")
    print()

    # Ángulo entre vectores
    cos_angulo = np.dot(v1, v2) / (np.linalg.norm(v1) * np.linalg.norm(v2))
    angulo_rad = np.arccos(cos_angulo)
    angulo_deg = np.degrees(angulo_rad)
    print(f"Ángulo entre v1 y v2:")
    print(f"  cos(θ) = (v1·v2) / (||v1|| * ||v2||) = {cos_angulo:.4f}")
    print(f"  θ = {angulo_deg:.2f}°")
    print()

    print("Vectores en 3D (o N-D — numpy los maneja igual):")
    v3d_a = np.array([1, 2, 3])
    v3d_b = np.array([4, 5, 6])
    print(f"  {v3d_a} + {v3d_b} = {v3d_a + v3d_b}")
    print(f"  ||{v3d_a}|| = {np.linalg.norm(v3d_a):.4f}")


# ============================================================
# SECCIÓN 3: Matrices
# ============================================================

def seccion_matrices():
    print("\n" + "=" * 60)
    print("SECCIÓN 3: Matrices")
    print("=" * 60)

    print("Una matriz es una tabla de números organizada en filas y columnas.")
    print("Se usan para: transformaciones geométricas, sistemas de ecuaciones,")
    print("redes neuronales, grafos, imágenes (una imagen es una matriz de píxeles).")
    print()

    # Crear matrices
    A = np.array([[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9]])

    B = np.array([[9, 8, 7],
                  [6, 5, 4],
                  [3, 2, 1]])

    print(f"Matriz A (3x3):\n{A}")
    print(f"\nMatriz B (3x3):\n{B}")
    print()

    # Suma de matrices (elemento a elemento)
    print(f"A + B:\n{A + B}")
    print()

    # Multiplicación por escalar
    print(f"2 * A:\n{2 * A}")
    print()

    # Transpuesta
    print(f"Transpuesta de A (A.T):\n{A.T}")
    print("  La transpuesta cambia filas por columnas: A[i][j] ← A[j][i]")
    print()

    # Multiplicación de matrices (NO es elemento a elemento)
    C = np.array([[1, 2],
                  [3, 4],
                  [5, 6]])
    D = np.array([[7, 8, 9],
                  [10, 11, 12]])

    print(f"C (3x2):\n{C}")
    print(f"D (2x3):\n{D}")
    print()
    print("C @ D (multiplicación matricial):")
    print(f"{C @ D}")
    print("  Para multiplicar: columnas de C deben = filas de D")
    print("  Resultado tiene dimensión: (filas de C) x (columnas de D) = 3x3")
    print()

    # Acceso a elementos
    print("Acceso a elementos de A:")
    print(f"  A[0][0] = {A[0][0]}  (fila 0, columna 0 — Python indexa desde 0)")
    print(f"  A[1][2] = {A[1][2]}  (fila 1, columna 2)")
    print(f"  A[0]    = {A[0]}     (toda la fila 0)")
    print(f"  A[:, 1] = {A[:, 1]}  (toda la columna 1 — slicing de NumPy)")


# ============================================================
# SECCIÓN 4: Determinante e Inversa
# ============================================================

def seccion_determinante_inversa():
    print("\n" + "=" * 60)
    print("SECCIÓN 4: Determinante e Inversa")
    print("=" * 60)

    print("Solo las matrices cuadradas (nxn) tienen determinante e inversa.")
    print()

    M = np.array([[2, 1],
                  [5, 3]])
    print(f"Matriz M:\n{M}")
    print()

    # Determinante
    det = np.linalg.det(M)
    print(f"Determinante det(M) = {det:.1f}")
    print(f"  Para una 2x2: det = ad - bc = {M[0,0]}*{M[1,1]} - {M[0,1]}*{M[1,0]} = {M[0,0]*M[1,1] - M[0,1]*M[1,0]}")
    print()

    print("¿Por qué importa el determinante?")
    print("  - det(M) ≠ 0 → la matriz tiene inversa → el sistema tiene solución única")
    print("  - det(M) = 0 → la matriz es singular → sin solución única")
    print()

    # Inversa
    M_inv = np.linalg.inv(M)
    print(f"Inversa M⁻¹:\n{M_inv}")
    print()

    # Verificación: M * M⁻¹ = Identidad
    identidad = M @ M_inv
    print(f"Verificación M @ M⁻¹ (debe ser la identidad):\n{np.round(identidad)}")
    print("  La matriz identidad es el '1' de las matrices: M * I = M")


# ============================================================
# SECCIÓN 5: Resolver sistemas de ecuaciones con matrices
# ============================================================

def seccion_sistemas_con_matrices():
    print("\n" + "=" * 60)
    print("SECCIÓN 5: Sistemas de Ecuaciones → Notación Matricial Ax=b")
    print("=" * 60)

    print("Cualquier sistema de ecuaciones lineales se puede escribir como Ax=b:")
    print()
    print("  Sistema:       2x + y = 7        A = [[2, 1],    b = [7,")
    print("                 x - y = 2              [1,-1]]         2]")
    print()

    A = np.array([[2, 1],
                  [1, -1]], dtype=float)
    b = np.array([7, 2], dtype=float)

    print(f"A =\n{A}")
    print(f"b = {b}")
    print()

    # Resolver: x = A⁻¹ * b
    solucion = np.linalg.solve(A, b)
    print(f"Solución (np.linalg.solve): x={solucion[0]:.1f}, y={solucion[1]:.1f}")
    print()

    # Verificación
    verificacion = A @ solucion
    print(f"Verificación A @ x = {verificacion}  (debe ser {b})")
    print()

    print("Ejemplo con 3 ecuaciones y 3 incógnitas:")
    print("  x + y + z = 6")
    print("  2x - y + z = 3")
    print("  x + 2y - z = 2")

    A3 = np.array([[1, 1, 1],
                   [2, -1, 1],
                   [1, 2, -1]], dtype=float)
    b3 = np.array([6, 3, 2], dtype=float)
    sol3 = np.linalg.solve(A3, b3)
    print(f"  Solución: x={sol3[0]:.1f}, y={sol3[1]:.1f}, z={sol3[2]:.1f}")
    print()

    print("Esto se usa en gráficos 3D, simulaciones físicas, machine learning.")
    print("Los modelos de ML son básicamente resolver Ax=b con millones de variables.")


# ============================================================
# SECCIÓN 6: Matrices especiales útiles
# ============================================================

def seccion_matrices_especiales():
    print("\n" + "=" * 60)
    print("SECCIÓN 6: Matrices Especiales en NumPy")
    print("=" * 60)

    print("np.zeros() — matriz de ceros (estado inicial):")
    print(np.zeros((3, 3)))
    print()

    print("np.ones() — matriz de unos:")
    print(np.ones((2, 4)))
    print()

    print("np.eye() — matriz identidad:")
    print(np.eye(4))
    print()

    print("np.arange() — vector de secuencia (como range pero en array):")
    print(np.arange(0, 10, 2))
    print()

    print("np.linspace() — N puntos igualmente espaciados (útil para graficar):")
    puntos = np.linspace(0, 1, 6)
    print(puntos)
    print("  linspace(0, 1, 6) da 6 valores desde 0 hasta 1 inclusive")
    print()

    print("np.reshape() — cambia la forma sin cambiar datos:")
    v = np.arange(1, 13)
    M = v.reshape(3, 4)
    print(f"  vector {v}")
    print(f"  reshape(3,4):\n{M}")


# ============================================================
# MAIN
# ============================================================

def main():
    print("\n" + "#" * 60)
    print("  MÓDULO 03: ÁLGEBRA LINEAL CON NUMPY")
    print("#" * 60)

    seccion_intro_numpy()
    seccion_vectores()
    seccion_matrices()
    seccion_determinante_inversa()
    seccion_sistemas_con_matrices()
    seccion_matrices_especiales()

    print("\n" + "=" * 60)
    print("FIN DEL MÓDULO 03")
    print("Siguiente: 04_Calculo/limites_y_derivadas.py")
    print("=" * 60)


if __name__ == "__main__":
    main()
