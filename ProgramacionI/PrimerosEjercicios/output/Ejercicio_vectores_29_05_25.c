/* 
EJERCITACION PARA RESOLVER

En un negocio trabajan 4 vendedores, cuyos legajos son de 3 cifras.
(Ingresarlos al inicio del programa)

Cada vez que se realiza una venta, se emite una factura, donde se indica:
* Numero de Factura
* Legajo del vendedor
* Importe de la venta.
Esta informacion termina con Numero de Factura igual a cero o negativo
Se pide:
1-) Facturacion por vendedor.
2-) Cantidad de facturas emitidas por vendedor.
3-) Facturación Total del negocio.
INFORMAR LO PEDIDO, MEDIANTE EL SIGUIENTE LISTADO:

LEGAJO VENDEDOR CANTIDAD DE FACTURAS FACTURACION

XXX XXXX XXXXX.XX
XXX XXXX XXXXX.XX
XXX XXXX XXXXX.XX
XXX XXXX XXXXX.XX

FACTURACION TOTAL XXXXXX.XX

EJERCITACION PARA PENSAR

IDEM anterior
Pero los legajos de los vendedores, son números correlativos de 1 a 4

LISTADO PEDIDO

LEGAJO VENDEDOR CANTIDAD DE FACTURAS FACTURACION

1 XXXX XXXXKX.XX
2 XXXX XXXXKX.XX
3 XXXX XXXXKX.XX
4 XXXX XXXXKX.XX

FACTURACION TOTAL XXXXXX.XX
*/

#include<stdio.h>

void legajos(int[],int);
void CARGA(int[], int);


int main(void)
{
    int leg[4],NFAC[1000]      ;
    CARGA (leg,4);
    
}

/////////////////////////////////////
void CARGA(int V[], int CE)
{
 int I;
 for (I=0; I<CE; I++)
 {
 
  do
  {
      printf("Ingresar legajo Numero %d: ", I+1);
     scanf ("%d",&V[I]);	
  
 
  } while (V[I]<100 || V[I]>999);
  
   
 }	
}