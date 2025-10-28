/*  SE DISPONE DE UNA LISTA SIMPLEMENTE ENLAZADA DE NODOS CANDI         */

/*  CADA NODO CANDI REPRESENTA LA CANTIDAD DE VOTOS OBTENIDA POR UN     */
/*  DETERMINADO CANDIDATO EN UNA DE VARIAS MESAS PERTENECIENTES A       */
/*  DIVERSAS LOCALIDADES QUE APARECERAN REPETIDAS PARA EL CANDIDATO,N)  */
/*  SEGUN LA CANTIDAD DE MESAS DONDE HAYA CONSEGUIDO VOTOS              */

/*  CONSTRUIR LA FUNCION LISTA::GANADOR() QUE PERMITA  :                 */
/*  1. DETERMINAR EL CANDIDATO GANADOR Y LA CANTIDAD DE VOTOS OBTENIDOS. */
/*  2. DETERMINAR EN QUE LOCALIDAD OBTUVO MAS VOTOS.                     */
/*  3. DETERMINAR EL PORCENTAJE DE VOTOS OBTENIDOS EN ESA LOCALIDAD      */


#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define NUM 2000

using namespace std ; 

class CANDI {
	public :
		char NOM[20];
		int VOTOS ;
		char LOCALIDAD[20];
		CANDI * SIG ;
		CANDI(char*,char*);
		~CANDI() ;
};


CANDI::CANDI(char * NOMBRE , char * LOC)
{
	strcpy(NOM,NOMBRE);
	strcpy(LOCALIDAD,LOC);
	VOTOS = 1000 + rand()%5000 ;
}

CANDI::~CANDI()
{
	printf("\n\n   MATANDO A ... %s " , NOM );
	getch() ;
}


class LISTA {
	private :
		CANDI * INICIO ;
		char ganador[20];
		int maxVotos;
		char localidadGanadora[20];
		int votosLocalidadGanadora;
	public :
		LISTA() ;
		void MIRAR() ;
		void GANADOR() ;
		void MAXLOCALIDAD() ;
		void PORCENTAJE() ;
};

LISTA :: LISTA ()
{
	int I ;
	CANDI * P ;
	char NOMBRE[20];
	char LOCALIDAD[20];
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO",
			   "AMADO","BARTOLO","CLEMENTE","FACUNDO",
			   "TATIANA","DANIELA","SILVINA","TAMARA" } ;
	char LOC[][20] = { "HAEDO" , "CASTELAR" , "MORON" , "MORENO" ,
			   "LINIERS" , "RAMOS MEJIA" , "ITUZAINGO" , "FLORES" ,
			   "CIUDADELA" , "CABALLITO","HURLINGHAM","SAN JUSTO",
			   "VILLA TESSEI","VILLA SARMIENTO","MERLO","RAFAEL CASTILLO" } ;		   
	INICIO = NULL ;
	for ( I=0 ; I<NUM ; I++ ) {
		strcpy(LOCALIDAD , LOC[rand()%16]);
		strcpy(NOMBRE , NOM[rand()%24]);
		
		P = new CANDI(NOMBRE,LOCALIDAD) ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
	
}

void LISTA :: MIRAR ()
{
	CANDI * P ;
	int C = 0 ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "\n\n\t\t  %4d \t %-20s %-20s %d" , ++C , P->NOM , P->LOCALIDAD , P->VOTOS ) ;
		//getch();
		P = P->SIG ;
	}
	//getch();
}

//PUNTO 1 BUSQUEDA DE GANADOR

void LISTA::GANADOR() {
    CANDI *P = INICIO;
   
    while (P) {
        int total = 0;
        CANDI *Q = INICIO;
        while (Q) {
            if (strcmp(P->NOM, Q->NOM) == 0)
                total += Q->VOTOS;
            Q = Q->SIG;
        }
        if (total > maxVotos) {
            maxVotos = total;
            strcpy(ganador, P->NOM);
        }
        P = P->SIG;
    }

    printf("\n\nGANADOR: %-10s con %5d votos", ganador, maxVotos);
}

//PUNTO 2 BUSQUEDA DE LOCALIDAD CON MAS VOTOS DEL GANADOR

void LISTA::MAXLOCALIDAD() {
    CANDI *P = INICIO;
    int maxLocal = 0;    

    while (P) {
        if (strcmp(P->NOM, ganador) == 0 && P->VOTOS > maxLocal) {
            maxLocal = P->VOTOS;
            strcpy(localidadGanadora, P->LOCALIDAD);
        }
        P = P->SIG;
    }

    printf("\n\nEl ganador %-10s obtuvo su mayor cantidad de votos en %-10s con %d votos",ganador, localidadGanadora, maxLocal);


}

//PUNTO 3 BUSQUEDA DE PORCENTAJE DE VOTOS DEL GANADOR EN LA LOCALIDAD

void LISTA::PORCENTAJE() {
 CANDI *P = INICIO;
 float total = 0;
 while (P) {
     if (strcmp(P->NOM, ganador) == 0 && strcmp(P->LOCALIDAD, localidadGanadora) == 0) {
         total += P->VOTOS;
     }
     P = P->SIG;
 }

 //printf("\n\nEl porcentaje de votos del ganador %-10s en la localidad %-10s es %2f", ganador, localidadGanadora, (total * 100) / maxVotos);

cout.precision(2);
cout<<"\n\nEl porcentaje de votos del ganador "<<ganador<<" en la localidad "<<localidadGanadora<<" es "<<(total * 100) / maxVotos;

}

int main()
{
	srand(25);
	
	LISTA L ;
	
	L.MIRAR() ;

	L.GANADOR();

	L.MAXLOCALIDAD();	

	L.PORCENTAJE();

	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	return 0 ;
}
