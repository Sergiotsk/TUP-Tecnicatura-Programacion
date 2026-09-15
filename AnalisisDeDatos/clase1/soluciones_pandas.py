"""
Soluciones de ejercicios_pandas.py — mirá esto solo después de intentar.

Correr con:
    uv run python soluciones_pandas.py
"""

import pandas as pd
import numpy as np

data = {
    "nombre": ["Ana", "Bruno", "Carla", "Diego", "Elena", "Fede", "Gina"],
    "materia": ["Programacion", "Programacion", "BasesDeDatos", "BasesDeDatos",
                "Programacion", "Ingles", "BasesDeDatos"],
    "nota": [8, 6, 9, np.nan, 7, 10, 5],
    "asistencia_pct": [90, 75, 95, 60, 85, 100, 55],
}
df = pd.DataFrame(data)

print("=== Ejercicio 1: exploración básica ===")
print(df.head(3))
print(df.shape)
print(df.dtypes)
print(df.describe())

print("\n=== Ejercicio 2: selección de columnas ===")
nombres = df["nombre"]
nombres_notas = df[["nombre", "nota"]]
print(nombres)
print(nombres_notas)

print("\n=== Ejercicio 3: filtrado ===")
aprobados = df[df["nota"] >= 7]
de_programacion = df[df["materia"] == "Programacion"]
buenos_alumnos = df[(df["nota"] >= 7) & (df["asistencia_pct"] >= 80)]
print(aprobados)
print(de_programacion)
print(buenos_alumnos)

print("\n=== Ejercicio 4: valores faltantes ===")
nulos_por_columna = df.isna().sum()
promedio_nota = df["nota"].mean()
df_relleno = df.copy()
df_relleno["nota"] = df_relleno["nota"].fillna(promedio_nota)
df_sin_nulos = df.dropna()
print(nulos_por_columna)
print(df_relleno)
print(df_sin_nulos)

print("\n=== Ejercicio 5: columna calculada ===")
df["aprobo"] = df["nota"] >= 6
print(df)

print("\n=== Ejercicio 6: ordenar ===")
por_nota = df.sort_values("nota", ascending=False)
por_materia_y_nota = df.sort_values(["materia", "nota"], ascending=[True, False])
print(por_nota)
print(por_materia_y_nota)

print("\n=== Ejercicio 7: groupby ===")
promedio_por_materia = df.groupby("materia")["nota"].mean()
resumen_por_materia = df.groupby("materia").agg({"nota": "mean", "asistencia_pct": "max"})
cantidad_por_materia = df["materia"].value_counts()
print(promedio_por_materia)
print(resumen_por_materia)
print(cantidad_por_materia)

print("\n=== Ejercicio 8: CSV ===")
df.to_csv("notas.csv", index=False)
df2 = pd.read_csv("notas.csv")
print(df2.head())
