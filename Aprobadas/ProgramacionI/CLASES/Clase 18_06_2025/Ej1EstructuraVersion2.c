// PRIMER EJEMPLO DE ESTRUCTURA (version 2)
#include <stdio.h>
// generar un tipo de dato PRODUCTO
typedef struct {
	          int codigo;
	          float precio;
               }PRODUCTO;
               
PRODUCTO CARGA_ESTRUCTURA(void);
void INFORME_ESTRUCTURA(PRODUCTO);
              
main() 
{
  PRODUCTO P,P1;
  printf("\nIngresar codigo del producto ");
  scanf("%d", &P.codigo);
  printf("\nIngresar precio del producto ");
  scanf("%f",&P.precio);
  printf("\nLOS DATOS INGRESADOS SON: CODIGO: %d y PRECIO: %.2f",P.codigo,P.precio );	
  P1 = CARGA_ESTRUCTURA();
  INFORME_ESTRUCTURA(P1);	
} 
///////////////////////////////////////////////////
PRODUCTO CARGA_ESTRUCTURA(void) 
{
  PRODUCTO DATO;
  printf("\n ESTAMOS DENTRO DE LA FUNCION DE CARGA ");	
  printf("\nIngresar codigo del producto ");
  scanf("%d", &DATO.codigo);
  printf("\nIngresar precio del producto ");
  scanf("%f",&DATO.precio);	
  return DATO;
}
/////////////////////////////////////////////////////////
void INFORME_ESTRUCTURA(PRODUCTO AUX)
{
  printf("\n INFORME DENTRO DE LA FUNCION ");
  printf("\nLOS DATOS INGRESADOS SON: CODIGO: %d y PRECIO: %.2f",AUX.codigo,AUX.precio );	
} 
