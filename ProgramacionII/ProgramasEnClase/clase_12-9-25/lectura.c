#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//NOMBRALO COMO escritura y cambia 80 por BD

struct ALUMNO{
    char NOM[20];
    char SEX;
    int NOTA;
};

int main(){


    struct ALUMNO X ;
    FILE * FP;

if(!(FP=fopen("BD","rb"))){
    printf("\n\tERROR AL ABRIR EL ARCHIVO");
    
    exit(1);
}

fread(&X,sizeof(X),1,FP);

printf("\n\n\t\t%-16s %8s %12s","NOMBRE","SEXO","NOTA");
while(!feof(FP)){

    printf("\n\n\t\t%-16s %8c %12d",X.NOM,X.SEX,X.NOTA);

    fread(&X,sizeof(X),1,FP);
}

   
   
   
    printf("\n\n\n\n");



    fclose(FP);
    
    return 0;


}