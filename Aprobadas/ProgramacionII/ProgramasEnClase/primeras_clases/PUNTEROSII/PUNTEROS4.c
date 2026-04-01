			/***************************/
			/*                         */
			/*        PUNTEROS         */
			/*			               */
			/***************************/

/*  PUNTEROS 3.C  */
//  VECTOR DE ESTRUCTURAS MANEJO CON PUNTERO

#include <stdio.h>
#include <conio.h>

struct ALUMNO {
		char NOM[20] ;
		char SEX ;
		int NOTA ;
} ;

#define N  6

int main( )
{
		struct ALUMNO VEC[N] , AUX ;     
		struct ALUMNO * P ;
		int I , J ;
		
		/*  CARGA DEL VECTOR  */
		
		for ( P = VEC ; P < VEC+N ; P++ ) {       
				printf ("\n\n\t\t NOMBRE :  ");
				gets( P->NOM );
				printf ("\n\t\t SEXO   :  ");
				P->SEX = getchar();
				printf ("\n\t\t NOTA   :  ");
				scanf("%d" , &(P->NOTA) );	
				fflush(stdin);		
		}


		/*  IMPRESION DEL VECTOR  */
		printf("\n\n      IMPRESION DEL VECTOR");
		
		for ( P = VEC ; P < VEC+N ; P++ )    
				printf ("\n\n\t\t %-12s %8c %10d " , P->NOM , P->SEX , P->NOTA );			
				
		printf("\n\n\n") ;	
		getchar();  
		
				
		/*  OTRA IMPRESION DEL VECTOR  */
		printf("\n\n      OTRA IMPRESION DEL VECTOR");
		for ( P = VEC , I = 0  ; I < N ; I++ ) 
				printf ("\n\n\t\t %-12s %8c %10d " , (P+I)->NOM , (P+I)->SEX , (P+I)->NOTA );			
				
		printf("\n\n\n") ;	
		getchar();  
	
		
		/* ORDENAMIENTO  */
		P = VEC ;
		for ( I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ )
						if ( (P+J)->NOTA < (P+J+1)->NOTA ) {
								/*  swapping  */
								AUX      = *(P+J) ;
								*(P+J)   = *(P+J+1) ;
								*(P+J+1) = AUX ;
						}
		
				
		printf("\n\n\n  VECTOR ORDENADO")	;	
		/*  IMPRESION DEL VECTOR  ORDENADO  */
		for ( P = VEC , I = 0  ; I < N ; I++ ) 
				printf ("\n\n\t\t %-12s %8c %10d " , (P+I)->NOM , (P+I)->SEX , (P+I)->NOTA );
		getchar();


		/*   BONUS TRACK   :   CAMPOS MULTIPLES    USO NO TRADICIONAL DEL FOR   */
//		printf("\n\n\n\t\t  USO NO TRADICIONAL \n\n\n");
//		for ( I = 0 , printf("\n\t VAMOS A DAR UNAS VUELTAS\n") ; I < 10 ;
//		I++ , printf("\n\t\t DE TANTAS VUELTAS ME ESTOY MAREANDO") ) /*SENTENCIA NULA*/ ;

		getch();
		return 0 ;
}



/*
		for ( INI ; COND ; INC ) {
				SENTENCIA COMPUESTA ;
		}

		for ( INI1 , INI2 , ... ; COND ; INC1 , INC2 , ... ) {
				SENTENCIA COMPUESTA ;
		}
*/
