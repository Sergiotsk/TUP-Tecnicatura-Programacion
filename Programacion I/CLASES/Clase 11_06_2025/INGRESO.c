 /******************************** STRING O CADENA DE CARACTERES**************************/
/******************************************** INGRESO ***********************************/
#include <stdio.h>
main()
{
 char NOMBRE_MASCOTA[21];
 char NOMBREyAPELLIDO[61];
 /**** ingreso de datos *****/
 printf("\n Ingresar el nombre de mi mascota ");
 scanf("%s",NOMBRE_MASCOTA);
 printf("\n Ingresar mi nombre y apellido ");
 scanf("%s",NOMBREyAPELLIDO);
 fflush(stdin);  // limpia buffer de entrada
 //gets(NOMBREyAPELLIDO);
 fgets(NOMBREyAPELLIDO, 61,stdin);

 /**** informe de datos *****/
 printf("\n\n MI NOMBRE Y APELLIDO ES %s \n EL NOMBRE DE MI MASCOTA ES %s\n\n", NOMBREyAPELLIDO,NOMBRE_MASCOTA);
 puts("MI NOMBRE Y APELLIDO ES");
 puts(NOMBREyAPELLIDO);
 puts("EL NOMBRE DE MI MASCOTA ES");
 puts(NOMBRE_MASCOTA);

}



