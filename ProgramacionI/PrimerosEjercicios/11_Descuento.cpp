/*11_lA FARMACIA EFECTUA DESCUENTOS SEGUN EL IMPORTE DE LA COMPRA CON LA SIGUIENTE ESCALA:

            A)MENOR DE 3255$ EL DESCUENTO ES DEL 4,5%
            B)ENTRE 3255 Y 5000 $  8,0%
            C)MAS DE 5000$ EL DESCUENTO ES DEL 10,5%

cPNFECCIONAR UN PROGRAMA QUE RECIBA UN IMPORTE E INFORME :
 EL PRECIO INGRESADO , EL DESCUENTO Y EL PRECIO NETO A COBRAR, CON MENSAJES ACLARATORIOS */
 
 
 #include <stdio.h>
 
 
 main()
 
 {
 float IMP,DESC,IMPORTE;
 
 printf ("Ingrese el Importe: ");
 scanf("%f",&IMP);
 
 
 if(IMP>0 && IMP<3255)
	DESC= IMP*0.045;
	
		if(IMP>=3255 && IMP<=5000)
		
		DESC= IMP*0.8;
		
			if(IMP>5000)
			
				DESC= IMP*0.1;

 	
 
 	IMPORTE=IMP-DESC;
	
 	printf("Precio ingresado: %.2f\n",IMP);
 	printf("Descuento: %.2f\n",DESC);
 	printf("Precio Neto: %.2f\n", IMPORTE);
}
