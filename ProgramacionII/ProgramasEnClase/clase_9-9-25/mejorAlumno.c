#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO{
    char NOM[20];
    char SEX;
    int  NOTA;
};

int main(void){
    FILE *FP;
    struct ALUMNO X;
    int MAX=0;
    char MEJOR[20];

    FP = fopen("BD", "rb");
    if(!FP){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }

   while(fread(&X,sizeof(X),1,FP)==1){
    if(X.NOTA>MAX){
        MAX=X.NOTA;
        strcpy(MEJOR,X.NOM);
    }
   }

    printf("\n\n\t\t%-16s %8s %12s", "NOMBRE", "SEXO", "NOTA");
    printf("\n\n\t\t%-16s %8c %12d", MEJOR, X.SEX, MAX);










    printf("\n\n");
    fclose(FP);
    return 0;
}
