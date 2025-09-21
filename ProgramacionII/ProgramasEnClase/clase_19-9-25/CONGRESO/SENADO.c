/*  EL ARCHIVO SENADO.DAT ESTA FORMADO POR :
    NOMBRE DEL SENADOR (string de 20)
    NUMERO DE AUXILIARES (int)
    LEGAJO DE LOS AUXILIARES (unsigned int)
    
    EL ARCHIVO ASESOR.DAT ESTA FORMADO POR ESTRUCTURAS lEG
    
    SE PIDE DETERMINAR :
    
    1. SENADOR QUE OCASIONA MAS GASTOS
    2. SENADORES QUE NO TIENEN CHOFERES
    3. SENADOR QUE OCASIONA MAS GASTOS EN GUARDAESPALDAS
*/
  
  
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
	char SENADOR[20] , MAXSENADOR[20] ;
	unsigned int LEGAJO ; 
	unsigned int SUELDOS , MAXSUELDOS , CHOFER ; 	
			
	FPSENADO = fopen ("SENADO.DAT" , "rb") ;
	FPASESOR = fopen ("ASESOR.DAT" , "rb") ;
		
	fread(SENADOR , 20 , 1 , FPSENADO );
	while ( ! feof(FPSENADO) ) {
			fread(&NUMASESORES , sizeof(NUMASESORES) , 1, FPSENADO );
			printf("\n\n\t\t %-30s %30d\n\n" , SENADOR , NUMASESORES);
			for ( I = 0 ; I < NUMASESORES ; I++ ) {
				fread(&LEGAJO , sizeof(unsigned int) , 1, FPSENADO );
				printf("%10d" , LEGAJO );
			}
			fread(SENADOR , 20 , 1, FPSENADO );
	}
	getchar();
	
	printf("\n\n\n\t\t\tNOMINA DE ASESORES\n\n");

	fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
	while ( ! feof(FPASESOR) ) {
			printf("\n\n\n\t\t %10d \t\t %-30s %30d\n\n" , 
			ASESOR.LEGAJO , ASESOR.CARGO , ASESOR.SUELDO);
			
			fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
	}
    getchar();
    
	rewind ( FPSENADO ) ;
	rewind ( FPASESOR ) ;
	
	/*****************************/
	/*                           */
	/*   SENADOR DE MAS GASTOS   */
	/*                           */
	/*****************************/
	
	printf("\n\n\n\n\t\t\t\t SENADOR DE MAS GASTOS\n");
	MAXSUELDOS = 0 ;
	
	fread(SENADOR , 20 , 1, FPSENADO );
	while ( ! feof(FPSENADO) ) {
			fread(&NUMASESORES , sizeof(NUMASESORES) , 1, FPSENADO );
			/*  TENGO LA CANTIDAD DE ASESORES  */
			
			SUELDOS = 0 ;    
			
			//  CUANTO COBRAN TODOS ELLOS ??
			for ( I = 0 ; I < NUMASESORES ; I++ ) {
				fread(&LEGAJO , sizeof(unsigned int) , 1, FPSENADO );
										
				/*  CUANTO COBRA CADA ASESOR ??  */
				rewind(FPASESOR);
				fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
				while ( ! feof(FPASESOR) ) {
						if ( ASESOR.LEGAJO == LEGAJO  ) 
								SUELDOS = SUELDOS + ASESOR.SUELDO ;
								
						fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
				}
			}	
						
			if ( SUELDOS > MAXSUELDOS ) {
					MAXSUELDOS = SUELDOS ;
					strcpy ( MAXSENADOR , SENADOR );				
			}	
						
			fread(SENADOR , 20 , 1, FPSENADO );
	}
	
	printf("\n\n\t\t\t\t SENADOR DE MAS GASTOS  =  %s\n\n\n\n" , MAXSENADOR);
	getchar();
	
		
	/**********************************************/
	/*                                            */
	/*   SENADOR DE MAS GASTOS EN GUARDAESPALDAS  */
	/*                                            */
	/**********************************************/
	printf("\n\n\n\n\t\t\t\t SENADOR DE MAS GASTOS EN GUARDAESPALDAS\n");

	rewind ( FPSENADO ) ;
	rewind ( FPASESOR ) ;
	MAXSUELDOS = 0 ;
		
	fread(SENADOR , 20 , 1, FPSENADO );
	while ( ! feof(FPSENADO) ) {
			
			
			fread(&NUMASESORES , sizeof(NUMASESORES) , 1, FPSENADO );
			/*  TENGO LA CANTIDAD DE ASESORES  */
			SUELDOS = 0 ;    //  CUANTO COBRAN TODOS ELLOS ??
			for ( I = 0 ; I < NUMASESORES ; I++ ) {
				fread(&LEGAJO , sizeof(unsigned int) , 1, FPSENADO );
								
				/*  CUANTO COBRA CADA GUARDAESPALDAS ??  */
				rewind(FPASESOR);
				fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
				while ( ! feof(FPASESOR) ) {
						if ( ASESOR.LEGAJO == LEGAJO && !strcmp(ASESOR.CARGO,"GUARDAESPALDAS") )
									SUELDOS = SUELDOS + ASESOR.SUELDO ;
								
						fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
				}
			}
			if ( SUELDOS > MAXSUELDOS ) {
					MAXSUELDOS = SUELDOS ;
					strcpy ( MAXSENADOR , SENADOR );				
			}	
					
			fread(SENADOR , 20 , 1, FPSENADO );
	}
	
	printf("\n\n\n\n\t\t\t\t SENADOR DE MAS GASTOS EN GUARDAESPALDAS =  %s\n\n\n\n" , 
	MAXSENADOR);
	getchar();
	

	/**********************************************/
	/*                                            */
	/*   SENADORES SIN CHOFERES                   */
	/*                                            */
	/**********************************************/
	printf("\n\n\n\n\t\t\t\t SENADORES  SIN  CHOFERES\n");

	rewind ( FPSENADO ) ;
	rewind ( FPASESOR ) ;
	
	fread(SENADOR , 20 , 1, FPSENADO );
	while ( ! feof(FPSENADO) ) {
			CHOFER = 0 ;			
			fread(&NUMASESORES , sizeof(NUMASESORES) , 1, FPSENADO );
			/*  TENGO LA CANTIDAD DE ASESORES  */
			for ( I = 0 ; I < NUMASESORES ; I++ ) {
				fread(&LEGAJO , sizeof(unsigned int) , 1, FPSENADO );
								
				/*  COLAPINTO ???  */
				rewind(FPASESOR);
				fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
				while ( ! feof(FPASESOR) ) {
						if ( ASESOR.LEGAJO == LEGAJO && !strcmp(ASESOR.CARGO,"CHOFER") )
									CHOFER = 1 ;
								
						fread(&ASESOR , sizeof(ASESOR) , 1, FPASESOR );
				}
			}
			if (  ! CHOFER ) 
					printf("\n\n\t\t\t\t %s" , SENADOR)	;				
								
			fread(SENADOR , 20 , 1, FPSENADO );
	}
	getchar();
	
	printf("\n\n\n  FIN DEL PROGRAMA \n"); 
	
	return 0 ;
}
