/*    EJERCICIO DE ESTRUCTURAS    */

/*
1. Construir ls funcion float PROMEDIO ( struct ALUMNO); 
   que reciba una estructura alumno y retorne el promedio 
   (float) de sus notas.
2. Cual es el alumno de mejor promedio ? - Usar la funcion del punto 1 -
3. Cual es la ciudad que tiene el mejor promedio de sus alumnos ? 
   - Usar la funcion del punto 1 -
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO   20
#define NUMNOTA  8
#define CANT    40
#define SEMILLA 255

struct ALUMNO {
		char NOM[LARGO] ;
		char LOC[LARGO] ;
		char SEX ;
		int NOTA[NUMNOTA];
} ;
	

void CARGAR ( struct ALUMNO [] , int );
void MIRAR  ( struct ALUMNO [] , int );
void ORDENAR  ( struct ALUMNO [] , int );
float PROMEDIO ( struct ALUMNO);
struct ALUMNO MEJOR_ALUMNO ( struct ALUMNO [] , int );
void MEJOR_CIUDAD ( struct ALUMNO [] , int );

int main()
{
      	struct ALUMNO VEC[CANT] , MEJOR ;
      	srand(SEMILLA);
		        	
    	CARGAR ( VEC , CANT );
		MIRAR ( VEC , CANT );
	
//		ORDENAR ( VEC , CANT );
//		MIRAR ( VEC , CANT );
	
//      PROMEDIO DE LA ALUMNA 6
//		printf("\n\n\n  EL PROMEDIO DE %s ES %.2f" , 
//		VEC[6].NOM , PROMEDIO(VEC[6]) )	;

	
	/*  FUNCIONES PEDIDAS  */

	//      ALUMNO DE MEJOR PROMEDIO  
		MEJOR = MEJOR_ALUMNO(VEC, CANT);
	
		
		printf("\n\n\n  EL MEJOR ALUMNO ES %s" , MEJOR.NOM );
		printf("\n\n  Y SU PROMEDIO ES %.2f" , PROMEDIO (MEJOR) );
		    	
		    	

		MEJOR_CIUDAD ( VEC , CANT );    	
		    	
		    	
		printf("\n\n\n" ) ;    	
        return 0 ;
}


void CARGAR ( struct ALUMNO V[] , int N )
{
		int I , J ;
		char CIUDADES[][LARGO] = {"BUENOS AIRES","MENDOZA","PARANA","SALTA",
								  "LA PLATA","CORDOBA","ROSARIO","MAR DEL PLATA"};
		
		char NOM[][LARGO] = {"LUCAS","VERONICA","ANA","LAURA",
							 "MARIO","ROBERTO","ANALIA","CAROLINA",
							 "MARIA","ELVIRA","LUCIANO","CRISTINA",
							 "MONICA","CINTIA","CARLOS","CARLA",
							 "JUANA","MARINA","MELISA","EDUARDO",
							 "EDEMNIRO","BLANCA","LORENA","PANCRACIO",
							 "LUIS","MANUEL","EMA","MORENA",
							 "HERMINDO","ALBERTO","AMELIA","BELISARIO",
							 "RUPERTO","EVANGELINA","NORMA","MARTA",
							 "GUSTAVO","GERONIMO","HUGO","ANGELINA"};
		
		char SEX[] = {'M','F','F','F','M','M','F','F',
					  'F','F','M','F','F','F','M','F',
					  'F','F','F','M','M','F','F','M',
					  'M','M','F','F','M','M','F','M',
					  'M','F','F','F','M','M','M','F'};		
		
		for ( I = 0 ; I < N ; I++ ) {
				strcpy( V[I].NOM , NOM[I] );
    			strcpy( V[I].LOC , CIUDADES[rand()%8] );
    			V[I].SEX = SEX[I] ;
    			for ( J = 0 ; J < NUMNOTA ; J++ ) 
    					V[I].NOTA[J] = 2+ (rand()%9) ;
        }
}


void MIRAR ( struct ALUMNO V[] , int N )
{
		int I , J ;

		printf("\n\n\n\n\t %-15s %-15s %8s \t              %s \n" , 
		"NOMBRE" , "CIUDAD" , "SEXO" , "NOTAS") ;
		for ( I = 0 ; I < CANT ; I++ ) {
				printf("\n\n\t %-15s %-15s %8c \t " , V[I].NOM , V[I].LOC , V[I].SEX);
    			for ( J = 0 ; J < NUMNOTA ; J++ )
    					printf("%4d" , V[I].NOTA[J]);
    			}
    	getchar();
}




void ORDENAR ( struct ALUMNO V[] , int N )
{
		int I , J ;
		struct ALUMNO AUX ;
		
		for ( I = 0 ; I < N ; I++ ) 
				for ( J = 0 ; J < N-I-1 ; J++ )	
						if ( strcmp (V[J].LOC , V[J+1].LOC ) > 0 )	{
								/*  swapping  */
								AUX    = V[J] ;
								V[J]   = V[J+1] ;
								V[J+1] = AUX ;
						}
}


float PROMEDIO ( struct ALUMNO X )
{
		int I , SUMA ;
	
		for ( SUMA  = I = 0 ; I < NUMNOTA ; I++ )
				SUMA = SUMA + X.NOTA[I] ;
	
		return (float)SUMA / NUMNOTA ;
		
		//   return SUMA / 8.0 ;
}


struct ALUMNO MEJOR_ALUMNO ( struct ALUMNO V[] , int N )
{
	//   RECIBE EL VECTOR DE ESTRUCTURAS Y RETORNA 
	//   LA ESTRUCTURA DEL MEJOR PROMEDIO
	
	int POSMAX , I ;
	
	POSMAX = 0 ;
	for ( I = 1 ; I < CANT ; I++ )
			if ( PROMEDIO( V[I] ) > PROMEDIO ( V[POSMAX]) )
					POSMAX = I ;
	return V[POSMAX];	
}


void MEJOR_CIUDAD ( struct ALUMNO V[] , int N )
{
	int I , J ;
	int NUMAL , MAXNUMAL ;
	float PROM, MEJORPROMEDIO ;
	char CIUDAD[20] , MEJORCIUDAD[20] ;
	
	strcpy ( MEJORCIUDAD , "NINGUNA") ;
	MEJORPROMEDIO = 0.0 ;
	MAXNUMAL = 0 ;
	
	for ( I = 0 ; I < CANT ; I++ ) {
			strcpy ( CIUDAD , V[I]. LOC); 
			NUMAL = 0 ;
			PROM = 0.0 ;
			for ( J = 0 ; J < CANT ; J++ ) {
					if ( ! strcmp ( CIUDAD , V[J].LOC) ) {
						NUMAL++ ;
						PROM = PROM + PROMEDIO(V[J]) ;
					}
			}
			PROM = PROM / NUMAL ;		
			if ( PROM > MEJORPROMEDIO ) {
					MEJORPROMEDIO = PROM ;
					MAXNUMAL = NUMAL ;
					strcpy ( MEJORCIUDAD , CIUDAD) ;
			}
	}
	
	printf("\n\n\n\t MEJOR CIUDAD\n\n");
	printf("\n\n\t\t\t %s" , MEJORCIUDAD);
	printf("\n\n\t\t\t %.2f" , MEJORPROMEDIO);
	printf("\n\n\t\t\t %d" , MAXNUMAL);	
}





