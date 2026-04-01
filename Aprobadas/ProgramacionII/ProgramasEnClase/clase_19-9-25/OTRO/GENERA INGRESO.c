/*  SE DISPONE DE UNA LISTA SIMPLEMENTE ENLAZADA DE NODOS CANDI         */

/*  CADA NODO CANDI REPRESENTA LA CANTIDAD DE VOTOS OBTENIDA POR UN     */
/*  DETERMINADO CANDIDATO EN UNA DE VARIAS LOCALIDADES                  */

/*  CONSTRUIR LA FUNCION LISTA::GANADOR() QUE PERMITA  :                 */
/*  1. DETERMINAR EL CANDIDATO GANADOR Y LA CANTIDAD DE VOTOS OBTENIDOS. */
/*  2. DETERMINAR EN QUE LOCALIDAD OBTUVO MAS VOTOS.                     */
/*  3. DETERMINAR EL PORCENTAJE DE VOTOS OBTENIDOS EN ESA LOCALIDAD      */


#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define NUM 4300


struct INGRESANTE {
		int LEG;
		int R ;
};

struct INGRESO {
		int LEG ;
		char CARRERA[20] ;
};

struct EXAMEN {
		int LEG ;
		int NOTA ;
};

char * GENERACARRERA() ;

int main()
{
		struct INGRESANTE VEC[NUM] , AUX ;
		int I , J , N ;
		FILE * FP ;
		struct INGRESO X ;
		struct EXAMEN  Y ;
	
	
		printf("\n\n\t GENERANDO VECTOR ...");
		N = 123456 ;
		for ( I = 0 ; I < NUM ; I++ ) {
				VEC[I].LEG = N ;
				VEC[I].R   = rand()%10000 ;
				N = N + 1 + rand()%6 ;			
		}
		
		/*  ordenar por R  */
		printf("\n\n\t ORDENAMIENTO 1 DEL VECTOR ...");
		for ( I = 0 ; I < NUM ; I++ )
			for ( J = 0 ; J < NUM-I-1 ; J++)
				if ( VEC[J].R < VEC[J+1].R ) {
						AUX = VEC[J] ;
						VEC[J] = VEC[J+1] ;
						VEC[J+1] = AUX ;				
				}
		
		
		/*  PASAR AL ARCHIVO "INGRESO" CON LAS CARRERAS  */
		printf("\n\n\t CREANDO ARCHIVO INGRESO ...");
		FP = fopen("INGRESO","wb");		
		for ( I = 0 ; I < NUM ; I++ ) {
				X.LEG = VEC[I].LEG ;
				strcpy ( X.CARRERA , GENERACARRERA() );
			
				fwrite ( &X , sizeof(X) , 1 , FP );			
		}
		fclose(FP);
		
		printf("\n\n\t REASIGNANDO PORSICION ALEATORIA ...");
		for ( I = 0 ; I < NUM ; I++ ) 
				VEC[I].R   = rand()%10000 ;
		
		/*  ordenar por R  */
		printf("\n\n\t ORDENAMIENTO 2 DEL VECTOR ...");
		for ( I = 0 ; I < NUM ; I++ )
			for ( J = 0 ; J < NUM-I-1 ; J++)
				if ( VEC[J].R < VEC[J+1].R ) {
						AUX = VEC[J] ;
						VEC[J] = VEC[J+1] ;
						VEC[J+1] = AUX ;				
				}
		
		/*  PASAR AL ARCHIVO "EXAMEN" CON LAS NOTAS  */
		printf("\n\n\t CREANDO ARCHIVO EXAMEN ...");
		FP = fopen("EXAMEN","wb");		
		N = NUM - 1350 ;
		for ( I = 0 ; I < N ; I++ ) {
				Y.LEG = VEC[I].LEG ;
				if ( rand()%100 < 80 )
						Y.NOTA = 6 + rand()%5 ;
				else
						Y.NOTA = 2 + rand()%5 ;
			
				fwrite ( &Y , sizeof(Y) , 1 , FP );			
		}
		fclose(FP);
		
		
		
	printf ("\n\n\nFIN DEL PROGRAMA  " );
	return 0 ;
}


char * GENERACARRERA()
{
		static char NOM[][20] = {"ARQUITECTURA","FISICA","QUIMICA","MATEMATICA",
						  		 "INGENIERIA","MEDICINA","ABOGACIA","PSICOLOGIA",
						  		 "PERIODISMO","SOCIOLOGIA","ANTROPOLOGIA","ODONTOLOGIA",
						  		 "LITERATURA","PEDAGOGIA"};
		return NOM[rand()%14];	
}
