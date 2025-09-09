/*	ej3
 Ingresar 2 numeros (entero y real) Realizar una funcion que calcule la SUMA y otra el PROMEDIO de los ingresados 
 Ambos informes en el programa principal 
*/


#include<stdio.h>

float SUMA(int,float);
float PROMEDIO (int,float);
float OTRO_PROMEDIO(float);


main()
{
int NRO1;
float NRO2,SUM,PROM;     //Prototipo o declaracion de la funcion

printf("\n Ingresar primer Numero(ENTERO): ");
scanf("%d",&NRO1);

printf("\n Ingresar primer Numero(REAL): ");
scanf("%f",&NRO2);

//SUM = NRO1 +NRO2 ;   //SIN FUNCION

SUM = SUMA(NRO1,NRO2);  //Llamada a funcion

printf("\n La suma de los numeros ingresados es %.2f", SUM);

//PROM = PROMEDIO(NRO1,NRO2);//Llamada funcion
PROM = OTRO_PROMEDIO(SUMA(NRO1,NRO2));

printf("\n El promedio es %.2f", PROM);


	
}
//////////////////////////////////////////////////
/*FUNCION SUMA*/

float SUMA(int N1,float N2) //Definicion de la funcion SUMA
{
	
/*	float S;
	S = N1 + N2;
	return S ;
	*/
	
	return N1 + N2 ;//TAMBIEN SE PUEDE PONER ENTRE PARENTESIS(N1 + N2)
	
	
}

/*FUNCION PROMEDIO*/

float PROMEDIO (int N1,float N2)     //Definicion de la funcion PROMEDIO
{
		
	
	return (N1 + N2 )/2;
	
	
		
		
		
		
	}

/*FUNCION OTRO_PROMEDIO*/

float OTRO_PROMEDIO (float N)     //Definicion de la funcion PROMEDIO
{
		
	
	return (N)/2;
	
	
		
		
		
		
	}





