//Implementar una función genérica que lea y controle el ingreso de una vocal.
#include <stdio.h>
#include <ctype.h>

char LeeControl(char,char,char,char,char);
main()
{
  char Letra;
  printf("\n Ingresar una vocal ");
  Letra = LeeControl('A','E','I','O','U');
  printf("\nSE INGRESO LA VOCAL %c",Letra);	
}
///////////////////////////////////////////////////////////////
/*char LeeControl(char L1,char L2,char L3,char L4,char L5)
{
 char L;
 do{
 	 fflush(stdin);
	 scanf("%c",&L);
	 L=toupper(L);
	 if(L!=L1 && L!=L2 && L!=L3 && L!=L4 &&  L!=L5 )
	 	printf("\nERROR, INGRESAR NUEVAMENTE ");
	}while(L!=L1 && L!=L2 && L!=L3 && L!=L4 &&  L!=L5 );
	
 return L;
	
}*/
//////////////////////////////////////////////////////////////
char LeeControl(char L1,char L2,char L3,char L4,char L5)
{
 char L;
 fflush(stdin);
 scanf("%c",&L);
 L=toupper(L);
 while(L!=L1 && L!=L2 && L!=L3 && L!=L4 &&  L!=L5 )
 {
   if(L!=L1 && L!=L2 && L!=L3 && L!=L4 &&  L!=L5 )
	 	printf("\nERROR, INGRESAR NUEVAMENTE ");
	fflush(stdin);
    scanf("%c",&L);
    L=toupper(L);
 }
	
 return L;
	
}
