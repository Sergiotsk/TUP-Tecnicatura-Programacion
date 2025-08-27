/*Ordenamiento por Burbujeo*/
#include <stdio.h>
#define N 5

void ORDENAR(int [], int);
void MOSTRAR (int [], int);

main()
{
	int V[]={112,130,200,180,300};
	
	printf ("\n\n\tVECTOR INICIAL (ANTES DEL ORDEN)\n");
	MOSTRAR(V,N);
	
	ORDENAR(V, N);
	
	printf ("\n\n\tVECTOR ORDENADO\n");
	MOSTRAR(V,N);
}
//////////////////////////////////////////////////////////////////////
void MOSTRAR (int VEC[], int CE)
{
	int I;
	for (I=0;I<CE;I++)
		printf("\tPos: %d Valor: %d\n",I, VEC[I]);
}

////////////////////////////////////////////////////////////////////
void ORDENAR(int VEC[], int CE)
{
	int I, J, AUX;
	for(I=0;I<CE-1;I++)
		for (J=0;J<CE-1-I;J++)
			if (VEC[J] < VEC[J+1]) // se ordena en forma descendente
			//if (VEC[J] > VEC[J+1]) // se ordena en forma ascendente 
			   {                   
				AUX=VEC[J];
				VEC[J]=VEC[J+1];
				VEC[J+1]=AUX;
			   }
}

