/*a-) Generar el Tipó De dato Abstracto(TDA) ALUMNOS conteniendo los siguientes campos:
 DNI (entero)
 APELLIDO Y NOMBRE ( máximo 60 caracteres)
 NOTA PRIMER PARCIAL (entero)
 NOTA SEGUNDO PARCIAL (entero)
 NOTA PROMEDIO (real)
 CONDICION (máximo 20 caracteres)
b-) Se sabe que como máximo hay 90 alumnos. Generar un VECTOR en programa principal del tipo
ALUMNOS.
c-)Generar la función CARGA_ALUMNOS que permita SOLAMENTE el ingreso de:
 DNI – APELLIDO Y NOMBRE – NOTA PRIMER PARCIAL – NOTA SEGUNDO PARCIAL
Esta carga finaliza con DNI cero.
NOTAS (0 a 10). Utilizar función para el ingreso y verificación de los valores.
d-) Generar la función PROCESO que calcule el promedio y la condición de cada alumno, según:
 Ambas notas >= 7 condición “PROMOCIONA”
 Alguna nota o las dos < 6 condición “REPROBADA”
 Otro caso condición “CURSADA”
e-) Permitir consultas por DNI, informando la NOTA PROMEDIO y CONDICION correspondiente.
 Finaliza la consulta con DNI a consultar igual a cero.
 FUNCION BUSQUEDA. (Solo busca el DNI a consultar dentro del vector creado)
f-) Listado ordenado en forma descendente por Nota promedio.


*/
#include<stdio.h>
#include<string.h>
#define CantAlumnos 2

typedef struct 
{
    int DNI;
    char AyN[61];
    int Nota1, Nota2;
    float Nprom;
    char Cond[21];

}ALUMNOS;
////////////////////////
int CARGA_ALUMNOS(ALUMNOS[],int);
int LeeControlRango(int,int);
void PROCESO(ALUMNOS[],int);
void INFORME(ALUMNOS[],int);
int BUSQUEDA(ALUMNOS[],int,int);
void ORDEN(ALUMNOS[],int);



int main(void){

int CA,DniAconsultar,POS;
ALUMNOS VA[CantAlumnos] ;

CA=CARGA_ALUMNOS(VA,CantAlumnos);// CA va a contener la cantidad real de ALUMNOS
PROCESO(VA,CA);
ORDEN(VA,CA);
printf("\n Listado de mayor a menor");
INFORME(VA,CA);
printf("\nSE PROCESAN LAS CONSULTAS");
printf("\n Ingresar DNI (finaliza con DNI 0): ");
scanf("%d",&DniAconsultar);

while (DniAconsultar!=0)
{
   POS=BUSQUEDA(VA,DniAconsultar,CA);
   if(POS >= 0)

        printf("\n La nota promedio es: %.2f y la condicion es: %s",VA[POS].Nprom,VA[POS].Cond);

   else
        printf("\n NO EXISTE EL DNI");
   
    printf("\n Ingresar DNI Valido(finaliza con DNI 0): ");
    scanf("%d",&DniAconsultar);    
}
}
////////////////////////////////////////////////////////funciones
int CARGA_ALUMNOS(ALUMNOS V[],int CE){

    ALUMNOS AUX;
    int I=0;

    printf("\nIngresar DNI,(Finaliza con 0); ");
    scanf("%d",&AUX.DNI);

    while (AUX.DNI !=0 && I<CE) 
    {
        fflush(stdin);
        printf("\nIngresar Apellido y Nombre del alumno: ");
        fgets(AUX.AyN, 61, stdin);
        AUX.AyN[strcspn(AUX.AyN, "\n")] = 0; // Eliminar el salto de línea
        printf("\nIngresar nota del primer parcial: ");
        AUX.Nota1=LeeControlRango(1,10);
        printf("\nIngresar nota del segundo parcial: ");
        AUX.Nota2=LeeControlRango(1,10);
        V[I]=AUX;
        I++;

         printf("\nIngresar DNI,(Finaliza con 0); ");
         scanf("%d",&AUX.DNI);
    }
   return I;

}

///////////////////////////////////////////////////
int LeeControlRango(int DESDE ,int HASTA)
{
  int DATO;
  do{
 	 scanf("%d",&DATO);
 	 if (DATO < DESDE || DATO > HASTA)
 	 	printf("\nERROR, calificacion no permitida, Ingresar nuevamente: ");
 	}while (DATO < DESDE || DATO > HASTA);	
  return DATO;
}
////////////////////////
void PROCESO(ALUMNOS V[],int CE)
{

int I;
for (I = 0; I < CE; I++)
{
    
    V[I].Nprom=(float)(V[I].Nota1 + V[I].Nota2)/2;

    if (V[I].Nota1 >=7 && V[I].Nota2 >=7)
         strcpy(V[I].Cond,"PROMOCIONA");
    
    else
        if(V[I].Nota2 >=4 && V[I].Nota2 >=4)
          strcpy(V[I].Cond,"CURSADA");

          else
            strcpy(V[I].Cond,"REPROBADA");

}
}
////////////////////////////
void INFORME(ALUMNOS V[],int CE)

{
   int I;
   printf("\n%8s\t%20s\t%15s\t%15s","DNI","Apellido y Nombre","Nota Promedio","Condicion");
    for (I = 0; I < CE; I++)
    {
         printf("\n%8d\t%20s\t%15.2f\t%15s",V[I].DNI,V[I].AyN,V[I].Nprom,V[I].Cond);
    }
}
/////////////////////////////////
int BUSQUEDA(ALUMNOS V[],int DatoAbuscar,int CE)
{
    int POSI= -1; //no encontrado
    int I=0; //wse comienza a recorrer el primer elemento

    while (POSI == -1 && I < CE)
    {
        if(V[I].DNI == DatoAbuscar)
       
             POSI= I;

        else
             I++; 
    }

     return POSI;  
}
/////////////////////////////////////
void ORDEN(ALUMNOS V[],int CE)
{
	int I,J;
	ALUMNOS AUX;


    for(I=0 ;I < CE-1;I++)
        for(J=0;J<CE-1-I;J++)
           // if(V[J].Nprom  <  V[J+1].Nprom) //  5.5           9.5

           //A gualdad de nota promedio se ordena alfabeticamente por apellido y nombre
             if(((V[J].Nprom  <  V[J+1].Nprom) || (V[J].Nprom  ==  V[J+1].Nprom)) && (strcmpi(V[J].AyN,V[J+1].AyN)>0)) //  5.5           9.5
            {
                AUX=V[J];
                V[J]=V[J+1];
                          // 9.5      5.5
            }		
	
}
