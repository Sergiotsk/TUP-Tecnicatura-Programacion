//3_se ingresan 3 numeros DISTINTOS, determinar el mayor


#include <stdio.h>

main()
{
	int NRO1, NRO2, NRO3;
	printf("Ingresar 3 numeros distintos : ");
	scanf("%d%d%d", &NRO1,&NRO2,&NRO3);
	
	if( NRO1!=NRO2 && NRO1!=NRO3 && NRO2!=NRO3)
	
	   if (NRO1>NRO2 && NRO1>NRO3)
	   
	   		printf("El MAYOR es %d", NRO1);	   		
	   		
	   	else
		   
		   	if(NRO2>NRO1 && NRO2>NRO3)
			   
			printf("El MAYOR es %d", NRO2);
			   
			else
				
			printf("El MAYOR es %d", NRO3);
				
	else
	
		printf("ERROR, los numeros tienen que ser distintos");
	
	
	
	
	
	
}
