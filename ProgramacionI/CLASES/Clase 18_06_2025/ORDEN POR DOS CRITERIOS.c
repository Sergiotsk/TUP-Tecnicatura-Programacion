/* ORDEN DE UNA LISTA DE PRODUCTOS CON LA CANTIDAD VENDIDA.
SE ORDENA EN FORMA DESCENDENTE POR CANTIDAD VENDIDA Y A IGUALDAD DE ESTA POR CODIGO DE PRODUCTO EN FORMA ASCENDENTE
*/
#include <stdio.h>
#define N 10

void MOSTRAR (int[], int[],  int);
void ORDEN (int[], int[], int);


main()
{
 int CODPROD[N]= { 1000, 4000, 3500, 8000,6000,2000,3000,7000,5500,6600}; 
 int CANTVEN[N]={ 20,40,30,80,40,80,80,90,20,30};
 
 printf ("\n\n INFORME ANTES DEL ORDENAMIENTO");
 MOSTRAR (CODPROD, CANTVEN, N);
 
 ORDEN (CODPROD, CANTVEN, N);

 printf ("\n\n INFORME DESPUES DEL ORDENAMIENTO");
 MOSTRAR (CODPROD, CANTVEN, N);
}

///////////////////////////////////////////////////////////////////
/* DEFINICION O CODIGO DE LAS FUNCIONES */
//////////////////////////////////////////////////////////////////

/* funcion muestra codigo  y cantidad de ventas realizadas */
void MOSTRAR (int V1[], int V2[], int CE)
{
  int I;
  printf("\n CODIGO DE PRODUCTO	        CANTIDAD VENDIDA    ");
  for (I =0; I < CE; I++)	
     printf ("\n\t %5d	\t     %6d  " , V1[I], V2[I]);
}

///////////////////////////////////////////////////////////////
/* funcion orden , ordena en forma descendente por Cantidad Vendida y a igualdad de esta por codigo en forma ascendente*/
void ORDEN (int V1[], int V2[],  int CE)
{
	int I,J,AUXI;
			
	for (I=0; I<CE-1; I++)
		for(J=0; J<CE-1-I; J++)
		if( (V2[J]<V2[J+1]) || ( (V2[J]==V2[J+1]) && (V1[J]< V1[J+1]) ) )
		{
			
			AUXI = V1[J];       
			V1[J] = V1[J+1];
			V1[J+1] = AUXI;
			
			AUXI = V2[J];     
			V2[J] = V2[J+1];
			V2[J+1] = AUXI;
					
		}
}
/////////////////////////////////////////////////////////////////////////////////







