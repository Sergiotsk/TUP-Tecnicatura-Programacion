/*17_Un negocio vende distintos artículos identificados por un código, y sus precios correspondientes
, según se muestra:
.código 1; 10 ; 100 : 520 pesos la unidad
.código 2; 22; 222 : 70 pesos la unidad. La caja de 10 unidades vale 650 pesos.
.código 3; 33 : 200 pesos la unidad. Si la compra es por más de 10 unidades se hace un
descuento
del 10% sobre el total de la compra.
.código 4 ;44 : 100 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a comprar y
se informe el importe de la compra, con las siguientes leyendas:
CODIGO xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx

ANALISIS:


CODIGO(CANT)    CANTIDAD COMPRADA(CANT)          IMPORTE A PAGAR(IMPO)
     
     1                     2                              1 * 520-> 1040
     2                     2                CAJA 0 UNIDAD 2  2*70->140         
     22                    10               CAJA 1  UNIDAD 0  1*650->650
	 2                     15               CAJA 1  UNIDAD 5  1*650 + 5*70->1000   
     2                     25               CAJA 2  UNIDAD 5  2*650 + 5*70->1650    
     3                      2               CAJA 0 UNIDAD 2   2*200-> 400  Dto=0      
    33                      10                     10*200->2000            Dto=0
    33                       20                    20*200->4000            Dto=10%
                                                       Dto=4000*0.1 ->400
    4                       2                 2*100->200  

*/



#include <stdio.h>


main()

{
	
	int cod,cant,caja,uni;
	float impo,dto;
	
	printf("Ingresar codigo de producto: ");
	scanf("%d",&cod);
	
	printf("\nIngresar cantidad comprada: ");
	scanf("%d",&cant);
		
		switch(cod)
		{
			case 1: case 10: case 100:
				impo=cant * 520;
				printf("\nCodigo %d cantidad %d importe a pagar $ %.2f", cod,cant,impo);
				break;
			case 2: case 22: case 222:
				
				caja=cant/10;
				uni=cant%10;
				impo=caja*650 + uni*70;
				printf("\nCodigo %d cantidad %d importe a pagar $ %.2f", cod,cant,impo);
				break;
					
			case 3: case 33:
				impo=cant*200;
				if(cant>10)
				
				{
					dto=impo*0.1;
					impo=impo-dto; //= impo=impo*0.9
					
				}
					printf("\nCodigo %d cantidad %d importe a pagar $ %.2f", cod,cant,impo);
					break;
				
				
			
			case 4: case 44:
				
				impo=cant*100;
				printf("\nCodigo %d cantidad %d importe a pagar $ %.2f", cod,cant,impo);
				break;
		
			default: printf("\nCodigo incorrecto");	
		}
	
	


	
	
	
	
	
	
	
}







