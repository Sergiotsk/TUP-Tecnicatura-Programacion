import numpy as np 
import pandas as pd 

"""
Cargar en DF
 
Crear columna promedio y columna is_aprobado

"""

datos = {
    "Alumno": [
        "Alumno 1", "Alumno 2", "Alumno 3", "Alumno 4",
        "Alumno 5", "Alumno 6", "Alumno 7", "Alumno 8",
        "Alumno 9", "Alumno 10", "Alumno 11", "Alumno 12",
        "Alumno 13", "Alumno 14", "Alumno 15", "Alumno 16",
        "Alumno 17", "Alumno 18", "Alumno 19", "Alumno 20",
        "Alumno 21", "Alumno 22", "Alumno 23", "Alumno 24",
        "Alumno 25", "Alumno 26", "Alumno 27", "Alumno 28"
    ],
    "Parcial_1": [
        7.5, 6.0, 8.5, 4.5,
        9.0, 5.5, 7.0, 3.5,
        8.0, 6.5, 5.0, 9.5,
        4.0, 7.5, 6.0, 8.5,
        2.5, 7.0, 5.5, 9.0,
        6.5, 4.5, 8.0, 3.0,
        7.5, 5.0, 9.0, 6.0
    ],
    "Parcial_2": [
        8.0, 7.0, 9.0, 5.0,
        8.5, 6.0, 6.5, 4.0,
        7.5, 7.0, 5.5, 10.0,
        4.5, 8.0, 6.5, 9.0,
        3.0, 6.5, 6.0, 8.5,
        7.0, 5.0, 8.5, 4.5,
        8.0, 5.5, 9.5, 6.5
    ]
}


def main():

    df = pd.DataFrame(datos)
    
    df["Promedio"] = (df["Parcial_1"] + df["Parcial_2"]) / 2
     
    df["Estado"] = (df["Promedio"] >= 6).map({True: "Aprobado", False: "Desaprobado"})
    
    print(df.head(20).to_string(index=False))

if __name__ == "__main__":
    main()
        