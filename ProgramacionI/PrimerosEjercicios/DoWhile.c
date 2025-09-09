/*Do While

Controlar el ingreso de un NRO entero de 3 cifras


                      100........................999
                      
                      
      NRO  ->12       mal ingreso -> volver a ingresar 
           ->-123       mal ingreso -> volver a ingresar                
           ->12345       mal ingreso -> volver a ingresar                
           ->999       BUEN, INGRESO                
                 
           




*/





//PRIMERA FORMA CON WHILE

/*#include<stdio.h>


main(){
int NRO
printf("\nIngrese un Nro entero positivo de 3 cifras ");
scanf("%d",&NRO);	

while(NRO < 100  ||   NRO > 999)
{
	
	
	printf("\nIngrese un Nro entero positivo de 3 cifras ");
scanf("%d",&NRO);	
	
	
	
	
}

printf("\nSE INGRESO CORRECTAMENTE");
	
	*/
	
	
//SEGUNDA FORMA CON DO WHILE


	
	
	
#include<stdio.h>


main(){
int NRO;

do{
	
	if(NRO < 100 || NRO >999)
	printf("\nERROR,Ingresar nuevamente");
	
	printf("\nIngrese un Nro entero positivo de 3 cifras ");
    scanf("%d",&NRO);	
	
	
}
while(NRO < 100  ||   NRO > 999);

printf("\nSE INGRESO CORRECTAMENTE");
	



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
