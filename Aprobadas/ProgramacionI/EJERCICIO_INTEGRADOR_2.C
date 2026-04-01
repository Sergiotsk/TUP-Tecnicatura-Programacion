/*
Una empresa maneja 20 productos numerados del 1000 al 1019. Además, vende en 5 sucursales
distintas con códigos 100, 200, 300, 400 y 500. Como información inicial se debe ingresar el precio de
los 20 productos.
Por teclado se ingresan las ventas realizadas en el año. Por cada venta se ingresa:
- Código de producto
- Mes
- Cantidad Vendida
- Sucursal
Las ventas se ingresan sin orden alguno y terminan con Mes igual a 0.
Todos los datos que se ingresan deben estar correctamente validados.
1. Mostrar un cuadro resumen de la recaudación de las ventas del año. Según el siguiente formato
(mostrar títulos):
Producto Mes 1 Mes 2 Mes 3 Mes 4 .. Mes 12
1000 xxx.xx xxx.xx xxx.xx xxx.xx ... xxx.xx|
1001 xxx.xx xxx.xx xxx.xx xxx.xx ... xxx.xx
1002 xxx.xx xxx.xx xxx.xx xxx.xx ... xxx.xx
..
1019 xxx.xx xxx.xx xxx.xx xxx.xx ... xxx.xx
2. Mostrar la cantidad total de ventas realizadas en cada sucursal a lo largo del año
3. Mostrar el importe total de ventas en el último trimestre del año
Como mínimo realizar las siguientes funciones:
 Función con argumentos (reutilizable) para ingresar los meses , códigos de producto y sucusales
 Función para cargar el vector de precios
 Función para listar cada ítem pedido

*/
#include<stdio.h>
#define CANT_PRODUCTOS 3
void CARGA_PRODUCTOS(int [], float [], int);
int LeeControlRango(int,int);
int LeeControlExistente (int V[],int DATO,int CE);
int LeeControlRango_0(int,int);
int BUSQUEDA (int [], int , int );	
//void Informe_VENTASxMES();
void CARGA_VENTAS(float[][12],int);



int main(void){
    int COD_PRODUCTO[CANT_PRODUCTOS];
    float PRECIO[CANT_PRODUCTOS];
    float VxMES[20][12]={{0}};
    int mes;
    CARGA_PRODUCTOS(COD_PRODUCTO,PRECIO,CANT_PRODUCTOS);

    printf("\nIngrese mes de ventas(1 a 12): ");
    mes=LeeControlRango_0(1,12);

    while(mes !=0)
    {
    
      






    


    }


}
/////////////////////////////////////////////////////////////////////FUNCIONES
void CARGA_PRODUCTOS(int VC[], float VP[], int CE)
{
  int I,DATO;
  for (I=0; I<CE; I++)	
  {
   do
   {
    printf("\n Ingresar codigo de producto(entre 1000 y 1019): ");
     DATO=LeeControlRango(1000,1019);
   if (LeeControlExistente(VC,DATO,CE) != -1)
   {
    printf("\nCodigo ya ingresado. Ingresar otro.");
   }
   } while (LeeControlExistente(VC,DATO,CE) != -1);

   VC[I]= DATO;  
   
  
   printf("\n Ingresar precio del producto  ");
   scanf("%f", &VP[I]);		
  }
}
/////////////////////////////////////////////////////
int LeeControlRango(int Desde, int Hasta)
{
  int Dato;
  do{
  	scanf("%d",&Dato);
  	if (Dato < Desde  || Dato > Hasta)
  		printf("\n ERROR, Ingresar nuevamente ");
    
    }	while(Dato < Desde  || Dato > Hasta);
    
  return Dato;	
}
/////////////////////////////////////////////////////
int LeeControlExistente (int V[],int CLAVE,int CE)

{

 int I = 0,posi=-1; 
 while (posi == -1 && I<CE )  

  {
      if (V[I]==CLAVE) 
     {
      posi=1; 
             
     } 
    else
       I++;
  }

       return posi;

}
///////////////////////////////////////////////////
int LeeControlRango_0(int Desde,int Hasta)
{


int Dato;
  do{
  	scanf("%d",&Dato);
  	if ((Dato < Desde  || Dato > Hasta) && Dato !=0)
  		printf("\n ERROR, Ingresar nuevamente ");
    
    }	while(Dato < Desde  || Dato > Hasta);
    
  return Dato;	









}
/* void CARGA_VENTAS(float MV[][12],int CE)
{
   
  int I,J;

    for (I=0;I<CE;I++)
    {
      
    }
    
  





}
*/