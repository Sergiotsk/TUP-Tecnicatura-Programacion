/*  MANEJO DE UNA LISTA SIMPLE  */
/*  CARGA AUTOMATICA  */

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
//		getchar();
}


class LISTA {
	private :
		NODO * INICIO ;
		void PONER_P ( NODO *);
		void PONER_F ( NODO *);
		NODO * MINIMO() ;
		NODO * MAXIMO() ;
		NODO * BUSCAR(char *) ;
		void ELIMINAR( NODO *);
		void SECUESTRAR( NODO *);
	public :
		LISTA();
		~LISTA();
		void AGREGAR_P(char*) ;
		void AGREGAR_F(char*) ;
		void MIRAR();
		void MENOR();
		void MAYOR();
		void MATAR( char *);
		void SACAR( char *);
		void ORDENAR();
		void MIRARCP();
};

LISTA::LISTA()
{
		INICIO = NULL ; 
}

LISTA::~LISTA()
{
		NODO * P , * G;
		cout << "\n\n\n MATANDO A ... TODOS LOS NODOS \n\n" ;
		P = INICIO ;
		
		while ( P ) {
				G = P->SIG ;
				delete P ;
				P = G ;
		}		
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


void LISTA::AGREGAR_F( char * NOM )
{
		NODO * P ;
		P = new NODO ( NOM ) ;
		PONER_F ( P );
}

void LISTA::PONER_F ( NODO * PN )
{
		NODO * P ;
		P = INICIO ;
		
		PN->SIG = NULL ;  /*  ESTE VA A SER EL NUEVO ULTIMO NODO  */
		
		if ( INICIO ) {
				/*  LISTA NO VACIA  */
				while ( P->SIG )
						P = P->SIG ;    /*  LLEVO A P HASTA EL ULTIMO NODO */
				P->SIG = PN ;
				return ;			
		}
		/*  LISTA VACIA  */
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

void LISTA::MIRARCP ()
{
		NODO * P ;
	
		printf("\n\n       CONTENIDO DE LA LISTA\n\n");
		
		P = INICIO ;
		while ( P ) {
				printf("\n\t\t %10X %-15s %10X" , P , P->NOM , P->SIG );
				P = P->SIG ;
		}	
		printf("\n\n");
		getchar();	
}

void LISTA::MENOR()
{
		if ( INICIO )
			printf("\n\n  EL MENOR ES %s" , MINIMO()->NOM );
		getchar();
	
}

NODO * LISTA::MINIMO()
{
		NODO * P , * PMIN ;
	
		PMIN = P = INICIO ;
		while ( P ) {
				if ( strcmp ( P->NOM , PMIN->NOM) < 0 )
						PMIN = P ;			
				P = P->SIG ;
		}
		return PMIN ;	
}


void LISTA::MAYOR()
{
		if ( INICIO )
			printf("\n\n  EL MAYOR ES %s" , MAXIMO()->NOM );
		getchar();
	
}

NODO * LISTA::MAXIMO()
{
		NODO * P , * PMAX ;
	
		PMAX = P = INICIO ;
		while ( P ) {
				if ( strcmp ( P->NOM , PMAX->NOM) > 0 )
						PMAX = P ;			
				P = P->SIG ;
		}
		return PMAX ;	
}

NODO * LISTA::BUSCAR( char * S )
{
		NODO * P ;
	
		P = INICIO ;
		while ( P ) {
				if ( ! strcmp ( P->NOM , S ) ) {
						return P ;
				}
				P = P->SIG ;
		}
		return NULL ;	
}

void LISTA::MATAR( char * S )
{
		NODO * P ;
		P = BUSCAR(S) ;
	
		if ( P )
				ELIMINAR(P) ;
}


void LISTA::ELIMINAR( NODO * PELIM)
{
		if ( PELIM == INICIO ) {
				/*  ELIMINAR PRIMER NODO  */
				INICIO = PELIM->SIG ;
				delete PELIM ;
				return ;			
		}
		/*  ELIMINAR OTRO NODO  */
		NODO * P ;
		P = INICIO ;
		while ( P->SIG != PELIM && P )
				P = P->SIG ;
		if ( P ) {
//				P->SIG = PELIM->SIG ;
				P->SIG = P->SIG->SIG ;
				delete PELIM ;
		}
}


void LISTA::SACAR( char * S )
{
		NODO * P ;
		P = BUSCAR(S) ;
	
		if ( P )
				SECUESTRAR(P) ;
}


void LISTA::SECUESTRAR( NODO * PELIM)
{
		if ( PELIM == INICIO ) {
				/*  ELIMINAR PRIMER NODO  */
				INICIO = PELIM->SIG ;
				return ;			
		}
		/*  ELIMINAR OTRO NODO  */
		NODO * P ;
		P = INICIO ;
		while ( P->SIG != PELIM && P )
				P = P->SIG ;
		if ( P ) 
				P->SIG = P->SIG->SIG ;
}

void LISTA::ORDENAR()
{
		NODO * P ;
		NODO * AUXINI ;
		
		AUXINI = NULL ;		
		
		while ( INICIO ) {
				P = MAXIMO();
				SECUESTRAR(P);
				P->SIG = AUXINI ;
				AUXINI = P ;
		}
		INICIO = AUXINI ;
}



/*  prototipo  */
char * GENERANOM() ;

int main()
{
	LISTA L ;
	char NOM[20] ;
	
	strcpy (NOM , GENERANOM() ) ;	
	while ( strcmp (NOM , "FIN") ) {
			L.AGREGAR_F(NOM) ;
			strcpy (NOM , GENERANOM() ) ;
	}

	L.MIRARCP();

//	L.MENOR();
//	L.MAYOR();
	
//	printf("\n\n\t\t  NOMBRE A ELIMINAR  :  ");
//	gets(NOM);
	
//	L.MATAR(NOM) ;

	L.ORDENAR();
	
	L.MIRARCP();
	
	printf("\n\n\n   FIN DEL PROGRAMA ");
	getch();
	return 0 ;
}



char * GENERANOM ()
{
		static char NOM[][20] = {"CAROLINA","ROBERTO","PEPE","LOLA","FIN",
						  "ANASTASIA","VERONICA","CARLOS","ANSELMO",
						  "LUIS","ANA","LAURA","EDUARDO",
						  "PANCRASIO","SAUL","RODOLFO","EUSTAQUIO",
						  "MANUEL","RIGOBERTO","MARIA","CLARA","FIN" };
		static int I = 0 ;
		return NOM[I++];
}






