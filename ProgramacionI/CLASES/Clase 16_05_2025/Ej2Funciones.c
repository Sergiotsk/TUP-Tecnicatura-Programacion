//Implementar una funci�n gen�rica que retorne 1 si el numero recibido es �PAR�
// y 0 si el valor recibido es �IMPAR�
#include <stdio.h>
int PAR_IMPAR(int); //  prototipo o declaracion de la funcion

int main(void)
{
 int NRO;
 printf("\nIngresar un numero entero ");
 scanf("%d",&NRO);	
 //if (PAR_IMPAR(NRO)==1)
 if (PAR_IMPAR(NRO))	
 	printf("\n EL NUMERO INGRESADO ES PAR ");
 else
    printf("\n EL NUMERO INGRESADO ES IMPAR ");
	
}
//////////////////////////////////////////////////////////////
int PAR_IMPAR(int N)
{
 if (N%2 == 0)	
     return 1;
 //else
     return 0;
}





