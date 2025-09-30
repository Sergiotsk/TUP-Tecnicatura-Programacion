			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  CONSTRUCTORES PARAMETRIZADOS  */

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
		ALFA(int);     /*  CONSTRUCTOR  */
		void CARGAR ( char *) ; 
		void MIRAR();	
};


ALFA::ALFA(int A)
{
		MAX = A ;
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
		int Y ;
		cout << "\n\n   CANTIDAD DE REPETICIONES  =  ";
		cin >> Y ;
		
		ALFA X(Y) ;
			
		X.CARGAR ("ALGUIEN") ;
		X.MIRAR () ;
		  
		getch();
		return 0 ;
}


