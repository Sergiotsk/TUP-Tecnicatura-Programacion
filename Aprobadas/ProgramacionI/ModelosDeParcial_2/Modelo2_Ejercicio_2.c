/*Un depósito de productos reciclables recepciona 100 productos distintos y desea hacer un relevamiento de su
existencia. Para ello se conoce:
 Código de producto (nro. correlativo de 1 a 100)
 Descripción del producto (máximo 50 caracteres)
 Cantidad en existencia (real en kilos)
 Valor de compra (real por kilo)
 Zona de procedencia del producto ( carácter) C- (CABA) – G- (GBA) – O (OTRO) -
 Día de la semana de la última recepción (LUNES – MARTES - MIERCOLES – JUEVES o VIERNES)
Se pide un programa que:
a- Declarar un tipo de dato que contenga la información de los productos reciclables
b- Declarar un vector de estructuras del tipo de dato creado en el punto a.
c- Cargar en un vector de estructuras, los datos referentes a los productos, Función CARGA.
(Implementar mínimamente una función para leer y validar un campo)
d- Indicar los códigos de producto y descripción cuando el dia de ultima recepción fue VIERNES
e- Obtener la Cantidad de existencia mínima cuando la zona de procedencia es G(GBA). Informando Código de
producto y Valor de la compra. (puede haber más de uno)





if (strcmpi(V[I].dia,"VIERNES")==0)//COMPARA STRING Y DA 0 SI SON IGUALES DEBO INCLUIR string<h>
{
   


}


*/

#include<stdio.h>
#include<string.h>
#define CP 100


typedef struct 
{
    int Codigo;
    char Descripcion[51];
    float CantKg;
    float ValorxKg;
    char Procedencia;
    char UltRecepcion[10];

}Reciclables;
int LeeControlRango(int,int);
void CARGA(Reciclables [],int);
void INFO_VIERNES(Reciclables [],int);
void CANT_MIN(Reciclables [],int);






int main(void)
{
    Reciclables Rproductos[CP];
    CARGA(Rproductos,CP);
    INFO_VIERNES(Rproductos,CP);
    CANT_MIN(Rproductos,CP);
    
}
/////////////
void CARGA(Reciclables Vr[],int CE)
{
   int I;

   for (I=0;I<CE;I++)
   {
       printf("\nIngresar codigo de producto: ");
       Vr[I].Codigo=LeeControlRango(1,100);


       printf("\nIngrese descripcion del producto: ");
       fflush(stdin);
       gets(Vr[I].Descripcion);

        printf("\nIngrese cantidad existente (Kg) del producto: ");
        scanf("%f",Vr[I].CantKg);

        printf("\nIngrese procedencia del producto: ");
        scanf("c",Vr[I].Procedencia);

         printf("\nIngrese dia de la ultima recepcion del producto: ");
         gets(Vr[I].UltRecepcion);




    }


 }  
 ////////////////////////////////////
 void INFO_VIERNES(Reciclables Vr[],int CE)
 {
   int I;
      printf("\nDatos de los productos que fueron recepcionados el dia VIERNES por ultama vez ");
      printf("\n\tCodigo  Descripcion");

      for(I=0;I<CE;I++)
      { 
        if (strcmpi(Vr[I].UltRecepcion,'VIERNES')==0)
        {
          printf("\n\t%8s %10s",Vr[I].Codigo,Vr[I].Descripcion);
        }  





      } 

 }
 //////////////////////////////
 void CANT_MIN(Reciclables Vr[],int CE)
 {
    int I;








 }
/////////////////////////////////////
int LeeControlRango(int DESDE, int HASTA)
{
    int DATO;

  do
  {
    fflush(Stdin);
    scanf("%d",&DATO);
    if (DATO<DESDE || DATO>HASTA)
    {
        printf("\nERROR,ingresar nuevamente: ");
    }
    
  } while (DATO<DESDE || DATO>HASTA);
  







}