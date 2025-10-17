/*  CONSTRUIR LAS FUNCIONES DEPURA Y GANADOR QUE PERTENECEN  */
/*  A LA CLASE LISTA, SEGUN EL ENUNCIADO ADJUNTO             */

//  Se dispone de una lista con nodos que tienen nombre de candidato
//  y cantidad de votos recibidos.
//  Los candidatos aparecen repetidos. 
//  Depurar la lista de forma que cada candidato aparezca solo una vez
//  con la totalidad de sus votos.
//  Determinar el candidato ganador y los votos obtenidos. 




#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;


class CANDI {
	public :
		char NOM[20];
		int VOTOS ;
		CANDI * SIG ;
};

class LISTA {
	private :
		CANDI * INICIO ;
	public :
		LISTA() ;
		void MIRAR() ;
};

LISTA :: LISTA ()
{
	int I ;
	CANDI * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<60 ; I++ ) {
		P = new CANDI ;
		strcpy ( P->NOM , NOM [ rand()%16 ] ) ;
		P->VOTOS = 1 + rand()%100 ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}

void LISTA :: MIRAR ()
{
	CANDI * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "     %-10s%5d" , P->NOM , P->VOTOS) ;
		P = P->SIG ;
	}
	getch();
}

int main()
{
	LISTA L ;
	L.MIRAR() ;
	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	return 0 ;
}
