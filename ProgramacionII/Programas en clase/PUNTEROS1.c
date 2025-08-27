			/***************************/
			/*                         */
			/*        PUNTEROS         */
			/*			               */
			/***************************/

/*  PUNTEROS 1.C  */


#include <stdio.h>
#include <conio.h>

/*
OPERADOR BINARIO &   ----->    AND A NIVEL DE BITS

0 0 1 1         0011 & 1010   ----->  0010
1 0 1 0

0 0 1 0
*/

int main( )
{
		int * P ;
		int A ;
		char * Q ;
		short * Z ;
		
		printf ("\n\n   LA DIRECCION DE A ES  %10d  %10o  %10X %10p" , &A , &A , &A , &A ) ;
				
		P = &A ;    		
		
		printf ("\n\n   LA DIRECCION DE A ES  %10d  %10o  %10X %10p" , P , P , P , P ) ;


//      LO QUE NO SE DEBE HACER
//		Q = &A ;   // WARNING : asignacion con tipos de punteros distintos
//		P = Q ;    // WARNING : asignacion con tipos de punteros distintos
//		P = 0X6F54AB98 ;   // WARNING : asignacion A PUNTERO DESDE ENTERO SIN CAST
		
//		CARGA DE PUNTEROS CON PUNTERO DE DISTINTO TIPO O CON DIRECCION DIRECTAMENTE		
		P = (int *)Q ;
		P = (int *)0X6F54AB98 ;	//	  OJO !!!!
		P = (int *)65987412 ;   //    OJO !!!!

//		*P = 25 ;      ESTOY INVADIENDO ZONAS PROHIBIDAS

		P = (int *) 0X2000 ;
		printf ("\n\n   EL CONTENIDO DE P ES  %10X " , P ) ;

		P = &A ;
		*P = 654 ;    //  CARGANDO A DE FORMA INDIRECTA
		printf ("\n\n   CONTENIDO DE A ES  %10d  %10d" , A , *P ) ;

		printf ("\n\n\n\n\n");





/*      ARITMETICA DE PUNTEROS  */

		P = (int *) 0X2000 ;     
		P = P + 4 ;
		printf ("\n\n   EL CONTENIDO DE P ES  %10X " , P ) ;
		
		printf ("\n\n\n\n\n");
		
		Q = (char *) 0X2000 ;
		printf ("\n\n   EL CONTENIDO DE Q ES  %10X " , Q ) ;
		
		Q = Q + 4 ;
		printf ("\n\n   EL CONTENIDO DE Q ES  %10X " , Q ) ;
		
		
		printf ("\n\n\n\n\n");
		Z = (short int *) 0X2000 ;
		Z = Z - 4 ;
		printf ("\n\n   EL CONTENIDO DE Z ES  %10X " , Z ) ;

		printf("\n\n\n\n");
		getch();
		return 0 ;
}


