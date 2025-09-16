/******************************/
/*                            */
/*     ARCHIVOS BINARIOS      */
/*			                  */
/******************************/

/*  ACCESO RANDOM  */

/*   BAJAS     ARCHIVO TEMPORAL    */
/*   ELIMINAMOS A LOS VARONES   */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct ALUMNO {
		char NOM[20];
		char SEX ;     
		int NOTA ;
};

/*
			 FILE *  tmpfile ();
			 
			 ej :
			 		TMP1 = tmpfile() ;
			 		tmp2 = tmpfile() ;
			 		
			 		. . . . . . . . 
			 		
			 		fclose (TMP1) ;
			 		fclose (TMP2) ;
			 		
*/


int main( )
{
		struct ALUMNO X ;
		FILE * FP , * FPT ;
				
		if ( !(FP = fopen ( "BD" , "rb" )) ) 	{           
				printf(" ERROR EN APERTURA DE BD ");
				exit(1) ;			
		}	
		
		if ( !(FPT = tmpfile( )) ) 	{           
				printf(" ERROR EN ARCHIVO TEMPORAL ");
				exit(1) ;			
		}
		
		
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP) ) {
				if ( X.SEX == 'F' )
						fwrite ( &X , sizeof(X) , 1 , FPT );				
				fread ( &X , sizeof(X) , 1 , FP );			
		}
		
		fclose(FP);
		rewind(FPT);
		
		
		/*  COPIA INVERSA  */
		
		if ( !(FP = fopen ( "BD" , "wb" )) ) 	{           
				printf(" ERROR EN CREACION DE BD ");
				exit(1) ;			
		}	
		
			
		fread ( &X , sizeof(X) , 1 , FPT );
		while ( ! feof(FPT) ) {
				fwrite ( &X , sizeof(X) , 1 , FP );				
				fread ( &X , sizeof(X) , 1 , FPT );			
		}
		
		fclose(FP);
		fclose(FPT);
		
						
		return 0 ;
}


