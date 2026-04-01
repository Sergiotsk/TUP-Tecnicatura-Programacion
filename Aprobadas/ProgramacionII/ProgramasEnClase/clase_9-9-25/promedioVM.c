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
    float PROMVH=0,PROMM=0,PROM,CANVH=0,CANM=0;
    
   

    FP = fopen("BD", "rb");
    if(!FP){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }

   while(fread(&X,sizeof(X),1,FP)==1){
    if(X.SEX=='M'){
        CANVH++;
        PROMVH+=X.NOTA;
    }
    else{
        CANM++;
        PROMM+=X.NOTA;
    }
       
   }

   
   printf("\n\n\t\tPROMEDIO DE VARONES: %.2f", PROMVH/CANVH);
   printf("\n\n\t\tPROMEDIO DE MUJERES: %.2f", PROMM/CANM);
  

  }