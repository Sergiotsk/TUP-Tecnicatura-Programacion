/*
1-)Un laboratorio de especialidades medicinales que produce cierto jarabe tiene dos tipos de envases
Tipo ¡¥A¡¦ de 240 mililitros, y Tipo ¡¥B¡¦ de 160 mililitros. Cuyos costos unitarios de cada envase son del
Tipo ¡¥A¡¦ $200 y del Tipo ¡¥B¡¦ es $150.
El laboratorio tiene varias lineas de produccion, y de cada una de ellas se conoce:
„h Nro. linea de produccion
„h Cantidad de mililitros producidos
„h Tipo de envase a utilizar ( ¡¥A¡¦ o ¡¥B¡¦)
Esta informacion termina con Nro. Linea de produccion cero o negativo
Se pide informar:
1. Por cada linea de produccion: Nro. de linea, cantidad de envases necesarios y costo total de los
envases.
2. Cantidad de lineas que usaron mas de 500 envases.
3. Numero de la linea que uso mas envases. (suponer unico)
4. Porcentajes de envases utilizados de cada tipo
5. Cantidad de mililitros sin envasar, por sobrante del envase utilizado


EJEMPLO
         NRO_LINEA           CAN_MILI           TIPO_E  CANT_ENVASES    COSTO


   




*/

#include <stdio.h>
#include <ctype.h>

#define COSTO_TIPO_A 200
#define COSTO_TIPO_B 150


main(){
	
	int NRO_LINEA, CAN_MILI,CANT_ENVASES, COSTO_ENVASES, MAX_ENVASES_NRO_LINEA ,CANT_ENVASES500,MAX_ENVASES,CONTMAX ;
	int 	TOTAL_CANT_ENVASES_TIPO_A,	TOTAL_CANT_ENVASES_TIPO_B,TOTAL_ENVASES, SUM_SOBRANTE,SOBRANTE;
	char TIPO_E ;
	CANT_ENVASES500= MAX_ENVASES = TOTAL_CANT_ENVASES_TIPO_A =TOTAL_CANT_ENVASES_TIPO_B=CONTMAX= SUM_SOBRANTE=0;
	
	
	printf("\nIngresar numero dee Linea(finaliza con cero o negativo) ");
	scanf("%d",&NRO_LINEA);
	
	
	while(NRO_LINEA>0){
		
			printf("\nIngresar cantidad de ML producidos: ");
			scanf("%d",&CAN_MILI);
			
		
			printf("\nIngresar tipo de envase: ");
			fflush(stdin);//Limpia buffer de entrada(saca el ultimo ENTER)
			scanf("%c",&TIPO_E);
			TIPO_E = toupper(TIPO_E);//	se asume que el ingreso es correcto -> se ingreso  A o B
			
			switch(TIPO_E)
			{
				case 'A':   CANT_ENVASES = CAN_MILI/240;
				            COSTO_ENVASES = CANT_ENVASES*COSTO_TIPO_A; 
							TOTAL_CANT_ENVASES_TIPO_A+=CANT_ENVASES;    
							SOBRANTE = CAN_MILI%240;     break;
				
				case 'B':   CANT_ENVASES = CAN_MILI/160;
				            COSTO_ENVASES = CANT_ENVASES*COSTO_TIPO_B;  
							TOTAL_CANT_ENVASES_TIPO_B+=CANT_ENVASES;  
							SOBRANTE =CAN_MILI%160 ;         
				
				}	///fin de switch
		SUM_SOBRANTE+=SOBRANTE;
		if(CANT_ENVASES > 500)
		CANT_ENVASES500 ++;
		
		if(CONTMAX == 0){
			MAX_ENVASES =CANT_ENVASES;
			MAX_ENVASES_NRO_LINEA= NRO_LINEA;
			CONTMAX++;
			
		}
		else if(CANT_ENVASES > MAX_ENVASES){
			MAX_ENVASES =CANT_ENVASES;
			MAX_ENVASES_NRO_LINEA =NRO_LINEA;
		}
		
		
		printf("\nlINEA DE PRODUCCION: %d \nCantidad de envases necesarios: %d \nCosto TOTAL de los envases: %d ",NRO_LINEA,CANT_ENVASES,COSTO_ENVASES);
		
		
		
		
		printf("\nIngresar numero dee Linea(finaliza con cero o negativo) ");
		scanf("%d",&NRO_LINEA);
	
		///
		
	}
	
	if(CONTMAX!=0)//HAY DATOS
	{
		printf("\n Cantidad de lineas que usaron mas de 500 envases  %d",	CANT_ENVASES500);
		printf("\n Numero de la linea que uso mas envases            %d",		MAX_ENVASES_NRO_LINEA);
		TOTAL_ENVASES=TOTAL_CANT_ENVASES_TIPO_A+TOTAL_CANT_ENVASES_TIPO_B; 
		printf("\n Porcentaje de envases del tipo A                  %.2f",	(float) TOTAL_CANT_ENVASES_TIPO_A/TOTAL_ENVASES*100),printf("%%");
		printf("\n Porcentaje de envases del tipo A                  %.2f",	(float) TOTAL_CANT_ENVASES_TIPO_B/TOTAL_ENVASES*100),printf("%%");
		printf("\n Cantidad de ML sin envasar SOBRANTE:              %d ",	SUM_SOBRANTE),printf("Ml");	

	}
	
	else
		printf("\nNo se ingresaron DATOS");
	
	
	
	
	
	
	
	
	
	
}
