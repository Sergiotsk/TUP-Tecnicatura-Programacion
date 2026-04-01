#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *FP;
   
    if(!( FP = fopen(argv[1], "rb");)){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }
    fseek(FP,0,SEEK_END);
    printf("\n");
    printf("TAMANIO DEL ARCHIVO:\n");
    printf("\n");
    printf("\n\tEL ARCHIVO TIENE %ld BYTES\n",ftell(FP));
    printf("\n\n");
    printf("\n\tEn KILOBYTES: %.f KB\n", (float)ftell(FP) / 1024);
    printf("\n\n");
 
    
    fclose(FP);
 
    return 0;
}
