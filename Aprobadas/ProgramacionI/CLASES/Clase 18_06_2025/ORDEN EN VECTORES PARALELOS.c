/* DADA UNA LISTA DE PRODUCTOS (CODIGOS)  CON EL PRECIO RESPECTIVO.
SE ORDENA EN FORMA ASCENDENTE POR CODIGO DEPRODUCTO*/
#include <stdio.h>
#define N 10

void MOSTRAR (int[], float[],  int);
void ORDEN (int[], float[], int);


main()
{
 int CODPROD[N]= { 1000, 4000, 3500, 8000,6000,2000,3000,7000,5500,6600}; 
 float PRECIO[N]={ 201,405,300,80,405,150,361,400,206,309};
 
 printf ("\n\n INFORME ANTES DEL ORDENAMIENTO");
 MOSTRAR (CODPROD, PRECIO, N);
 
 ORDEN (CODPROD, PRECIO, N);

 printf ("\n\n INFORME DESPUES DEL ORDENAMIENTO");
 MOSTRAR (CODPROD, PRECIO, N);
}

///////////////////////////////////////////////////////////////////
/* DEFINICION O CODIGO DE LAS FUNCIONES */
//////////////////////////////////////////////////////////////////

/* funcion muestra codigo  y el precio respectivo */
void MOSTRAR (int V1[], float V2[], int CE)
{
  int I;
  printf("\n CODIGO DE PRODUCTO	        PRECIO    ");
  for (I =0; I < CE; I++)	
     printf ("\n\t %5d	\t     %10.2f  " , V1[I], V2[I]);
}

///////////////////////////////////////////////////////////////
/* funcion orden , ordena en forma ascendente por Codigo */
void ORDEN (int V1[], float V2[],  int CE)
{
	int I,J,AUXI;
	float AUXF;
			
	for (I=0; I<CE-1; I++)
		for(J=0; J<CE-1-I; J++)
		if( V1[J] > V1[J+1]) 
		{
			
			AUXI = V1[J];       
			V1[J] = V1[J+1];
			V1[J+1] = AUXI;
			
			AUXF = V2[J];     
			V2[J] = V2[J+1];
			V2[J+1] = AUXF;
					
		}
}
/////////////////////////////////////////////////////////////////////////////////

