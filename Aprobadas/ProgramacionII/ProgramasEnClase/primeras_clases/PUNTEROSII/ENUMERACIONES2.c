			/***************************/
			/*                         */
			/*        ENUMERACIONES    */
			/*			               */
			/***************************/

/*  PUNTEROS 3.C  */
//  PUNTEROS A ESTRUCTURA

#include <stdio.h>
#include <conio.h>

enum PEPE { ALFA , BETA , DELTA , GAMMA = 20 , EPSILON , OMEGA , PI = 21 };


int main( )
{
		enum PEPE X ;
		
		X = DELTA + BETA ;
		
		
		printf ("\n\n\n\n\t\t %4d  %4d  %4d  %4d  %4d  %4d  %4d  " , 
		ALFA , BETA , DELTA , GAMMA , EPSILON , OMEGA , PI);
		printf ("\n\n\t\t %10d " , X) ;
		
		getch();
		return 0 ;
}


