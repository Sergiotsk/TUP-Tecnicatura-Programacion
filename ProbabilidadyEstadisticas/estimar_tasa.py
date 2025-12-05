from scipy.stats import norm
import math

def calcular_intervalo(exitos, total, confianza=0.95):
    """
    Calcula el intervalo de confianza para una proporción (tasa de conversión).
    """
    if total == 0:
        return 0, 0, 0
        
    p_hat = exitos / total  # Tasa observada
    
    # Valor Z para el nivel de confianza (1.96 para 95%)
    z = norm.ppf((1 + confianza) / 2)
    
    # Error estándar
    error_estandar = math.sqrt((p_hat * (1 - p_hat)) / total)
    margen_error = z * error_estandar
    
    limite_inferior = max(0, p_hat - margen_error)
    limite_superior = min(1, p_hat + margen_error)
    
    return p_hat, limite_inferior, limite_superior

def main():
    print("\n--- CALCULADORA DE EFECTIVIDAD (FACEBOOK) ---")
    print("Introduce los datos de tu panel de estadísticas (Meta Business Suite):")
    
    try:
        # Solicitamos los datos de Facebook
        alcance = int(input("1. Alcance (Personas alcanzadas): "))
        nuevos_seguidores = int(input("2. Nuevos Seguidores (o conversiones): "))
        
        if alcance <= 0:
            print("Error: El alcance debe ser mayor a 0.")
            return

        tasa, bajo, alto = calcular_intervalo(nuevos_seguidores, alcance)

        print(f"\n--- RESULTADOS DEL ANÁLISIS ---")
        print(f"Muestra (Alcance):   {alcance}")
        print(f"Éxitos (Seguidores): {nuevos_seguidores}")
        print(f"Tasa de Conversión:  {tasa:.4%} (Tu rendimiento actual)")
        print("-" * 50)
        print(f"INTERVALO DE CONFIANZA (95%):")
        print(f"Tu tasa real oscila entre [{bajo:.4%}] y [{alto:.4%}]")
        print("-" * 50)
        
        # Interpretación práctica
        print("INTERPRETACIÓN PARA TU ESTRATEGIA:")
        print(f"Con un 95% de seguridad, por cada 1,000 personas nuevas que alcances,")
        print(f"obtendrás entre {int(bajo*1000)} y {int(alto*1000)} nuevos seguidores.")
        
        # Comparación con tu meta del 1.05%
        meta = 0.0105
        if bajo >= meta:
            print(f"\n✅ ¡EXCELENTE! Tu tasa mínima ({bajo:.2%}) ya supera tu meta del 1.05%.")
        elif alto < meta:
            print(f"\n❌ A MEJORAR. Tu mejor escenario ({alto:.2%}) aún no llega al 1.05%.")
        else:
            print(f"\n⚠️ ZONA DE INCERTIDUMBRE. Tu meta del 1.05% está dentro del margen de error.")

    except ValueError:
        print("Por favor, introduce solo números enteros (sin puntos ni comas).")

if __name__ == "__main__":
    main()
