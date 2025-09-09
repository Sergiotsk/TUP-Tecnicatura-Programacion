/*
Confeccionar un programa que solicite el ingreso del valor del radio (r) de un círculo y con
dicho valor calcule la superficie del círculo, la longitud de la circunferencia (perímetro) y el
volumen de la esfera.

superficie= pi r2

perimetro = 2pi r

volumen = 4/3	pir3

FUNCION POW(base,exponente)



*/

#include<stdio.h>
#include<math.h>
#define PI 3.14

main()

{
	
	float Radio,SUP,VOL,PER ;
	
	
	
	printf("Ingresar el radio del circulo ");
	scanf("%f",&Radio);
	
	
	//SUP = PI*Radio*Radio;
	SUP = PI*pow(Radio,2);
	PER =2*PI*Radio;
	//VOL =4/3.*PI*Radio*Radio*Radio;
	VOL =4/3.*PI*pow(Radio,3);
	
	
		printf("\nSUPERFICIE %.2f",SUP);
		printf("\nPERIMETRO %.2f",PER);
		printf("\nVOLUMEN %.2f",VOL);
	
	
	
}
