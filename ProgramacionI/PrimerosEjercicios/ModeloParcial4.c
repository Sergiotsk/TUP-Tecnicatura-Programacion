/*
Ej2
Un programa de TV realiza un concurso donde los televidentes deben llamar diciendo cual
es la altura del Aconcagua.

Se reciben N llamadas, por cada una se conoce:

* DNI del concursante
* Zona de donde llama ( *C' (Capital) - *G' (Gran Bs. As) — 'R'(Resto del país))
* Respuesta del participante

Ingresar inicialmente N que es la cantidad de llamadas.
Sabiendo que la altura del Aconcagua es de 6962 metros, se pide informar:
1. Porcentaje de respuestas correctas.

2. Cantidad de respuestas equivocadas en menos de 100 metros.(de más o de menos)


3_CANTIDAD DE LLAMADAS DE CADA ZONA

4_ZONA CON MENOR CANTIDAD DE LLAMADAS


*/


#include<stdio.h>
#include<ctype.h>


#define ALTURA_ACON 6962

main(){
	
	int DNI,N,llamadas,RESPUESTA,INCORRECTAS,LLAMADOS_C,LLAMADOS_G,LLAMADOS_R,RES_TOTALES,INCORRECTAS_100,MAX_INCORRECTA,MAX_DNI;
    int RESPUESTAS_OK=INCORRECTAS=LLAMADOS_C=LLAMADOS_G=LLAMADOS_R=INCORRECTAS_100=0;
    float P_CORRECTAS=0;
	char ZONA;
	printf("\nIngresar cantidad de llamadas: ");/// esto ess por que no esta definida la cantidad
	scanf("%d",&N);
	
	if(N>0){
		
		for(llamadas =1; llamadas<= N ;llamadas++)
		{			
			
			printf("\nIngrese DNI del concursante: ");
 			scanf("%d",&DNI);
		
			printf("\nIngrese ZONA de donde llama: ");
			fflush(stdin);
			ZONA=toupper(ZONA);
			scanf("%C",&ZONA);
	
			printf("\nIngrese su RESPUESTA: ");
			scanf("%d",&RESPUESTA);							
			
					if(RESPUESTA==ALTURA_ACON){
			
			RESPUESTAS_OK++;
			
		}	
	
			else
				INCORRECTAS++	;
				
				
			if(INCORRECTAS==1){
			
			MAX_INCORRECTA=RESPUESTA;
			MAX_DNI=DNI;		
			
		}
		else if(MAX_INCORRECTA>RESPUESTA){
			
			MAX_INCORRECTA=RESPUESTA;
			MAX_DNI=DNI;
		
		
		
		}
				
				
       if(RESPUESTA>=(ALTURA_ACON-100) && RESPUESTA<=(ALTURA_ACON+100) && RESPUESTA!=ALTURA_ACON)
		
		       INCORRECTAS_100++ ;			
		
		
	
		
		
	switch(ZONA){
		
		
		
		case 'C' :
		
		LLAMADOS_C++;break;
		
		case 'G':
			
		LLAMADOS_G++;break;
		
		case 'R':
			
		LLAMADOS_R++;	
		
		
	}
		
		
		
		
			
			
			
		}
		
		
		printf("\n Porcentaje de respuestas correctas                                          %.2f", (float)RESPUESTAS_OK/N*100);
		printf("\n Cantidad de respuestas incorrectas en menos de 100 mts                      %d",INCORRECTAS_100);
		printf("\n DNI del televidente que dijo la MAYOR altura INCORRECTA                     %d",MAX_DNI);
		printf("\n Cantidad de llamadas de zona C                                              %d",LLAMADOS_C);
		printf("\n Cantidad de llamadas de zona G                                              %d",LLAMADOS_G);
		printf("\n Cantidad de llamadas de zona R                                              %d",LLAMADOS_R);
		
		
		
		
		
		
	}
	else 
	printf("\nNo hubo llamados");
	
	
	
	
	
	
	
	
}
