/*Una fabrica produce 20 tipos de embalajes mediante 5 maquinas
Cada dia durante cada produccion se genera una planilla,
 donde se indica:
	*Planilla de produccion
	*tipo de embalaje (1 a 20 ) LeerYControlar con funcion generica
	*maquina que la produjo (4 cifras)
	*cantidad producida.(>0) LeerYControlar con funcion generica
En la ultima informacion se ingreso una 
planilla de produccion cero o negativa.

INGRESAR PREVIAMENTE LOS CODIGOS DE LAS MAQUINAS (mediante una funcion)

Determinar:
a) Cantidad total de embalajes fabricados.
b) Tipo/s de embalaje/s del cual se ha fabricado la mayor cantidad producida. Funcion Maximo
c) Listado indicando:
Numero de maquina   Cantidad fabricada
   xxxx 				xxx
   xxxx 				xxxx
Funcion para Listar
d) Embalajes (Numero/s) no producidos.*/

#include <stdio.h>
// declaracion o prototipos de las funciones
int LeeControlRango(int,int);
void CARGA_CODIGO_MAQUINA(int [],int);
int BUSQUEDA (int[], int, int);
int LeeControlMayorA(int);
int MAXIMO( int[],int);
void LISTAR (int[],int[],int );
void NO_FABRICADOS (int[], int);


main()
{ // inicio main
 int COD_MAQUINA[5],PLAP, TIPO_E, POS, MAQUI, CANT_P;
 int TOTAL_FAB=0, MAX_CANTxEmbalaje, I;
 int V_CANTPxEmbalaje[20]={0}, V_CANTPxMaquina [5]={0};
 
 CARGA_CODIGO_MAQUINA(COD_MAQUINA,5);
 /* POR EJEMPLO:
     COD_MAQUINA -> [ 1000, 2000, 3000, 4000, 5000]
     POSICION    ->     0    1     2     3      4 
     
  */   
 printf ("\n AQUI COMIENZA LA PRODUCCION ");
 printf("\nIngresar PLANILLA DE PRODUCCION (finaliza con cero o negativo )");
 scanf("%d",&PLAP);
 while (PLAP > 0)
 {// inicio while
 	
 	printf("Ingresar CODIGO DE MAQUINA DE LA PRODUCCION ");
 	MAQUI = LeeControlRango(1000,9999);
 	/* SE BUSCA LO INGRESADO ( MAQUI) EN EL VECTOR DE CODIGO DE MAQUINA
 	   CRITERIO DE BUSQUEDA -> POS >= 0  -> SE ENCONTRO
 	   				   POS  -1   -> NO SE ENCONTRO*/
 	POS = BUSQUEDA (COD_MAQUINA, MAQUI, 5);
 	// EJEMPLO -> MAQUI -> 2000 -> EXISTE -> POS -> 1
 	// EJEMPLO -> MAQUI -> 8000 -> NO EXISTE -> POS -> -1
 	if (POS >=0)  // se encontro
 	{ // inicio if
 	  printf("\nIngresar TIPO DE EMBALAJE (1 a 20) ");
 	  TIPO_E = LeeControlRango(1,20);	
 	  
 	  printf("\nIngresar CANTIDAD PRODUCIDA ");
 	  CANT_P = LeeControlMayorA(0);
 	  //a) Cantidad total de embalajes fabricados
 	  TOTAL_FAB += CANT_P;
 	  //b) Cantidad fabricada por tipo de embalaje.	
 	  // V_CANTPxEmbalaje[20] = {0, 0, 0, ......, 0}
 	  // indice              ->  0  1  2          19
 	  // tipo de embajaje    ->  1  2  3 .........20
	  //	EJEMPLO => TIPO_E -> 2
	  //	           CANT_P -> 28	
 	  // V_CANTPxEmbalaje[20] = {0, 28, 0, ......, 0}
	  V_CANTPxEmbalaje[TIPO_E-1] +=CANT_P; 
	  
	  //c-) Cantidad fabricada por maquina
	  //COD_MAQUINA -> [ 1000, 2000, 3000, 4000, 5000]
     	  //POSICION    ->     0    1     2     3      4 
  //V_CANTPxMaquina [5]->[   0,   28 ,  0  ,  0  ,   0 ]
	  // EJEMPLO -> MAQUI -> 2000 -> EXISTE -> POS -> 1
	  //            CANT_P -> 28
	  V_CANTPxMaquina [POS]	+=CANT_P;
	   	
	} // fin if 
	else
	  printf("\n CODIGO DE MAQUINA INCORRECTO");
 	
 	printf("\nIngresar PLANILLA DE PRODUCCION (finaliza con cero o negativo )");
      scanf("%d",&PLAP);
  }// fin while
 printf("\n\n INFORMES");
 if (TOTAL_FAB !=0)
  {
  //a) Cantidad total de embalajes fabricados.	
  printf("\n Cantidad total de embalajes fabricados %d",TOTAL_FAB);
  // b) Tipo/s de embalaje/s del cual se ha fabricado la mayor cantidad producida.
  MAX_CANTxEmbalaje =  MAXIMO( V_CANTPxEmbalaje,20);	
  //V_CANTPxEmbalaje[20] = {10, 50, 50, 0, 50,  ......, 0}
 	  // indice       ->  0   1   2   3   4           19
  // tipo de embajaje   ->  1   2   3   4   5  .........20
  // MAX_CANTxEmbalaje -> 50
  printf ("\n\nMAXIMA CANTIDAD PRODUCIDA %d ",MAX_CANTxEmbalaje );
  printf(" SE PRODUJO EN LOS EMBALAJES:  ");
  for (I= 0; I<20; I++)
      if (V_CANTPxEmbalaje [I]== MAX_CANTxEmbalaje)
      	printf(" %d ", I+1 );  // 2  3  5
  /*c) Listado indicando:
       Numero de maquina   Cantidad fabricada
  		 xxxx 				xxx
   		 xxxx 				xxxx
	Funcion para Listar*/
   LISTAR (COD_MAQUINA,V_CANTPxMaquina,5 );
  // d) Embalajes (Numero/s) no producidos.*/
  
   NO_FABRICADOS (V_CANTPxEmbalaje, 20);
  
  }
  else
    printf("\n NO SE EXISTE PRODUCCION ");	
}// fin main

//definicion (codigo) de las funciones
void CARGA_CODIGO_MAQUINA(int V[],int CE)
{
  int I;
  printf("\n INGRESO DE CODIGOS DE LAS MAQUINAS ");
  for (I=0; I<CE; I++)
  	{
  	 printf("\n Ingresar codigo (4 cifras) ");
	 V[I] = LeeControlRango(1000,9999);  	
  	}	
}
////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////
int BUSQUEDA (int V[], int DatoAbuscar, int CE)
{
 int POSI = -1; // no encontrado
 int I = 0; // se comienza a recorrer desde la primer posicion del vector
 while (POSI == -1 && I<CE)
 	if (V[I] == DatoAbuscar)
 		POSI = I;
 	else
 	      I++;
 return POSI;	
}
/////////////////////////////////////////////////////////////
int LeeControlMayorA(int Valor)
{
 int Dato;
  do{
  	scanf("%d",&Dato);
  	if (Dato <= Valor )
  		printf("\n ERROR, Ingresar nuevamente ");
    }	while(Dato <=Valor);
  return Dato;	
}
/////////////////////////////////////////////////////////////
int MAXIMO( int V [],int CE)
{
 int I, MAX;
 for (I=0; I<CE; I++)
 	if (I==0 || V[I]> MAX)	
 	  MAX = V[I];
 return MAX;	
}
//////////////////////////////////////////////////////////////
void LISTAR (int VC[],int VP[],int CE )
{
  int I;
  printf ("\n\n%17s\t%18s", "Numero de maquina", "Cantidad fabricada");	
  for (I=0; I<CE; I++)
  	printf ("\n\n%17d\t%18d", VC[I], VP[I]);	
}
//////////////////////////////////////////////////////////////
void NO_FABRICADOS (int V[], int CE)
{
 int I;
 printf ("\n\n\t EMBALAJES NO FABRICADOS ");
  for (I=0; I<CE; I++)	
     if (V[I] == 0)
        printf ("\n\t %d", I+1);
}
