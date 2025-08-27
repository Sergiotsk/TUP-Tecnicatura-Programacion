/*
1-) Dado un conjunto de valores enteros leerlos y luego:
a) Cargar una matriz M1 de 3 x 2 por filas y una matriz M2 de 3 x 4 por columnas.
b) La suma de los elementos de las columnas de M1.
c) La suma de los elementos de las filas de M1.
d) La suma total de los elementos de M1.
e) El valor promedio de M1.
f) M�ximo valor de la matriz M1 y en qu� posici�n (fila-columna) se encuentra.
NOTA: puede haber varios m�ximos */
#include<stdio.h>

void CARGAxFILAS(int [][2],int,int);
void INFORME_MATRIZ_M1(int [][2],int,int);
void CARGAxCOLUMNAS(int [][4],int, int);
void INFORME_MATRIZ_M2(int [][4],int,int);
void SUMA_COLUMNA(int[][2],int[],int,int);
void INFORME_VECTOR(int [],int);
void SUMA_FILA(int[][2],int[],int,int);
int SUMA_ELEMENTOS_MATRIZ(int[][2],int,int);
int MAXIMO_VALOR_MATRIZ(int[][2],int,int);
void INFORME_MAXIMO(int[][2],int,int,int);

int main(void)
{
	int M1[3][2],M2[3][4],VsumaColumna[2]={0},VsumaFila[3]={0},MAXI=0;
	//a) Cargar una matriz M1 de 3 x 2 por filas y una matriz M2 de 3 x 4 por columnas.
	CARGAxFILAS(M1,3,2);
	INFORME_MATRIZ_M1(M1,3,2);	
	CARGAxCOLUMNAS(M2,3,4);
	INFORME_MATRIZ_M2(M2,3,4);
	SUMA_COLUMNA(M1,VsumaColumna,3,2);
	printf("\nInforme vector -suma de COLUMNAS de la matriz M1");
	INFORME_VECTOR(VsumaColumna,2);
	//c 
	SUMA_FILA(M1,VsumaFila,3,2);
	printf("\nInforme vector -suma de fila de la matriz M1");
	//d)
	//E)
	
	//Maximo valor de la matriz
	MAXI=MAXIMO_VALOR_MATRIZ(M1,3,2);
	
	INFORME_MAXIMO(M1,MAXI,3,2);
	
}
///////////////////////////////////////////////////FUNCIONES
void CARGAxFILAS(int M[][2],int F,int C)
{	
	int I,J;
	
	printf("\nCarga de datos por fila en la matriz ");
	for (I=0;I<F;I++)
		for(J=0;J<C;J++)
		{
			printf("\nIngresar datos n fila: %d y columna: %d :",I,J);
			scanf("%d",&M[I][J]);
		}	
}
///////////////////////////////////////
void INFORME_MATRIZ_M1(int M[][2],int F,int C)
	{	
		int I,J;
		printf("\n INFORME MATRIZ M1");
		
		for(I=0;I<F;I++)
			
		{
			printf("\n");
			for(J=0;J<C;J++)
			printf("%4d",M[I][J]);					
		}

	  }
/////////////////////////////////////
void CARGAxCOLUMNAS(int M[][4],int F, int C)
	{
			
	int I,J;
	
	printf("\nCarga de datos por COLUMNA en la matriz M2 ");
	for (J=0;J<C;J++)
		for(I=0;I<F;I++)
		{
			printf("\nIngresar datos n fila: %d y columna: %d :",I,J);
			scanf("%d",&M[I][J]);
		}
	
	
	}
/////////////////////////////////////
void INFORME_MATRIZ_M2(int M [][4],int F,int C)	
	{
	int I,J;
	printf("\n INFORME MATRIZ M2");
		
	for(I=0;I<F;I++)
		{
			printf("\n");
			for(J=0;J<C;J++)
			printf("%4d",M[I][J]);				
						
		}
	}
////////////////////////////////////
void SUMA_COLUMNA(int M[][2],int V[],int F,int C)
	{
		    int I,J;		
			for(I=0;I<C;I++)
				for(J=0;J<F;J++)
				  V[J]+=M[I][J];		   		
		
		}	
////////////////////////////////////
void SUMA_FILA(int M[][2],int V[],int F,int C)
{
 
int I,J;		
			for(J=0;J<C;J++)
				for(I=0;I<F;I++)
					V[J]+=M[I][J];
}		
///////////////////////////////////
void INFORME_VECTOR(int V[],int CE)
	{	
	  int I;
	
			for(I=0;I<CE;I++)	
		       printf("\n%4d",V[I]);				
		
	}
//////////////////////////////////
int SUMA_ELEMENTOS_MATRIZ(int M [][2],int F,int C)
{
	
	int I,J,SUM=0;	
		for (I=0;I<F;I++)
			{
				for(J=0;J<C;J++)
				SUM+=M[I][J];			
		
			}
		return SUM;
		
}
/////////////////////////////////
int MAXIMO_VALOR_MATRIZ(int M [][2],int F,int C)
{
	int I,J;
	int MAXI=M[0][0];
	for (I=0;I<F;I++)
		{
				for(J=0;J<C;J++)
				if (M[I][J]>MAXI)
				MAXI=M[I][J];
				
		 }		
				return MAXI;
	
	
}
////////////////////////////////
void INFORME_MAXIMO(int M[][2],int MAXI,int F,int C)
{
		
	int I,J;
	printf("\nMaximo valor de la matriz M1 es: %d ",MAXI);
	printf("\nY se encuentra en");
	for (I=0;I<F;I++)
			for(J=0;J<C;J++)
			if (M[I][J]==MAXI)
			printf("\n FILA: %d COLUMNA: %d",I+1,J+1);
			
}
