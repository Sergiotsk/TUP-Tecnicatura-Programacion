
/*Primer PROGRAMA*/
#include <stdio.h>

int main() 
{
    int NRO1, NRO2;
    float PROM;
    printf("Ingresar 2 numeros entero: ");
    scanf("%d%D", &NRO1, &NRO2);   
    //PROM=(NRO1 + NRO2)/2;
    PROM=(float)(NRO1 + NRO2)/2;
    
     
     
     printf("\n El promedio es %.2f", PROM);
     
     return 0;
    
    
}

 
