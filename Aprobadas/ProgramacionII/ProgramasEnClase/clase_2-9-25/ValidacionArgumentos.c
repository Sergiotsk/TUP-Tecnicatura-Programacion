


#include<stdio.h>
#include<stdlib.h>


int main(	int argc ,char *argv[]){
	
	if (argc < 2){
		
		
		
		printf("Uso: %s <numero>\n",argv[0]);
	}
	
	int valor =atoi (argv[1]);
	
	printf("[atoi] Valor convertido: %d\n", valor);
	
	return 0;
	
}


//ver  STRTOL string to long

// atof de ascii a float

