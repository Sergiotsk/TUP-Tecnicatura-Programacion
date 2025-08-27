/*JEMPLOS DE PRIMER PARCIAL
Ej1
Un programa de TV realiza un concurso donde los televidentes deben llamar diciendo cual
es la altura del Aconcagua.

Por cada llamada recibida se conoce:
* DNI del concursante
* Zona de donde llama ( *C' (Capital) - *G' (Gran Bs. As) — R'(Resto del país))
* Respuesta del participante

Esta información termina con DNI cero o negativo
Sabiendo que la altura del Aconcagua es de 6962 metros, se pide informar:
1. Porcentaje de respuestas correctas.
2. Cantidad de respuestas equivocadas en menos de 100 metros.(de más o de menos)
3. DNI del televidente que dijo la mayor altura incorrecta. (suponer único)
4. Cantidad de llamadas de cada zona.

DNI            ZONA              RESPUESTA


2132132          G
*/



#include<stdio.H>
#include<ctype.h>

#define ALTURA_ACON 6962


main(){
	
	int DNI,RESPUESTA,INCORRECTAS,LLAMADOS_C,LLAMADOS_G,LLAMADOS_R,RES_TOTALES,INCORRECTAS_100,MAX_INCORRECTA,MAX_DNI;
    int RESPUESTAS_OK=INCORRECTAS=LLAMADOS_C=LLAMADOS_G=LLAMADOS_R=INCORRECTAS_100=0;
    float P_CORRECTAS=0;
	char ZONA;
	
	printf("\nIngrese su DNI: ");
	scanf("%d",&DNI);
	

	while(DNI!=0){
		
	printf("\nIngrese ZONA: ");
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
		
		
		
		
	
		
		printf("\nIngrese su DNI: ");
    	scanf("%d",&DNI);
 		
		
		
	}
	


	
    RES_TOTALES=(RESPUESTAS_OK+INCORRECTAS);
    if(RESPUESTAS_OK!=0){
    	
    		P_CORRECTAS=(RESPUESTAS_OK*100)/(float)RES_TOTALES;
			printf("\nRespuestas CORRECTAS:                    %.2f",P_CORRECTAS);printf("%%");
	
   	}
	else
		printf("\nRespuestas CORRECTAS:                                                   0");
		
	
	
		printf("\nCantidad de respuestas equivocadas en menos de 100 metros               %d",INCORRECTAS_100);
		printf("\nCantidad de respuestas equivocada mas ALTA                              %d",MAX_INCORRECTA);
	
	
	
}
