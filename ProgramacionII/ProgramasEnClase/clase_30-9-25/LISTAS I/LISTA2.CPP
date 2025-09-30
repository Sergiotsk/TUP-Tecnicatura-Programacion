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
		strcpy ( NOM , S );/*Constructor*/
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
	NODO * pActual = INICIO;
	while ( pActual ) {
		NODO * pSiguiente = pActual->SIG;
		delete pActual;
		pActual = pSiguiente;
	}
	INICIO = NULL;
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
		int NOMC = 0;

	
		printf("\n\n       CONTENIDO DE LA LISTA\n\n");
		
		P = INICIO ;
		while ( P ) {
			
				if (P->NOM[0] == 'C'){
					NOMC++;
				}
				printf("\n\t\t %s" , P->NOM);
				P = P->SIG ;
			
		}	
		printf("\n\n");
		printf("\nLa lista contien %d nombres que comienzan con C\n",NOMC);
		getchar();	
}

/*  prototipo  */
char * GENERANOM() ;

int main()
{
	LISTA L ;
	char NOM[20] ;
	
	strcpy (NOM , GENERANOM() ) ;	
	while ( strcmp (NOM , "FIN") ) {
			L.AGREGAR_P(NOM) ;
			strcpy (NOM , GENERANOM() ) ;
	}


	L.MIRAR(); //
	

	printf("\n\n\n   FIN DEL PROGRAMA ");
	getch();
	return 0 ;
}



char * GENERANOM ()
{
		static char NOM[][20] = {"CAROLINA","ROBERTO","PEPE","LOLA",     //el char debe ser static para que cuando invoque la funcion no me de puntero colgante(el puntero a char, no ve a NOM
						  "ANASTASIA","VERONICA","CARLOS","ANSELMO",
						  "LUIS","ANA","LAURA","EDUARDO",
						  "PANCRASIO","SAUL","RODOLFO","EUSTAQUIO",
						  "MANUEL","RIGOBERTO","MARIA","CLARA","FIN" };
		static int I = 0 ;//static para que no se reinicie, pone a 	I en
		                  // las variables globales,pero perteneciente a la funcion en que se declara
		return NOM[I++];
}






/*En base a la lista2, se pide indicar cuantos nombres comienzan con C*/
