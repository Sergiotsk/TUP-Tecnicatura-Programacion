			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  SOBRECARGA DE CONSTRUCTORES */

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
		ALFA(int);     /*  CONSTRUCTOR PARAMETRIZADO CON DEFAULT (parece pero no es ) */
		ALFA() ;       //  OTRO CONSTRUCTOR ?????   !!!!!
		void CARGAR ( char *) ; 
		void MIRAR();	
};


ALFA::ALFA(int A)
{
		MAX = A ;
}

ALFA::ALFA()
{
		MAX = 3 ;
		cout << "\n\n  SEGUNDO CONSTRUCTOR \n\n";
		getchar();
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
		ALFA X(25) ;
			
		X.CARGAR ((char *)"ALGUIEN") ;
		X.MIRAR () ;
		  
		cout  << "\n\n\n\n";
		getch();
		 
		ALFA Y ;
			
		Y.CARGAR ((char *)"CUALQUIERA") ;
		Y.MIRAR() ;  
		  
		  
		getch();
		return 0 ;
}


