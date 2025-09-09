//2_ se ingrsan 2 numeros N1(dividendo) Y N2 (divisor).dividirlos siempre que sea posible

#include <stdio.h>

main()
{
	float N1,N2,res;

printf("Ingrese el primer numero");
scanf("%f",&N1);

printf("Ingrese el segundo numero");
scanf("%f",&N2);

if(N1 != 0)

{
		res = N1/N2;
	printf("	El resultado es %f",res);

}
else 

     printf("No esposible hacer la division");
       

	
	
	
	
}

