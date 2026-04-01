
#include<stdio.h>
#include<stdlib.h>


int main(	int argc ,char *argv[]){
	
	if (argc < 2){		
		
		printf("Uso: %s <numero>\n",argv[0]);
		return 1;
	}
	
	float valor =atoi (argv[1]);
	
	printf("[atoi] Valor convertido: %d\n", valor);
	
	return 0;
	
}
// main (int argc,char argv[],char *envp[])->para variables de entorno
