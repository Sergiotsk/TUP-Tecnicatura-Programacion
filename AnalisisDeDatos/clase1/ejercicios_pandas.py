"""
Ejercicios básicos de pandas — Análisis de Datos

Correr con:
    uv run python ejercicios_pandas.py

Cada ejercicio tiene un TODO. Completá el código donde dice
`# TODO` y descomentá el print correspondiente para verificar.
Las soluciones están en soluciones_pandas.py — intentá antes de mirar.
"""

import pandas as pd
import numpy as np

# ---------------------------------------------------------------
# Dataset de ejemplo: notas de estudiantes
# ---------------------------------------------------------------
data = {
    "nombre": ["Ana", "Bruno", "Carla", "Diego", "Elena", "Fede", "Gina"],
    "materia": ["Programacion", "Programacion", "BasesDeDatos", "BasesDeDatos",
                "Programacion", "Ingles", "BasesDeDatos"],
    "nota": [8, 6, 9, np.nan, 7, 10, 5],
    "asistencia_pct": [90, 75, 95, 60, 85, 100, 55],
}

df = pd.DataFrame(data)


# ---------------------------------------------------------------
# Ejercicio 1: exploración básica
# ---------------------------------------------------------------
# a) Mostrá las primeras 3 filas del DataFrame
# b) Mostrá cuántas filas y columnas tiene (shape)
# c) Mostrá los tipos de datos de cada columna (dtypes)
# d) Mostrá estadísticas descriptivas de las columnas numéricas (describe)

# TODO: completar
# print(df.head(3))
# print(df.shape)
# print(df.dtypes)
# print(df.describe())


# ---------------------------------------------------------------
# Ejercicio 2: selección de columnas
# ---------------------------------------------------------------
# a) Seleccioná solo la columna "nombre" (te da una Series)
# b) Seleccioná las columnas "nombre" y "nota" (te da un DataFrame)

# TODO: completar
# nombres = df["nombre"]
# nombres_notas = df[["nombre", "nota"]]


# ---------------------------------------------------------------
# Ejercicio 3: filtrado con condiciones (máscaras booleanas)
# ---------------------------------------------------------------
# a) Filtrá los estudiantes con nota >= 7
# b) Filtrá los estudiantes de la materia "Programacion"
# c) Filtrá los estudiantes con nota >= 7 Y asistencia_pct >= 80
#    (recordá usar & en vez de "and", y paréntesis en cada condición)

# TODO: completar
# aprobados = df[df["nota"] >= 7]
# de_programacion = df[df["materia"] == "Programacion"]
# buenos_alumnos = df[(df["nota"] >= 7) & (df["asistencia_pct"] >= 80)]


# ---------------------------------------------------------------
# Ejercicio 4: valores faltantes (NaN)
# ---------------------------------------------------------------
# a) Contá cuántos valores nulos hay por columna (isna().sum())
# b) Creá una copia del df reemplazando los NaN de "nota" por el promedio
#    de la columna (fillna)
# c) Creá otra copia eliminando las filas que tengan algún NaN (dropna)

# TODO: completar
# nulos_por_columna = df.isna().sum()
# promedio_nota = df["nota"].mean()
# df_relleno = df.copy()
# df_relleno["nota"] = df_relleno["nota"].fillna(promedio_nota)
# df_sin_nulos = df.dropna()


# ---------------------------------------------------------------
# Ejercicio 5: nueva columna calculada
# ---------------------------------------------------------------
# Creá una columna "aprobo" que sea True si nota >= 6, False si no
# (para el NaN puede quedar False o NaN, no te preocupes por eso ahora)

# TODO: completar
# df["aprobo"] = df["nota"] >= 6


# ---------------------------------------------------------------
# Ejercicio 6: ordenar
# ---------------------------------------------------------------
# a) Ordená el DataFrame por "nota" de mayor a menor
# b) Ordená por "materia" y luego por "nota" descendente dentro de cada materia

# TODO: completar
# por_nota = df.sort_values("nota", ascending=False)
# por_materia_y_nota = df.sort_values(["materia", "nota"], ascending=[True, False])


# ---------------------------------------------------------------
# Ejercicio 7: agrupar y agregar (groupby)
# ---------------------------------------------------------------
# a) Calculá el promedio de "nota" por "materia"
# b) Calculá, por materia, el promedio de nota Y el máximo de asistencia_pct
#    a la vez (agg con un diccionario)
# c) Contá cuántos estudiantes hay por materia (value_counts o groupby+size)

# TODO: completar
# promedio_por_materia = df.groupby("materia")["nota"].mean()
# resumen_por_materia = df.groupby("materia").agg({"nota": "mean", "asistencia_pct": "max"})
# cantidad_por_materia = df["materia"].value_counts()


# ---------------------------------------------------------------
# Ejercicio 8: guardar y leer CSV
# ---------------------------------------------------------------
# a) Guardá el DataFrame `df` en un archivo "notas.csv" (sin la columna de índice)
# b) Leelo de nuevo en una variable df2 y mostrá sus primeras filas

# TODO: completar
# df.to_csv("notas.csv", index=False)
# df2 = pd.read_csv("notas.csv")
# print(df2.head())


if __name__ == "__main__":
    print("Descomentá los ejercicios de a uno para probarlos.")
