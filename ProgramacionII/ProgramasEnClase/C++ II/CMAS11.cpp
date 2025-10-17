			/***************************/
			/*                         */
			/*    ELEMENTOS DE C++     */
			/*			               */
			/***************************/

/*  ALIAS DE UNA VARIABLE    TIPO & */


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>



using namespace std ;


int main( )
{
		int A  ;
		int & B = A ;
		
		A = 654 ;
		
		printf("\n\n\t\t  A = %d       B = %d" , A , B);
		
		
		B = 65473 ;
		
		printf("\n\n\t\t  A = %d       B = %d" , A , B);
		
		printf("\n\n\t\t  &A = %X       &B = %X" , &A , &B);
		
}

/*

void  funcion1 ( int X );
void  funcion2 ( int & Y );

funcion1 ( A );
funcion2 ( A );

NO SON SOBRECARGABLES !!!!!

*/


