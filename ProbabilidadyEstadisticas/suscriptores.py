from scipy.stats import binom

# --- TUS DATOS ---
total_seguidores = 50000      # CAMBIA ESTO por tu número real de seguidores
precio_suscripcion = 5.00     # Precio en USD (o tu moneda)
meta_porcentaje = 0.005        # Tu meta es el 1% (0.01)

# --- ESCENARIOS DE LA INDUSTRIA ---
# Tasa: Probabilidad real de que un seguidor pague
escenarios = {
    "Pesimista (0.1%)": 0.001,
    "Realista (0.3%)":  0.003,
    "Promedio (0.5%)":  0.005,
    "PIOLARDO (0.9%)":  0.009,
    "Bueno (1%)":     0.010,
    "Excelente (2%)": 0.020
}

meta_suscriptores = int(total_seguidores * meta_porcentaje)

print(f"\n--- SIMULADOR DE MONETIZACIÓN ---")
print(f"Seguidores: {total_seguidores:,}")
print(f"Meta (1%):  {meta_suscriptores} suscriptores de pago")
print(f"Precio:     ${precio_suscripcion}")
print("-" * 75)
print(f"{'Escenario':<18} | {'Tasa Real':<10} | {'Suscriptores':<12} | {'Ingreso Mensual':<15} | {'Prob. de Meta'}")
print("-" * 75)

for nombre, p_real in escenarios.items():
    # Valor esperado (Media)
    esperados = int(total_seguidores * p_real)
    
    # Ingresos estimados
    ingresos = esperados * precio_suscripcion
    
    # Probabilidad de alcanzar TU meta del 1% (meta_suscriptores)
    # Si la tasa real es menor a tu meta, la probabilidad cae rápido.
    prob_meta = 1 - binom.cdf(meta_suscriptores - 1, total_seguidores, p_real)
    
    print(f"{nombre:<18} | {p_real:.1%}       | {esperados:<12} | ${ingresos:,.2f}       | {prob_meta:.4f}")

print("-" * 75)
print("NOTA: La columna 'Prob. de Meta' indica la chance de llegar al 0.05% de tus seguidores")
print("      dado ese escenario de conversión real.")
