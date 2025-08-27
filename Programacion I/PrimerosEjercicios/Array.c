#include <stdio.h>

int main() {
    int numeros[4];
    int menor, posicion,i;

    // Ingreso de datos
    for (i = 0; i < 4; i++) {
        printf("Ingresar numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Mostrar los valores ingresados
    printf("Valores ingresados: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Inicializo el menor con el primer número
    menor = numeros[0];
    posicion = 1;

    // Busco el menor comparando con el resto
    for (i = 1; i < 4; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
            posicion = i + 1;
        }
    }

    // Muestro resultados
    printf("El menor valor es %d\n", menor);
    printf("Fue ingresado en la posicion %d\n", posicion);

    return 0;
}

