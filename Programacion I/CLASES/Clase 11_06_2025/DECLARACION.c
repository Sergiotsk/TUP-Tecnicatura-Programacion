/*******************STRING O CADENA DE CARACTERES****************************/
/********************DECLARACIONES ******************************************/
#include <stdio.h>
main()
{
 char NOMBRE1[]={"ANA"};
 char NOMBRE2[10]={"ANA"};
 char NOMBRE3[10]={'A','N','A','\0'};
 char NOMBRE4[]={'A','N','A','\0'};
 char NOMBRE5[20]={"ANA MARIA"};
 printf("\n\n LOS NOMBRES DECLARADOS SON ");
 printf("\n %s", NOMBRE1);
 printf("\n %s", NOMBRE2);
 printf("\n %s", NOMBRE3);
 printf("\n %s", NOMBRE4);
 printf("\n %s", NOMBRE5);
 printf("\n OTRA FORMA DE VISUALIZAR LOS NOMBRES ES \n");
 puts(NOMBRE1);
 puts(NOMBRE2);
 puts(NOMBRE3);
 puts(NOMBRE4);
 puts(NOMBRE5);

}



