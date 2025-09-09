// SEGUNDO EJEMPLO DE ESTRUCTURA (version 1)
#include <stdio.h>
// generar un tipo de dato PRODUCTO, QUE CONTENGA:
//CODIGO PRODUCTO - PRECIO - FECHA DE VENCIMIENTO (DIA - MES - ANIO)
struct FECHA {
	        int DIA, MES, ANIO;};
struct PRODUCTO{
	          int codigo;
	          float precio;
	          struct FECHA FVENC;
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
  printf("\nIngresar fecha de vencimiento ");
  printf("\n DIA "); scanf("%d",&P.FVENC.DIA);
  printf("\n MES "); scanf("%d",&P.FVENC.MES);
  printf("\n ANIO "); scanf("%d",&P.FVENC.ANIO);
  printf("\nLOS DATOS INGRESADOS SON: CODIGO: %d y PRECIO: %.2f",P.codigo,P.precio );	
  printf("\nFECHA DE VENCIMIENTO ES DIA: %d - MES: %d - ANIO: %d",P.FVENC.DIA,P.FVENC.MES,P.FVENC.ANIO);
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
  printf("\nIngresar fecha de vencimiento ");
  printf("\n DIA "); scanf("%d",&DATO.FVENC.DIA);
  printf("\n MES "); scanf("%d",&DATO.FVENC.MES);
  printf("\n ANIO "); scanf("%d",&DATO.FVENC.ANIO);	
  return DATO;
}  
/////////////////////////////////////////////////////////  
void INFORME_ESTRUCTURA(struct PRODUCTO AUX) 
{
  printf("\n INFORME DENTRO DE LA FUNCION ");
  printf("\nLOS DATOS INGRESADOS SON: CODIGO: %d y PRECIO: %.2f",AUX.codigo,AUX.precio );	
  printf("\nFECHA DE VENCIMIENTO ES DIA: %d - MES: %d - ANIO: %d",AUX.FVENC.DIA,AUX.FVENC.MES,AUX.FVENC.ANIO);
}         
