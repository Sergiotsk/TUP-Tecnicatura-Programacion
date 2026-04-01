/*clase:2-09-2025



if (b==null){
	printf("	no hay memoria");
	
	exit(1);//NO USAR RETURN 
}


int cont=1;

while(malloc(1))

	cont++;///para medir memoria disponible enel heap /parva 
	
	
	
	
	
	///segunda pate de la clase 
	
	
	
	
	 la funcion main es una funcion que media entre nosotros y el SO
	


  */
  
  #include<stdio.h>
  
  int main(int argc ,char *argv[]){
  	
  	printf("Numero de argumentos (argc):%d\n",argc);
  	
  	int i;
  	
  	for ( i=0 ; i<argc ;i++){
  		
  		printf("argv[%d] = %s\n",i,argv[i]);
  		
  		
  		
	  }
  	
  	return 0;
  	
  	
  }
  
  
		
	

