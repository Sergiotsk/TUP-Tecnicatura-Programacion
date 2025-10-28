/*   GUIRNALDA   */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class ALUMNO {
	public :
			ALUMNO(char *) ;
			~ALUMNO() ;
			char NOM[20] ;
			ALUMNO * SIG ;	
};


ALUMNO::ALUMNO(char * S)
{
		strcpy ( NOM , S );
		SIG = NULL ;
}

ALUMNO::~ALUMNO()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		getchar();
}




class PARTIDO {
	public :
			char NOM[20] ;
			ALUMNO * PALUM ;
			PARTIDO * SIG ;	
			PARTIDO(char * , ALUMNO *) ;
			~PARTIDO() ;
};


PARTIDO::PARTIDO(char * S , ALUMNO * PRESI)
{
		strcpy ( NOM , S );
		PALUM = PRESI ;
}

PARTIDO::~PARTIDO()
{
		cout << "\n\n   MATANDO A ... TODOS LOS ALUMNOS" ;
		cout << "\n\n   PARA USTEDES" ;
		getchar();
}



class GUIRNALDA {
	private :
			PARTIDO * INICIO ;
			PARTIDO * BUSCAR(char *);
	public :
			GUIRNALDA() ;
			~GUIRNALDA() ;
			void ARREGLATE(char *);
			void MIRAR() ;
};


GUIRNALDA::GUIRNALDA()
{
		INICIO = NULL ;
}

GUIRNALDA::~GUIRNALDA()
{
		cout << "\n\n   QUE SE VAYAN TODOS !!!! " ;
		cout << "\n\n   DESTRUYENDO A TODOS LOS PARTIDOS " ;
		cout << "\n\n   ADIVINEN ....  " ;
		getchar();
}

void GUIRNALDA::ARREGLATE(char * S)
{
		char BUF[20] ;
		ALUMNO * PAL , * P ;
		PARTIDO * PPAR ;
		
		PAL = new ALUMNO(S) ;
		
		cout << "\n\n\t" << S << ", ... VOTATE ALGO ...    ";
		cin >> BUF ;
	
		PPAR = BUSCAR(BUF) ;
	
		if ( PPAR ) {
				/*  PARTIDO EXISTENTE  */
				P = PPAR->PALUM ;		/*  APUNTO AL PRESIDENTE  */
				while ( P->SIG )
						P = P->SIG ; 	/*  AVANZO AL ULTIMO ALUMNO  */
				P->SIG = PAL ;		
				return ;
		}
		/*  PARTIDO NUEVO   */
		PPAR = new PARTIDO(BUF,PAL) ;
		PPAR->SIG = INICIO ;
		INICIO = PPAR ;	
}

PARTIDO * GUIRNALDA::BUSCAR(char * S)
{
		PARTIDO * P ;
		P = INICIO ;
		
		while (P) {
				if ( ! strcmp ( P->NOM , S ) )
						return P ;			
				P = P->SIG ;
		}
		return NULL ;
}


void GUIRNALDA::MIRAR()
{
		PARTIDO * PPAR ;
		ALUMNO * PAL ;
		
		fflush(stdin);
		system("cls");
		cout << "\n\n\n\n\t\t    CONTENIDO DE LA GUIRNALDA \n\n" ;
		PPAR = INICIO ;
		while ( PPAR ) {
				cout << "\n\n\n\n\t\t    PARTIDO   :   " << PPAR->NOM ;
				cout << "\n\n" ;
			
				PAL = PPAR->PALUM ;
				while ( PAL ) {
						cout << "\n\t\t    " << PAL->NOM ;				
						PAL = PAL->SIG ;
				}
				getchar();
						
				PPAR = PPAR->SIG ;
		}
}











char * GENERANOM();

int main( )
{  
		GUIRNALDA G ;		
		char BUF[20];
		
		cout << "\n\n    NOMBRE DEL VOTANTE   :   " ;
		cin >> BUF ;
		while ( strcmp(BUF,"FIN") ) {
				G.ARREGLATE(BUF) ; 
			
				cout << "\n\n    NOMBRE DEL VOTANTE   :   " ;
				cin >> BUF ;
		}
		
		G.MIRAR() ;
		
		printf("\n\n");
		return 0 ;
}


char * GENERANOM()
{
	static int I = 0 ;
	static char NOM[][20] = {"DARIO","CAROLINA","PEPE","LOLA",
						     "PACO","LUIS","MARIA","ANSELMO",
						  	 "ANA","LAURA","PEDRO","ANIBAL",
						     "PABLO","ROMUALDO","ALICIA","MARTA",
						     "MARTIN","TOBIAS","SAUL","LORENA","FIN"};
	static int NUM = 30 + rand()%15 ;
	
	if ( I++ < NUM )
			return NOM[rand()%20] ;
	return NOM[20] ;
}




