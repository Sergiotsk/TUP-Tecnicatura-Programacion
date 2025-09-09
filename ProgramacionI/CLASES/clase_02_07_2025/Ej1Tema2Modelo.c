/*Dada una matriz con valores enteros de 4x3
Implementar solamente una funci�n que determine y guarde en un vector el m�nimo valor por fila.*/
#include <stdio.h>
void FUNCION_MIN_FILA(int[][3], int [], int , int);
void  MINIMO_VALOR_FILA(int[], int);

int main(void)
{
 int MAT[4][3]={10,12,15,40, 30,20,80,24,55, 14, 36,11};
            /*  0  10  12  15 -> 10
		    1  40  30  20 -> 20
		    2  80  24  55 -> 24
		    3  14  36  11 -> 11	*/
 int MINFila[4];
 FUNCION_MIN_FILA(MAT, MINFila, 4 , 3);
 MINIMO_VALOR_FILA(MINFila, 4 );

}
//////////////////////////////////////////////////////////
void FUNCION_MIN_FILA(int M[][3], int V[], int CF, int CC)
{
 int I, J;
 for (I=0;I<CF; I++)
 {
 	V[I] = M[I][0];
 	for (J=1;J<CC; J++)
 	   if (M[I][J]< V[I])
 	     	V[I] = M[I][J];
  }	
	
	
}
/////////////////////////////////////////////////////////
void  MINIMO_VALOR_FILA(int V[], int CF)
{
 int I;
 printf("\n MINIMO VALOR POR FILA ");
 for (I=0;I<CF; I++)	
	printf ("\nFILA: %d VALOR: %d ", I+1, V[I]);

}

