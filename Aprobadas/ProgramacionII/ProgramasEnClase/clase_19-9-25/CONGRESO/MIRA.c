

#include <stdio.h>
#include <stdlib.h>   
#include <string.h>   
 
#define NUMSEN 20
struct LEG {
	 unsigned int LEGAJO ;
	 char CARGO[20] ;
	 unsigned int SUELDO ;
};

int main()
{
	
	FILE * FPSENADO ;
	FILE * FPASESOR ;
	int I , J , K , NUMASESORES ;
	struct LEG ASESOR ;
	char SENADOR[20] ;
	unsigned int LEGAJO ;
	
	
	FPSENADO = fopen ("SENADO.DAT" , "rb") ;
	FPASESOR = fopen ("ASESOR.DAT" , "rb") ;
	
	
	fread(SENADOR , sizeof(SENADOR) , 1, FPSENADO );
	while ( ! feof(FPSENADO) ) {
			fread(&NUMASESORES , sizeof(NUMASESORES) , 1, FPSENADO );
			printf("\n\n\t\t %-30s %30d\n\n" , SENADOR , NUMASESORES);
			for ( I = 0 ; I < NUMASESORES ; I++ ) {
				fread(&LEGAJO , sizeof(unsigned int) , 1, FPSENADO );
				printf("%10d" , LEGAJO );
			}
			getchar();
				
			fread(SENADOR , sizeof(SENADOR) , 1, FPSENADO );
	}
	
	printf("\n\n\n\t\t\tNOMINA DE ASESORES\n\n");

	fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
	while ( ! feof(FPASESOR) ) {
			printf("\n\n\n\t\t %10d \t\t %-30s %30d\n\n" , ASESOR.LEGAJO , ASESOR.CARGO , ASESOR.SUELDO);
			getchar();
				
			fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
	}

	fclose ( FPSENADO ) ;
	fclose ( FPASESOR ) ;
	
	
	printf("\n\n\n  FIN DEL PROGRAMA DE GENERACION\n"); 
	
	return 0 ;
}
