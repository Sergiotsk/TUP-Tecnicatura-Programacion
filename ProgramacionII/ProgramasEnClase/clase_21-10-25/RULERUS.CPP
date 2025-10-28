/*  LA RULETA RUSA GENERA UNA LISTA CERRADA DE 16 COMPETIDORES */
/*  LA FUNCION DISPARAR() CUYO PROTOTIPO SE ADJUNTA, RECIBE UN ENTERO   */
/*  Y DEBE HACER AVANZAR EL PUNTERO AL INICIO TANTOS NODO COMO INDICA  */
/*  EL ENTERO RECIBIDO.  */
/*  CON POSTERIORIDAD DEBE ELIMINAR ESE NODO DE LA LISTA. SU DESTRUCTOR */
/*  SE ENCARGARA DE INDICAR QUIEN ES.  */
/*  AL EJECUTAR LA FUNCION 15 VECES SOLO QUEDARA EL GANADOR  */
/*  SE PIDE CONSTRUIR LA FUNCION DISPARAR() */

/* MODIFIQUE LA CLASE A FIN DE PERMITIR ACTUAR A DISPARAR()  */

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define NUM 16

class CANDI {
	public :
		char NOM[20];
		CANDI * SIG ;
		~CANDI() ;
};

CANDI::~CANDI()
{
	printf("\n\n   MATANDO A ... %s " , NOM );
	getch() ;
}


class RUSA {
	private :
		CANDI * INICIO ;
	public :
		RUSA() ;
		void MIRAR() ;
};

RUSA :: RUSA ()
{
	int I ;
	CANDI * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<NUM ; I++ ) {
		P = new CANDI ;
		strcpy ( P->NOM , NOM [ I ] ) ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
	/* CERRANDO LA RULETA */
	P = INICIO ;
	while ( P->SIG ) P = P->SIG ;
	P->SIG = INICIO ;
}

void RUSA :: MIRAR ()
{
	int I ;
	cout<< "\n\n\n" ;
	for ( I = 0 ; I < NUM ; I++ ) {
		printf ( "\n     %-10s" , INICIO->NOM ) ;
		INICIO = INICIO->SIG ;
	}
	getch();
}


void DISPARAR(RUSA,int) ;

int main()
{
	int I ;
	//clrscr();
	RUSA R ;
	R.MIRAR() ;

	for ( I = 0 ; I < NUM-1 ; I++ ) {

            DISPARAR(R , rand() % 100);

        	R.MIRAR() ;
	}

	std::cout << "\n\n\nFIN DEL PROGRAMA  " ;
	getch();
}
