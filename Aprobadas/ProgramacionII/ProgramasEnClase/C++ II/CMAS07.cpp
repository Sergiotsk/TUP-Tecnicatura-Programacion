			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  OBJETOS DINAMICOS */
/*  
    MALLOC Y FREE NO SE DAN CUENTA QUE MANEJAN UN OBJETO 
    Y NO HAY CONSTRUCTOR NI DESTRUCTOR  
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std ;

class ALFA {
	public :
		ALFA();     		/*  CONSTRUCTOR  */
		~ALFA() ;			/*  DESTRUCTOR  */
		void MIRAR();	
};


ALFA::ALFA()
{
		printf("\n\n\n    BRAHMA ES EL CONSTRUCTOR \n\n") ;
		getch();
}

ALFA::~ALFA()
{
		printf("\n\n\n    SHIVA ES EL DESTRUCTOR \n\n") ;
		getch();
}



void ALFA::MIRAR()
{
		cout << "\n\n\t\t VISHNU ES EL PROTECTOR \n\n" ;
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
		  
		P = (ALFA *) malloc (sizeof(ALFA));  
		P->MIRAR () ;
		free (P) ; 
		  
		printf("\n\n\n   FIN OBJETO DINAMICO \n\n");
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}


