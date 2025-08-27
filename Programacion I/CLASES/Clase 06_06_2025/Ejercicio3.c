/*3-) Una empresa de peajes, en una determinada zona tiene 5 cabinas para el cobro de peajes.
Desea obtener una estadística diaria de la recaudación de cada cabina entre las 0 y 6 horas.
Se ingresa:
* Nro. cabina (1 a 5)
* Hora (0 a 6)
* Importe del peaje.
Finaliza la información con Nro. cabina cero.*/
#include <stdio.h>
////////////////////////////////////////////////////////////////////////////
int LeeControlRango(int,int);
float LeeControlMayorA(float);
void INFORME(float [][7],int,int);
///////////////////////////////////////////////////////////////////////////
main()
{ // inicio main
 float R[5][7]={{0}}, IMPO;
 int NC, H;
 printf("\n INGRESO DE DATOS ");
 printf("\nIngresar Numero de cabina de 1 a 5 (Finaliza con cero) ");
 NC = LeeControlRango(0,5);
 while (NC != 0)
 { // inicio while
 	printf("\nIngresar HORA entre 0 y 6 : ");
 	H = LeeControlRango(0,6);
 	printf("\nIngresar IMPORTE: ");
 	IMPO = LeeControlMayorA(0);
 	R[NC-1][H]+=IMPO;
 	printf("\nIngresar Numero de cabina de 1 a 5 (Finaliza con cero) ");
 	NC = LeeControlRango(0,5);
 } // fin while
 INFORME(R,5,7);
 	
	
} // fin main
////////////////////////////////////////////////////////////////////////
int LeeControlRango(int Desde ,int Hasta)
{
 int DATO;
 do{
 	 scanf("%d",&DATO);
 	 if (DATO < Desde || DATO > Hasta)
 	 	printf("ERROR, Ingresar nuevamente ");
   }while (DATO < Desde || DATO > Hasta);	
  return DATO;	
}
///////////////////////////////////////////////////////////////////////
float LeeControlMayorA(float Valor)
{
  float DATO;
  do{
 	 scanf("%f",&DATO);
 	 if (DATO <= Valor)
 	 	printf("ERROR, Ingresar nuevamente ");
   }while (DATO <=  Valor);	
  return DATO;	
}
///////////////////////////////////////////////////////////////////////
void INFORME(float M [][7],int F,int C)
{
  int I,J;
  printf("\n\n Recaudacion de cada cabina entre las 0 y 6 horas");
  printf("\nCABINA\t\t\t\t\t  HORA\n");	
  for (J=0; J< C; J++)	
  	printf("%10d", J);
  for (I=0; I< F; I++)
   {
   	 printf("\n%d", I+1);
   	 for (J=0; J< C; J++)
		printf("%10.2f", M[I][J]);	
   }
}
