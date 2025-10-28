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
		// Constructor: crea una lista inicial con 60 nodos aleatorios
		LISTA() ;
		// Muestra la lista (nombre y votos) tal como está enlazada
		void MIRAR() ;
		// Depura la lista: fusiona nodos repetidos por nombre acumulando sus votos
		void DEPURA() ;
		// Determina e informa el candidato con mayor cantidad de votos
		void GANADOR() ;
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
	// Genera 60 nodos con nombre aleatorio de la tabla y votos [1..100]
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
	// Recorre la lista imprimiendo nombre y votos de cada nodo
	printf("CANDIDATO\tVOTOS\n");
	while ( P ) {
		printf ( "     %-10s%5d\n" , P->NOM , P->VOTOS) ;
		P = P->SIG ;
	}
	getch();
}

void LISTA :: DEPURA ()
{
	// Idea: para cada nodo P, buscar más adelante (Q) nodos con el mismo nombre.
	// Si coincide, acumular votos en P y eliminar físicamente el nodo duplicado.
	CANDI * P ;
	CANDI * Q ;
	CANDI * R ;
	CANDI * AUX ;

	P = INICIO ;
	while ( P ) {
		// R sigue a Q para poder quitar el nodo duplicado cuando aparezca
		R = P ;
		Q = P->SIG ;
		while ( Q ) {
			if ( strcmp ( P->NOM , Q->NOM ) == 0 ) {
				// Encontrado duplicado: sumar votos al primer nodo (P)
				P->VOTOS += Q->VOTOS ;
				// Saltear Q en la lista y liberar su memoria
				R->SIG = Q->SIG ;
				AUX = Q ;
				Q = Q->SIG ;
				delete AUX ;
			} else {
				// Avanzar en la búsqueda manteniendo el seguidor R
				R = Q ;
				Q = Q->SIG ;
			}
		}
		P = P->SIG ;
	}
}

void LISTA :: GANADOR ()
{
	// Busca el nodo con mayor cantidad de votos y lo muestra
	// Caso borde: lista vacía, no hay ganador que mostrar
	if ( ! INICIO ) return ;

	// P recorre la lista; G guarda el puntero al candidato ganador parcial
	CANDI * P = INICIO ;
	CANDI * G = INICIO ;

	// Comenzamos comparando desde el segundo nodo
	P = INICIO->SIG ;
	while ( P ) {
		// Si P tiene más votos que el actual ganador G, actualizamos G
		// Nota: en caso de empate, se mantiene el primero encontrado (G)
		if ( P->VOTOS > G->VOTOS ) G = P ;
		P = P->SIG ;
	}

	printf ( "\n\nGANADOR: %-10s%5d" , G->NOM , G->VOTOS ) ;
	getch();
}

int main()
{
	LISTA L ;
	L.MIRAR() ;
	L.DEPURA() ;
	L.MIRAR() ;
	L.GANADOR() ;
	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	return 0 ;
}
