/*  MANEJO DE UNA LISTA SIMPLE  */

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std ;

#define N 10

class NODO {
	public :
		NODO ( char * );
		~NODO() ;
		char NOM[20];
		NODO * SIG ;
};


NODO::NODO( char * S )
{
		strcpy ( NOM , S );
} 

NODO::~NODO()
{
		cout << "\n\n\n MATANDO A ... " << NOM << "\n\n" ;
		getchar();
}


class LISTA {
	private :
		NODO * INICIO ;
		void PONER_P ( NODO *);
	public :
		LISTA();
		~LISTA();
		void AGREGAR_P(char*) ;
		void MIRAR();
};

LISTA::LISTA()
{
		INICIO = NULL ; 
}

LISTA::~LISTA()
{
		cout << "\n\n\n MATANDO A ... TODOS LOS NODOS \n\n" ;
		NODO* actual=INICIO;
		NODO* siguiente;

		while(actual){
			siguiente=actual->SIG; //guardo referencia al siguiente
			delete actual;  // libero el nodo actual
			actual=siguiente;// paso al siguiente

		}
		
		getchar();
}

void LISTA::AGREGAR_P( char * NOM )
{
		NODO * P ;
		P = new NODO ( NOM ) ;
		PONER_P ( P );
}

void LISTA::PONER_P ( NODO * PN )
{
		PN->SIG = INICIO ;
		INICIO = PN ;
}


void LISTA::MIRAR ()
{
		NODO * P ;
	
		printf("\n\n       CONTENIDO DE LA LISTA\n\n");
		
		P = INICIO ;
		while ( P ) {
				printf("\n\t\t %s" , P->NOM);
				P = P->SIG ;
		}	
		printf("\n\n");
		getchar();	
}


int main()
{
	LISTA L ;
	char NOM[20] ;

	for ( int I = 0 ; I < N ; I++ ) {
			printf ("\n\n  NOMBRE  :  ");
			scanf ("%s" , NOM) ;
			L.AGREGAR_P(NOM) ;
	}

	L.MIRAR();

	printf("\n\n\n   FIN DEL PROGRAMA ");
	getch();
	return 0 ;
}


