			/***************************/
			/*                         */
			/*        PUNTEROS         */
			/*			               */
			/***************************/

/*  PUNTEROS 1 B.C  */

/*  DIFERENCIA DE PUNTEROS  */

#include <stdio.h>
#include <conio.h>


int main( )
{
		int * P , * Q ;
					
		P = (int *) 0X2025 ;
		Q = (int *) 0X2000 ;	
			
		printf ("\n\n   LA DIFERENCIA DE P - Q ES %d " , P - Q ) ;

		printf("\n\n\n\n");
		getch();
		return 0 ;
}


