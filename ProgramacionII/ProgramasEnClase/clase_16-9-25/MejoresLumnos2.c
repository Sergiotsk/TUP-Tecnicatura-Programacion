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


int main(void){
    FILE *FP;
    struct ALUMNO X;    
    int MAX_NOTA=0, cont=0;    

    FP = fopen("BD", "rb");
    if(!FP){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }
    while(fread(&X,sizeof(X),1,FP)==1){
        if(X.NOTA>MAX_NOTA){
            MAX_NOTA=X.NOTA;
            
        }

       }
       rewind(FP);
    
       printf("\n\n\t\t%-16s %8s %12s", "NOMBRE", "SEXO", "NOTA");
   while(fread(&X,sizeof(X),1,FP)==1){
  
    if(X.NOTA==MAX_NOTA){ 

        printf("\n\n\t\t%-16s %8c %12d", X.NOM, X.SEX, X.NOTA);
      
    }
    
   }

   
  
   printf("\n\n");
   
   getchar();




fclose(FP);
return 0;

  }
