/******************************/
/*                            */
/*     ARCHIVOS BINARIOS      */
/*			                  */
/******************************/

/*  CREAR.C  */

/*   CREAR UN ARCHIVO BINARIO    */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO {
		char NOM[20];
		char SEX ;
		int NOTA ;
};


int main( )
{
		struct ALUMNO X ;
		FILE * FP ;
		
		if ( !(FP = fopen ( "BD" , "wb" )) ) 	{           
				printf(" ERROR EN CREACION DE BD ");
				exit(1) ;			
		}	

		printf ( " CARGA DEL ARCHIVO       FINALIZA CON NOMBRE DE ALUMNO -FIN-   \n\n");
		
		printf("\n\t NOMBRE  :   ");
		gets(X.NOM);
		while ( strcmpi (X.NOM , "FIN") ) {
				printf("\n\t SEXO    :   ");
				X.SEX =  getchar() ;
				printf("\n\t NOTA    :   ");
				scanf("%d" , &(X.NOTA) );
				fwrite ( &X , sizeof(X) , 1 , FP ) ;
				fflush(stdin) ;
				printf("\n\t NOMBRE  :   ");
				gets(X.NOM);			
		}
				
		fclose(FP) ;
				
		return 0 ;
}


