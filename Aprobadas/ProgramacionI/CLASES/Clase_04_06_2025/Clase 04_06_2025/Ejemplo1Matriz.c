#include <stdio.h>
int main(void)
{
  // tipo de dato IDENTIFICADOR [CANTIDAD DE FILAS][CANTIDAD DE COLUMNAS]
  int MAT[2][3]; // declaracion de matriz de enteros de 2 x 3	
  int I, J, CONT=1;
  //INGRESO DE VALORES EN LA MATRIZ 
  for (I=0; I<2; I++)   // recorre fila
  	for ( J=0; J<3;J++) // recorre columna
  		MAT[I][J]= CONT++;
  
  /*I=0
  	 J=0  -> MAT[0][0] -> 1
  	 J=1  -> MAT[0][1] -> 2
  	 J=2  -> MAT[0][2] -> 3
    I=1
      J=0  -> MAT[1][0] -> 4
  	J=1  -> MAT[1][1] -> 5
  	J=2  -> MAT[1][2] -> 6
   // INFORME DE LOS VALORES DE LA MATRIZ */
   printf ("\n INFORME \n");
   for (I=0;I<2; I++)
   {
	for ( J=0; J<3;J++)
         printf("%3d",MAT[I][J] );
      printf("\n");
   }
}
   
   
   
   
