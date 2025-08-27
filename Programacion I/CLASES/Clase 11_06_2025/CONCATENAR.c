/********************************* STRING O CADENA DE CARACTERES ***************
  CONCATENAR 2 CADENA DE CARACTERES
*******************************************************************************/

#include <stdio.h>
#include <string.h>
main()
{
 char N1[10] = {"CHAU"} ;
 char N2[16] = {"HOLA "};
 printf("\n Primer cadena %s : ",N1);
 printf("\n Segunda cadena %s : ",N2);

 strcat(N2,N1);
 printf("\n Cadena concatenada %s : ",N2);

}





