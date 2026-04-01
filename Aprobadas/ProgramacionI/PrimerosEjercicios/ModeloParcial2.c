/*Una empresa de colectivos de larga distancia desea hacer una estad�stica para la cual registra durante un d�a la siguiente informaci�n, por cada viaje realizado:

NRO. DE INTERNO DEL COLECTIVO

ZONA DE DONDE PROVIENE: �N� (Norte), �S� (Sur), �E� (Este), �O� (Oeste)

HORA DE LLEGADA: de 0 a 23

CANTIDAD DE PASAJEROS TRANSPORTADOS

Termina el ingreso de datos con Nro. de interno 0 (cero)

Se pide informar:

Cantidad de pasajeros transportados provenientes de cada zona

Promedio de pasajeros transportados

Nro. de Interno del colectivo con mayor cantidad de pasajeros transportados (suponer que es �nico)

Cantidad de micros que llegaron entre las 0 hs y 12 hs inclusive


INTERNO                ZONA                      HORA LLEGADA           CANTIDAD DE PASAJEROS

NRO_INT 				ZONA                        H_LLEGADA                       CANT_PAS



600						  N							5								100


*/


#include<stdio.h>
#include<ctype.h>



int NRO_INT,H_LLEGADA, CANT_PAS,PAS_TOTAL,INT_MAX;
int  PAS_NORTE=0,PAS_SUR=0,PAS_OESTE=0,PAS_ESTE=0,CONT_VIAJE=0,MAX_PAS=0,CONT_MICRO=0;
char ZONA;
float PROM=0;


main(void){

	
	printf("\nIngrese Nro de interno: ");
	scanf("%d",&NRO_INT);
	
	while(NRO_INT>0)
	
{

    CONT_VIAJE++;
	printf("\nIngrese Zona: ");
	fflush(stdin);	
	scanf("%c",&ZONA);
	ZONA=toupper(ZONA);
	
	printf("\nIngrese Hora de llegada: ");
	scanf("%d",&H_LLEGADA);
	
	printf("\nIngrese Cantidad de pasajeros: ");
	scanf("%d",&CANT_PAS);
	
	if(H_LLEGADA>=0 && H_LLEGADA<=12)
	CONT_MICRO++;
	
switch (ZONA){
	
	case 'N':
		PAS_NORTE+=CANT_PAS;break;
		
	case 'S':
		PAS_SUR+=CANT_PAS;break;
	
	case 'E':
		PAS_ESTE+=CANT_PAS;break;
		
	case 'O':
		PAS_OESTE+=CANT_PAS;			
		
		
		

		
}
	

	if(CONT_VIAJE!=0)
		{
			MAX_PAS=CANT_PAS;
			INT_MAX=NRO_INT;
			
			}	
			else
			if(CANT_PAS>MAX_PAS){
				
				MAX_PAS=CANT_PAS;
				INT_MAX=NRO_INT;
			       
				
				
				
			}
				
			
	
	printf("\nIngrese Nro de interno: ");
	scanf("%d",&NRO_INT);
	
		
	
	
	
	}	
	
if(CANT_PAS!=0){
	printf("\nCantidad de pasajeros Zona NORTE:           %d",PAS_NORTE);
	printf("\nCantidad de pasajeros Zona   SUR:           %d",PAS_SUR);
	printf("\nCantidad de pasajeros Zona  ESTE:           %d",PAS_ESTE);
	printf("\nCantidad de pasajeros Zona OESTE:           %d",PAS_OESTE);
	PAS_TOTAL=PAS_NORTE+PAS_SUR+PAS_ESTE+PAS_OESTE;	
	PROM=(float)PAS_TOTAL/CONT;
    printf("\nEL Promedio de pasajeros TOTALES ES:        %.2f",PROM);
	
	printf("\nInterno con MAS pasajeros:                  %d",INT_MAX);
	printf("\nMicros entre las 0 y 12 inclusive:          %d",CONT_MICRO);

	
	
}
	else
	printf("\nNo se realizaron recorridos.");
	
}
	
		
	

	

