/*  SE DISPONE DE UNA LISTA SIMPLEMENTE ENLAZADA DE NODOS CANDI         */

/*  CADA NODO CANDI REPRESENTA LA CANTIDAD DE VOTOS OBTENIDA POR UN     */
/*  DETERMINADO CANDIDATO EN UNA DE VARIAS LOCALIDADES(SIN REPETICION)  */

/*  CONSTRUIR LA FUNCION LISTA::GANADOR() QUE PERMITA  :                 */
/*  1. DETERMINAR EL CANDIDATO GANADOR Y LA CANTIDAD DE VOTOS OBTENIDOS. */
/*  2. DETERMINAR EN QUE LOCALIDAD OBTUVO MAS VOTOS.                     */
/*  3. DETERMINAR EL PORCENTAJE DE VOTOS OBTENIDOS EN ESA LOCALIDAD      */


#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define NUM 200

using namespace std ; 

class CANDI {
	public :
		char NOM[20];
		int VOTOS ;
		char LOCALIDAD[20];
		CANDI * SIG ;
		CANDI(char*,char*);
		~CANDI() ;
};


CANDI::CANDI(char * NOMBRE , char * LOC)
{
	strcpy(NOM,NOMBRE);
	strcpy(LOCALIDAD,LOC);
	VOTOS = 1000 + rand()%5000 ;
}

CANDI::~CANDI()
{
	printf("\n\n   MATANDO A ... %s " , NOM );
	getch() ;
}


class LISTA {
	private :
		CANDI * INICIO ;
		CANDI * BUSCAR (char * , char *);
	public :
		LISTA() ;
		void MIRAR() ;
};

LISTA :: LISTA ()
{
	int I ;
	CANDI * P ;
	char NOMBRE[20];
	char LOCALIDAD[20];
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO",
			   "AMADO","BARTOLO","CLEMENTE","FACUNDO",
			   "TATIANA","DANIELA","SILVINA","TAMARA" } ;
	char LOC[][20] = { "HAEDO" , "CASTELAR" , "MORON" , "MORENO" ,
			   "LINIERS" , "RAMOS MEJIA" , "ITUZAINGO" , "FLORES" ,
			   "CIUDADELA" , "CABALLITO","HURLINGHAM","SAN JUSTO",
			   "VILLA TESSEI","VILLA SARMIENTO","MERLO","RAFAEL CASTILLO" } ;		   
	INICIO = NULL ;
	for ( I=0 ; I<NUM ; I++ ) {
		strcpy(LOCALIDAD , LOC[rand()%16]);
		strcpy(NOMBRE , NOM[rand()%24]);
		if ( ! BUSCAR(NOMBRE,LOCALIDAD) ) {
				P = new CANDI(NOMBRE,LOCALIDAD) ;
				P->SIG = INICIO ;
				INICIO = P ;
		}
	}
	
}


CANDI * LISTA::BUSCAR ( char * NOM , char * LOC )
{
	CANDI * P ;
	P = INICIO ;
	while (P) {
			if ( !strcmp(P->NOM , NOM) && !strcmp(P->LOCALIDAD , LOC)   )
					return P ;		
			P = P->SIG ;
	}
	return NULL ;	
}


void LISTA :: MIRAR ()
{
	CANDI * P ;
	int C = 0 ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "\n\n\t\t  %4d \t %-20s %-20s %d" , ++C , P->NOM , P->LOCALIDAD , P->VOTOS ) ;
		getch();
		P = P->SIG ;
	}
	getch();
}




int main()
{
	srand(25);
	
	LISTA L ;
	
	L.MIRAR() ;

	
	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	return 0 ;
}
