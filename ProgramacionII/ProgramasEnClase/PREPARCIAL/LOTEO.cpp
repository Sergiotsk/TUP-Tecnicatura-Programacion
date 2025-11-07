/*   LOTEO   */
/// enunciado del problema:
//   SE LOTEA UN CAMPO PARA LA CONSTRUCCION DE UN COUNTRY
//   SE DISPONEN DE 500 LOTES DE DIFERENTES VALORES
//   ESTA INFORMACION SE ENCUENTRA EN UNA LISTA SIMPLEMENTE ENLAZADA
//   DE CLASE LOTEO. lOS NODOS DE CLASE TERRENO TIENEN LA INFORMACION
//   DEL CODIGO DE CADA LOTE (string) Y EL PRECIO (int).

//   EL SEGUIMIENTO DE LAS VENTAS SE LLEVA EN UNA ESTRUCTURA TIPO GUIRNALDA
//   DE TIPO COUNTRY. ESTA ESTA FORMADA POR LA LISTA DE LOS COMPRADORES (INVERSORES)
//   CUYOS NODOS TIENEN LOS NOMBRES DE ESTOS Y EL INICIO DE LA LISTA SECUNDARIA CON
//   NODOS LOTE QUE TIENEN LOS CODIGOS DE LAS PARCELAS ADQUIRIDAS POR LOS INVERSORES.
//   CADA UNO DE ESTOS PUEDE HABER COMPRADO VARIOS LOTES.

//   SE PIDE :
//			1	DIBUJAR LA ESTRUCTURA DE DATOS TOTAL CON LOS NOMBRES DE LAS CLASES
//              Y DE LOS CAMPOS.
//			2	CONSTRUIR LA FUNCION : void COUNTRY::MASGASTO(LOTEO); INVOCANDOLA
//              EN EL MAIN.
//          3   EN ESTA FUNCION DETERMINAR QUIEN ES EL INVERSOR QUE MAS DINERO INVIRTIO
//              EN LA COMPRA DE LOTES, Y CUAL FUE ESE MONTO.


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

#define NUMLOTES 500

#define SEMILLA 654


class TERRENO {
	public :
			TERRENO() ;
			char CODIGOLOTE[10] ;
			int  PRECIO ;
			TERRENO * SIG ;			
			
};

TERRENO::TERRENO()
{
		CODIGOLOTE[0] = 'A' + rand()%('Z'-'A'-1);
		CODIGOLOTE[1] = '0'+ rand()%10 ;
		CODIGOLOTE[2] = '0'+ rand()%10 ;
		CODIGOLOTE[3] = '0'+ rand()%10 ;
		CODIGOLOTE[4] = 'A' + rand()%('Z'-'A'-1);
		CODIGOLOTE[5] = '0'+ rand()%10 ;
		CODIGOLOTE[6] = '\0';
		PRECIO = 20000 + 1000 * (rand()%100);
}

class LOTEO {
	public :
		TERRENO * INICIO ;
		LOTEO() {
				INICIO = NULL ;
				TERRENO * P ;
				P = INICIO ;
				for ( int I = 0 ; I < NUMLOTES ; I++ ){
						P = new TERRENO ;
						P->SIG = INICIO ;
						INICIO = P ;
				}
		}
		void MIRALOTE();
		char * DA_COD (int) ;
};

void LOTEO::MIRALOTE()
{
		TERRENO * P ;
		P = INICIO ;
		printf("\n\n\n\t\t\t  LISTA DE LOTES\n\n\n");
		int I = 1 ;
		while (P) {
				printf("\n\t\t\t %10d \t %-15s %10d" , I++ , P->CODIGOLOTE , P->PRECIO );
				//getchar();
				P = P->SIG ;
		}
		printf("\n\n\n\n");
		getchar();
}

char * LOTEO::DA_COD( int N )
{
		int I ;
		TERRENO * P ;
		P = INICIO ;
		for ( I = 0 ; I < N ; I++ )
				P = P->SIG ;
		return P->CODIGOLOTE ;
}


/**********************************************************************/


class LOTE {
	public :
		char CODIGOLOTE[10] ;
		LOTE * SIG ;
};


class INVERSOR {
	public :
		char NOM[20];
		LOTE * INILOTE ;
		INVERSOR * SIG ;
};


class COUNTRY {
	private :
		INVERSOR * INICIO ;
		INVERSOR * BUSCAR ( char * );
	public :
		COUNTRY();
		void MIRAR(LOTEO);
		void ARREGLATE ( char * );
		void MASGASTO(LOTEO);
};

COUNTRY::COUNTRY()
{
		INICIO = NULL ;
}

void COUNTRY::MIRAR(LOTEO L)
{
		INVERSOR * P ;
		LOTE * Q ;
		TERRENO * T ;

		P = INICIO ;
		while (P) {
				printf( "\n\n\t\t\tINVERSOR: %s\n\n" , P->NOM);

				Q = P->INILOTE ;
				
				int Gasto = 0;
				while ( Q ) {
					printf("\t\t\tLOTE:%s--->", Q->CODIGOLOTE);
					T =L.INICIO ;
					while ( T ) {
						
						if ( !strcmp( Q->CODIGOLOTE, T->CODIGOLOTE)) {
							Gasto += T->PRECIO;
							printf("Precio: %d\n", T->PRECIO);
						}
						T = T->SIG ;
					}
						Q = Q->SIG ;
				}

				printf( "\nTotal Invertido por %s: %d" , P->NOM , Gasto);

				getchar();
				P = P->SIG ;
		}

}

INVERSOR * COUNTRY::BUSCAR(char * S)
{
		INVERSOR * P ;
		P = INICIO ;
		while ( P ) {
				if ( ! strcmp( P->NOM , S )  )
						return P ;
				P = P->SIG;
		}
		return NULL ;
}

void COUNTRY::ARREGLATE ( char * COD )
{
		char * GENERANOM();
		char BUF[20];
		INVERSOR * PINV ;
		LOTE * Q ;
		Q = new LOTE ;
		strcpy ( Q->CODIGOLOTE , COD );
		strcpy ( BUF , GENERANOM() );
		PINV = BUSCAR(BUF);
		if ( PINV ) {
					/*   INVERSOR EXISTENTE  */
					Q->SIG = PINV->INILOTE ;
					PINV->INILOTE = Q ;
					return ;
		}
		/*    INVERSOR NUEVO  */
		PINV = new INVERSOR ;
		strcpy ( PINV->NOM , BUF);
		PINV->INILOTE = Q ;
		Q->SIG = NULL ;
		PINV->SIG = INICIO ;
		INICIO = PINV ;
		return ;
}

/// 2)Funcion que determina el inversor que mas gasto en la compra de lotes

void COUNTRY::MASGASTO(LOTEO L)
{
		INVERSOR * P ;
		int MAXGASTO = 0 ;
		
		char NOMMAX[20] ;
		LOTE * Q ;
		TERRENO * T ;
		P = INICIO ;
		while ( P ) {
				Q = P->INILOTE ;
				int GASTO = 0 ;
				while ( Q ) {
						T = L.INICIO ;
						while ( T ) {
							if ( strcmp( Q->CODIGOLOTE, T->CODIGOLOTE ) == 0) {
								GASTO += T->PRECIO ;
							}
							T = T->SIG ;
						}
												
					Q = Q->SIG ;
				}

				if ( GASTO > MAXGASTO ) {
					MAXGASTO = GASTO ;
					strcpy( NOMMAX, P->NOM );
				}
				P = P->SIG ;
		}
		
		printf("\nEl inversor que mas gasto es: %s con una inversion de %d", NOMMAX, MAXGASTO);

		P = INICIO ;
		while (P) {
				if(!strcmp(P->NOM,"LUCRECIA")){
	

				Q = P->INILOTE ;
				
				int Gasto = 0;
				printf("\n\n\tLUCRECIAS INVIRTIO EN LOS SIGUIENTES LOTES:");
				while ( Q ) {
					
					printf("\n\n\t\t\tLOTE:%s--->", Q->CODIGOLOTE);
					T =L.INICIO ;
					while ( T ) {
						
						if ( !strcmp( Q->CODIGOLOTE, T->CODIGOLOTE)) {
							Gasto += T->PRECIO;
							printf("Precio: %d\n", T->PRECIO);
						}
						T = T->SIG ;
					}
						Q = Q->SIG ;
				}

				printf( "\nTotal Invertido por %s: %d" , P->NOM , Gasto);

				getchar();
			}
				P = P->SIG ;
		}

}


int main( )
{
		LOTEO L ;
		COUNTRY C ;
		char BUF[20];
		LOTE * Q ;
		INVERSOR * PINV ;
		int I ;

		srand( SEMILLA );

		for ( I = 0 ; I < NUMLOTES ; I = I + (1+rand()%3) )
				C.ARREGLATE(L.DA_COD(I)) ;

		L.MIRALOTE() ;

		C.MIRAR(L) ;

        C.MASGASTO(L);

		printf("\n\n");
		return 0 ;
}

char * GENERANOM()
{
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
							 "ROCIO","FIN"};
	return NOM[rand()%48] ;
}



