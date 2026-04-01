#include <stdio.h>


struct ALUMNO{
    char NOM[20];
    char SEX;
    int  NOTA;
};

int main(void){
    FILE *FP;
    struct ALUMNO PROMOCION;
    
FP = fopen("BD", "rb");
if(!FP){
    printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
    return 1;
}

fread(&PROMOCION,sizeof(PROMOCION),1,FP);


printf("\n\n\t\t%28s","Alumnos PROMOCIONADOS\n");
printf("\n\n\t\t%-16s %8s %12s","NOMBRE","SEXO","NOTA");
while(fread(&PROMOCION,sizeof(PROMOCION),1,FP)==1){
    if(PROMOCION.NOTA>=8 && PROMOCION.NOTA<=10)
        printf("\n\n\t\t%-16s %8c %12d", PROMOCION.NOM, PROMOCION.SEX, PROMOCION.NOTA);    
        
    }
    printf("\n\n\t\t");
    fclose(FP);
    return 0;
}