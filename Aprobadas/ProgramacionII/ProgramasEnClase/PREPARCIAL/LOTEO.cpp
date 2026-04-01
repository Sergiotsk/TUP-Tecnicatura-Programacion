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
/*

4) REALIZAR FUNCION  void COUNTRY::MASCARO(LOTEO L)

PARA ENCONTRAR EL LOTE MAS CARO, SI ESTE SE VENDIO O NO, Y SI SE VENDIO QUIEN FUE SU COMPRADOR


                         
                         LOGICA DE DESARROLLO
    
    1.EN LOTEO BUSCAR EL NODO DEL MAXIMO PRECIO
    2.YA TENEMOS EL CODIGO Y EL PRECIO 
    3.CAMBIAR A LA GUIRNALDA CON EL CODIGO 
    4.BUSCAR LOTE DONDE FIGURA CODIGO (*).
    5.DE NODO INVERSOR OBTENER NOMBRE DEL DUE�O 
    (*)==NULL ,SI NO SE ENCUENTRA INFORMAR QUE NO ESTA VENDIDO    

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ostream>

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
		void INSERTAR_INICIO(char *,int);
		void CONTAR(LOTEO);
		void INSERTAR_FINAL(char *, int);
		bool ELIMINARXCODIGO(char *);
		
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
		void MASCARO(LOTEO);
		void CONTAR_VENDIDOS();
		void LOTE_MAS_BARATO(LOTEO);
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

				//getchar();
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

//4)DETERMINAR LOTE MAS CARO E INFORMAR SI FUE VENDIDO Y SU COMPRADO O NO

void COUNTRY::MASCARO(LOTEO L)
{
	
	LOTE * Q;
	INVERSOR * P;
	TERRENO * T;
	int MASCARO=0;
	char MASCAROCOD[10];
	int cont=0;
	bool encontrado= false;
	
	
		T=L.INICIO;
		while(T)
		{
			if(T->PRECIO>MASCARO)
			{
				
				MASCARO=T->PRECIO;
				strcpy(MASCAROCOD,T->CODIGOLOTE);					
				
				
			}		
			
			T=T->SIG;
		}

	    cout<<"\nEL O LOS LOTES MAS CAROS TIENEN UN VALOR DE:"<<MASCARO<<endl;

    	cout<<"\nSU CODIGO ES:"<<endl;
		
		
		T=L.INICIO;		
		while(T)
		{
			if(MASCARO==T->PRECIO)
			{
				encontrado=false;
				cont++;
				cout<<cont<<"."<<T->CODIGOLOTE;
				
				P=INICIO;	
				while(P){

							Q=P->INILOTE;
							while(Q && !encontrado){
			    
								if(!strcmp(T->CODIGOLOTE,Q->CODIGOLOTE)){

								encontrado=true;				
				
								cout<<"-->FUE VENDIDO A: "<<P->NOM<<endl;
								break;
								

				
								}
			
		     
							Q=Q->SIG;
							}
				
		
		
							P=P->SIG;
						}	
						if(!encontrado)
						cout<<"-->NO SE VENDIO"<<endl;
							
				
			}		
			
			T=T->SIG;


		}				
	
	
}

void COUNTRY::LOTE_MAS_BARATO(LOTEO L){



        TERRENO * T;		
        LOTE * Q;		
        INVERSOR * P;


        char BARATO[10]="";
		char CODBARATO[10]="";
	
        int Mprecio;
		bool VENDIDO;

        T=L.INICIO;

        Mprecio=T->PRECIO;
       
		

        while(T)
        {	
			int PREC=T->PRECIO;
			strcpy(BARATO,T->CODIGOLOTE);
            if(PREC<Mprecio)
			{
				Mprecio=PREC;
				
			}

			VENDIDO=false;
			P=INICIO;
			while(P && !VENDIDO){
				Q=P->INILOTE;
				while(Q){
					if(!strcmp(BARATO,Q->CODIGOLOTE)){						
						VENDIDO=true;
						break;
						
					}
					Q=Q->SIG;
				}
				P=P->SIG;
			}   
			if(!VENDIDO && PREC<Mprecio || CODBARATO[0]=='\0'){
				Mprecio=PREC;
				strcpy(CODBARATO,BARATO);
				
			}            

      
        T=T->SIG;
	}
	  

        cout<<"\nEl lote mas BARATO disponible es: "<<CODBARATO<<" y su precio es de "<<Mprecio<<endl;

}
/////////////////PRACTICAS LIBRES////////////////////////

/*INSERTAR UN LOTE POR EL INICIO*/

void LOTEO::INSERTAR_INICIO(char * codigo, int precio) {
    TERRENO * nuevo = new TERRENO;
    strcpy(nuevo->CODIGOLOTE, codigo);
    nuevo->PRECIO = precio;
    
    nuevo->SIG=INICIO;

	INICIO=nuevo;
    
    
}
/*INSERTAR UN LOTE POR EL FINAL*/
void LOTEO::INSERTAR_FINAL(char * codigo, int precio){
    
	TERRENO * T, * nuevo =new TERRENO;
	strcpy(nuevo->CODIGOLOTE, codigo);
    nuevo->PRECIO = precio;
	nuevo->SIG=NULL;
	
	T=INICIO;
	while (T->SIG!=NULL)
	{
		T=T->SIG;
	}
	T->SIG=nuevo;
	






}



/*CONTAR NODOS, CUANTOS TERRENOS HAY?*/
void LOTEO::CONTAR(LOTEO L){
  
	TERRENO * T;
	T=INICIO;
	int CONT=0;

	while (T!=NULL)
	{
		CONT++;
		T=T->SIG;
	}
	
		
		
		cout<<"EXISTEN "<<CONT<<" LOTES EN TOTAL."<<endl;


}

/*CONTAR LOTES VENDIDOS*/

void COUNTRY::CONTAR_VENDIDOS(){

	INVERSOR * P;
	LOTE * Q;
	int CONT=0;
	P=INICIO;
	while (P)
	{
		Q=P->INILOTE;	
		while (Q)
			{
				CONT++;

				Q=Q->SIG;
			}
			
		P=P->SIG;
	}
	

	cout<<"CANTIDAD DE LOTES VENDIDOS: "<<CONT<<endl;
	
}
/*BUSCAR Y ELIMINAR TERRENO, BUSCANDO POR CODIGO*/
    
bool LOTEO::ELIMINARXCODIGO(char * COD){
TERRENO * T;
TERRENO * ANT;
TERRENO *ACT;

T=INICIO;

//CASO1: LISTA VACIA
if(INICIO==NULL)return false;


//CASO2: ESTA EN EL INICIO
if(!strcmp(T->CODIGOLOTE,COD)){

	T=INICIO;
	INICIO=INICIO->SIG;
	delete T;
	return true;
}


//CASO3: ESTA EN EL MEDIO O EL FINAL
ANT = INICIO;
ACT = INICIO->SIG;
while (ACT)
{
	
	if(!strcmp(ACT->CODIGOLOTE,COD)){

		ANT->SIG= ACT->SIG; //DESVINCULAR
		delete ACT;         //LIBERAR
		return true;
	}

	ANT=ACT;
	ACT=ACT->SIG;

	
}

	
	return false;//NO ENCONTRADO

}

////////////////////////////////////////////////////////
int main( )
{
		LOTEO L;
		COUNTRY C ;
		char BUF[20];
		INVERSOR * PINV ;
		int I ;
		char nuevoCOD[10],FnuevoCOD[10],EliminarCOD[10];
		int nuevoPRECIO,FnuevoPRECIO;
		bool ELIMINADO=false;
		

		srand( SEMILLA );

		for ( I = 0 ; I < NUMLOTES ; I = I + (1+rand()%3) )
				C.ARREGLATE(L.DA_COD(I)) ;

			
		do
		{
			cout<<"INGRESE NUEVO LOTE POR EL PRINCIPIO"<<endl;
			cout<<"CODIGO DE 10 CARACTERES: ";
			cin>>nuevoCOD;
			if (strcmp(nuevoCOD, "FIN") == 0) break;
			cout<<"PRECIO: ";
			cin>>nuevoPRECIO;
			L.INSERTAR_INICIO(nuevoCOD,nuevoPRECIO);

		} while (true);
		
		
	do {
   			 cout<<"INGRESE NUEVO LOTE AL FINAL(FIN para terminar)"<<endl;
   			 cout<<"CODIGO: ";
   			 cin>>FnuevoCOD;
  			  if (strcmp(FnuevoCOD, "FIN") == 0) break;

   			 cout<<"PRECIO: ";
   			 cin>>FnuevoPRECIO;
   			 L.INSERTAR_FINAL(FnuevoCOD, FnuevoPRECIO);
		} while (true);


		C.MIRAR(L) ;
		L.MIRALOTE() ;
		C.LOTE_MAS_BARATO(L);
		C.MASGASTO(L);

			
			getchar();
			
			//getchar();
			C.MASCARO(L);
			L.CONTAR(L);	
			C.CONTAR_VENDIDOS();	

			do
			{
				cout<<"INGRESE CODIGO DEL LOTE QUE DESEA ELIMINAR(FIN para terminar)"<<endl;
     			cout<<"CODIGO: ";
    			cin>>EliminarCOD;
   			 if (!strcmp(EliminarCOD, "FIN")) break;
				ELIMINADO=L.ELIMINARXCODIGO(EliminarCOD);

			if(ELIMINADO)
				cout<<"Lote eliminado CORRECTAMENTE"<<endl;
			else 
				cout<<"Lote NO encontrado en los registros existentes"<<endl;

			} while (strcmp(EliminarCOD, "FIN"));
			
			
			getchar();
			L.MIRALOTE();

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



