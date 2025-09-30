/*  MANEJO DE UNA LISTA SIMPLE  */
/*  CARGA AUTOMATICA  */

/*  Realizara una marat�n sudamericana mixta. El listado de competidores  */
/*  sexo y pais reptesentado se observa usando la funcion mirar           */

//   Se pide

//   1.   Construir una funcion que pertenezca a la clase y muestre cuantos  
//        hombres y cuantas mujeres compiten.
//   2.   Construir una funcion que pertenezca a la clase y reciba como 
//        argumento el nombre de un pais, y muestre en pantalla la totalidad
//        de los competidores de ese pais (nombre y sexo), o bien si no tiene 
//        ninguno.
//   3.   Construir una funcion que pertenezca a la clase y que reciba un nombre 
//        de competidor como argumento y muestre en pantalla a que pais representa,
//        o bien si no esta entre los competidores. 
//   4.   Construir una funcion que pertenezca a la clase y muestre en pantalla la 
//        totalidad de los datos del hombre y la mujer que ganaron la marat�n.


#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std ;


class NODO {
	public :
		NODO ( char * , char , char *);
		~NODO() ;
		char NOM[20];
		char SEXO ;
		char PAIS[20];
		int TIEMPO ;
		NODO * SIG ;
};


NODO::NODO( char * N , char S , char * P )
{
		strcpy ( NOM , N );
		SEXO = S ;
		strcpy ( PAIS , P );
		TIEMPO = 6000 + rand()%3000 ;
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
		void AGREGAR_P(char* , char , char*) ;
		void MIRAR();
		void contarSexo();
};


void LISTA::contarSexo(){
	
	NODO * P;
	P=INICIO;
	int mujeres=0,varones=0;
	
	while(P){
		
		if(P->SEXO== 'F')mujeres++;
		else if(P->SEXO== 'M')varones++;
		
		
	}

	cout<< "Competidores: "<<endl;
		cout<<"mujeres: "<<mujeres<<endl;
		cout<<"hombres: "<<varones<<endl;
	
	
	
	
}

LISTA::LISTA()
{
		INICIO = NULL ; 
}

LISTA::~LISTA()
{
		cout << "\n\n\n MATANDO A ... TODOS LOS NODOS \n\n" ;
		cout << "\n\n\n ESTA ES PARA USTEDES ... \n\n" ;
		getchar();
}

void LISTA::AGREGAR_P( char * NOM , char SEXO , char * PAIS )
{
		NODO * P ;
		P = new NODO ( NOM , SEXO , PAIS ) ;
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
				printf("\n\t\t %-15s %4c \t\t %-15s\t\t%d" , 
				P->NOM , P->SEXO , P->PAIS , P->TIEMPO );
				P = P->SIG ;
		}	
		printf("\n\n");
		getchar();	
}

/*  prototipo  */
char * GENERANOM() ;
char GENERASEX() ;
char * GENERAPAIS() ;

int main()
{
	LISTA L ;
	char NOM[20] ;
	char SEXO ;
	char PAIS[20];
	
	strcpy (NOM , GENERANOM() ) ;	
	while ( strcmp (NOM , "FIN") ) {
			SEXO = GENERASEX() ;
			strcpy (PAIS , GENERAPAIS() ) ;
			L.AGREGAR_P(NOM,SEXO,PAIS) ;
			strcpy (NOM , GENERANOM() ) ;
	}


	L.MIRAR();

	printf("\n\n\n   FIN DEL PROGRAMA ");
	getch();
	return 0 ;
}



char * GENERANOM ()
{
		static char NOM[][20] = {"CAROLINA","ROBERTO","PEPE","LOLA",
						  "ANASTASIA","VERONICA","CARLOS","ANSELMO",
						  "LUIS","ANA","LAURA","EDUARDO",
						  "PANCRASIO","SAUL","RODOLFO","EUSTAQUIO",
						  "MANUEL","RIGOBERTO","MARIA","CLARA",
						  "VALENTINA","MARTA","PEDRO","PABLO",
						  "HERNAN","LAUTARO","ENZO","EVANGELINA",
						  "HUGO","GREGORIO","ALICIA","CARMEN","FIN" };
		static int I = 0 ;
		return NOM[I++];
}

char GENERASEX ()
{
		static char SEX[] = {'F','M','M','F','F','F','M','M',
		                     'M','F','F','M','M','M','M','M',
							 'M','M','F','F','F','F','M','M',
							 'M','M','M','F','M','M','F','F'};
		static int I = 0 ;
		return SEX[I++];
}


char * GENERAPAIS ()
{
		static char NOM[][20] = {"URUGUAY","CHILE","ARGENTINA","BRASIL",
						  "PERU","VENEZUELA","COLOMBIA","PARAGUAY",
						  "ECUADOR","BOLIVIA" };
		return NOM[rand()%10];
}



