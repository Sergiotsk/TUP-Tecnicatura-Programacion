/*1-) Dado un conjunto de valores enteros leerlos y luego:
a) Cargar una matriz M1 de 3 x 2 por filas y una matriz M2 de 3 x 4 por columnas.
b) La suma de los elementos de las columnas de M1.
c) La suma de los elementos de las filas de M1.
d) La suma total de los elementos de M1.
e) El valor promedio de M1.
f) Máximo valor de la matriz M1 y en qué posición (fila-columna) se encuentra.
NOTA: puede haber varios máximos*/

#include <stdio.h>
void CARGAxFILAS(int [][2],int,int);
void INFORME_MATRIZ_M1(int [][2],int,int);
void CARGAxCOLUMNAS(int [][4],int,int);
void INFORME_MATRIZ_M2(int [][4],int,int);
void SUMA_COLUMNA(int[][2],int[],int,int);
void INFORME_VECTOR(int [],int);
void SUMA_FILA(int[][2],int[],int,int);
int SUMA_ELEMENTOS_MATRIZ(int [][2],int,int);
int MAXIMO_VALOR_MATRIZ(int [][2],int,int);
void INFORME_MAXIMO(int [][2],int,int,int);
////////////////////////////////////////////////////////////////
main()
{
 int M1[3][2], M2[3][4];
 int VsumaColumna[2]={0}, VsumaFila[3]={0}, S, MAX;
 //Cargar una matriz M1 de 3 x 2 por filas 
 CARGAxFILAS(M1,3,2);
 INFORME_MATRIZ_M1(M1,3,2);
// Carga matriz M2 de 3 x 4 por columnas
 //CARGAxCOLUMNAS(M2,3,4);
 //INFORME_MATRIZ_M2(M2,3,4);
 //La suma de los elementos de las columnas de M1.
 SUMA_COLUMNA(M1,VsumaColumna,3,2);
 printf("\nINFORME VECTOR - SUMA COLUMNAS DE LA MATRIZ M1");
 INFORME_VECTOR(VsumaColumna,2);
 //c) La suma de los elementos de las filas de M1.
 SUMA_FILA(M1,VsumaFila,3,2);
 printf("\nINFORME VECTOR - SUMA FILA DE LA MATRIZ M1");
 INFORME_VECTOR(VsumaFila,3);
 //d) La suma total de los elementos de M1.
 S=SUMA_ELEMENTOS_MATRIZ(M1,3,2);
 printf("\nLA SUMA DE LOS ELEMENTOS DE LA MATRIZ ES %d ",S);
 //e) El valor promedio de M1.
 printf("\nVALOR PROMEDIO DE LA MATRIZ %.2f", (float)S/6);
 //Máximo valor de la matriz M1
 MAX = MAXIMO_VALOR_MATRIZ(M1,3,2);
 INFORME_MAXIMO(M1, MAX, 3, 2);
 
}
/////////////////////////////////////////////////////////////////
void CARGAxFILAS(int M[][2],int F,int C)
{
 int I, J;
 printf("\nCARGA DE DATOS POR FILAS EN LA MATRIZ ");
 for(I=0;I<F;I++)
 	for(J=0;J<C;J++)
	 {
	    printf("\nIngresar dato en Fila: %d y Columna: %d : ",I,J);
		scanf("%d",&M[I][J]);	
	 }	
}
/////////////////////////////////////////////////////////////////
void INFORME_MATRIZ_M1(int M[][2],int F,int C)
{
  int I, J;
  printf("\nINFORME MATRIZ M1");
  for(I=0;I<F;I++)
 	{
	 printf("\n");
	 for(J=0;J<C;J++)
	   printf("%4d",M[I][J]);
	}
}
////////////////////////////////////////////////////////////////
void CARGAxCOLUMNAS(int M[][4],int F,int C)
{
  int I, J;
  printf("\nCARGA DE DATOS POR COLUMNA EN LA MATRIZ ");
  for(J=0;J<C;J++)
 	for(I=0;I<F;I++)
	 {
	    printf("\nIngresar dato en Fila: %d y Columna: %d : ",I,J);
		scanf("%d",&M[I][J]);	
	 }	
}	
//////////////////////////////////////////////////////////////////////
void INFORME_MATRIZ_M2(int M[][4],int F,int C)
{
  int I, J;
  printf("\nINFORME MATRIZ M2");
  for(I=0;I<F;I++)
 	{
	 printf("\n");
	 for(J=0;J<C;J++)
	   printf("%4d",M[I][J]);
	}
}	
////////////////////////////////////////////////////////////////
void SUMA_COLUMNA(int M[][2],int V[],int F,int C)
{
  int I,J;
  for(J=0;J<C;J++)	
	for(I=0;I<F;I++)
	    V[J]+=M[I][J];
}
//////////////////////////////////////////////////////////////
void INFORME_VECTOR(int V[],int CE)
{
  int I;	
  for(I=0;I<CE;I++)	
    printf ("\n%4d",V[I]);
}
//////////////////////////////////////////////////////////////
void SUMA_FILA(int M[][2],int V[],int F,int C)
{
  int I,J;
  for(I=0;I<F;I++)
  	for(J=0;J<C;J++)	
	    V[I]+=M[I][J];
}
//////////////////////////////////////////////////////////////
int SUMA_ELEMENTOS_MATRIZ(int M[][2],int F,int C)
{
 int I,J, SUM =0;
 for(I=0;I<F;I++)
  	for(J=0;J<C;J++)
	  SUM += M[I][J];	
 return SUM;	
}
//////////////////////////////////////////////////////////////
int MAXIMO_VALOR_MATRIZ(int M [][2],int F,int C)
{
  int I,J;
  int MAXI = M[0][0];
  for(I=0;I<F;I++)
  	for(J=0;J<C;J++)
	  if ( M[I][J] > MAXI)
	  	 MAXI = M[I][J];	
  return MAXI;
}
///////////////////////////////////////////////////////////////
void INFORME_MAXIMO(int M[][2],int MAXI,int F,int C)
{
   int I,J;
   printf("\nMAXIMO VALOR DE LA MATRIZ %d ",MAXI);
   printf("\nSE ENCUENTRA EN ")	;
   for(I=0;I<F;I++)
  	for(J=0;J<C;J++)
	  if ( M[I][J] == MAXI)
	      printf("\n FILA: %d  COLUMNA: %d", I, J);
}
