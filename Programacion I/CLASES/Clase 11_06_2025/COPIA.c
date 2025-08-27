/******************************************** STRING O CADENA DE CARACTERES ******************************/
/****** INGRESAR 1 NOMBRE de un ALUMNO DE maximo 20 caracteres EN UN STRING
/******* ASIGNAR (COPIAR ) EL NOMBRE EN OTRO STRING*******************************************************/
/**COPIAR O ASIGNAR***************************************************************************************/
#include <stdio.h>
#include <string.h>
main()
{
 char NOMBRE1[21], NOMBRE2[21], NOMBRE3[21];
 printf("\n Ingresar NOMBRE del alumno : ");
 gets(NOMBRE1);
 NOMBRE2 = NOMBRE1 ;      //ESTA MAL
 //strcpy(NOMBRE2 , NOMBRE1); //strcpy(destino, origen);
 //strcpy(NOMBRE3 , NOMBRE1);
 printf("\n El NOMBRE INGRESADO es %s ",NOMBRE1);
 printf("\n El NOMBRE COPIADO es %s ",NOMBRE2);
 printf("\n El NOMBRE COPIADO es %s ",NOMBRE3);
}



