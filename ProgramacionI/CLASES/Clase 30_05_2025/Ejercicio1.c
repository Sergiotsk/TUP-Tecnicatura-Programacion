/*En un negocio trabajan 4 vendedores, cuyos legajos son de 3 cifras.
(Ingresarlos al inicio del programa)
Cada vez que se realiza una venta, se emite una factura, donde se indica:
* N�mero de Factura
* Legajo del vendedor
* Importe de la venta.
Esta informaci�n termina con N�mero de Factura igual a cero o negativo
Se pide:
1-) Facturaci�n por vendedor.
2-) Cantidad de facturas emitidas por vendedor.
3-) Facturaci�n Total del negocio.
INFORMAR LO PEDIDO, MEDIANTE EL SIGUIENTE LISTADO:
LEGAJO VENDEDOR   CANTIDAD DE FACTURAS   FACTURACION
	XXX 			XXXX 			 XXXXX.XX
	XXX 			XXXX 			 XXXXX.XX
	XXX 			XXXX 			 XXXXX.XX
	XXX			XXXX 			 XXXXX.XX
		FACTURACION TOTAL 		XXXXXX.XX*/
#include <stdio.h>
// prototipos o declaracion de laas funciones
int LeeControlRango(int,int);	
void CARGA(int [],int);
void INFORME_LEGAJOS(int[],int);
int BUSQUEDA (int[],int,int);
void IMPORTE_FINAL(int[], float[], int [], int, float );
int main(void)
{//inicio main
 int VLEG[4],CantFactXven[4]={0};
 int NFAC,POS, CODV;
 float FactXven[4]={0},FactTOTAL = 0, IMPO;
 printf("\n CARGA DE LEGAJOS DE LOS VENDEDORES");
 CARGA(VLEG,4);
 INFORME_LEGAJOS(VLEG,4);
 printf("\nPROCESAMIENTO DE LAS VENTAS DEL NEGOCIO ");
 printf("\nIngresar numero de factura (termina con cero o negativo )");
 scanf("%d",&NFAC);
 while(NFAC > 0)
 { // inicio while
   printf("\nIngresar legajo del vendedor que realizo la venta ");
   scanf("%d", &CODV);
   POS = BUSQUEDA (VLEG,CODV,4);
   if (POS >= 0)
   	{ printf ("\nIngresar Importe de la venta ");
   	  scanf("%f", &IMPO);
   	  FactXven[POS]+=IMPO;
   	  CantFactXven[POS]++;
   	  FactTOTAL +=IMPO;
   	}	
   	else
   		printf("\nNO EXISTE EL LEGAJO DEL VENDEDOR");
 	
 	printf("\nIngresar numero de factura (termina con cero o negativo )");
    scanf("%d",&NFAC);
 	
 }// fin while
 IMPORTE_FINAL(VLEG,  FactXven, CantFactXven, 4, FactTOTAL );
 
}// fin main
///////////////////////////////////////////////////////////////
//definicion de funciones (codigo)
void CARGA(int V[],int CE)
{
 int I;
 for (I=0; I<CE;I++)
 {
  printf("\nIngresar Legajo del vendedor (3 cifras) ");
  V[I] = LeeControlRango(100,999);	
 }
}
/////////////////////////////////////////////////////////////
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
void INFORME_LEGAJOS(int V[],int CE)
{
 int I;
 printf (" \nInforme de los legajos de los vendedores");
 for (I=0; I<CE;I++)
 	printf ("\n%d",V[I]);
}
////////////////////////////////////////////////////////////////
int BUSQUEDA (int V[],int DATO,int CE)
{
 int POSI = -1; //no encontrado
 int I = 0; // se recorre desde la primer posicion
 while (POSI == -1 && I < CE )  // mientra no se encuentra y estamos dentro del vector se sigue buscando
    if (V[I]== DATO)  
       POSI = I;   // si se encuentra, se asigna la posicion
    else
       I++;
 return POSI;
}
/////////////////////////////////////////////////////////////////	
void IMPORTE_FINAL(int VL [], float VF[], int VC[], int CE, float T)
{
  int I;
  printf("\n%17s%24s%15s", "LEGAJO VENDEDOR","CANTIDAD DE FACTURAS","FACTURACION");
  for(I=0;I<CE;I++)
  	printf("\n%17d%24d%15.2f", VL[I],VC[I],VF[I]);
  printf("\n\nFACTURACION TOTAL %15.2f",T);
}	
	
	


