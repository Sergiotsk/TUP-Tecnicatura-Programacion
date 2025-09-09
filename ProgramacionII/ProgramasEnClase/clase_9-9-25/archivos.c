#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//NOMBRALO COMO escritura

struct ALUMNO{
    char NOM[20];
    char SEX;
    int NOTA;
};

int main(){


    struct ALUMNO X ;
    FILE * FP;

if(!(FP=fopen("80","wb"))){
    printf("\n\tERROR AL ABRIR EL ARCHIVO");
    
    exit(1);
}

    printf("\n\tNOMBRE  : ");
    gets(X.NOM);

    while(strcmp(X.NOM,"FIN")!=0)
    {   

    printf("\n\tSEXO    : ");
     X.SEX = getchar();
   
    printf("\n\tNOTA    : ");
    scanf("%d",&X.NOTA);
    fflush(stdin);

    fwrite(&X,sizeof(X),1,FP);


     printf("\n\n\n\tNOMBRE  : ");
    gets(X.NOM);

   }
    printf("\n\n\n\n");



    fclose(FP);
    getch();
    return 0;


}
