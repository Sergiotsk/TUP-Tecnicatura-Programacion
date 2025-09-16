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
    char buscado[20];
    int encontrados = 0;

    FP = fopen("BD", "rb");
    if(!FP){
        printf("\n\tERROR AL ABRIR EL ARCHIVO\n");
        return 1;
    }

    printf("\n\tINGRESE NOMBRE A BUSCAR : ");
    
    if (fgets(buscado, sizeof(buscado), stdin) == NULL){
        
        fclose(FP);
        return 1;
    }
    buscado[strcasecmp(buscado, "\r\n")] = '\0';   /* quitar Enter */

    while (fread(&X, sizeof(X), 1, FP) == 1){
        if (strcasecmp(X.NOM, buscado) == 0){
            if (encontrados == 0){
                printf("\n\n\t\t%-16s %8s %12s", "NOMBRE", "SEXO", "NOTA");
            }
            printf("\n\n\t\t%-16s %8c %12d", X.NOM, X.SEX, X.NOTA);
            encontrados++;
        }
    }

    if (encontrados == 0){
        printf("\n\n\tNO SE ENCONTRARON REGISTROS PARA: %s", buscado);
    }

    printf("\n\n");
    fclose(FP);

    getchar();
    return 0;
}
