/*  EL ARCHIVO "INGRESO" TIENE LOS DATOS DE LA INSCRIPCION DE ALUMNOS  A UNA UNIVERSIDAD. 
		SE COMPONE DE ESTRUCTURAS INGRESO
	SE COMPONEN DE LEGAJO DEL ALUMNO Y CARRERA EN LA QUE SE INSCRIBIO 

	EL ARCHIVO "EXAMEN" TIENE LOS DATOS DEL EXAMEN DE INGRESO COMUN A TODAS LAS CARRERAS.
	SE COMPONE DE ESTRUCTURAS EXAMEN               
	ESTAS ESTAN FORMADAS POR EL LEGAJO DEL ALUMNO Y LA NOTA DEL EXAMEN 

	SE PIDE  :                                                           
		1. PERMITIR EL INGRESO DE UN NOMBRE DE CARRERA E INDICAR :           
  			A)  CUANTOS ALUMNOS SE INSCRIBIERON EN ESA CARRERA               
  			B)  CUANTOS ALUMNOS SE PRESENTARON A EXAMEN (DE ESA CARRERA)     
  			C)  CUANTOS ALUMNOS DE ESA CARRERA APROBARON (NOTA >= 6)         

  		2. CUAL ES LA CARRERA EN LA QUE HUBO MAYOR INSCRIPCION               

  		3. CUAL ES LA CARRERA QUE TUVO MAYOR CANTIDAD DE INGRESANTES         */


          #include <conio.h>
          #include <stdlib.h>
          #include <stdio.h>	
          #include <string.h>
          
          
          
          struct INGRESO {
                  int LEG ;
                  char CARRERA[20] ;
          };
          
          struct EXAMEN {
                  int LEG ;
                  int NOTA ;
          };
          
          
          void VERINGRESO();
          void VEREXAMEN();
          int PRIMERO();
          void SEGUNDO();
          
          int main()
          {
                  
              VERINGRESO();
               printf("\n\n\n------------------------------------------------------------------------------------------------------------------------\n\n\n");
              VEREXAMEN();
              printf("\n\n\n------------------------------------------------------------------------------------------------------------------------\n\n\n");
               PRIMERO();
               SEGUNDO();
                   
               
               
                  printf ("\n\n\nFIN DEL PROGRAMA  " );
                  return 0 ;
          }
          
          int PRIMERO(){
              FILE *FP;
              FILE *FP2;
              if( !(FP = fopen("INGRESO","rb"))){
                  printf("erorr en ingreso");
                  exit(1);
              }
              if( !(FP2 = fopen("EXAMEN","rb"))){
                  printf("erorr en ingreso");
                  exit(1);
              }
              struct INGRESO x;
              struct EXAMEN y;
              char carrera[20];
              
              
              printf("INGRESE EL NOMBRE DE UNA CARRERA:");
              gets(carrera);
              int cont_carrera=0,cont_examen=0,aprobados=0;
              while(fread(&x,sizeof(x),1,FP)==1){
                  if(strcmp(carrera,x.CARRERA)==0){
                      while(fread(&y,sizeof(y),1,FP2)==1){
                          
                          if(x.LEG==y.LEG){
                              cont_examen++;
                              
                              if(y.NOTA>=6){
                                  aprobados++;
                              }
                          }
                      }
                      cont_carrera++;
                  }
              }
              if(cont_carrera>0){
                  printf("\nSE INSCRIBIERON %d ALUMNOS",cont_carrera);
                  if(cont_examen>0){
                      printf(" Y SE PRENSENTARON A EXAMEN %d ALUMNOS.\n Y APROBARON :%d\n",cont_examen,aprobados);
                  }else{
                      printf("\nY NO SE PRESENTARON ALUMNOS A EXAMEN.");
                  }
              
              
              
              
              
              }else{
                  printf("\nCARRERA INEXISTENTE O SIN ALUMNOS\n");
              }
              
              return 0;
          }
          void SEGUNDO(){
              FILE *FP;
              if( !(FP = fopen("INGRESO","rb"))){
                  printf("erorr en ingreso");
                  exit(1);
              }
              struct INGRESO x;
              char NOM[][20] = {"ARQUITECTURA","FISICA","QUIMICA","MATEMATICA",
                                             "INGENIERIA","MEDICINA","ABOGACIA","PSICOLOGIA",
                                             "PERIODISMO","SOCIOLOGIA","ANTROPOLOGIA","ODONTOLOGIA",
                                             "LITERATURA","PEDAGOGIA"};
              int i=0,flag=-1;
              int ingresos[14]={0};				  		 
                  while(fread(&x,sizeof(x),1,FP)==1){
                      i=0;
                      flag=-1;
                      while(i<15 && flag!=1){
                          if(strcmp(x.CARRERA,NOM[i])==0){
                              ingresos[i]++;
                              flag=1;
                          }else{
                          i++;
                          }
                      }
                  }
          
                  int j=0,max=ingresos[0],pos=0;
                  for(j=0;j<15;j++){
                      if(ingresos[j]>max){
                          max=ingresos[j];
                          pos=j;
                      }
                  }
                  printf("LA CARRERA CON MAS INSCRIPCIONES FUE: %-15s CON %d INSCRIPCIONES.",NOM[pos],max);
              fclose(FP);
          }
          
          void VERINGRESO(){
              FILE *FP;
              if( !(FP = fopen("INGRESO","rb"))){
                  printf("erorr en ingreso");
                  exit(1);
              }
              struct INGRESO x;
              while(fread(&x,sizeof(x),1,FP)==1){
                  printf("\n LEGAJO: %d\tCARRERA: %-20s",x.LEG,x.CARRERA);
              }
              fclose(FP);
          }
          void VEREXAMEN(){
              FILE *FP;
              if( !(FP = fopen("EXAMEN","rb"))){
                  printf("erorr en ingreso");
                  exit(1);
              }
              struct EXAMEN x;
              while(fread(&x,sizeof(x),1,FP)==1){
                  printf("\n LEGAJO: %d\tNOTA: %d",x.LEG,x.NOTA);
              }
              fclose(FP);
          }