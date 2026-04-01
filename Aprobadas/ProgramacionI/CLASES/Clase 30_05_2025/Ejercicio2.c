/*En un negocio trabajan 4 vendedores, cuyos legajos son de 1 a 4.
Cada vez que se realiza una venta, se emite una factura, donde se indica:
* Número de Factura
* Legajo del vendedor
* Importe de la venta.
Esta información termina con Número de Factura igual a cero o negativo
Se pide:
1-) Facturación por vendedor.
2-) Cantidad de facturas emitidas por vendedor.
3-) Facturación Total del negocio.
INFORMAR LO PEDIDO, MEDIANTE EL SIGUIENTE LISTADO:
LEGAJO VENDEDOR   CANTIDAD DE FACTURAS   FACTURACION
	1 			XXXX 			 XXXXX.XX
	2 			XXXX 			 XXXXX.XX
	3 			XXXX 			 XXXXX.XX
	4			XXXX 			 XXXXX.XX
		FACTURACION TOTAL 		XXXXXX.XX*/
#include <stdio.h>
// prototipos o declaracion de laas funciones
int LeeControlRango(int,int);	
void IMPORTE_FINAL(float[], int [], int, float );
main()
{//inicio main
 int CantFactXven[4]={0};
 int NFAC,POS, CODV;
 float FactXven[4]={0},FactTOTAL = 0, IMPO;
 
 printf("\nPROCESAMIENTO DE LAS VENTAS DEL NEGOCIO ");
 printf("\nIngresar numero de factura (termina con cero o negativo )");
 scanf("%d",&NFAC);
 while(NFAC > 0)
 { // inicio while
   printf("\nIngresar legajo del vendedor que realizo la venta ");
   CODV = LeeControlRango(1,4);
   printf ("\nIngresar Importe de la venta ");
   scanf("%f", &IMPO);
   FactXven[CODV-1]+=IMPO;
   CantFactXven[CODV-1]++;
   FactTOTAL +=IMPO;
   
 	printf("\nIngresar numero de factura (termina con cero o negativo )");
    scanf("%d",&NFAC);
 	
 }// fin while
 IMPORTE_FINAL(  FactXven, CantFactXven, 4, FactTOTAL );
 
}// fin main
///////////////////////////////////////////////////////////////
//definicion de funciones (codigo)

int LeeControlRango(int Desde,int Hasta)
{
  int DATO;
  do{
  	  scanf("%d", &DATO);
  	  if (DATO < Desde || DATO > Hasta)
  	  	  printf("\n ERROR, Ingresar nuevamente ");
  }while ((DATO < Desde || DATO > Hasta));
  return DATO;
  }	
//////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////	
void IMPORTE_FINAL( float VF[], int VC[], int CE, float T)
{
  int I;
  printf("\n%17s%24s%15s", "LEGAJO VENDEDOR","CANTIDAD DE FACTURAS","FACTURACION");
  for(I=0;I<CE;I++)
  	printf("\n%17d%24d%15.2f", I+1,VC[I],VF[I]);
  printf("\n\nFACTURACION TOTAL %15.2f",T);
}	
	
	


