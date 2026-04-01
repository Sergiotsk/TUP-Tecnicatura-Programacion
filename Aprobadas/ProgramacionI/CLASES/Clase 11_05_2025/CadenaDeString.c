/*
SE CONOOCE 
-DNI
-APELLIDO Y NOMBRE(maximo 40 caracteres)
-nota promedio
DE 30 ALUMNOS DE UNA COMISION.
 SE PIDE:
A) CARGAR TODA LA INFORMACION EN ARRAYS
B)SE CONSULTA SEGUN APELLIDO Y NOMBRE.INFORMANDO DNI Y LA NOTA PROMEDIO 
LA CONSULTA FINALIZA CUANDO SE INGRESA "FIN"
C)INFORMAR 

        DNI                     APELLIDO Y NOMBRE           NOT PROMEDIO
*/


#include<stdio.h>
#include<string.h>

#define CANT_ALUMNOS 3

void CARGA_DATOS(int[],char[][41],float[],int);
void INFORME(int[],char[][41],float[],int);
int  BUSQUEDA_NOMBRE(char[][41],char[],int);



int main(void)
{
int DNI[CANT_ALUMNOS],POS;
char ApeYNom[CANT_ALUMNOS][41],AyNconsulta[41];
float NotaProm[CANT_ALUMNOS];
CARGA_DATOS(DNI,ApeYNom,NotaProm,CANT_ALUMNOS);
INFORME(DNI,ApeYNom,NotaProm,CANT_ALUMNOS);

printf("\nINICIO DE CONSULTAS ");
printf("\nIngresar Apellido y nombre de la consulta (finaliza con FIN): ");
fflush(stdin);
gets(AyNconsulta);

// while (AyNconsulta != "FIN") ---->MAL
while (strcmpi(AyNconsulta,"FIN")!=0)  //strmpi  -> retorna 0 cuando son iguales 
                                      // o o distinto de 0 cuando no son iguales
{
    POS=BUSQUEDA_NOMBRE(ApeYNom,AyNconsulta,CANT_ALUMNOS);
    if (POS >=0)//SE ENCONTRO
    {
        printf("\nDNI del alumno %d -NOTA PROMEDIO %.2f",DNI[POS], NotaProm[POS]);
    }
    else
    printf("\nNO existe el apellido y Nombre buscado ");
    
    printf("\nIngresar Apellido y nombre de la consulta (finaliza con FIN): ");
    fflush(stdin);
    gets(AyNconsulta);
    
}






printf("\nFIN DE LA CONSULTA");






}

/////////////////////////////////////////////funciones

void CARGA_DATOS(int VD[],char AyN[][41],float VP[],int CE)
{

int I;
for(I=0;I<CE;I++)
{

printf("\nINGRESAR DNI DE ALUMNO %d:",I+1);
scanf("%d",&VD[I]);
fflush(stdin);
printf("\nIngresar Apellido y Nombre: ");
gets(AyN[I]);

printf("\nIngresar Nota Promedio: ");
scanf("%f",&VP[I]);
}
}

//////////////////////////////////////////////
void INFORME(int VD[],char AyN[][41],float VP[],int CE)
{
 int I;
 printf("\n\t\t LISTADO DE ALUMNOS ");
 printf("\n\t\t____________________");
 printf("\n%8s\t%30s\t%14s","DNI","APELLIDO Y NOMBRE","NOTA PROMEDIO");
 for (I=0;I<CE;I++)
 {
   printf("\n%8d\t%30s\t%14.2f",VD[I],AyN[I],VP[I]);
 }
 }
 //////////////////////////////////////////////
 int  BUSQUEDA_NOMBRE(char AyN[][41],char DatoAbuscar[],int CE)
 {

int I=0,POSI=-1;

while (I < CE && POSI==-1 )
  if (strcmpi(AyN[I],DatoAbuscar)==0)  
       POSI = I;   // si se encuentra, se asigna la posicion
    else
       I++;

return POSI;

 }