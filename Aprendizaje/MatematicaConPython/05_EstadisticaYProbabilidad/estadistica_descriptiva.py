"""
MÓDULO 05: Estadística y Probabilidad — Estadística Descriptiva
PROYECTO: Matemática con Python
LIBRERÍAS: numpy, scipy.stats, matplotlib

=== ¿QUÉ APRENDO DE MATEMÁTICA? ===
- Medidas de tendencia central: media, mediana, moda
- Medidas de dispersión: varianza, desvío estándar, rango intercuartílico
- Distribución de datos: simetría, asimetría
- Probabilidad básica
- La distribución normal (campana de Gauss)

=== ¿QUÉ APRENDO DE PYTHON? ===
- numpy: estadística descriptiva con arrays
- scipy.stats: distribuciones de probabilidad
- matplotlib: histogramas, box plots, gráficos de funciones
- Diccionarios en Python (útiles para agrupar resultados)

INSTALACIÓN:
  pip install numpy scipy matplotlib
"""

import numpy as np
from scipy import stats


# ============================================================
# SECCIÓN 1: Medidas de tendencia central
# ============================================================

def seccion_tendencia_central():
    print("=" * 60)
    print("SECCIÓN 1: Medidas de Tendencia Central")
    print("=" * 60)

    print("¿Cómo resumir un conjunto de datos con un solo número?")
    print()

    # Dataset de ejemplo: notas de un examen
    notas = np.array([78, 85, 90, 72, 68, 91, 88, 75, 82, 95,
                      70, 84, 78, 91, 60, 88, 74, 83, 79, 88])

    print(f"Notas de un examen (n={len(notas)}):")
    print(f"  {np.sort(notas)}")
    print()

    # Media (promedio aritmético)
    media = np.mean(notas)
    print(f"Media (promedio): {media:.2f}")
    print(f"  Suma de todos / n = {np.sum(notas)} / {len(notas)} = {media:.2f}")
    print()

    # Mediana
    mediana = np.median(notas)
    print(f"Mediana: {mediana}")
    print(f"  El valor del medio cuando los datos están ordenados.")
    print(f"  Si n es par, es el promedio de los dos valores centrales.")
    print(f"  Más robusta que la media ante valores extremos (outliers).")
    print()

    # Moda (scipy)
    moda_result = stats.mode(notas)
    moda = moda_result.mode
    moda_count = moda_result.count
    print(f"Moda: {moda} (aparece {moda_count} veces)")
    print(f"  El valor más frecuente del dataset.")
    print()

    # Comparación: cuándo usar cada una
    print("¿Cuándo usar cada medida?")
    print("  Media:   datos sin outliers, distribución simétrica")
    print("  Mediana: hay outliers, datos asimétricos (ej: salarios)")
    print("  Moda:    datos categóricos, o la moda tiene sentido práctico")
    print()

    # Ejemplo de outlier afectando la media
    salarios = np.array([45000, 48000, 50000, 52000, 55000, 250000])
    print(f"Ejemplo con outlier — Salarios: {salarios}")
    print(f"  Media:   ${np.mean(salarios):,.0f}  ← distorsionada por el outlier")
    print(f"  Mediana: ${np.median(salarios):,.0f}  ← más representativa")


# ============================================================
# SECCIÓN 2: Medidas de dispersión
# ============================================================

def seccion_dispersion():
    print("\n" + "=" * 60)
    print("SECCIÓN 2: Medidas de Dispersión")
    print("=" * 60)

    print("La dispersión mide cuánto varían los datos respecto a la media.")
    print("Dos datasets pueden tener la misma media pero muy diferente dispersión.")
    print()

    grupo_a = np.array([48, 49, 50, 51, 52])   # Datos muy concentrados
    grupo_b = np.array([10, 30, 50, 70, 90])   # Datos muy dispersos

    for nombre, datos in [("Grupo A", grupo_a), ("Grupo B", grupo_b)]:
        media = np.mean(datos)
        varianza = np.var(datos)          # Varianza poblacional
        desvio = np.std(datos)            # Desvío estándar
        rango = np.max(datos) - np.min(datos)
        q1 = np.percentile(datos, 25)
        q3 = np.percentile(datos, 75)
        iqr = q3 - q1

        print(f"{nombre}: {datos}")
        print(f"  Media:              {media:.1f}")
        print(f"  Rango (max-min):    {rango}")
        print(f"  Varianza:           {varianza:.1f}")
        print(f"  Desvío estándar:    {desvio:.1f}")
        print(f"  Q1={q1:.1f}, Q3={q3:.1f}, IQR={iqr:.1f}")
        print()

    print("Desvío estándar (σ): el promedio de cuánto se aleja cada dato de la media.")
    print("  σ pequeño → datos concentrados cerca de la media")
    print("  σ grande  → datos muy dispersos")
    print()

    print("Varianza = σ²  (el desvío al cuadrado)")
    print("  Se usa la raíz cuadrada (desvío) porque queda en las mismas unidades.")
    print()

    # Cómo se calcula la varianza manualmente
    datos = np.array([2, 4, 4, 4, 5, 5, 7, 9])
    media = np.mean(datos)
    diferencias = datos - media
    diferencias_cuadradas = diferencias ** 2
    varianza_manual = np.mean(diferencias_cuadradas)

    print(f"Ejemplo paso a paso con {datos}:")
    print(f"  Media = {media}")
    print(f"  Diferencias (xi - media): {diferencias}")
    print(f"  Diferencias²:             {diferencias_cuadradas}")
    print(f"  Varianza = promedio(dif²) = {varianza_manual:.4f}")
    print(f"  Desvío  = √varianza       = {np.sqrt(varianza_manual):.4f}")
    print(f"  np.std(datos) =           {np.std(datos):.4f}  ✓")


# ============================================================
# SECCIÓN 3: Percentiles y cuartiles
# ============================================================

def seccion_percentiles():
    print("\n" + "=" * 60)
    print("SECCIÓN 3: Percentiles y Cuartiles")
    print("=" * 60)

    print("El percentil P dice que el P% de los datos están por debajo de ese valor.")
    print()

    notas = np.array([55, 60, 62, 65, 68, 70, 72, 74, 75, 78,
                      80, 82, 85, 87, 88, 90, 91, 93, 95, 98])

    print(f"Notas ordenadas: {notas}")
    print()

    p25 = np.percentile(notas, 25)   # Q1
    p50 = np.percentile(notas, 50)   # Q2 = Mediana
    p75 = np.percentile(notas, 75)   # Q3
    p90 = np.percentile(notas, 90)

    print(f"Q1 (percentil 25): {p25}  → el 25% de los alumnos sacó menos de {p25}")
    print(f"Q2 (percentil 50): {p50}  → Mediana")
    print(f"Q3 (percentil 75): {p75}  → el 75% de los alumnos sacó menos de {p75}")
    print(f"Percentil 90:      {p90}  → el 10% sacó más de {p90}")
    print()
    print(f"IQR = Q3 - Q1 = {p75} - {p25} = {p75 - p25}")
    print(f"  El IQR contiene el 50% central de los datos.")
    print()

    # Detección de outliers con IQR
    iqr = p75 - p25
    limite_inferior = p25 - 1.5 * iqr
    limite_superior = p75 + 1.5 * iqr
    outliers = notas[(notas < limite_inferior) | (notas > limite_superior)]
    print(f"Detección de outliers (método IQR):")
    print(f"  Límite inferior: Q1 - 1.5*IQR = {p25} - {1.5*iqr} = {limite_inferior}")
    print(f"  Límite superior: Q3 + 1.5*IQR = {p75} + {1.5*iqr} = {limite_superior}")
    print(f"  Outliers encontrados: {outliers}  (ninguno en este caso)")


# ============================================================
# SECCIÓN 4: Probabilidad básica
# ============================================================

def seccion_probabilidad():
    print("\n" + "=" * 60)
    print("SECCIÓN 4: Probabilidad Básica")
    print("=" * 60)

    print("Probabilidad de un evento A:")
    print("  P(A) = casos favorables / casos totales")
    print("  Siempre: 0 ≤ P(A) ≤ 1")
    print()

    # Dado de 6 caras
    cara_total = 6
    print("Dado de 6 caras:")
    print(f"  P(sacar 4) = 1/6 = {1/6:.4f}")
    print(f"  P(par)     = 3/6 = {3/6:.4f}  (caras: 2,4,6)")
    print(f"  P(>4)      = 2/6 = {2/6:.4f}  (caras: 5,6)")
    print()

    # Probabilidad complementaria
    p_lluvia = 0.30
    p_no_lluvia = 1 - p_lluvia
    print(f"Probabilidad complementaria:")
    print(f"  P(lluvia) = {p_lluvia}")
    print(f"  P(no lluvia) = 1 - P(lluvia) = {p_no_lluvia}")
    print()

    # Simulación Monte Carlo — probabilidad empírica
    print("Simulación Monte Carlo — lanzar moneda 10.000 veces:")
    np.random.seed(42)
    lanzamientos = np.random.randint(0, 2, size=10000)  # 0=cara, 1=cruz
    p_cara_empirica = np.mean(lanzamientos == 0)
    print(f"  Probabilidad empírica de cara: {p_cara_empirica:.4f}")
    print(f"  Teórica: 0.5000")
    print(f"  Con suficientes muestras, la probabilidad empírica converge a la teórica.")
    print(f"  (Ley de los Grandes Números)")
    print()

    # Probabilidad condicional
    print("Probabilidad condicional P(A|B) = P(A y B) / P(B)")
    print()
    print("Ejemplo: En un grupo de 100 estudiantes:")
    print("  60 estudian programación (P)")
    print("  40 estudian matemáticas  (M)")
    print("  25 estudian ambas        (P ∩ M)")

    total = 100
    p_prog = 60 / total
    p_mat = 40 / total
    p_ambas = 25 / total

    p_mat_dado_prog = p_ambas / p_prog
    print(f"  P(P) = {p_prog}")
    print(f"  P(M) = {p_mat}")
    print(f"  P(P∩M) = {p_ambas}")
    print(f"  P(M|P) = P(M∩P)/P(P) = {p_ambas}/{p_prog} = {p_mat_dado_prog:.4f}")
    print(f"  'Si ya estudia programación, hay un {p_mat_dado_prog:.1%} de chance de que también estudie mat.'")


# ============================================================
# SECCIÓN 5: La distribución normal
# ============================================================

def seccion_distribucion_normal():
    print("\n" + "=" * 60)
    print("SECCIÓN 5: La Distribución Normal (Campana de Gauss)")
    print("=" * 60)

    print("La distribución normal N(μ, σ) describe datos que se acumulan")
    print("simétricamente alrededor de la media μ.")
    print()
    print("Regla empírica (68-95-99.7):")
    print("  68% de los datos caen en [μ-σ, μ+σ]")
    print("  95% de los datos caen en [μ-2σ, μ+2σ]")
    print("  99.7% de los datos caen en [μ-3σ, μ+3σ]")
    print()

    # Usar scipy.stats.norm
    mu = 70      # media: puntaje promedio de un examen
    sigma = 10   # desvío: variación típica

    norm_dist = stats.norm(loc=mu, scale=sigma)

    print(f"Distribución de notas: N(μ={mu}, σ={sigma})")
    print()

    # Probabilidades
    p_mayor_80 = 1 - norm_dist.cdf(80)
    p_entre_60_80 = norm_dist.cdf(80) - norm_dist.cdf(60)
    print(f"P(nota > 80) = {p_mayor_80:.4f}  ({p_mayor_80:.1%})")
    print(f"P(60 < nota < 80) = {p_entre_60_80:.4f}  ({p_entre_60_80:.1%})")
    print()

    # Percentiles
    p10 = norm_dist.ppf(0.10)
    p90 = norm_dist.ppf(0.90)
    print(f"Percentil 10 (nota baja): {p10:.1f}")
    print(f"Percentil 90 (nota alta): {p90:.1f}")
    print()

    # Z-score: estandarización
    print("Z-score: cuántos desvíos estándar está un dato de la media")
    print("  z = (x - μ) / σ")
    print()
    for nota in [55, 65, 70, 80, 90]:
        z = (nota - mu) / sigma
        percentil = norm_dist.cdf(nota) * 100
        print(f"  Nota {nota}: z = {z:+.1f}  →  percentil {percentil:.1f}°")
    print()
    print("El z-score normaliza datos de distintas escalas al mismo rango.")
    print("Es clave en machine learning para escalar features (StandardScaler).")


# ============================================================
# MAIN
# ============================================================

def main():
    print("\n" + "#" * 60)
    print("  MÓDULO 05: ESTADÍSTICA DESCRIPTIVA CON PYTHON")
    print("#" * 60)

    seccion_tendencia_central()
    seccion_dispersion()
    seccion_percentiles()
    seccion_probabilidad()
    seccion_distribucion_normal()

    print("\n" + "=" * 60)
    print("FIN DEL MÓDULO 05")
    print("Siguiente: 06_MatematicaDiscreta/logica_y_conjuntos.py")
    print("=" * 60)


if __name__ == "__main__":
    main()
