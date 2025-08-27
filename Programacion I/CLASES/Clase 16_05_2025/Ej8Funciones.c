/*En un experimento de laboratorio se toman tiempos entre reacciones, de
comienzo de la reacci�n (hora, minutos, segundos) y de fin de la reacci�n (hora,
minutos, segundos) durante el cada d�a. El ingreso de datos termina con el ingreso
de hora de comienzo negativa.
Determinar el tiempo entre las reacciones para cada par de valores (hora, minutos,
segundos).
Para el c�lculo de dicho tiempo se sugiere usar:
a. FUNCI�N DE CONVERTIR TIEMPO (hora, minuto, segundo) a segundos
b. FUNCI�N RESTA
c. FUNCI�N DIVISI�N*/
#include<stdio.h>
//PROTOTIPOS DE FUNCIONES
int LeeMayorA(int);
int LeeControlRango(int,int);
int CONVERTIR (int, int,int);
int RESTA (int,int);
int DIVISION (int,int);
int RESTO(int,int);

main()
{ // inicio main
  int HC, MC, SC, HF, MF, SF, SegTOTALINICIO, SegTOTALFIN, DifSegundos, HORA, aux, MINUTO, SEGUNDO;
  printf("\nIngresar hora de comienzo de la reaccion (fin con negativo)");
  HC = LeeMayorA(23);	
  while(HC>=0)
  { // inicio while
   printf("\nIngresar minuto de comienzo de la reaccion "); 
   MC = LeeControlRango(0,59);
  
   printf("\nIngresar segundo de comienzo de la reaccion "); 
   SC = LeeControlRango(0,59);
   
   printf("\nIngresar hora  de fin de la reaccion "); 
   HF = LeeControlRango(0,23);
  
   printf("\nIngresar minuto  de fin de la reaccion "); 
   MF = LeeControlRango(0,59);
   
   printf("\nIngresar segundo  de fin de la reaccion "); 
   SF = LeeControlRango(0,59);
   
   SegTOTALINICIO = CONVERTIR(HC,MC,SC);
   SegTOTALFIN = CONVERTIR(HF,MF,SF);
   
   DifSegundos = RESTA(SegTOTALFIN, SegTOTALINICIO);
   
   HORA = DIVISION(DifSegundos,3600);
   aux = RESTO(DifSegundos,3600);
   MINUTO = DIVISION(aux,60);
   SEGUNDO = RESTO(aux,60);
   printf("\nEl tiempo entre reacciones es Hora: %d - Minutos: %d - Segundos: %d",HORA,MINUTO,SEGUNDO );
   
   printf("\nIngresar hora de comienzo de la reaccion (fin con negativo)");
   HC = LeeMayorA(23);	
  
  }//fin while
  
   	
}// fin main
/////////////////////////////////////////////////////////////////////////
int LeeMayorA(int VALOR)
{
 int DATO;
 do{
 	 scanf("%d",&DATO);
 	 if (DATO>VALOR)
 	 	printf("\nERROR, Ingresar nuevamente");
 	}while (DATO >VALOR);	
  return DATO;	
}
/////////////////////////////////////////////////////////////////////////
int LeeControlRango(int DESDE ,int HASTA)
{
  int DATO;
  do{
 	 scanf("%d",&DATO);
 	 if (DATO < DESDE || DATO > HASTA)
 	 	printf("\nERROR, Ingresar nuevamente");
 	}while (DATO < DESDE || DATO > HASTA);	
  return DATO;
}
/////////////////////////////////////////////////////////////////////////
int CONVERTIR (int H, int M ,int S)
{
	return H*3600+M*60+S;
}
////////////////////////////////////////////////////////////////////////
int RESTA (int F,int I)
{
	return F-I;
}
////////////////////////////////////////////////////////////////////////
int DIVISION (int A ,int B)
{
	return A/B;
}
///////////////////////////////////////////////////////////////////////
int RESTO(int A,int B)
{
	return A%B;
}
