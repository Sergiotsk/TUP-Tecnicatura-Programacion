/*  EL ARCHIVO "INGRESO" TIENE LOS DATOS DE LA INSCRIPCION DE ALUMNOS  */
/*  A UNA UNIVERSIDAD. SE COMPONE DE ESTRUCTURAS INGRESO               */
/*  SE COMPONEN DE LEGAJO DEL ALUMNO Y CARRERA EN LA QUE SE INSCRIBIO  */

/*  EL ARCHIVO "EXAMEN" TIENE LOS DATOS DEL EXAMEN DE INGRESO COMUN A  */
/*  TODAS LAS CARRERAS. SE COMPONE DE ESTRUCTURAS EXAMEN               */
/*  ESTAS ESTAN FORMADAS POR EL LEGAJO DEL ALUMNO Y LA NOTA DEL EXAMEN */

/*  SE PIDE  :                                                           */
/*  1. PERMITIR EL INGRESO DE UN NOMBRE DE CARRERA E INDICAR :           */
/*  	A)  CUANTOS ALUMNOS SE INSCRIBIERON EN ESA CARRERA               */
/*  	B)  CUANTOS ALUMNOS SE PRESENTARON A EXAMEN (DE ESA CARRERA)     */
/*  	C)  CUANTOS ALUMNOS DE ESA CARRERA APROBARON (NOTA >= 6)         */


/*  2. CUAL ES LA CARRERA EN LA QUE HUBO MAYOR INSCRIPCION               */

/*  3. CUAL ES LA CARRERA QUE TUVO MAYOR CANTIDAD DE INGRESANTES         */

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct INGRESO {
		int LEG ;
		char CARRERA[20] ;
};

struct EXAMEN {
		int LEG ;
		int NOTA ;
};

struct MAX_CARRERA{
		char CARRERA[20];
		int CANTIDAD;
		int CANTIDAD_APROBADOS;
};

int main()
{
	
	struct MAX_CARRERA max_carrera[500];
	struct INGRESO unIngreso;
	struct EXAMEN unExamen;
	FILE *fpIngreso, *fpExamen;
	int CANT_INSCRIPCIONES=0,CANT_EXAMENES=0,CANT_APROBADOS=0;
	char carreraBuscada[20]; 
	int legajosBuscados[500];
	int cantLegajosBuscados=0;	
	max_carrera[0].CANTIDAD=0;
	int totalCarreras=0;
	
	


	if((fpIngreso=fopen("INGRESO", "rb")) == NULL ){		// error si no se puede abrir el archivo
		printf ("\n\n\nNO SE PUEDE ABRIR EL ARCHIVO " );
		getchar();				
	}
	
	while(fread(&unIngreso, sizeof(struct INGRESO), 1, fpIngreso) == 1){

		printf("\n LEGAJO: %d\tCARRERA: %-20s",unIngreso.LEG,unIngreso.CARRERA);
				
	}
	rewind(fpIngreso);

	if((fpExamen=fopen("EXAMEN", "rb")) == NULL ){		
		printf ("\n\n\nNO SE PUEDE ABRIR EL ARCHIVO " );
		getchar();				
	}
	
	while(fread(&unExamen, sizeof(struct EXAMEN), 1, fpExamen) == 1){

		printf("\n LEGAJO: %d\tNOTA: %d",unExamen.LEG,unExamen.NOTA);
		
		

		
	}
	printf("\n\n");
	rewind(fpExamen);
	getchar();

	
	
	printf("\n\nIngrese el nombre de la carrera a buscar: ");
	fgets(carreraBuscada, sizeof(carreraBuscada), stdin);		// use fgets para evitar problemas con el buffer, y por que me tiraba warning usando el gets 
	carreraBuscada[strcspn(carreraBuscada, "\n")] = 0; 			//aca saco el \n que me deja fgets
	
	
	
	

	fread(&unIngreso, sizeof(struct INGRESO), 1, fpIngreso);
	while(!feof(fpIngreso)){
			
		// Comparo la carrera del archivo con la carrera buscada
		if(strcasecmp(unIngreso.CARRERA,carreraBuscada) == 0){
			
			legajosBuscados[cantLegajosBuscados]=unIngreso.LEG;
			cantLegajosBuscados++;
			CANT_INSCRIPCIONES++;
		}

		fread(&unIngreso, sizeof(struct INGRESO), 1, fpIngreso);
	}
	if(CANT_INSCRIPCIONES==0){
		printf("No se encontro la carrera buscada\n");
		return(0);
	}

	
	
	rewind(fpIngreso); // para que el puntero vuelva al inicio del archivo

	
	if(( fpExamen=fopen("EXAMEN", "rb")) == NULL ){		
		printf ("\n\n\nNO SE PUEDE ABRIR EL ARCHIVO " );
		getchar();				
	}

	fread(&unExamen, sizeof(struct EXAMEN), 1, fpExamen);

	while(!feof(fpExamen)){
		for(int i=0;i<cantLegajosBuscados;i++){
			if(unExamen.LEG == legajosBuscados[i]){
				CANT_EXAMENES++;
				if(unExamen.NOTA >= 6){
					CANT_APROBADOS++;
					
				}		
			}	
			
			}	
		fread(&unExamen, sizeof(struct EXAMEN), 1, fpExamen);
	}
	rewind(fpExamen); // para que el puntero vuelva al inicio del archivo

	

	fread(&unIngreso,sizeof(struct INGRESO),1,fpIngreso);
	while(!feof(fpIngreso)){
		int encontrada=0;
		for(int i=0;i<totalCarreras;i++){
		if(strcasecmp(unIngreso.CARRERA,max_carrera[i].CARRERA) == 0){

			max_carrera[i].CANTIDAD++;	
			encontrada=1;
	}
	
  }

  // Si no está, la agrego nueva
	if (!encontrada) {
		strcpy(max_carrera[totalCarreras].CARRERA, unIngreso.CARRERA);
		max_carrera[totalCarreras].CANTIDAD = 1;
		totalCarreras++;
	}

	fread(&unIngreso, sizeof(struct INGRESO), 1, fpIngreso);
	
	
}
rewind(fpIngreso);


	// Buscar la carrera con más inscripciones
    int max = 0;
    char carreraMax[20];
    for (int i = 0; i < totalCarreras; i++) {
        if (max_carrera[i].CANTIDAD > max) {
            max = max_carrera[i].CANTIDAD;
            strcpy(carreraMax, max_carrera[i].CARRERA);
        }
    }


while (fread(&unExamen, sizeof(struct EXAMEN), 1, fpExamen) == 1) {
    if (unExamen.NOTA >= 6) {
        // Buscar el legajo en INGRESO para saber a qué carrera pertenece
        
        while (fread(&unIngreso, sizeof(struct INGRESO), 1, fpIngreso) == 1) {
            if (unIngreso.LEG == unExamen.LEG) {
                // Buscar la carrera en el vector max_carrera y sumar aprobado
                for (int i = 0; i < totalCarreras; i++) {
                    if (strcasecmp(unIngreso.CARRERA, max_carrera[i].CARRERA) == 0) {
                        max_carrera[i].CANTIDAD_APROBADOS++;
                       
                    }
                }
                
            }
        }
		rewind(fpIngreso);
    }
}

	char carreraMaxAprobados[20];
	int max_aprobados=0;
	for(int i=0;i<totalCarreras;i++){
		if(max_carrera[i].CANTIDAD_APROBADOS>=max_aprobados){
			max_aprobados=max_carrera[i].CANTIDAD_APROBADOS;
			strcpy(carreraMaxAprobados,max_carrera[i].CARRERA);
		}
	}


	printf("\nCantidad de inscripciones en %s: %d\n", carreraBuscada, CANT_INSCRIPCIONES);
	printf("\nCantidad de ALUMNOS que rindieron examenes en %s: %d\n", carreraBuscada, CANT_EXAMENES);
	printf("\nCantidad de ALUMNOS que aprobaron examenes en %s: %d\n", carreraBuscada, CANT_APROBADOS);	
	printf("\nLa carrera con mayor inscripcion es: %s (%d inscriptos)\n", carreraMax, max);	
	printf("\nCarrera con Mayor cantidad de Aprobados %s (%d aprobados)",carreraMaxAprobados,max_aprobados);
	


	
	
	printf ("\n\n\nFIN DEL PROGRAMA  " );
	getchar();

	fclose(fpIngreso);
	fclose(fpExamen);
}

