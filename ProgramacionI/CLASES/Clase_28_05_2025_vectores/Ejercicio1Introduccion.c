/*Dada una lista de 10 valores enteros.
Se pide:
a-) Cargar la lista en memoria en un vector llamado A.
b-) Copiar este vector en otro llamado B.
c-) Generar un vector C correspondiente a la suma de A y B.
d-) Copiar A en orden inverso en otro vector llamado D.
e-) Listar los cuatro vectores simult�neamente informando en la primera columna el
n�mero de orden de los elementos.
f-) Posiciones de elementos pares del vector A.
g-) Elementos de posiciones impares del vector A.
h-) La suma de los elementos del vector A.
i-) Valor promedio del vector A.
j-) Cantidad de elementos iguales a 32 del vector A.
k-) M�ximo Valor del vector A (multiple)*/
#include <stdio.h>
//prototipos o declaraciones de funciones
void CARGA(int [],int);
void INFORME_PRUEBA(int[],int);
void COPIA(int[],int[],int);
void SUMA(int[],int[],int[],int);
void INVERSO(int[],int[],int);
void INFORME(int[],int [],int[],int[],int);
void ELEMENTOS_PARES(int[],int);
void POSICION_IMPAR(int[],int);
int SUMA_ELEMENTOS(int[],int);
float PROMEDIO(int , int);
int CUENTA_CANTIDAD (int[],int,int);
int MAXIMO_VECTOR(int[],int);
void INFO_POSICION_MAXIMO (int[],int,int);
int main(void)
{
 int VA[10], VB[10],VC[10],VD[10], S, CANT, MAX;
 
 //a-) Cargar la lista en memoria en un vector llamado A.
 CARGA(VA,10);
 INFORME_PRUEBA(VA,10);
 //b-)Copiar este vector en otro llamado B.
 COPIA(VA,VB,10);
 //c-) Generar un vector C correspondiente a la suma de A y B.
 SUMA(VA,VB,VC,10);
 //d-) Copiar A en orden inverso en otro vector llamado D.
 INVERSO(VA,VD,10);
 // f-)Listar los cuatro vectores simult�neamente informando en la primera columna el
 //n�mero de orden de los elementos.
 INFORME(VA,VB,VC,VD,10);
 //f-) Posiciones de elementos pares del vector A.
 ELEMENTOS_PARES(VA,10);
 //g-) Elementos de posiciones impares del vector A.
 POSICION_IMPAR(VA,10);
 //h-) La suma de los elementos del vector A.
 S = SUMA_ELEMENTOS(VA,10);
 printf("\nLA SUMA DE LOS ELEMENTOS DE VA ES %d ", S);
 //i-) Valor promedio del vector A.
 printf("\nVALOR PROMEDIO DE VA %.2f", PROMEDIO(S,10));
 //j-) Cantidad de elementos iguales a 32 del vector A.
 CANT = CUENTA_CANTIDAD (VA,10,32);
 printf("\nLA CANTIDAD DE ELEMENTOS IGUALES A 32 DEL VECTOR A ES %d",CANT);
 //k-) M�ximo Valor del vector A (multiple)
 MAX = MAXIMO_VECTOR(VA,10);
 printf("\nEL MAXIMO VALOR DEL VECTOR VA ES %d ", MAX);
 // Indicar las posiciones donde se encuentran los maximos
 INFO_POSICION_MAXIMO (VA,MAX,10);
}
///////////////////////////////////////////////////////
void CARGA(int V[], int CE)
{
 int I;
 for (I=0; I<CE; I++)
 {
   printf("Ingresar elemento en posicion %d: ", I+1);
   scanf ("%d",&V[I]);	
 }	
}
//////////////////////////////////////////////////////
void INFORME_PRUEBA(int V[],int CE)
{ int I;
  printf("INFORME PRUEBA DE CARGA ");
  for(I=0; I<CE; I++)
   {
     printf("\n ELEMENTO %d",I+1);
    printf(": ");
    printf("%d",V[I]);
   }
}
//////////////////////////////////////////////////////
void COPIA(int Vorigen[],int Vdestino[], int CE)
{
 int I;
 for (I=0; I<CE; I++)
     Vdestino[I]= Vorigen[I];
}
//////////////////////////////////////////////////////
void SUMA(int V1[],int V2[],int V3[],int CE)
{
  int I;	
  for (I=0; I<CE; I++)	
       V3[I] = V1[I] + V2[I];
}
/////////////////////////////////////////////////////
void INVERSO(int V[],int Vinverso[],int CE)
{
 int I;	
 for (I=0; I<CE; I++)	
 	Vinverso[I] = V[CE-1-I];	
}
////////////////////////////////////////////////////
void INFORME(int V1[],int V2[],int V3[],int V4[], int CE)
{
 int I;
 printf("\n POSICION  VECTOR A VECTOR B VECTOR C VECTOR D  ");
 for (I=0; I<CE; I++)
 	printf("\n %8d %8d %8d %8d %8d",I+1,V1[I],V2[I],V3[I],V4[I]);	
}
/////////////////////////////////////////////////////////////////
void ELEMENTOS_PARES(int V[], int CE)
{
  int I;
  printf("\nPOSICIONES DE ELEMENTOS PARES ");
  for (I=0; I<CE; I++)	
      if (V[I]%2==0)
         printf("\n%d", I+1);
}
////////////////////////////////////////////////////////////////
void POSICION_IMPAR(int V[],int CE)
{
 int I;
 printf("\nELEMENTOS DE POSICIONES IMPARES ");
 for (I=0; I<CE; I++)	
 	  if (V[I]%2!=0)
         printf("\n%d", I+1);
}
//////////////////////////////////////////////////////////////
int SUMA_ELEMENTOS(int V[],int CE)
{
  int I , SUM = 0;	
  for (I=0; I<CE; I++)	
  	SUM +=V[I];
  return SUM;	
}
////////////////////////////////////////////////////////////////
float PROMEDIO(int S , int CE)
{
	return (float)S/CE;
}
///////////////////////////////////////////////////////////////
int CUENTA_CANTIDAD (int V [],int CE ,int Valor)
{
 int I, CONT=0;
 for (I=0; I<CE; I++)	 	
 	if (V[I]==Valor)
 		CONT++;
 return CONT;
 	
}
////////////////////////////////////////////////////////////////
int MAXIMO_VECTOR(int V[],int CE)
{
 int I, MAXI;	
 for (I=0; I<CE; I++)
   //if (I==0)
   //   MAXI = V[I];	
   // else
   //   if (V[I]> MAXI)
   //	   MAXI = V[I]; 
   if ((I==0) || (V[I]> MAXI))
      MAXI = V[I]; 
  return MAXI;	
}
//////////////////////////////////////////////////////////
void INFO_POSICION_MAXIMO (int V[],int MAX ,int CE)
{
  int I;
  printf("\n POSICIONES DEL MAXIMO ");
  for (I=0; I<CE; I++)
      if (V[I]== MAX)
	   printf("%d", I+1);	
}


