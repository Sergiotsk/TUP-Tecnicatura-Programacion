

#include<stdio.h>


int MES;

main()
{
	printf("Ingresar numero de MES ");
	scanf("%d",&MES);
	
	switch(MES)
	
	{
		
		case 1 : printf("ENERO"); break;
	    case 2 : printf("FEBRERO"); break;
		case 3 : printf("MARZO"); break;
		case 4 : printf("ABRIL"); break;
		case 5 : printf("MAYO"); break;
	    case 6 : printf("JUNIO"); break;
		case 7 : printf("JULIO"); break;
		case 8 : printf("AGOSTO"); break;
		case 9 : printf("SEPTIEMBRE"); break;
		case 10 : printf("OCTUBRE"); break;
		case 11 : printf("NOVIEMBRE"); break;
		case 12 : printf("DICIEMBRE"); break;
		
		default : printf("ERROR, NO SE INGRESO UN NUMERO VALIDO");
		
		
		
		
	}
	
	
	
	
	
	
	
}
