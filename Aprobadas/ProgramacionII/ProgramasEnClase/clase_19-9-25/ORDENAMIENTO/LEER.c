/******************************/
/*                            */
/*     ARCHIVOS BINARIOS      */
/*			                  */
/******************************/

/*  LEER.C  */

/*   ABRE Y LEE UN ARCHIVO BINARIO    */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20];
		char SEX ;
		int NOTA ;
};

int main( )
{
		struct ALUMNO X ;
		FILE * FP ;
		
		if ( !(FP = fopen ( "BD" , "rb" )) ) 	{           
				printf(" ERROR EN CREACION DE BD ");
				exit(1) ;			
		}	
		
		printf ( " DATOS DEL ARCHIVO   \n\n");
				
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP) ) {
				printf("\n\t\t %-14s %8c %10d" , X.NOM , X.SEX , X.NOTA );
				fread ( &X , sizeof(X) , 1 , FP );			
		}
				
		fclose(FP) ;
		printf("\n\n\n\n");		
		return 0 ;
}





