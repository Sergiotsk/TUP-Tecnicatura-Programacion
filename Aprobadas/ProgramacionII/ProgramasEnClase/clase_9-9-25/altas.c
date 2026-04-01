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

if(!(FP=fopen("BD","ab"))){
    printf("\n\tERROR AL ABRIR EL ARCHIVO");
    
    exit(1);
}
printf("\n\n\n\t  NOMBRE : ");
 gets(X.NOM);
 	while(strcmp(X.NOM,"FIN")){
 		printf("\n\t  SEXO : ");
 		X.SEX=getchar();
 		printf("\n\t  NOTA	: ");
 		scanf("%d",&(X.NOTA) );
 		fflush(stdin);
 	
 		fwrite(&X, sizeof(X),1,FP);
 	
 		printf("\n\n\n\t  NOMBRE : ");
 		gets(X.NOM);
 }


    fclose(FP);
    getchar();
    return 0;


}