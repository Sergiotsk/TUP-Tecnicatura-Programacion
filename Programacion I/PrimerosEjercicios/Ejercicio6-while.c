/*
un ngocio de perfumeria efectua descuento segun el imrte de estas con las siguiete escala :

a)menor a 5000 3,5%
b)entre 5000 y 15000 pesos el 10%
c)entre 15001 y 30000 el 20%
d)mayor a 30000 el 25%

confeccionar un programa
1)que solicite  el importe original  e informe a este , el descuento a efectuar y el importe neto a cobrar con mensajes aclaratorios
2)importe promedio
finalice con negativo o cero

   IMPO                CONT              SUM            DTO1      DTO2     DTO3     DTO4         IMPONET

*/
 #include <stdio.h>
 
 
 main()
 
 {
 	int CONT;
 	float IMPO,SUM=0,DTO1,DTO2,DTO3,DTO4,IMPONET,DTO;
 /*	DTO1=.035;
 	DTO2=.1;
 	DTO3=.2;
 	DTO4=.25;*/
 	CONT=0;
 	
 	
 	printf("\nIngrese el importe: ");
 		scanf("%f", &IMPO);
 	while(IMPO>0)
 	{
 	
 		
 		CONT++;
 		if(IMPO<5000)
 		{
 			DTO =.035;
 			IMPONET=IMPO-(IMPO*DTO);
 			SUM+=IMPONET;
 			
		 }
 		else if(IMPO>=5000 && IMPO<=15000){
 			
 			DTO=.1;
 			IMPONET=IMPO-(IMPO*DTO);
 			SUM+=IMPONET;
		 }
 		else if(IMPO>15000 &&  IMPO<=30000){
 			
 			DTO=.2;
 			IMPONET=IMPO-(IMPO*DTO);
 			SUM+=IMPONET;			
 			
		 }
 		else
 		{
 			DTO=.25;
 			IMPONET=IMPO-(IMPO*DTO);
 			SUM+=IMPONET;
 			
		 }
		 printf("\n Importe: %.2f$",IMPO);
 		printf("\n Descuento: %.2f",DTO*100);
 		printf("%%");
 		printf("\n Importe NETO: %.2f$",IMPONET);
		 printf("\nIngrese el importe: ");
 		scanf("%f", &IMPO);
 		
 		
 		
 		
	 } 	
	 if(IMPONET<=0)
	 
	 printf("\nNo se realizaron ventas");
	 
	 else
 		  printf("\nImporte promedio: %.2f",SUM/CONT);
 }
 
 
 
