// PRIMER EJEMPLO DE ESTRUCTURA (version 1)
#include <stdio.h>
// generar un tipo de dato PRODUCTO
struct PRODUCTO{
	          int codigo;
	          float precio;
               };
struct PRODUCTO CARGA_ESTRUCTURA(void);
void INFORME_ESTRUCTURA(struct PRODUCTO);

main() 
{
  struct PRODUCTO P,P1;
  printf("\nIngresar codigo del producto ");
  scanf("%d", &P.codigo);
  printf("\nIngresar precio del producto ");
  scanf("%f",&P.precio);
  printf("\nLOS DATOS INGRESADOS SON: CODIGO: %d y PRECIO: %.2f",P.codigo,P.precio );	
  P1 = CARGA_ESTRUCTURA();
  INFORME_ESTRUCTURA(P1);	
}
/////////////////////////////////////////////////////////////
struct PRODUCTO CARGA_ESTRUCTURA(void)
{
  struct PRODUCTO DATO;
  printf("\n ESTAMOS DENTRO DE LA FUNCION DE CARGA ");	
  printf("\nIngresar codigo del producto ");
  scanf("%d", &DATO.codigo);
  printf("\nIngresar precio del producto ");
  scanf("%f",&DATO.precio);	
  return DATO;
}  
/////////////////////////////////////////////////////////  
void INFORME_ESTRUCTURA(struct PRODUCTO AUX) 
{
  printf("\n INFORME DENTRO DE LA FUNCION ");
  printf("\nLOS DATOS INGRESADOS SON: CODIGO: %d y PRECIO: %.2f",AUX.codigo,AUX.precio );	
}         
