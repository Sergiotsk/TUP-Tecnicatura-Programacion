			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  POLIMORFISMO */
/*  SOBRECARGA DE FUNCIONES  */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class COMPLEJO {
	public :
		int RE ;
		int IM ;
		void VER();	
};

void COMPLEJO::VER()
{
		cout << RE ;
		if ( IM < 0 ) cout << " - " << -IM << " i " ;
		else          cout << " + " << IM << " i " ;
}

int CUADRADO ( int );
float CUADRADO ( float );
COMPLEJO CUADRADO ( COMPLEJO );

int main( )
{
		int A , B ;
		float F , G ;
		COMPLEJO X , Y ;
		
		A = 25 ;
		F = 321.75 ;
		X.RE = 12 ;
		X.IM = 5 ; 
		
		B = CUADRADO (A) ;
		G = CUADRADO (F) ;
		Y = CUADRADO (X) ;
				
		cout << "\n\n\t\t EL CUADRADO DE " << A << " ES " << B ;		
//		cout << "\n\n\t\t EL CUADRADO DE " << F << " ES " << G ;
		printf ( "\n\n\t\t EL CUADRADO DE %f ES %f" , F , G );
		cout << "\n\n\t\t EL CUADRADO DE " ;
		X.VER() ;
		cout << "  ES  " ;
		Y.VER() ;	
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}


int CUADRADO ( int Z )
{
		return Z * Z ;
}


float CUADRADO ( float Z )
{
		return Z * Z ;
}


COMPLEJO CUADRADO ( COMPLEJO Z )
{
		COMPLEJO W ;
		W.RE = Z.RE * Z.RE - Z.IM * Z.IM ;
		W.IM = 2 * Z.RE * Z.IM ;
	
		return W ;
}
