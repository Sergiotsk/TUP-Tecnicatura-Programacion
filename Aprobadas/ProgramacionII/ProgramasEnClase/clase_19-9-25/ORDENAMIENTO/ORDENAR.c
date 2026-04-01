/******************************/
/*                            */
/*     ARCHIVOS BINARIOS      */
/*			                  */
/******************************/

/*  ORDENAR.C  */

/*   ORDENA UN ARCHIVO BINARIO    */

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
		struct ALUMNO X , Y ;
		FILE * FP ;
		int I , J , N ;
		
		if ( !(FP = fopen ( "BD" , "r+b" )) ) 	{           
				printf(" ERROR EN CREACION DE BD ");
				exit(1) ;			
		}	
		
		/*  MEDIR  EL  ARCHIVO  */
		fseek ( FP , 0L , SEEK_END );
		N = ftell(FP) / sizeof(X) ;
		printf("\n\n\t\t BD TIENE %d REGISTROS" , N) ;	
		
		for ( I = 0 ; I < N-1 ; I++ )
				for ( J = 0 ; J < N-I-1 ; J++ ) {
						fseek ( FP , J * sizeof(X) , SEEK_SET);
						fread ( &X , sizeof(X) , 1 , FP );
						fread ( &Y , sizeof(Y) , 1 , FP );
						if ( strcmp( X.NOM , Y.NOM ) > 0 )  {
								/*  SWAPPING  */
								fseek ( FP , J * sizeof(X) , SEEK_SET);
								fwrite ( &Y , sizeof(Y) , 1 , FP );
								fwrite ( &X , sizeof(X) , 1 , FP );
						}
				}
		
		fclose(FP) ;
		printf("\n\n\n");		
		return 0 ;
}




