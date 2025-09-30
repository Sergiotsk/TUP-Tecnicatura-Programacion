			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  NUEVOS FLUJOS DE ENTRDA Y SALIDA  */

#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std ;

int main( )
{
		int A ;
		cout << "\n\n    INGRESE UN VALOR ENTERO = " ;
		cin >>  A ;
		cout << "\n\n    VALOR DE A = " << A ;

		
		float F ;
		cout << "\n\n\n\n\n    INGRESE UN VALOR FLOTANTE = " ;
		cin >>  F ;
		cout << "\n\n    VALOR DE F = " << F ;


		char C ;
		cout << "\n\n\n\n\n    INGRESE UN CARACTER = " ;
		cin >>  C ;
		cout << "\n\n    VALOR DE C = " << C ;


		char STR[20] ;
		cout << "\n\n\n\n\n    INGRESE UN NOMBRE = " ;
		cin >>  STR ;
		cout << "\n\n    NOMBRE INGRESADO = " << STR ;

		getch();
		return 0 ;
}


