#include <stdio.h>
int main(void)
{
  // tipo de dato IDENTIFICADOR [CANTIDAD DE FILAS][CANTIDAD DE COLUMNAS]
  int MAT[3][3]; // declaracion de matriz de enteros de 2 x 3	
  int I, J;
  //INGRESO DE VALORES EN LA MATRIZ 
  for (I=0; I<3; I++)   // recorre fila
  	for ( J=0; J<3;J++) // recorre columna
  	   if ( I == J) 
	     MAT[I][J] = I*J;
	   else
	     MAT[I][J] = 0;
 
   // INFORME DE LOS VALORES DE LA MATRIZ */
   printf ("\n INFORME \n");
   for (I=0;I<3; I++)
   {
	for ( J=0; J<3;J++)
         printf("%3d",MAT[I][J] );
      printf("\n");
   }
}
   
   
   
   
