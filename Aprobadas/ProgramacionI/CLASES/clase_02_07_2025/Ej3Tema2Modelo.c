/*Dado un texto de m�ximo 1000 caracteres.
Realizar solamente la funci�n que calcule el
 porcentaje de letras vocales contenidas en el texto.*/
#include <stdio.h>
#include <ctype.h>
float FuncionPorcentajeVocales(char[]);
int main(void)
{
  char Texto[1001];
  float PorceVocales;
  printf("\nIngresar el texto ");
  gets(Texto);      // "Hola Mundo" contador caracteres -> 10 
   			//                 contador vocales -> 4
  PorceVocales = FuncionPorcentajeVocales(Texto);
  if (PorceVocales!=0.0)	 
  	printf("\nEL PORCENTAJE DE VOCALES ES %.2f",PorceVocales );
  else
      printf("\nNO HAY CARACTERES INGRESADOS O NO HAY VOCALES");
}
/////////////////////////////////////////////////////////
float FuncionPorcentajeVocales(char T[])
{
  int Cont_caracteres = 0;
  int Cont_vocales = 0;
  while (T[Cont_caracteres] != '\0')
  {
  	Cont_caracteres++;
  	
	T[Cont_caracteres] = toupper(T[Cont_caracteres] );
  	if (T[Cont_caracteres] =='A' || T[Cont_caracteres] =='E' || T[Cont_caracteres] =='I' || T[Cont_caracteres] =='O'|| T[Cont_caracteres] =='U')
  	  Cont_vocales ++;
  }
  if (Cont_caracteres!=0)	
  	return (float)(Cont_vocales)/Cont_caracteres*100; 
  return 0.0;
}
