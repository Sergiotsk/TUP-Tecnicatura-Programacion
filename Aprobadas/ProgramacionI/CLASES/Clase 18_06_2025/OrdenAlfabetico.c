// ORDENAR EN FORMA ALFABETICA
#include <stdio.h>
#include <string.h>
#define N 4
void MOSTRAR(char [][60], int);
void Orden_Alfabetico(char [][60], int);
main()
{
  char nombres [][60]={"Pedro","Ana","Pepe","Leo"};
  printf ("\n\n INFORME ANTES DEL ORDENAMIENTO");
  MOSTRAR (nombres, N);	
  Orden_Alfabetico(nombres, N);
  printf ("\n\n INFORME DESPUES DEL ORDENAMIENTO");
  MOSTRAR (nombres, N);	
}
////////////////////////////////////////////////
void MOSTRAR(char NOM[][60], int CE)
{
 int I;
  printf("\n LISTADO DE NOMBRES ");
  for (I =0; I < CE; I++)	
     printf ("\n\t %s " , NOM[I]);	
}
////////////////////////////////////////////////
void Orden_Alfabetico (char NOM[][60],  int CE)
{
	int I,J;
	char AUX[60];
			
	for (I=0; I<CE-1; I++)
		for(J=0; J<CE-1-I; J++)
		if( strcmpi(NOM[J],NOM[J+1])>0)    
		{
			strcpy (AUX, NOM[J]);       
			strcpy (NOM[J], NOM[J+1]);
			strcpy (NOM[J+1],AUX);
		}
}


