/*********STRING O CADENA DE CARACTERES*********************************************
    INGRESAR 1 NOMBRE de un ALUMNO DE maximo 20 caracteres EN UN STRING
    ASIGNAR (COPIAR ) EL NOMBRE EN OTRO STRING
    CON FUNCIONES ******************************************************************/
#include <stdio.h>
#include <string.h>
void COPIA (char[],char[]);
void INFORME(char[],char []);
main()
{
 char NOMBRE1[21], NOMBRE2[21];
 printf("\n Ingresar NOMBRE del alumno : ");
 gets(NOMBRE1);
 //fgets(NOMBRE1,21,stdin);
 COPIA (NOMBRE2, NOMBRE1);
 INFORME (NOMBRE1, NOMBRE2);
 }
 /*************************************************************************/
 void COPIA (char Destino[], char Origen[])
 {
 	strcpy (Destino,Origen);
 }
 /************************************************************************/
 void INFORME (char NOMB1[], char NOMB2[])
 {
 printf("\n El NOMBRE INGRESADO es %s ",NOMB1);
 printf("\n El NOMBRE COPIADO es %s ",NOMB2);
 }
/************************************************************************/
