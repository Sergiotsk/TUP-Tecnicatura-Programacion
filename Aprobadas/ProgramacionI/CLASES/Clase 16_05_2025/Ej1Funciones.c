/*Implementar una función genérica que sume 2 números enteros. Utilizarla en
distintas situaciones (valores fijos, variables, …..)*/
#include <stdio.h>
#define NUMERO1 10
#define NUMERO2 65
int SUMA (int, int);  // prototipo o declaracion de la funcion

main()
{
 int NRO1,NRO2,SUM;
 printf("\nIngresar un numero entero ");
 scanf("%d",&NRO1);
 printf("\nIngresar otro numero entero ");
 scanf("%d",&NRO2);
 //SUM = SUMA (NRO1,NRO2);
 //printf("\nLA SUMA DE %d y %d ES %d", NRO1,NRO2,SUM);
 printf("\nLA SUMA DE %d y %d ES %d", NRO1,NRO2,SUMA(NRO1,NRO2));
 printf("\nLA SUMA DE LAS CONSTANTES %d y %d ES %d", NUMERO1, NUMERO2,SUMA(NUMERO1,NUMERO2) );
}
////////////////////////////////////////////////////////////////
//definicion de la funcion (codigo)
int SUMA (int N1, int N2)
{
 //int S;	
 //S = N1 + N2;
 //return S;
 return (N1+N2);	
}




