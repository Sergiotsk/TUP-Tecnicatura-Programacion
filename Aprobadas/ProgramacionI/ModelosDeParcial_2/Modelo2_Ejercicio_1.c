/*Dada una matriz con valores enteros de 4x3
Implementar solamente una función que determine y guarde en un vector el mínimo valor por fila.*/



#include<stdio.h>

void FuncionMinColumna(int [][3],int [],int,int);
void INFORME(int [],int);

int main(void)
{
    int Matriz[4][3]={{20, 56, 54},
                     { 50, 20, 99},
                     { 89,150,  5},
                     { 22, 46, 89}},Vmin[4];
    
    FuncionMinColumna(Matriz,Vmin,4,3);
    INFORME(Vmin,4);

   
    
}

///////////////////
void FuncionMinColumna(int M[][3],int Vm[],int CF,int CC)
{

int I,J,Min;

    for(I=0;I<CF;I++)
    {
        Min=M[I][0];
        for (J=1;J<CC;J++)
        {
            if (M[I][J]<Min)
            {
                Min=M[I][J];
            }
            Vm[I]=Min;
        }

       
    }   
    

}
//////////////
void INFORME(int V[],int CE)
{

int I;
 
    for (I = 0; I< CE; I++)
    {
        printf("\nLos minimos por Fila son:%d FILA %d",I+1,V[I]);
    }
    



}