			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  POLIMORFISMO */
/*  SOBRECARGA DE OPERADORES  */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

/*
	FUNCIONES SOBRECARGABLES

void  FUNC( int ) ;
void  FUNC( int , int ) ;
void  FUNC( int , float ) ;
void  FUNC( float , int ) ;
void  FUNC( float ) ;

*/

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

COMPLEJO operator + ( COMPLEJO , COMPLEJO );
COMPLEJO operator + ( int , COMPLEJO );
COMPLEJO operator + ( COMPLEJO , int );

int main( )
{
		int A , B , C ;
		float F , G , H ;
		COMPLEJO X , Y , Z ;
		
		A = 25 ;
		B = 321 ;
		
		F = 321.75 ;
		G = 14.23 ;
		
		X.RE = 12 ;
		X.IM = 5 ; 
		Y.RE = 64 ;
		Y.IM = -15 ; 
		
		C = A + B ;
		H = F + G ;
		Z = X + Y ;
		
		
		
		cout << "\n\n\t\t  " << A << " + " << B << " = " << C ;		

		printf ( "\n\n\t\t %f   +   %f   =  %f" , F , G , H);
		cout << "\n\n\t\t  " ;
		X.VER() ;
		cout << "  +  " ;
		Y.VER() ;	
		cout << "  =  " ;
		Z.VER() ;	
			
			
		Z = A + X ;
		
		cout << "\n\n\t\t  " << A ;
		cout << "  +  " ;
		X.VER() ;	
		cout << "  =  " ;
		Z.VER() ;	
			
		
		
		Z = X + A ;
		
		cout << "\n\n\t\t  " ;
		X.VER() ;	
		cout << "  +  " << A ;
		cout << "  =  " ;
		Z.VER() ;	
			
/*		
		Z = Y + A + X + B ;
		
		X + B  -------->  COMPLEJO       COMPLEJO - ENTERO
		A + (X+B) ----->  COMPLEJO       ENTERO - COMPLEJO
		Y + (A+X+B) --->  COMPLEJO       COMPLEJO - COMPLEJO
		
        &P        *P		
*/		
		
		
		
		
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}



COMPLEJO operator +  ( COMPLEJO X , COMPLEJO Y )
{
		COMPLEJO W ;
		W.RE = X.RE + Y.RE ;
		W.IM = X.IM + Y.IM ;
	
		return W ;
}


COMPLEJO operator + ( int A , COMPLEJO Y )
{
		COMPLEJO W ;
		W.RE = A + Y.RE ;
		W.IM = Y.IM ;
	
		return W ;
}


COMPLEJO operator + ( COMPLEJO X , int A )
{
		COMPLEJO W ;
		W.RE = X.RE + A ;
		W.IM = X.IM  ;
	
		return W ;
}












/*

	DECIMAL = 0.2        BINARIO  =  0.00110011001100110011001  1001100110011001100110011001100110.......    
									 0.00110011001100110011001  TRUNCADO
	0.2 x 2  =  0.4					 0.00110011001100110011010  REDONDEO
	0.4 x 2  =  0.8
	0.8 x 2  =  1.6
	0.6 x 2  =  1.2
	0.2 x 2  =  0.4	
	0.4 x 2  =  0.8
	0.8 x 2  =  1.6
	0.6 x 2  =  1.2
	0.2 x 2  =  0.4	
	...............
	
	
	DECIMAL = 0.125        BINARIO  =  0.001   

	0.125 x 2  =  0.25
	0.250 x 2  =  0.5
	0.500 x 2  =  1.0
	0.000 x 2  =  0.0
	0.000 x 2  =  0.0
	0.000 x 2  =  0.0
	0.000 x 2  =  0.0	
	.................
	
*/




/*     	
		TRANSFERENCIA POR REFERENCIA
		int A ;
		FUNC(A);
		
		void FUNC(X&);
		----------------------------
		TRANSFERENCIA POR VALOR
		int A ;
		FUNC(A);
		
		void FUNC(int B);
		----------------------------
		TRANSFERENCIA POR PUNTERO O POR REFERENCIA SIMULADA
		int A ;
		FUNC(&A);
		
		void FUNC( int * P);
		
*/
