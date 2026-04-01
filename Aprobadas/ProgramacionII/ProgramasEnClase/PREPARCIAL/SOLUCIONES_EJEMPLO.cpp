/* 
   SOLUCIONES DE EJEMPLO - EJERCICIOS LOTEO
   Estos son ejemplos de cómo resolver algunos ejercicios.
   Úsalos como referencia, pero intenta resolverlos tú primero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// ... (aquí irían las clases TERRENO, LOTEO, LOTE, INVERSOR, COUNTRY del archivo original)

// ============================================================================
// EJERCICIO 1: CONTAR LOTES VENDIDOS
// ============================================================================

void COUNTRY::CONTAR_LOTES_VENDIDOS()
{
    INVERSOR * P;
    LOTE * Q;
    int total = 0;
    
    P = INICIO;
    while (P) {
        Q = P->INILOTE;
        while (Q) {
            total++;
            Q = Q->SIG;
        }
        P = P->SIG;
    }
    
    printf("\nTotal de lotes vendidos: %d\n", total);
}

// ============================================================================
// EJERCICIO 2: MOSTRAR INVERSOR POR NOMBRE
// ============================================================================

void COUNTRY::MOSTRAR_INVERSOR(char * nombre)
{
    INVERSOR * P = BUSCAR(nombre);
    
    if (P == NULL) {
        printf("\nEl inversor '%s' no existe.\n", nombre);
        return;
    }
    
    LOTE * Q = P->INILOTE;
    int cantidad = 0;
    
    while (Q) {
        cantidad++;
        Q = Q->SIG;
    }
    
    printf("\nInversor: %s\n", P->NOM);
    printf("Cantidad de lotes: %d\n", cantidad);
    
    // Calcular total gastado (necesita acceso a LOTEO)
    // Esto se haría en otra función que reciba LOTEO como parámetro
}

// Versión completa con LOTEO:
void COUNTRY::MOSTRAR_INVERSOR_COMPLETO(char * nombre, LOTEO L)
{
    INVERSOR * P = BUSCAR(nombre);
    
    if (P == NULL) {
        printf("\nEl inversor '%s' no existe.\n", nombre);
        return;
    }
    
    LOTE * Q = P->INILOTE;
    TERRENO * T;
    int cantidad = 0;
    int totalGastado = 0;
    
    printf("\n=== INVERSOR: %s ===\n", P->NOM);
    
    while (Q) {
        cantidad++;
        printf("Lote: %s", Q->CODIGOLOTE);
        
        // Buscar precio en LOTEO
        T = L.INICIO;
        while (T) {
            if (strcmp(Q->CODIGOLOTE, T->CODIGOLOTE) == 0) {
                totalGastado += T->PRECIO;
                printf(" - Precio: %d\n", T->PRECIO);
                break;
            }
            T = T->SIG;
        }
        
        Q = Q->SIG;
    }
    
    printf("\nCantidad de lotes: %d\n", cantidad);
    printf("Total gastado: %d\n", totalGastado);
}

// ============================================================================
// EJERCICIO 4: PROMEDIO DE PRECIOS
// ============================================================================

float LOTEO::PROMEDIO_PRECIOS()
{
    TERRENO * P = INICIO;
    int suma = 0;
    int cantidad = 0;
    
    while (P) {
        suma += P->PRECIO;
        cantidad++;
        P = P->SIG;
    }
    
    if (cantidad == 0) {
        return 0.0;
    }
    
    return (float)suma / cantidad;
}

// ============================================================================
// EJERCICIO 5: INVERSOR CON MÁS LOTES
// ============================================================================

void COUNTRY::MAS_LOTES()
{
    INVERSOR * P = INICIO;
    int maxLotes = -1;
    char nomMax[20] = "";
    
    while (P) {
        LOTE * Q = P->INILOTE;
        int cantidad = 0;
        
        while (Q) {
            cantidad++;
            Q = Q->SIG;
        }
        
        if (cantidad > maxLotes) {
            maxLotes = cantidad;
            strcpy(nomMax, P->NOM);
        }
        
        P = P->SIG;
    }
    
    if (maxLotes >= 0) {
        printf("\nEl inversor con mas lotes es: %s con %d lotes\n", 
               nomMax, maxLotes);
    } else {
        printf("\nNo hay inversores registrados.\n");
    }
}

// ============================================================================
// EJERCICIO 8: TOTAL RECAUDADO
// ============================================================================

int COUNTRY::TOTAL_RECAUDADO(LOTEO L)
{
    INVERSOR * P = INICIO;
    int total = 0;
    
    while (P) {
        LOTE * Q = P->INILOTE;
        
        while (Q) {
            TERRENO * T = L.INICIO;
            
            while (T) {
                if (strcmp(Q->CODIGOLOTE, T->CODIGOLOTE) == 0) {
                    total += T->PRECIO;
                    break;
                }
                T = T->SIG;
            }
            
            Q = Q->SIG;
        }
        
        P = P->SIG;
    }
    
    return total;
}

// ============================================================================
// EJERCICIO 10: LOTES EN RANGO DE PRECIOS
// ============================================================================

void LOTEO::LOTES_EN_RANGO(int precioMin, int precioMax)
{
    TERRENO * P = INICIO;
    int encontrados = 0;
    
    printf("\n=== LOTES EN RANGO [%d - %d] ===\n", precioMin, precioMax);
    
    while (P) {
        if (P->PRECIO >= precioMin && P->PRECIO <= precioMax) {
            printf("Codigo: %s - Precio: %d\n", P->CODIGOLOTE, P->PRECIO);
            encontrados++;
        }
        P = P->SIG;
    }
    
    printf("\nTotal encontrados: %d\n", encontrados);
}

// ============================================================================
// EJERCICIO 11: QUIÉN COMPRÓ UN LOTE ESPECÍFICO
// ============================================================================

void COUNTRY::QUIEN_COMPRO(char * codigoLote)
{
    INVERSOR * P = INICIO;
    bool encontrado = false;
    
    printf("\n=== BUSCANDO LOTE: %s ===\n", codigoLote);
    
    while (P) {
        LOTE * Q = P->INILOTE;
        
        while (Q) {
            if (strcmp(Q->CODIGOLOTE, codigoLote) == 0) {
                printf("Comprado por: %s\n", P->NOM);
                encontrado = true;
                break; // Si un inversor solo puede tener un lote una vez
            }
            Q = Q->SIG;
        }
        
        P = P->SIG;
    }
    
    if (!encontrado) {
        printf("El lote no fue comprado por ningun inversor.\n");
    }
}

// ============================================================================
// NOTAS IMPORTANTES:
// ============================================================================

/*
1. SIEMPRE verifica punteros NULL antes de usarlos
2. Usa punteros auxiliares para no perder la referencia al inicio
3. En listas simplemente enlazadas, solo puedes avanzar hacia adelante
4. Para eliminar nodos, necesitas mantener referencia al nodo anterior
5. Para insertar ordenado, busca la posición correcta antes de insertar
6. Libera memoria con 'delete' cuando elimines nodos
*/

