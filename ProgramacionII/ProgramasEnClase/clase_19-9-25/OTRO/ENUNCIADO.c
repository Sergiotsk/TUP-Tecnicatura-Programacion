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




int main()
{
	struct INGRESO unIngreso;
	struct EXAMEN unExamen;
	FILE *fp, *fpExamen;
	int CANT_INSCRIPCIONES=0;
	char carreraBuscada[20]; // Variable para almacenar la carrera que busca el usuario
	
	printf("Ingrese el nombre de la carrera a buscar: ");
	gets(carreraBuscada); // Leer la carrera que busca el usuario
	
	if(( fp=fopen("INGRESO.unknown", "rb")) == NULL ){	
		printf ("\n\n\nNO SE PUEDE ABRIR EL ARCHIVO " );
		getchar();
		return 0;
	}
	

	fread(&unIngreso, sizeof(struct INGRESO), 1, fp);
	while(!feof(fp)){
		// Comparar la carrera del archivo con la carrera buscada
		if(strcmp(unIngreso.CARRERA, carreraBuscada) == 0){
			CANT_INSCRIPCIONES++;
		}
		fread(&unIngreso, sizeof(struct INGRESO), 1, fp);
	}
	fclose(fp);
	


	printf("\nCantidad de inscripciones en %s: %d", carreraBuscada, CANT_INSCRIPCIONES);
	printf ("\n\n\nFIN DEL PROGRAMA  " );
	getchar();
	return 0 ;


	if(( fpExamen=fopen("EXAMEN.unknown", "rb")) == NULL ){	
		printf ("\n\n\nNO SE PUEDE ABRIR EL ARCHIVO " );
		getchar();
		return 0;
	}

	fread(&unExamen, sizeof(struct EXAMEN), 1, fpExamen);
	while(!feof(fpExamen)){
		printf("%d %d", unExamen.LEG, unExamen.NOTA);
		fread(&unExamen, sizeof(struct EXAMEN), 1, fpExamen);
	}
	fclose(fpExamen); 



	
}


