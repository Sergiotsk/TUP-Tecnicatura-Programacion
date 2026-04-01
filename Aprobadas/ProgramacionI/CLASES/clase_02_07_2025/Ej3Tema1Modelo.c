/*Dado un texto de m�ximo 1000 caracteres.
Realizar solamente la funci�n que coloque al final del texto un punto (.) 
si no lo tiene.
Ejemplo: "Hola" -> "Hola."
         "Hola." -> "Hola."
*/
#include <stdio.h>
void Funcion_Punto(char[]);
int main(void)
{
  char Texto[1001];
  printf("\nIngresar el texto ");
  gets(Texto);      // "Hola"  ->  'H' 'o' 'l' 'a'  ' .' '\0' 
   			//	 I	 ->	0   1   2   3     4    5
  Funcion_Punto(Texto);
  printf("\n EL TEXTO CON PUNTO ES %s ", Texto);
}
//////////////////////////////////////////////////////////
void Funcion_Punto(char T[])
{
 int I = 0;
 while (T[I] != '\0')	
    I++;
 if (T[I-1] != '.')
 	{
 	  T[I] = '.';
 	  T[I+1] = '\0';
	}	
}

