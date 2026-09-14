import numpy as np 
import pandas as pd 

"""
Contexto: se registraronlas temperaturas diarias de un mes(30 valores en°C)
■Paso 1 — Generar o cargarlos datos:
–  Pista: Asignación directa
■Paso 2 — Calcular estadísticas descriptivas:
–  Pista: métodos de paquetes -Obtener media, desvio estandar, max y min de la lista de datos
■Paso 3 — Filtrar días con temperatura superior al promedio:
–  Pista:list comprehension
■Paso 4 — Contar cuántos días superaron el promedio:
–  Pista: métodos de paquetes y lista derivada

"""

def crear_array_temperaturas():

    return np.random.randint(0, 40, 30)
    

def main():

    temperaturas = crear_array_temperaturas()
    
    print(f"temperaturas: {temperaturas}")

    media = np.mean(temperaturas)
    desviacion_estandar = np.std(temperaturas)
    maximo = np.max(temperaturas)
    minimo = np.min(temperaturas)

    print(f"Media: {media}")
    print(f"Desviacion estandar: {desviacion_estandar}")
    print(f"Maximo: {maximo}")
    print(f"Minimo: {minimo}")

    dias_superiores_al_promedio = [temp for temp in temperaturas.tolist() if temp > media]

    cantidad_dias_superiores_al_promedio = len(dias_superiores_al_promedio)
    print(f"Cantidad de dias con temperatura superior al promedio: {cantidad_dias_superiores_al_promedio}")



if __name__ == "__main__":
    main()

