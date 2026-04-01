

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
	char SENADOR[][20] = {  "GUTIERREZ" , "GARCIA" , "ABERASTAIN" , "GOMEZ" , 
							"PIETROFANEZ" , "SATURNINO" , "FERNANDEZ" , "LOPEZ" ,
							"CARISTIMO" , "LOSADA" , "LOPREIATO" , "GALINDEZ" ,
							"VERDUGUEZ" , "CORNEJO" , "VASQUEZ" , "BORNINO" ,
							"GONZALEZ" , "AMENDOLA" , "ORDOÑEZ" , "LOPEZ" 	
	};
	char TAREA[][20] = { "ASESOR" , "GUARDAESPALDAS" , "CHOFER" };
	FILE * FPSENADO ;
	FILE * FPASESOR ;
	int I , J , K , NUMASESORES ;
	struct LEG VEC[2000] , AUXLEG ;
	int ORDEN[2000] , AUXORDEN ;
	
	srand(25);
	
	FPSENADO = fopen ("SENADO.DAT" , "wb") ;
	FPASESOR = fopen ("ASESOR.DAT" , "wb") ;
	
	/*  CARGA DEL VECTOR DE CARGOS  */
	for ( I = 0 ; I < 2000 ; I++ ) {
			VEC[I].LEGAJO = 1000000 + (rand()*rand())%8000000 ;
			K = rand() % 100 ;
			J = 0 ;
			if ( K > 50 ) J = 1 ;
			if ( K > 90 ) J = 2 ;
			strcpy ( VEC[I].CARGO , TAREA[J] ) ;
			VEC[I].SUELDO = 300000 + (rand()*rand())%500000 ;
			
			ORDEN[I] = rand() % 100000 ;
	}
	
		
	for ( K = I = 0 ; I < NUMSEN ; I++ ) {
			fwrite(SENADOR[I] , 20 , 1, FPSENADO );
			NUMASESORES = 2 + rand()%55 ;
			fwrite(&NUMASESORES , sizeof(NUMASESORES) , 1, FPSENADO );
			for ( J = 0 ; J < NUMASESORES ; J++ ) {
					fwrite(&VEC[K].LEGAJO , sizeof(unsigned int) , 1, FPSENADO );
					K++ ;
			}
	}
	
	
	//    ORDENAR
	for ( I = 0 ; I < 2000-1 ; I++ )
			for ( J = 0 ; J < 2000-I-1 ; J++ ) 
					if ( ORDEN[J] > ORDEN[J+1] ) {
							AUXORDEN   = ORDEN[J];
							ORDEN[J]   = ORDEN[J+1];
							ORDEN[J+1] = AUXORDEN ;
						
						
							AUXLEG   = VEC[J] ;
						    VEC[J]   = VEC[J+1] ;
							VEC[J+1] = AUXLEG ;
					}
	
	
	for ( J = 0 ; J < 2000 ; J++ ) 
			fwrite(&VEC[J] , sizeof(struct LEG) , 1, FPASESOR );
	
	fclose ( FPSENADO ) ;
	fclose ( FPASESOR ) ;
	
	
	printf("\n\n\n  FIN DEL PROGRAMA DE GENERACION\n"); 
	
	return 0 ;
}
