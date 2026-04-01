			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  CONSTRUCTOR  */

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
		ALFA();     /*  CONSTRUCTOR  */
		void CARGAR ( char *) ; 
		void MIRAR();	
};


ALFA::ALFA()
{
		printf("\n   CONSTRUCTOR EN ACCION\n") ; getchar();
		MAX = 5 ;
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

int main( )
{
		ALFA X ;
							
		X.CARGAR ((char *)"ALGUIEN") ;
		X.MIRAR () ;
		  
		getch();
		return 0 ;
}


