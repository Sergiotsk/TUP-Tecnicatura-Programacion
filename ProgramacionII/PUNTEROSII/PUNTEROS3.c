			/***************************/
			/*                         */
			/*        PUNTEROS         */
			/*			               */
			/***************************/

/*  PUNTEROS 3.C  */
//  VECTOR DE ESTRUCTURAS MANEJO TRADICIONAL

#include <stdio.h>
#include <conio.h>


struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int NOTA ;
};

#define N  6

int main( )
{
		struct ALUMNO VEC[N] , AUX ;
		int I , J ;
				
		/*  CARGA DEL VECTOR  */
		for ( I = 0 ; I < N ; I++ ) {       
				fflush(stdin);						  
				printf ("\n\n\t\t NOMBRE :  ");
				gets( VEC[I].NOM );
				printf ("\n\t\t SEXO   :  ");
				VEC[I].SEX = getchar();
				printf ("\n\t\t NOTA   :  ");
				scanf("%d" , &(VEC[I].NOTA) );			
		}

		
/*		EJEMPO DE INGRESO DE CARACTERES

		#include <stdio.h>
		#include <conio.h>
		char C ;
		scanf("%c" , &C);
		C = getchar() ;
		C = getch() ;
		C = getche() ;     e =  echo       
*/		
		
		
		
		/*  IMPRESION DEL VECTOR  */
		printf("\n\n      IMPRESION DEL VECTOR");
		for ( I = 0  ; I < N ; I++ ) 
				printf ("\n\n\t\t %-12s %8c %10d " , VEC[I].NOM , VEC[I].SEX , VEC[I].NOTA );			
		
		
		printf("\n\n\n")	;	
		
/*	
			printf("%6d%6d" , 28 , 4568);
			
			C           C
	            28  4568
			------------
	
			printf("%-6d%-6d" , 28 , 4568);
			
			C           C
	        28    4568
			------------
*/	
	
		getchar();  getchar();
		/* ORDENAMIENTO  */
		
		for ( I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( VEC[J].NOTA < VEC[J+1].NOTA ) {
								/*  swapping  */
								AUX      = VEC[J] ;
								VEC[J]   = VEC[J+1] ;
								VEC[J+1] = AUX ;
						}
		
		
		printf("\n\n\n  VECTOR ORDENADO")	;	
		/*  IMPRESION DEL VECTOR  ORDENADO  */
		for ( I = 0  ; I < N ; I++ ) 
				printf ("\n\n\t\t %-12s %8c %10d " , VEC[I].NOM , VEC[I].SEX , VEC[I].NOTA );			
		
		getch();
		return 0 ;
}


