/*   COMPETENCIA   */

/*   SE DESARROLLARA UN TORNEO POR DISCIPLINAS.                  */
/*   CADA UNA DE ESTAS TIENE UN DETERMINADO HANDICAP             */
/*   POR CADA DISCIPLINA SE DISPONE DE LA LISTA DE COMPETIDORES  */
/*   EN EL ORDEN EN QUE CLASIFICARON                             */
/*   SEGUN LA POSICION OBTENIDA SE ASIGNA EL SIGUIENTE PUNTAJE : */
/*   		PRIMERO     10 PUNTOS                                */
/*   		SEGUNDO      9 PUNTOS                                */
/*   		TERCERO      8 PUNTOS                                */
/*   		CUARTO       7 PUNTOS                                */
/*   		QUINTO       6 PUNTOS                                */
/*   		EL RESTO     2 PUNTOS                                */
/*   EL COMPETIDOR (QUE PUEDE ESTAR INSCRIPTO VARIAS VECES EN    */
/*   CADA DISCIPLINA) OBTIENE EL PUNTAJE DE SU POSICION MULTI    */
/*   PLICADO POR EL HANDICAP DE LA DISCIPLINA CONSIDERADA        */
/*   EL GANADOR ES EL QUE SUMA MAYOR PUNTAJE TOTAL               */
/*   LA INSCRIPCION EN CADA PARTICIPACION CUESTA 1000 $ POR      */
/*   EL HANDICAP DE LA DISCIPLINA EN QUE SE INSCRIBE             */

/*   SE PIDE :                                                   */
/*			1. DETERMINAR EL GANADOR Y SU PUNTAJE                */
/*          2. INDICAR QUE COMPETIDOR GASTO MAS DINERO Y CUANTO  */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class COMPETIDOR {
	public :
			COMPETIDOR(char *) ;
			~COMPETIDOR() ;
			char NOM[20] ;
			COMPETIDOR * SIG ;
};


COMPETIDOR::COMPETIDOR(char * S)
{
		strcpy ( NOM , S );
		SIG = NULL ;
}

COMPETIDOR::~COMPETIDOR()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		getchar();
}




class DISCIPLINA {
	public :
			char NOM[20] ;
			int HANDICAP ;
			COMPETIDOR * PALUM ;
			DISCIPLINA * SIG ;
			DISCIPLINA(char * , COMPETIDOR *) ;
			~DISCIPLINA() ;
};


DISCIPLINA::DISCIPLINA(char * S , COMPETIDOR * PRIMERO)
{
		strcpy ( NOM , S );
		HANDICAP = 5 + rand()%30 ;
		PALUM = PRIMERO ;
}

DISCIPLINA::~DISCIPLINA()
{
		cout << "\n\n   MATANDO A ... TODOS LOS COMPETIDORES" ;
		cout << "\n\n   PARA USTEDES" ;
		getchar();
}



class TORNEO {
	private :
			DISCIPLINA * INICIO ;
			DISCIPLINA * BUSCAR(char *);
	public :
			TORNEO() ;
			~TORNEO() ;
			void ARREGLATE(char *);
			void MIRAR() ;
			void GANADOR() ;
			void MAYOR_INVERSION();
};

void TORNEO::MAYOR_INVERSION()
{
    DISCIPLINA * D1 = INICIO, * D2;
    COMPETIDOR * C1, * C2, * DERROCHADOR;
    int INVERSION = 0, MAX_INVERSION = 0;

    while ( D1 )
    {
        C1 = D1->PALUM;

        while ( C1 )
        {
            INVERSION = 0;
            D2 = D1;

            while ( D2 )
            {
                C2 = D2->PALUM;

                while ( C2 )
                {
                    if ( !strcmp( C1->NOM, C2->NOM ) ) INVERSION += 1000;

                    C2 = C2->SIG;
                }

                D2 = D2->SIG;
            }

            if ( INVERSION > MAX_INVERSION )
            {
                MAX_INVERSION = INVERSION;
                DERROCHADOR = C1;
            }

            C1 = C1->SIG;
        }

        D1 = D1->SIG;
    }

    printf("\n\n\t\t MAYOR INVERSION: %s\n\t\tCANTIDAD GASTADA: $%d\n\n", DERROCHADOR->NOM, MAX_INVERSION);
}

void TORNEO::GANADOR()
{
    DISCIPLINA * D = INICIO, * D2;
    COMPETIDOR * C, * C2, * GANADOR;
    bool ya_procesado = false;
    int MAYOR_PUNTAJE = 0, puntaje = 0, participaciones = 0, max_participaciones = 0;

    C = D->PALUM;
    int pos = 0;

    while ( D )
    {
        C = D->PALUM;

        while ( C )
        {
            D2 = D;
            puntaje = 0;
            participaciones = 0;

            while ( D2 )
            {
                C2 = D2->PALUM;
                pos = 0;

                while ( C2 )
                {
                    pos++;

                    if ( !strcmp(C->NOM, C2->NOM) )
                    {
                        if (pos < 6) puntaje += (11 - pos) * D2->HANDICAP;
                        else puntaje += 2 * D2->HANDICAP;

                        participaciones++;
                    }

                    C2 = C2->SIG;
                }

                D2 = D2->SIG;
            }

            if ( MAYOR_PUNTAJE < puntaje )
            {
                MAYOR_PUNTAJE = puntaje;
                GANADOR = C;
                max_participaciones = participaciones;
            }

            C = C->SIG;
        }

        D = D->SIG;
    }

    printf("\n\n\t\tGANADOR: %s (%d puntos)\n\t\tPARTICIPO %d VECES\n\n", GANADOR->NOM, MAYOR_PUNTAJE, max_participaciones);
}


TORNEO::TORNEO()
{
		INICIO = NULL ;
}

TORNEO::~TORNEO()
{
		cout << "\n\n   DESTRUYENDO TODAS LAS DISCIPLINAS " ;
		cout << "\n\n   ADIVINEN ....  " ;
		getchar();
}

void TORNEO::ARREGLATE(char * S)
{
		/*   PROTOTIPO  */
		char * GENERADISCIPLINA();

		char BUF[20] ;
		COMPETIDOR * PAL , * P ;
		DISCIPLINA * PPAR ;

		PAL = new COMPETIDOR(S) ;

		strcpy ( BUF , GENERADISCIPLINA() ) ;

		PPAR = BUSCAR(BUF) ;

		if ( PPAR ) {
				/*  DISCIPLINA EXISTENTE  */
				P = PPAR->PALUM ;		/*  APUNTO AL PRIMERO  */
				while ( P->SIG )
						P = P->SIG ; 	/*  AVANZO AL ULTIMO COMPETIDOR  */
				P->SIG = PAL ;
				return ;
		}
		/*  NUEVA DISCIPLINA  */
		PPAR = new DISCIPLINA(BUF,PAL) ;
		PPAR->SIG = INICIO ;
		INICIO = PPAR ;
}

DISCIPLINA * TORNEO::BUSCAR(char * S)
{
		DISCIPLINA * P ;
		P = INICIO ;

		while (P) {
				if ( ! strcmp ( P->NOM , S ) )
						return P ;
				P = P->SIG ;
		}
		return NULL ;
}


void TORNEO::MIRAR()
{
		DISCIPLINA * PPAR ;
		COMPETIDOR * PAL ;

		fflush(stdin);
		system("cls");
		cout << "\n\n\n\n\t\t    CONTENIDO DEL TORNEO \n\n" ;
		PPAR = INICIO ;
		while ( PPAR ) {
				cout << "\n\n\n\n\t\t    DISCIPLINA   :   " << PPAR->NOM ;
				cout << "\n\n\t\t    HANDICAP     :   " << PPAR->HANDICAP ;
				cout << "\n\n" ;

				PAL = PPAR->PALUM ;
				while ( PAL ) {
						cout << "\n\t\t    " << PAL->NOM ;
						PAL = PAL->SIG ;
				}
				getchar();

				PPAR = PPAR->SIG ;
		}
}


char * GENERANOM();

int main( )
{
		TORNEO T ;
		char BUF[20];

		srand(65);

		strcpy ( BUF , GENERANOM() );
		while ( strcmp(BUF,"FIN") ) {
				T.ARREGLATE(BUF) ;

				strcpy ( BUF , GENERANOM() );
		}

		T.MIRAR() ;

        T.GANADOR() ;
        T.MAYOR_INVERSION() ;

		printf("\n\n");
		return 0 ;
}


char * GENERANOM()
{
	static int I = 0 ;
	static char NOM[][20] = {"DARIO","CAROLINA","PEPE","LOLA",
						     "PACO","LUIS","MARIA","ANSELMO",
						  	 "ANA","LAURA","PEDRO","ANIBAL",
						     "PABLO","ROMUALDO","ALICIA","MARTA",
						     "MARTIN","TOBIAS","SAUL","LORENA",
							 "ANDRES","KEVIN","LUCRECIA","RAUL",
							 "ENZO","BETO","HERMINDO","FELIPE",
							 "GUILLERMO","TATO","KARINA","AQUILES",
							 "MINERVA","OLGA","LALO","TATIANA",
							 "LILO","STICH","EMA","THELMA",
							 "LOUISE","BONNIE","CLYDE","ROMEO",
							 "JULIETA","VERONICA","JORGE","ALEJANDRO",
							 "ROCIO","LUJAN","LIBORIO","CONAN","FIN"};
	if ( ++I < 250 )
		return NOM[rand()%52] ;
	else
		return NOM[52] ;
}


char * GENERADISCIPLINA()
{
	static char NOM[][20] = {"TRIATLON","PENTATLON","MARTILLO","JABALINA",
						     "GARROCHA","SALTO TRIPLE","SALTO EN LARGO",
							 "MARATON","CARRERA 100 MTS","DISCO","MEDIA MARATON","PESAS" };
	return NOM[rand()%12] ;
}


