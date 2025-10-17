			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  DE CONSTRUCTORES Y DESTRUCTORES */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std ;

class ALFA {
	private :
		int MAX ;
		char NOMBRE[20];
	public :
		ALFA(int = 5);     /*  CONSTRUCTOR  */
		~ALFA() ;			/*  DESTRUCTOR  */
		void CARGAR ( char *) ; 
		void MIRAR();	
};


ALFA::ALFA(int A)
{
		MAX = A ;
		printf("\n\n\n    CONSTRUCTOR EN ACCION \n\n") ;
		getch();
}

ALFA::~ALFA()
{
		printf("\n\n\n    DESTRUCTOR EN ACCION DE %s\n\n" , NOMBRE) ;
		getch();
}

void ALFA::CARGAR ( char * S )
{
		strcpy ( NOMBRE , S ) ;
}


void ALFA::MIRAR()
{
		int I ;
		for ( I = 0 ; I < MAX ; I++ )
				cout << "\n\n\t\t" << NOMBRE ;
		getchar();
}

void FUNCION();

int main( )
{
		ALFA X(25) ;
			
		X.CARGAR ("ALGUIEN") ;
		X.MIRAR () ;
		  
		cout  << "\n\n\n\n";
		getch();
		 
		 
		FUNCION(); 
		 
		 
		ALFA Y ;
			
		Y.CARGAR ((char *)"CUALQUIERA") ;
		Y.MIRAR () ;  
		  
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}

void FUNCION()
{
		cout << "\n\n\t\t  ENTRAMOS EN LA FUNCION\n\n" ;
		getch();
		
		ALFA W ;
		
		W.CARGAR("CACHIRULA");
		cout << "\n\n\t\t  DENTRO DE LA FUNCION\n\n" ;
		getch();
	
		W.MIRAR();
		
		cout << "\n\n\t\t  ESTAMOS POR SALIR DE LA FUNCION\n\n" ;
		getch();
}
