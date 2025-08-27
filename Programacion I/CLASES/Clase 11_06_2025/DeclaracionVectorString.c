/*************************************************
1-) GUARDAR EN UN VECTOR DE STRING LOS NOMBRES (maximo 20 caracteres)
    DANIELA - MARTIN - LEO - AGUSTIN -MAXIMILIANO
2-) MEDIANTE UNA FUNCION MOSTRAR LO GUARDADO\
*************************************************/
#include <stdio.h>
void MOSTRAR (char [][21],int);

/**************************************************************************/
 main()
{ char NOMBRE[][21]={"DANIELA","MARTIN","LEO","AGUSTIN","MAXIMILIANO"};
  //char NOMBRE[5][21]={"DANIELA","MARTIN","LEO","AGUSTIN","MAXIMILIANO"};

  MOSTRAR(NOMBRE,5);
}
/**************************************************************************/
void MOSTRAR ( char A[][21],int N)
{ int I;
  printf("\t         NOMBRES      \n");
  printf(" _____________________________________________________________ \n");
  for(I=0;I<N;I++)
   printf("\n    %-20s       \n",A[I]);
}

/**************************************************************************/
