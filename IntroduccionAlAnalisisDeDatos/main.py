"""
main.py — Ejercicios de práctica de Introducción al Análisis de Datos.

Los 4 ejercicios de la cátedra están como funciones esqueleto (con pass).
Completá el cuerpo de cada una siguiendo la consigna que está en ejercicios.md.

Cuando termines un ejercicio, descomentá su llamada en main() y probalo con:
    uv run python main.py
"""


# ============================================================
# EJERCICIO 1 — Calculadora básica
# ============================================================

def calculadora():
    """
    Calculadora básica.

    Consigna:
    1. Leer dos números y una operación (+, -, *, /)
    2. Mostrar el resultado
    3. Validar la división por cero con if

    Pistas para pensar:
    - input() SIEMPRE devuelve un string. ¿cómo convertís eso en un número?
    - ¿Cómo detectás la división por cero ANTES de intentar dividir?
    """
    num1 = float(input("Ingrese el primer número: "))
    operacion = input("Ingrese una operación (+, -, *, /): ")
    num2 = float(input("Ingrese el segundo número: "))
 
    if operacion == "+":
        resultado = num1 + num2
    elif operacion == "-":
        resultado = num1 - num2
    elif operacion == "*":
        resultado = num1 * num2
    elif operacion == "/":
        if num2 == 0:
            resultado = None
            print("Error: no se puede dividir por cero")
        else:
            resultado = num1 / num2
    else:
        resultado = None
        print("Operación no válida")
 
    if resultado is not None:
        print(f"Resultado: {resultado}")


# ============================================================
# EJERCICIO 2 — Clasificador de notas
# ============================================================

def clasificar_nota():
    """
    Clasificador de notas.

    Consigna:
    1. Leer una nota (0–10) y categorizarla en:
       Insuficiente / Aprobado / Bueno / Muy Bueno / Sobresaliente
    2. Usar if / elif / else con rangos

    Pistas para pensar:
    - Los límites de cada categoría los definís vos. Elegí los rangos y respetá el orden.
    - El/los caso/s borde: ¿qué pasa con el 0? ¿Y con el 10?
    - El orden de los elif importa: evaluá las condiciones de forma encadenada.
    """
    pass


# ============================================================
# EJERCICIO 3 — Tabla de multiplicar
# ============================================================

def tabla_multiplicar():
    """
    Tabla de multiplicar.

    Consigna:
    1. Pedir un número
    2. Mostrar su tabla del 1 al 10 usando un bucle for

    Pistas para pensar:
    - ¿Qué argumentos le pasás a range() para ir de 1 a 10 inclusive?
    - ¿Cómo formateás para que se vea así: "5 x 3 = 15"?
    """
    pass


# ============================================================
# EJERCICIO 4 — Número primo
# ============================================================
    """
    Determina si el número n es primo.

    Consigna:
    1. Determinar si el número ingresado es primo o no
    2. Implementar como función con parámetro y retorno booleano

    Pistas para pensar:
    - Un número primo es divisible SOLO por 1 y por sí mismo.
    - ¿Qué operador te dice si un número divide a otro sin dejar resto?
    - Casos borde: ¿es primo el 0? ¿el 1? ¿el 2?
    - Extra: para un número n alcanza con probar divisores hasta √n (raíz cuadrada),
      no hace falta llegar a n.
    """


def es_primo(numero):
    if numero < 2:
        return False
    for divisor in range(2, int(numero ** 0.5) + 1):
        if numero % divisor == 0:
            return False
    return True


# ============================================================
# Punto de entrada
# ============================================================

def main():
    """
    Descomentá cada ejercicio a medida que lo termines.
    """
    #calculadora()
    num = int(input("Ingrese un nuMero: "))
    resultado = es_primo(num)
    print(resultado)
    # clasificar_nota()
    # tabla_multiplicar()
    # print(es_primo(7))  # debería imprimir True
    # print(es_primo(4))  # debería imprimir False
    


if __name__ == "__main__":
    main()