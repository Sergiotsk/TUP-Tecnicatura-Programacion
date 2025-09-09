/*EJERCICIO 1: 3 (PUNTOS)
Dada una matriz con valores enteros de 3x4.
Implementar solamente una función que determine y guarde en un vector el mínimo valor por columna.

*/

#include<stdio.h>

void MinimoPorColumna(int[][4],int[4],int,int);
void INFORME(int[],int);

int main(void)
{
 int Matriz[3][4]={{20, 56, 54,4},
                  { 50, 20, 99,45},
                  { 89,150,  5,10}},Vmin[4];
MinimoPorColumna(Matriz,Vmin,3,4);
INFORME(Vmin,4);
}

//////////////////////////////////////////////////////////////////////////
void MinimoPorColumna(int M[][4],int Vminimo[4],int fila, int columnas)
{
        int I,J,MIN;

         for (J=0; J<columnas; J++)
         {
            MIN=M[0][J];
            for (I=1;I<fila;I++)
            {
                if(M[I][J]<MIN)
                   {
                     MIN=M[I][J];
                     Vminimo[J]=MIN;
                   }
            }    
             Vminimo[J]=MIN;        
         }  
}
///////////////////////////////////////////////////////////////////////////////
void INFORME(int V[],int CE)
{

int I;
 
    for (I = 0; I< CE; I++)
    {
        printf("\nLos minimos por columna son:%d %d",I,V[I]);
    }
    



}