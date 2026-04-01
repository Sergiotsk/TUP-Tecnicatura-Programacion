			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  COMPROBACION DE ACCESIBILIDAD  */

#include <stdio.h>
#include <conio.h>

class ALFA {
	private :
		int APRI ;
		void CARGAR() {
				APRI = 25 ;
				BPU  = 321 ;
		}
	public :
		int BPU ;
		void PONER() {
				APRI = 25 ;
				BPU  = 321 ;
		}
		void MIRAR();	
};

void ALFA::MIRAR()
{
		printf ( "\n\n\t\t  APRI = %d      BPU = %d" , APRI , BPU );
		getchar();
}


int main( )
{
		ALFA X ;
		
//		X.APRI = 987 ;    ERROR : APRI ES PRIVADA

		X.BPU = 444 ;
		X.MIRAR() ;
		
//		X.CARGAR() ;      ERROR  : METODO CARGAR ES PRIVADO

		X.PONER();
		X.MIRAR() ;
		
		getch();
		return 0 ;
}

/*
    A =       0 1 0 0 0 0 0 1
	
	A = A << 1 ;
	
	A =       1 0 0 0 0 0 1 0
*/
