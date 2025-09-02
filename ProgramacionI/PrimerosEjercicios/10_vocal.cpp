//10_Confeccionar un programa que permita ingresar un caracter 
//alfanumerico y determine e informe si lo ingresado corresponde 
//a una vocal,con el mensaje 'VOCAL'.

#include <stdio.h>
#include <ctype.h>

main()
{
	
	char car;
	
	printf("Ingrese un caracter: ");
	scanf("%c",&car);
	car= tolower(car);
	
	  
if(car=='a' || car=='e' || car=='i'|| car=='o'||car=='u')

	printf("VOCAL");
	
else	
		printf("No es una Vocal ");
	
	
	}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



