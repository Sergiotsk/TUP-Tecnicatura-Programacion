3/* 9_Un fabricante de reppuestos para tractores ha descubierto que ciertos
 articulos identificados por los numeros de catalogos 
12121 al 18081; 30012 al 67000 al 68000 son defectuosos
.Desea que se confecciones un programa informandole el numero de catalogo 
indique si el articulo es o no o no defecttuoso
los articulos del catalogo van desde el 1200 al 9000.

EJEMPLOS:


     


*/


#include <stdio.h>

main()
{
	
	int Nro_Catalogo;
	
	printf("Ingrese Numero de Catalogo ");
	scanf("%d",&Nro_Catalogo);
	
	if (Nro_Catalogo>=12000 && Nro_Catalogo<=90000)
	
		if( (Nro_Catalogo>=12121 && Nro_Catalogo<=18081) || (Nro_Catalogo>=30012 && Nro_Catalogo<=45565) ||  (Nro_Catalogo>=67000 && Nro_Catalogo<=68000) )
	
			printf("DEFECTUOSO");	
			
		else
		
			printf("NO DEFECTUOSO");	
	
	else
	
		printf("Fuera de Catalogo");
	
		  
	
	
	
	
	
	
	
	
	
	
	
	
}
