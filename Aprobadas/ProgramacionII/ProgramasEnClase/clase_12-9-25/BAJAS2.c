/******************************/
/*                            */
/*     ARCHIVOS BINARIOS      */
/*			                  */
/******************************/

/*  ACCESO RANDOM  */

/*   BAJAS     ARCHIVO AUXILIAR    */
/*   ELIMINAMOS A LOS VARONES   */

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
		FILE * FP1 , * FP2 ;
				
		if ( !(FP1 = fopen ( "BD" , "rb" )) ) 	{           
				printf(" ERROR EN APERTURA DE BD ");
				exit(1) ;			
		}	
		
		if ( !(FP2 = fopen ( "FAUX" , "wb" ))  ) 	{           
				printf(" ERROR EN ARCHIVO FAUX") ;
				exit(1);			
		}
		

		
		fread ( &X , sizeof(X) , 1 , FP1 );
		while ( ! feof(FP1) ) {
				if ( X.SEX == 'F' )
						fwrite ( &X , sizeof(X) , 1 , FP2 );				
				fread ( &X , sizeof(X) , 1 , FP1 );			
		}
		
		fclose(FP1);
		fclose(FP2);
		
		
		/*  DESTRUIR ARCHIVO ORIGINAL  */
		
		remove ("BD") ;


/*
		int remove (nombre del archivo a destruir);    		
		
		0  ------>  OK !!!
		EOF  ---->  ERROR  !!!!
*/
		
		
		
		
		
		
		
		/*  RENOMBRAR  ARCHIVO AUXUKIAR  */
		
		rename ("FAUX" , "BD") ;


/*
		int rename (viejo archivo , nuevo nombre);    		
		
		0  ------>  OK !!!
		EOF  ---->  ERROR  !!!!
*/
				
						
		return 0 ;
}


