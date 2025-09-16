#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1_cual es la mejor nota
2_busqueda de maxximo
3_busqueda secuencial d la mejor NOTA
3_obtener nombre del alumno*/

struct ALUMNO{
    char NOM[20];
    char SEX;
    int  NOTA;
};
struct MEJORES{
    char NOM[20];
    char SEX;
    int NOTA;
};

int main(void){
    FILE *FP;
    struct ALUMNO X;
    struct MEJORES mejores[100];
    int MAX_NOTA=10, cont=0;    

    FP = fopen("BD", "rb");
    if(!FP){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }
    
    
   while(fread(&X,sizeof(X),1,FP)==1){
    if(X.NOTA>=MAX_NOTA){      
       mejores[cont].NOTA=X.NOTA;
       strcpy(mejores[cont].NOM,X.NOM);
       mejores[cont].SEX=X.SEX;
        cont++;
    }
   }

   printf("\n\n\t\t%-16s %8s %12s", "NOMBRE", "SEXO", "NOTA");
   for(int i=0;i<cont;i++){
    printf("\n\n\t\t%-16s %8c %12d", mejores[i].NOM, mejores[i].SEX, mejores[i].NOTA);
   }
   printf("\n\n");
   printf("\nLa cantidad de alumnos con nota mayor o igual a %d es: %d", MAX_NOTA, cont);

   getchar();




fclose(FP);
return 0;

  }