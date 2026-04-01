			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  NUEVOS OPERADORES NEW Y DELETE */
/*  
    NEW Y DELETE SABEN QUE ESTAN CREANDO Y DESTRUYENDO UN OBJETO 
    Y, POR LO TANTO, ACTUAN EL CONSTRUCTOR Y EL DESTRUCTOR  
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
		
/*
		OPERADOR NEW
		tipo * new tipo ;
		
		EJEMPLO :
					float * P ;
					P = new float ;
					
					int * VEC ;
					VEC = new int[10] ;
					
		OPERADOR DELETE ;
		delete puntero ;
		
		EJEMPLO :
					delete P ;
					
					delete []VEC ;
*/		  
		
		P = new ALFA ;  
		P->MIRAR () ;
		delete P ; 
		  
		printf("\n\n\n   FIN OBJETO DINAMICO \n\n");
				
		printf ("\n\n\n  FIN DEL PROGRAMA \n\n");
		getch();
		return 0 ;
}


