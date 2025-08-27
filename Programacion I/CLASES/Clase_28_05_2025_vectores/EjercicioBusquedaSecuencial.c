/*Se dispone de 5 n�meros enteros distintos.
Se pide:
A-) Guardar los 5 Nros. en un vector VEC
B-) Luego ingresar un Nro. entero.
C-) Indicar en que posici�n se encuentra el Nro. 
ingresado en B-) en el vector VEC, sino existe indicar el
mensaje �EL NRO NO SE ENCUENTRA�*/
#include <stdio.h>
//prototipos o declaraciones de funciones
void CARGA(int [],int);
void INFORME_PRUEBA(int[],int);
int BUSQUEDA (int[], int , int);
int main(void)
{
  int VEC[5], NRO_bus,POS;
  CARGA(VEC,5);	
  INFORME_PRUEBA(VEC,5);
  printf("\n Ingresar Numero a buscar en el vector ");
  scanf("%d", &NRO_bus);
  // LUGAR(posicion)donde se encuentra = BUSQUEDA (DONDE SE BUSCA, QUE SE BUSCA, HASTA DONDE SE BUSCA)
  // CRITERIO DE BUSQUEDA:
  // SI LA POSICION(indice) ES 0 O MAYOR SIGNIFICA QUE EXITE EL NRO. EN EL VECTOR
  // SI LA POSICION(indice) ES NEGATIVA (-1) SIGNIFICA QUE EL NRO NO EXISTE EN EL VECTOR
  POS=BUSQUEDA (VEC,NRO_bus,5);
  if (POS >= 0)
  	printf("\n SE ENCONTRO EN POSICION %d ", POS);
  else
      printf("\n NO SE ENCONTRO EL NUMERO BUSCADO ");
	
}
///////////////////////////////////////////////////
void CARGA(int V[], int CE)
{
 int I;
 for (I=0; I<CE; I++)
 {
   printf("Ingresar elemento en posicion %d: ", I);
   scanf ("%d",&V[I]);	
 }	
}
//////////////////////////////////////////////////////
void INFORME_PRUEBA(int V[],int CE)
{ int I;
  printf("INFORME PRUEBA DE CARGA ");
  for (I=0; I<CE; I++)
    printf("\n POSICION: %d ELEMENTO: %d ", I, V[I]);
}
//////////////////////////////////////////////////////
int BUSQUEDA (int VEC[], int DATO , int CE)
{
  int I = 0 , POSI = -1;  // POSI = -1 significa NO encontrado
  while (POSI == -1 && I<CE )  // mientras no se encuentra y estoy dentro del vector-> se sigue buscando
	if (VEC[I]== DATO)	
	   POSI = I;
	else
	   I++;
  return POSI;	
}
