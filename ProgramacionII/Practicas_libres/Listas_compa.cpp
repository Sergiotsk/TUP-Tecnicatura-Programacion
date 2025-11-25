/*  MANEJO DE UNA LISTA SIMPLE  */

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std ;

#define N 5

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
    SIG = NULL;
} 

NODO::~NODO()
{
	cout << "\n\n\n MATANDO A ... " << NOM << "\n\n" ;
	getchar();
}


class LISTA {
	private :
        NODO * INICIO ;
		//void PONER_P ( NODO *);
        //void poner_f (NODO *);
        void insercion_ordenada(NODO *);
	public :
		LISTA();
		~LISTA();
		//void AGREGAR_P(char*) ;
		void MIRAR();
        //int contar();
        //void buscar(char *nombre);
        //void buscar_eliminar(char *nombre);
        //void eliminar(NODO *AUX, NODO *P);
        //void agregar_f(char *);
        void insercion(char *);
        void inversion_lista();
        NODO *obtener_inicio(){return INICIO;};
};

LISTA::LISTA()
{
	INICIO = NULL ; 
}

LISTA::~LISTA()
{
    NODO *P = INICIO;
    while ( P )
    {
        NODO *TEMP = P;
        P = P->SIG;
        delete TEMP;
    }
    printf("NODOS ELIMINADOS CORRECTAMENTE");
	getchar();
}

/*void LISTA::AGREGAR_P( char * NOM )
{
		NODO * P ;
		P = new NODO ( NOM ) ;
		PONER_P ( P );
}*/

/*void LISTA::PONER_P ( NODO * PN )
{
		PN->SIG = INICIO ;
		INICIO = PN ;
}*/

/*void LISTA::agregar_f(char *NOM){
    NODO *P;
    P = new NODO (NOM);
    poner_f (P);
}*/

/*void LISTA::poner_f(NODO *PN){
    if (!INICIO) {
        INICIO = PN;
        PN->SIG = NULL;
        return;
    }
    NODO *P;
    P = INICIO;

    while ( P->SIG )
    {
        P = P->SIG;
    }
    
    P->SIG = PN;
    PN->SIG = NULL;
}*/

/*void LISTA::insercion(char *NOM){
    NODO *P;
    P = new NODO (NOM);
    insercion_ordenada(P);
}*/

/*void LISTA::insercion_ordenada(NODO *PN){

    NODO *P, *ANT;
    P = INICIO;
    ANT = NULL;

    if(!INICIO){
        INICIO = PN;
        PN->SIG = NULL;
        return;
    }

    if (strcmp(PN->NOM, INICIO->NOM) < 0)
    {
        PN->SIG = INICIO;
        INICIO = PN;
        return;
    }

    while (P && strcmp(PN->NOM, P->NOM) > 0)
    {
        
        ANT = P;
        P = P->SIG;

    }
    
    ANT->SIG = PN;
    PN->SIG = P;
}*/

/*void LISTA::MIRAR ()
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
}*/

/*int LISTA::contar () {
    int aux = 0;
    NODO *P;
    P = INICIO;
    while ( P )
    {
        if (P->NOM)
        {
            aux++;
        }
        P = P->SIG;
    }
    return aux;
}*/

/*void LISTA::buscar(char *nombre){
    NODO *P;
    int aux = 0;
    P = INICIO;

    while ( P )
    {
        if(strcmp(nombre, P->NOM) == 0){
            printf("\nEl Nombre ingresado existe en la Lista: %s", P->NOM);
            aux ++;
        }
        P = P->SIG;
    }

    if(aux == 0){
        printf("El nombre no se encuentra en la lista.");
    }
    
}*/

/*void LISTA::buscar_eliminar(char *nombre){
    NODO *P, *AUX;
    P = INICIO;
    AUX == NULL;
    int aux = 0;
    while ( P )
    {
        if(strcmp(nombre, P->NOM) == 0){
            aux ++;
            eliminar(AUX,P);
            break;
        }
        AUX = P;
        P = P->SIG;
    }
    
    if (aux == 0)
    {
        printf("\nNo existe NODO con el nombre ingresado.");
    }
    
}*/

/*void LISTA::eliminar(NODO *AUX, NODO *P){

    if(AUX == NULL){
        INICIO = P->SIG;
    }else{
        AUX->SIG = P->SIG;
    }
    printf("Se elimino el nodo cuyo Nombre es: %s", P->NOM);
    delete (P);
}*/

/*void LISTA::inversion_lista(){
    NODO *ACT = INICIO, *ANT = NULL, *SIG =NULL;

    while ( ACT )
    {
        SIG = ACT->SIG;
        ACT->SIG = ANT;

        ANT = ACT;
        ACT = SIG;
    }
    
    INICIO = ANT;
}*/

/*LISTA fusionar(LISTA &L1, LISTA &L2){
    LISTA L3;
    NODO *P1 , *P2;
    P1 = L1.obtener_inicio();
    P2 = L2.obtener_inicio();

    while (P1 && P2)
    {
        if (strcmp(P1->NOM, P2->NOM) < 0)
        {
            L3.insercion(P1->NOM);
            P1 = P1->SIG;
        }else{
            L3.insercion(P2->NOM);
            P2 = P2->SIG;
        }
        
    }

    while( P1 ){
        L3.insercion(P1->NOM);
        P1 = P1->SIG;
    }
    
    while ( P2 ){
        L3.insercion(P2->NOM);
        P2 = P2->SIG;
    }

    return L3;
}*/


int main()
{
	//LISTA L, L2, L3;
    LISTA L;
    int cant = 0;
	char NOM[20] ;

    //printf("Ingresa dos LISTAS cada una con 5 Nombres\n");
    //printf("Lista 1: \n");
	for ( int I = 0 ; I < N ; I++ ) {
			printf ("\n\n  NOMBRE  :  ");
			scanf ("%s" , NOM) ;
			//L.AGREGAR_P(NOM) ;
            L.insercion(NOM);

	}
    /*printf("Lista 2: \n");
    for ( int I = 0 ; I < N ; I++ ) {
			printf ("\n\n  NOMBRE  :  ");
			scanf ("%s" , NOM) ;
			//L.AGREGAR_P(NOM) ;
            L2.insercion(NOM);

	}
	L.MIRAR();
    L2.MIRAR();
    cant = L.contar();
    printf("Ingrese un nombre a buscar: ");
    scanf("%s",NOM);
    L.buscar(NOM);
    printf("\nIngrese un nombre para eliminar su NODO: ");
    scanf("%s",NOM);
    L.buscar_eliminar(NOM);
    printf("\nCantidad de Nodos: %d", cant);
    printf("\nNODOS DESPUES DE ELIMINAR UNO");
    L.MIRAR();
    printf("\nIngrese un nombre para agregar:");
    scanf("%s",NOM);
    L.agregar_f(NOM);
    rintf("\nNODOS DESPUES DE AGREGAR");
    L.MIRAR();
    L.inversion_lista();
    L3 = fusionar(L,L2);
    L3.MIRAR();*/

	printf("\n\n\n   FIN DEL PROGRAMA ");
	getch();
	return 0 ;
}