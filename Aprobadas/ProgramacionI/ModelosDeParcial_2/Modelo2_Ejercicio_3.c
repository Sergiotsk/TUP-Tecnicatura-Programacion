/*Dado un texto de máximo 1000 caracteres.
Realizar solamente la función que calcule el porcentaje de letras vocales contenidas en el texto.*/







#include<stdio.h>
#include<ctype.h>

float FuncionPorcentajeVocales(char []);

int main(void)
{
    char Texto[1001];
    float PorceVocales;
printf("\nIngresar texto: ");
gets(Texto);

PorceVocales=FuncionPorcentajeVocales(Texto);

if (PorceVocales!=0)

    printf("\nPorcentaje de vocales es:  %.2f",PorceVocales);

else
    printf("\nNO HAY VOCALES");


}
////////////////////////////
float FuncionPorcentajeVocales(char T[])
{

     int Cont_caracteres = 0;
     int Cont_vocales =0;

     while (T[Cont_caracteres] != '\0')
     {
        Cont_caracteres++;

        T[Cont_caracteres]=toupper(T[Cont_caracteres]);

        if (T[Cont_caracteres]== 'A' || T[Cont_caracteres]== 'E' ||T[Cont_caracteres]== 'I' ||T[Cont_caracteres]== 'O' ||T[Cont_caracteres]== 'U')
        {
            Cont_vocales++;
        }
            
     }


     if (Cont_caracteres!=0)
     {
        return (float)(Cont_vocales)/Cont_caracteres*100;
     }
     
     

   return 0.0;




}
