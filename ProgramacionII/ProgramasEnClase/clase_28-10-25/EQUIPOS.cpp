
/*   TODOS QUIEREN A MESSI  (VARIANTE) */
/*   CONSTRUIR LA FUNCION CHEQUEAR QUE PERTENECE A GUIRNALDA  */
/*   QUE MUESTRE LOS EQUIPOS QUE INSCRIBIERON JUGADORES DUPLICADOS */
/*   ESTO ES, QUE TAMBIEN ESTAN EN OTROS EQUIPOS  */
/*   DE LA FORMA :   JUGADOR      EQUIPO 1      EQUIPO 2      */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

class JUGADOR {
		public :
			char NOM[20] ;
			JUGADOR * SIG ;
			JUGADOR(char *);
			~JUGADOR();	
};

JUGADOR::JUGADOR(char * S)
{
		strcpy ( NOM , S ) ;
		SIG = NULL ;
}
JUGADOR::~JUGADOR()
{
		cout << "\n\n   MATANDO A ... " << NOM << "\n\n";
		getchar();
}


class EQUIPO {
		public :
			char NOM[20] ;
			JUGADOR * PALUM ;
			EQUIPO * SIG ;
			EQUIPO ( char * , JUGADOR * ) ;
			~EQUIPO() ;	
};


EQUIPO::EQUIPO ( char * S , JUGADOR * PRESI )
{
		strcpy ( NOM , S ) ;
		PALUM = PRESI ;
}

EQUIPO::~EQUIPO()
{
		cout << "\n\n   MATANDO A ... TODOS LOS JUGADORES\n\n";
		cout << "\n\n   TAREA PARA USTEDES \n\n";
		getchar();
}


class GUIRNALDA {
		private :
			EQUIPO * INICIO ;
			EQUIPO * BUSCAR ( char * );
		public :
			GUIRNALDA() ;
			~GUIRNALDA() ;
			void ARREGLATE(char *);
			void MIRAR();
			void CHEQUEAR();
};

GUIRNALDA::GUIRNALDA()
{
		INICIO = NULL ;
}


GUIRNALDA::~GUIRNALDA()
{
		cout << "\n\n   QUE SE VAYAN TODOS !!! DESTRUYENDO EQUIPOS" ;
		cout << "\n\n   OTRA QUE ES PARA USTEDES " ;
		getchar();
}


EQUIPO * GUIRNALDA::BUSCAR(char * S)
{
		EQUIPO * P ;
		P = INICIO ;
		
		while ( P ) {
				if ( ! strcmp(P->NOM,S) )			
						return P ;			
				P = P->SIG ;			
		}
		return NULL ;
}



void GUIRNALDA::ARREGLATE ( char * S )
{
		char * GENERAEQUIPO() ;				/*  PROTOTIPO  */
		
		JUGADOR * PAL , * P ;
		EQUIPO * PPAR ;
		char BUF[20] ;
	
		PAL = new JUGADOR(S) ;
		
		strcpy ( BUF, GENERAEQUIPO() );
		
		PPAR = BUSCAR(BUF) ;

		if ( PPAR ) {
				/*  EQUIPO EXISTENTE  */
				P = PPAR->PALUM ;
				while ( P->SIG )
						P = P->SIG ;  /* VOY HASTA EL ULTIMO ALUMNO */
				P->SIG = PAL ;
				return ;			
		}		
		/*   EQUIPO NUEVO    */
		PPAR = new EQUIPO(BUF,PAL) ;
		PPAR->SIG = INICIO ;
		INICIO = PPAR ;
}

void GUIRNALDA::MIRAR()
{
		EQUIPO * PPAR ;
		JUGADOR * PAL ;
		
		cout << "\n\n  CONTENIDO DE LA GUIRNALDA\n\n\n";
		PPAR = INICIO ;
		while ( PPAR ) {
					cout << "\n\n\n\n\t\t" << PPAR->NOM << "\n" ;
			
					PAL = PPAR->PALUM ;
					while ( PAL ) {
							cout << "\n\n\t\t" << PAL->NOM ;
			
							PAL = PAL->SIG ;
					}
					getchar();
						
					PPAR = PPAR->SIG ;
		}
}
void GUIRNALDA::CHEQUEAR() {

	EQUIPO * PPAR;
	JUGADOR * PAL;
	PPAR = INICIO;
	while (PAL) {
		PAL = PPAR->PALUM;
		
		while (PPAR) {


			if (PAL->NOM==PPAR->PALUM->NOM) {
				cout<<"\n\n"<<PAL->NOM<<" EN "<<PPAR->NOM;
			}
			
			PPAR = PPAR->SIG;
		}
		

		PAL = PAL->SIG;
	}











}


char * GENERANOM();

int main()
{  
		char BUF[20] ;
		GUIRNALDA G ;
		
		srand(105);
		
		strcpy( BUF , GENERANOM() ) ;
		while ( strcmp (BUF,"FIN") ) {
				G.ARREGLATE(BUF) ;
				
				strcpy( BUF , GENERANOM() ) ;
		}
		
		G.MIRAR() ;		
		
//		G.CHEQUEAR();
		
		printf("\n\n      FIN DEL PROGRAMA");	
		return 0 ;
}


char * GENERANOM()
{
		static char NOM[][20] = {"MARADONA","RONALDO","MESSI",
						  "PELE","MESSI","LABRUNA",
						  "ORTEGA","RIQUELME","ROMA","CARRIZO",
						  "LORENZO","BOBBY MOORE","RONALDINHO","ARMANI",
						  "TARANTINI","RATTIN","ROSSI","ONEGA",
						  "ARTIME","VARACKA","GALLARDO","TEVEZ",
						  "MORETE","ERICO","LABRUNA","MORENO",
						  "PEDERNERA","LOUSTEAU","CAVENAGHI","NAVARRO",
						  "PAVONI","VERON","MESSI","RONALDO",
						  "PERFUMO","MATOSAS","PELE",
						  "CUBILLA","SANTORO","MALBERNAT","BECKENBAUER",
						  "EUSEBIO","PASTORIZA","JAIRZINHO","ROJAS",
						  "MADURGA","PIANETTI","ANDRADA","MARIN",
						  "ROMERO","ALONSO","FRANCESCOLI","DOMINGUEZ",
						  "MAYADA","MORA","MASCHERANO","KRANEVITER",
						  "SOLARI","MATURANA","BOBY MOORE",
						  "HIGUITA","BASILE","FRANCESCOLI",
						  "SARNARI","BILARDO","BATISTUTA","VALENTIM",
						  "CRISTIANO","ZAMORANO","SALAS","ARDILES",
						  "KEMPES","ZANABRIA","OLGUIN","PALACIOS",
						  "MESSI","VERON","FIN"};
		static int I = 0 ;
		return NOM[I++] ;	
}


char * GENERAEQUIPO()
{
		static char NOM[][20] = {"BARCELONA","RIVER","BOCA","JUVENTUS",
						  		 "MILAN","REAL MADRID","DYNAMO",
								 "BOTAFOGO","COLO COLO","PE�AROL",
								 "RACING","INDEPENDIENTE"  };
		return NOM[rand()%12] ;	
}

