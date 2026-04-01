/********************************* STRING O CADENA DE CARACTERES ***************
  INGRESAR 2 NOMBRES de DOS ALUMNOS DE maximo 20 caracteres EN DOS STRING
  COMPARAR LOS NOMBRES.
  DETERMINAR SI SON IGUALES
  En CASO CONTRARIO INFORMARLOS EN FORMA ALFABETICA*****************************/

#include <stdio.h>
#include <string.h>
main()
{
 char NOMBRE1[21], NOMBRE2[21];
 printf("\n Ingresar NOMBRE 1: ");
 gets(NOMBRE1);
 
 printf("\n Ingresar NOMBRE  2: ");
 gets(NOMBRE2);
 
 if (strcmp(NOMBRE1,NOMBRE2)== 0)
   printf ("\n LOS NOMBRES INGRESADOS SON IGUALES");
 else
    if (strcmp(NOMBRE1,NOMBRE2)< 0)
     printf("\n LOS NOMBRE SON DISTINTOS ORDENADOS ALFABETICAMENTE \n %s  %s",NOMBRE1,NOMBRE2);
    else
	 printf("\n LOS NOMBRE SON DISTINTOS ORDENADOS ALFABETICAMENTE \n %s   %s",NOMBRE2,NOMBRE1);
}





