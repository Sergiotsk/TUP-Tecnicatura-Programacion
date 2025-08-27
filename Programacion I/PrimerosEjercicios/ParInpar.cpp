//decir si un Nro. entero es par o inpar


#include<stdio.h>

main()

{
	int Nro, res;
	
	printf("Ingrese un numero entero: ");
		
		scanf("%d",&Nro);
		
		res = Nro % 2 ;
		
		if(res == 0)
		
		printf ("El numero es par.");
		
		else
		
		printf ("El numero es inpar");	
		
		
}


