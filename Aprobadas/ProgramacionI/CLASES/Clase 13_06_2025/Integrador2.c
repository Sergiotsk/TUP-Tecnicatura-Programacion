#include <stdio.h>
#include <string.h>

void CARGA_INICIAL(char [][11], float [], int);
void INFORME(char [][11], float [], int);
int LeeControlRango(int ,int);
int BUSQUEDA(char [][11], char[], int);
int LeeControlMayorA(int);
int Maximo(int[],int);
void INFORME_MAXIMO(int[], int, int);
void INFORME_C(float [][4],char [][11],int , int);
void INFORME_RECAUDACION(char [][11],float [][4],int,int);
////////////////////////////////////////////////////////////////////////
int main(void)
{
  char NOMSEC[5][11], SEC[11];
  float COST[5], REC[5][4]={{0}};
  float IMPO, DTO, TOTREC = 0;	

  int DIA, CL, POS, MAX;
  int CANTD [4]={0}	;

  CARGA_INICIAL(NOMSEC, COST, 5);
  INFORME(NOMSEC, COST, 5);
  printf("\n INICIO DE LAS VENTAS DE LOCALIDADES ");
  printf("\nIngresar Dia del Recital (Finaliza con cero) ");
  DIA = LeeControlRango(0,4);
  while (DIA !=0)
  { // inicio while
  	 printf("Ingresar SECTOR DE LA VENTA ");
  	 fflush(stdin);
	 gets(SEC);
  	 POS = BUSQUEDA(NOMSEC, SEC, 5);
  	 if (POS >= 0)
  	 {// inicio if 
  	    printf("\nIngresar cantidad de localidades ");
  	    CL = LeeControlMayorA(0);
  	    IMPO = CL * COST[POS];
  	    if (CL> 10  && (DIA == 3 ||  DIA == 4))
  	    {
  	       DTO = IMPO *0.08;
		   IMPO = IMPO - DTO;	// IMPO-=DTO;
  	    }
  	    REC[POS][DIA-1]+= IMPO;  // ITEM A-)
  	    CANTD [ DIA-1]+=CL;	     // ITEM B-)
        TOTREC += IMPO;	 //ITEM D-) 
 	  } // fin if
 	  else
 	     printf("\nERROR, EL SECTOR NO EXISTE ");
 	printf("\nIngresar Dia del Recital (Finaliza con cero) ");
    DIA = LeeControlRango(0,4);     
  }// fin while
  printf ("\n INFORMES ");
  //A- Listado indicando lo recaudado seg�n sector y d�a del recital
  INFORME_RECAUDACION(NOMSEC,REC,5,4);
  //B-) D�a o d�as de m�xima cantidad de localidades adquiridas.
 // PRIMERA ETAPA -> OBTENER EL MAXIMO
  MAX = Maximo(CANTD,4);	
 // SEGUNDA ETAPA -> MOSTRAR DIA/DIAS DE MAXIMA CANTIDAD DE LOCALIDADES
  INFORME_MAXIMO(CANTD, MAX, 4);
  //C-) Indicar el sector o sectores para el d�a 4 que NO hubo localidades solicitadas
  INFORME_C(REC,NOMSEC,5,4);
   	
}
/////////////////////////////////////////////////////////////////////////
void CARGA_INICIAL(char NOM[][11], float PRE[], int CE)
{
  int I;
  for (I=0;I<CE;I++)
  {
  	printf("\nIngresar sector ");
  	fflush(stdin);
	gets(NOM[I]);
	printf("\nIngresar costo ");
	scanf("%f",&PRE[I]);
   }	
}
/////////////////////////////////////////////////////////
void INFORME(char NOM[][11], float PRE[], int CE)
{
  int I;
  printf("\n%10s\t%10s","SECTOR","COSTO");
  for (I=0;I<CE;I++)
  	printf("\n%10s\t%10.2f",NOM[I],PRE[I]);
}
//////////////////////////////////////////////////////////////////////////
int LeeControlRango(int Desde ,int Hasta)
{ 
  int DATO;
  do{
  	 scanf("%d", &DATO);
  	 if (DATO < Desde || DATO > Hasta)
  	     printf("\nERROR; Ingresar nuevamente ");
   }while(DATO < Desde || DATO > Hasta);
   
   return DATO;
}
////////////////////////////////////////////////////////////////////////
int BUSQUEDA(char NOM[][11], char DatoAbuscar[], int CE)
{
 int I = 0, POSI = -1;
 while (POSI ==-1  && I < CE)
     if (strcmpi(NOM[I],DatoAbuscar) == 0 )
     	POSI = I;
     else
        I++;
 return POSI;
}
////////////////////////////////////////////////////////////////////////
int LeeControlMayorA(int Valor)
{
 int DATO;
  do{
  	 scanf("%d", &DATO);
  	 if (DATO <= Valor)
  	     printf("\nERROR; Ingresar nuevamente ");
   }while(DATO <= Valor);
   
   return DATO;	
}
//////////////////////////////////////////////////////////////////////////
int Maximo(int V[],int CE)
{
  int I, maxi = V[0];
  for (I=1; I<CE; I++)	
      if (V[I]> maxi)
         maxi = V[I];
  return maxi;         
}
//////////////////////////////////////////////////////////////////////////
void INFORME_MAXIMO(int V[], int maxi, int CE)
{
 int I;	
 printf ("\n CANTIDAD DE LOCALIDADES MAXIMA %d ", maxi);
 printf("\nOCURRIO EN LOS DIAS : ");
 for (I=0; I<CE; I++)
 	 if (V[I]== maxi)
 	 	printf(" %d ", I+1);
}
/////////////////////////////////////////////////////////////////
void INFORME_C(float MR[][4],char NOM[][11],int Filas , int Columnas)
{
  int I;
  printf("\n SECCIONES DONDE NO HAY CANTIDAD VENDIDA PARA EL DIA %d",Columnas );
  for (I=0; I< Filas; I++)	
     if (MR[I][Columnas-1] == 0)
        printf("\n\t %s", NOM[I]);
}
/////////////////////////////////////////////////////////////////
void INFORME_RECAUDACION(char NOM[][11],float MR[][4],int Filas, int Columnas)
{
  int I, J;
  printf("\n Recaudacion  segun sector y dia del recital "	);
  printf ("\n%11s","SECTOR");
  for (J= 1; J<=Columnas; J++)
        printf("\t%8s %d","DIA ",J);
  for (I=0; I< Filas; I++)
     {
     	printf("\n%11s",NOM[I]);
     	for (J=0; J<Columnas ; J++)
     	   printf("\t%10.2f",MR[I][J]);
     }
}
////////////////////////////////////////////////////////////////////
