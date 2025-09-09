			/***************************/
			/*                         */
			/*        ENUMERACIONES    */
			/*			               */
			/***************************/

/*  PUNTEROS 3.C  */
//  PUNTEROS A ESTRUCTURA

#include <stdio.h>
#include <conio.h>

enum PEPE { SALIR , ALTAS , BAJAS , MODIF };


int main( )
{
		enum PEPE X ;
		
		/*    MENU  */
		
//		INGRESO UNA OPCION EN X
		
		scanf("%d" , &X ) ;
		
		switch (X) {
			case ALTAS :   damos de alta ; break ;
			case BAJAS :   damos de baja ; break ;
			case MODIF :   modificamos   ; break ;
			case SALIR :   salimos ; break ;
		};
				
		getch();
		return 0 ;
}


