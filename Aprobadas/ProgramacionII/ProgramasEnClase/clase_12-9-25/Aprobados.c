#include <stdio.h>



struct ALUMNO{
    char NOM[20];
    char SEX;
    int  NOTA;
};

int main(void){
    FILE *FP;
    struct ALUMNO APROBADOS;
    
    FP = fopen("BD", "rb");
    if(!FP){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }

    fread(&APROBADOS,sizeof(APROBADOS),1,FP);

printf("\n\n\t\t%28s","Alumnos APROBADOS\n");
printf("\n\n\t\t%-16s %8s %12s","NOMBRE","SEXO","NOTA");
while(fread(&APROBADOS,sizeof(APROBADOS),1,FP)==1){
    if(APROBADOS.NOTA>=6 && APROBADOS.NOTA<=7.99)
        printf("\n\n\t\t%-16s %8c %12d", APROBADOS.NOM, APROBADOS.SEX, APROBADOS.NOTA);    
        
    }
    printf("\n\n\t\t");
    fclose(FP);
    return 0;
}