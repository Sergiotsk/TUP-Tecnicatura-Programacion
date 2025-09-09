/*

Implementar una funcion generica que lea y controle  el ingreso de un numero entero positivo de 3 cifras.
Reutilizar para ingresar un nuemero que represente un mes.Tambien para el ingreso de la hora



  PROGRAMA PRINCIPAL (main())
  
              NRO = LeeControlRango(100,999) ->numero positivo de 3 cifras
              MES = LeeControlRango(1,12)    ->numero que representa el mes
			  HORA = LeeControlRango(0,23)    ->numero que representa LA HORA
   




FUNCION -> int LeeControlRango (desde,hasta)



*/



#include<stdio.h>


int LeeControlRango(int,int);



main()
{
	int NRO,MES,HORA;
	
	
	printf("\nIngresar Nro de 3 cifras: ");
	NRO = LeeControlRango(100,999);
	printf("\n Se ingreso correctamente un numero positivo de 3 cifras %d",NRO);
	
	printf("\nIngresar MES: ");
	MES = LeeControlRango(1,12);
	printf("\n Se ingreso correctamente un numero REPRESENTATIVO DEL mes %d",MES);
	
	printf("\nIngresar HORA: ");
	HORA = LeeControlRango(0,23);
	printf("\n Se ingreso correctamente LA hora %d",HORA);
	
	
	
	
	
	
}
/////////////////////////////FUNCION

int LeeControlRango(int DESDE,int HASTA)
{
	
	int DATO;
	
	do{
		
		
		
	scanf("%d", &DATO);
		
		
		if(DATO < DESDE || DATO >HASTA)
			{
			printf("\nERROR,Ingresar nuevamente: ");
				
			}
		
				
	}
	while(DATO < DESDE || DATO >HASTA);
	
	return DATO;
	
		
	
	
	
	
	
	
	
}

