/*
EJERCITACION VECTORES CON ACCESO POR BUSQUEDA Y DIRECTO POR VARIABLE

Una fábrica produce 20 tipos de embalajes mediante 5 máquinas
Cada día durante cada producción se genera una planilla, donde se indica:

    Planilla de producción
    tipo de embalaje (1 a 20 ) LeerYControlar con función genérica
    máquina que la produjo (4 cifras)
    cantidad producida.(>0) LeerYControlar con función genérica

En la última información se ingresó una planilla de producción cero o negativa.
INGRESAR PREVIAMENTE LOS CODIGOS DE LAS MAQUINAS (mediante una función)
Determinar:

   a) Cantidad total de embalajes fabricados.
   b) Tipo/s de embalaje/s del cual se ha fabricado 
   la mayor cantidad producida. Función Máximo
   c) Listado indicando:

Numero de maquina      Cantidad fabricada
xxxx                   xxx
xxxx                   xxxx
Función para Listar

d) Embalajes (Número/s) no producidos.




*/

#include<stdio.h>

int LeeControlRango(int,int);

void CARGA(int [],int);

int BUSQUEDA (int[],int,int);

int LeeControlMayorA(int);

int MAXIMO(int[],int);

void LISTAR(int [], int [], int );

 int main(void)
 {
    int PLAP, CODM[5], TIPO_E, MAQUI, POS, CANT_P, TOTAL_FAB=0, V_CANTPxEmbalaje[20]={0}, V_CANTPxMaquina[5]={0};
    int MAX_CANTxEmbalaje,I=0;
   CARGA(CODM,5);
   printf("\n\t\t COMIENZA LA PRODUCCION");
   printf("\n Ingresar planilla de produccion");
   scanf("%d",&PLAP);

   while(PLAP > 0)
   {
      
      printf("\n Ingresar codigo de maquina de la produccion:");
      MAQUI=LeeControlRango(1000,9999);
      /* POR EJ:

               CODM -> [1000, 2000, 3000, 4000, 5000]
         POSICION->       0     1     2     3     4

         SE BUSCA LO INGRESADO (MAQUI) EN EL VECTOR DE CODIGO DE MAQUINA
         CRITERIO DE BUSQUEDA -> POS >=0  -> SI SE ENCONTRO
                                 POS  -1  -> NO SE ENCONTRO  
                                 
          EJ:  -> MAQUI -> 2000 ->EXISTE ->POS -> 1
               -> MAQUI -> 8000 ->NO EXISTE -> POS -> -1                      

      
      */
     POS=BUSQUEDA(CODM,MAQUI,5);
      if(POS >= 0)
      {
          printf("\n Ingresar tipo de embalaje:");
          TIPO_E= LeeControlRango(1,20);

          printf("\n Ingrese cantidad producida:");
          CANT_P= LeeControlMayorA(0);
          //a) cantidad total de embalajes
          TOTAL_FAB+= CANT_P;
          /*b) cantidad feabricado por tipo de embalaje
          V_CANTXEmbajaje [20] = {0,0,0,0,0,0,....,0}
          indice              ->  0 1 2 3 4 5      19
          tipo de embalaje    ->  1 2 3 4 5 6      20
          Ej=> TIPO_E -> 2
               CANT_P -> 28
          
         V_CANTPxEmbalaje[20]={0,28,0,0,0,0........,0}
        
  */
         V_CANTPxEmbalaje[TIPO_E-1] += CANT_P;

          /*b) cantidad feabricado por tipo de maquina
          V_CANTxMaquina [20] = {0,0,0,0,0}
          indice             ->  0 1 2 3 4       
          Num de Maquina     ->  1 2 3 4 5 
          Ej=> MAQUI  ->  2
               CANT_P -> 28
                    
  */
         V_CANTPxMaquina[POS]+= CANT_P;

      }
      else
      printf("\n Codigo de Maquina Incorrecto");     
    
    
    printf("\n Ingresar planilla de produccion");
    scanf("%d",&PLAP);
 }

 printf("\n INFORME");
 if(TOTAL_FAB!=0)
 {
    // a) Cantidad total de embalajes fabricados.
    printf("\nCantidad total producida %d",TOTAL_FAB);
  // b) Tipo/s de embalaje/s del cual se ha fabricado 
   //la mayor cantidad producida. Función Máximo
    MAX_CANTxEmbalaje = MAXIMO(V_CANTPxEmbalaje,20);
    printf("\nMaxima cantidad producida %d",MAX_CANTxEmbalaje);
    printf("\nSe produjo en los embalajes ");
    for(I=0;I<20; I++)
         if (V_CANTPxEmbalaje[I] == MAX_CANTxEmbalaje)
         {
            printf("\n %d",I+1);
         }
    /*
    c)Listado indicando:
    Numero de maquina      Cantidad fabricada
    xxxx                   xxx
    xxxx                   xxxx
    */     

    LISTAR(CODM,V_CANTPxMaquina,5);
               




 }
 else
 printf("\n No hubo produccion");
}//fin del main
 /////////////////////funciones////////////////////////////////////
 void CARGA(int V[],int CE)
{
 int I;
 for (I=0; I<CE;I++)
 {
   printf("\n Ingrese los codigos de las maquinas %d:",I+1);
   V[I] = LeeControlRango(1000,9999);	
 }
}
//////////////////////////////////////////////////////////////////
int LeeControlRango(int Desde,int Hasta)
{
  int DATO;
  do{
  	  scanf("%d", &DATO);
  	  if (DATO < Desde || DATO > Hasta)
  	  	  printf("\n ERROR, Ingresar nuevamente ");
  }while ((DATO < Desde || DATO > Hasta));
  return DATO;
  }	
  //////////////////////////////////////////////////////////////////
  int BUSQUEDA (int V[],int DATO,int CE)
{
 int POSI = -1; //no encontrado
 int I = 0; // se recorre desde la primer posicion
 while (POSI == -1 && I < CE )  // mientra no se encuentra y estamos dentro del vector se sigue buscando
    if (V[I]== DATO)  
       POSI = I;   // si se encuentra, se asigna la posicion
    else
       I++;
 return POSI;
}
//////////////////////////////////////////////////////////////////////
int LeeControlMayorA(int Valor)
{
   int DATO;
  do{
  	  scanf("%d", &DATO);
  	  if (DATO <= Valor)
  	  	  printf("\n ERROR, Ingresar nuevamente ");
  }while (DATO <=Valor);

  return DATO;

}
/////////////////////////////////////////////////////////////////////
int MAXIMO (int V[],int CE)
{
 int I, MAX;
 for(I=0 ; I<CE ; I++)
      if(I==0 || V[I]>MAX)
      MAX = V[I];

   return MAX;   

}
/////////////////////////////////////////////////////////////////////
void LISTAR(int VC[], int VP[], int CE )
{
int I;
printf("\n\n%17s\t%18s","NUMERO DE MAQUINA","CANTIDAD FABRICADA" );

   for(I=0 ; I<CE ; I++)
      printf("\n\n%17d\t%18d",VC[I],VP[I] );


}
///////////////////////////////////////////////////////////////////////
void NO_FABRICADOS(int V[],int CE)
{
 int I;
 printf("\n Embalajes NO fabricados");
 for(I=0 ; I<CE ; I++)
      if(V[I]==0)
      printf("%d",I+1);



}