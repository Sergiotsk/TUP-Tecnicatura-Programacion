/* SE DISPONE DE UNA LISTA DE PRECIOS DE 5 PRODUCTOS CONTENIENDO:
CODIGO DE PRODUCTO (todos distintos, de 3 cifras)
PRECIO
CONSULTA DE PRECIOS  - FIN DE CONSULTA -> CODIGO DE PRODUCTO CERO
INGRESAR -> CODIGO DE PRODUCTO 
SALIDA -> MOSTRAR EL PRECIO DEL PRODUCTO CONSULTADO */
#include <stdio.h>
#define CANT_PRODUCTOS 5
void CARGA_LISTA(int [], float [], int);
int BUSQUEDA (int [], int , int );	

main()
{
 int VCOD[CANT_PRODUCTOS], Cod_consulta, POS;
 float VPRE[CANT_PRODUCTOS];
 CARGA_LISTA(VCOD, VPRE, CANT_PRODUCTOS);	
 printf("\n CONSULTA DE PRECIOS ");
 printf("\nIngresar codigo de producto a consultar el precio (FINALIZA CODIGO CERO) ");
 scanf("%d", &Cod_consulta);
 while(Cod_consulta!=0)
 {
   POS = BUSQUEDA(VCOD,Cod_consulta,CANT_PRODUCTOS);
   if (POS >=0)	 // encontrado
      printf ("\nEL PRECIO DEL PRODUCTO ES %.2f", VPRE[POS]);
   else
      printf ("\n NO EXISTE EL CODIGO EN LA LISTA DE PRECIOS");
   
   printf("\nIngresar codigo de producto a consultar el precio (FINALIZA CODIGO CERO)");
   scanf("%d", &Cod_consulta);   
 }
 printf("\n FIN DE LAS CONSULTA DE PRECIOS ");	
}
////////////////////////////////////////////////////
void CARGA_LISTA(int VC[], float VP[], int CE)
{
  int I;
  for (I=0; I<CE; I++)	
  {
   printf("\n Ingresar codigo de producto de 3 cifras ");
   scanf("%d", &VC[I]);	
   printf("\n Ingresar precio del producto  ");
   scanf("%f", &VP[I]);		
  }
}
/////////////////////////////////////////////////////////////
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
