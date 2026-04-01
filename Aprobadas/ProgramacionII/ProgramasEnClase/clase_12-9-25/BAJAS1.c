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
		
		
		/*  COPIA INVERSA  */
		
		if ( !(FP1 = fopen ( "BD" , "wb" )) ) 	{           
				printf(" ERROR EN CREACION DE BD ");
				exit(1) ;			
		}	
		
		if ( !(FP2 = fopen ( "FAUX" , "rb" )) ) 	{           
				printf(" ERROR EN APERTURA AUX ");
				exit(1) ;			
		}
				
		fread ( &X , sizeof(X) , 1 , FP2 );
		while ( ! feof(FP2) ) {
				fwrite ( &X , sizeof(X) , 1 , FP1 );				
				fread ( &X , sizeof(X) , 1 , FP2 );			
		}
		
		fclose(FP1);
		fclose(FP2);
		
						
		return 0 ;
}


