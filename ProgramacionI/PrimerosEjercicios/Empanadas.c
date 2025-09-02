/*Una pizzería vende empanadas por unidad o por docena, la docena cuesta $17000 pero si se
compra individualmente se cobra $2000 la unidad. Si se compran más empanadas que no se
agrupen en docenas las adicionales se cobran como por unidad. Indicar el precio total a
abonar.*/

#include <stdio.h>
#define PRECIO_DOCENA 17000
#define PRECIO_UNIDAD 2000

main()
{
	int CANT,DOCENAS,UNIDADES;
	float IMPORTE;
	printf("Ingresar cantidad de empanadas");
	scanf("%d",&CANT);
	DOCENAS=CANT/12;
	UNIDADES=CANT%12;
	IMPORTE= DOCENAS*PRECIO_DOCENA+UNIDADES*PRECIO_UNIDAD;
    printf("El importe a abonar es $ %.2f", IMPORTE);
	
	
}
