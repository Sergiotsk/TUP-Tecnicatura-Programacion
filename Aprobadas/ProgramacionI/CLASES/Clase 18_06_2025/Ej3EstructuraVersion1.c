// TERCER EJEMPLO DE ESTRUCTURA (version 1)
#include <stdio.h>
#define N 2
// generar un tipo de dato PRODUCTO, QUE CONTENGA:
//CODIGO PRODUCTO - PRECIO - FECHA DE VENCIMIENTO (DIA - MES - ANIO)
struct FECHA {
	        int DIA, MES, ANIO;};
struct PRODUCTO{
	          int codigo;
	          float precio;
	          struct FECHA FVENC;
               };

void CARGA_VECTOR_ESTRUCTURA(struct PRODUCTO [], int);
void INFORME_VECTOR_ESTRUCTURA (struct PRODUCTO [], int);

main() 
{
  // GENERAR UN VECTOR DE ESTRUCTURA DEL TIPO struct PRODUCTO
  struct PRODUCTO VEC[N] ; // N definido como constante 
  printf("\nCARGA VECTOR DE ESTRUCTURA ");
  CARGA_VECTOR_ESTRUCTURA(VEC, N);
  INFORME_VECTOR_ESTRUCTURA(VEC, N);	
}
/////////////////////////////////////////////////////////////

void CARGA_VECTOR_ESTRUCTURA(struct PRODUCTO V[], int CE)   
{
  int I;	
  for (I=0; I< CE; I++)	
  {
    printf("\nIngresar codigo del producto ");
    scanf("%d", &V[I].codigo); // NOOOOOOO V.codigo[I]
    printf("\nIngresar precio del producto ");
    scanf("%f",&V[I].precio);
    printf("\nIngresar fecha de vencimiento ");
    printf("\n DIA "); scanf("%d",&V[I].FVENC.DIA);
    printf("\n MES "); scanf("%d",&V[I].FVENC.MES);
    printf("\n ANIO "); scanf("%d",&V[I].FVENC.ANIO);	
  }
}    
////////////////////////////////////////////////////////////////
void INFORME_VECTOR_ESTRUCTURA (struct PRODUCTO V[], int CE)
{
  int I;
  printf("\n INFORME DEL VECTOR DE ESTRUCTURA ");
  printf("\n%6s\t%10s\t%18s", "CODIGO", "PRECIO", "FECHA VENCIMIENTO");
  for (I=0; I< CE; I++)	
  	printf("\n%6d\t%10.2f\t%d-%d-%d",V[I].codigo,V[I].precio, V[I].FVENC.DIA, V[I].FVENC.MES, V[I].FVENC.ANIO);
	
}
