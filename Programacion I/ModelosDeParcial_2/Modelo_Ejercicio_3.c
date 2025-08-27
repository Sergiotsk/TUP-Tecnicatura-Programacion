/*EJERCICIO 3: 2 (PUNTOS)
Dado un texto de máximo 1000 caracteres.
Realizar solamente la función que coloque al final del texto un punto (.) si no lo tiene.*/


#include<stdio.h>


void PuntoFinal(char[]);

int main(void)
{
    char Texto[1001];
    printf("\nIngresar TEXTO: ");
    fflush(stdin);
    gets(Texto);
   // PuntoFinal(Texto,1001);//NO HACE FALTA LA CANTIDAD DE ELEMENTOS

   PuntoFinal(Texto);
   printf("\nDespues de la funcion punto final: %s",Texto);
     
}
//////////////
void PuntoFinal(char V[])
{
    int I=0;

while (V[I] != '\0')
{
        I++;
}

if ( V[I-1]!='.')
{
    V[I]='.';
    V[I+1]='\0';
}

}
///////////////