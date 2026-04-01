			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  NUEVOS OPERADORES NEW Y DELETE */
/*  
    MANEJO DE VECTOR DE OBJETOS 
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	private :
		static int X ;
		int ID ;
	public :
		ALFA();     		/*  CONSTRUCTOR  */
		~ALFA() ;			/*  DESTRUCTOR  */
		void MIRAR();	
};

int ALFA::X ;

ALFA::ALFA()
{
		printf("\n\n\n    BRAHMA ES EL CONSTRUCTOR \n\n") ;
		ID = X++ ;
		getch();
}

ALFA::~ALFA()
{
		printf("\n\n\n %d    SHIVA ES EL DESTRUCTOR \n\n", ID ) ;
		getch();
}



void ALFA::MIRAR()
{
		cout << "\n\t\t" << ID <<"   VISHNU ES EL PROTECTOR \n\n" ;
		getchar();
}

int main( )
{
		ALFA X ;
		ALFA * P ;
				
		X.MIRAR () ;
		  
		cout  << "\n\n\n\n";
		getch();
		 
		printf("\n\n\n   OBJETO DINAMICO \n\n");
		
		ALFA * VEC ;
		VEC = new ALFA[10] ;
//		VEC[5].MIRAR();
		(*(VEC+5)).MIRAR();
       
		printf("\n\n\t  AHORA VEMOS EL VECTOR"); getchar();       
		for ( int I = 0 ; I < 10 ; I++ ) {
				printf("\t\tI  =  %d " , I );
				(VEC+I)->MIRAR();
		}

		delete []VEC ;
		  
		printf("\n\n\n   FIN OBJETO DINAMICO \n\n");
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}


