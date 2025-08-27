/*En negocio de venta de puzzeles (rompecabezas) dispone de un 
  catalogo de sus 3000 productos.
De cada producto se conoce.
*Codigo del producto (entero de 4 cifras)
*Descripcion del producto (maximo 60 caracteres)
*Procedencia (caracter - N (Nacional) o I (Importado)
*Cantidad de piezas del puzzele (entero- 500 - 1000 -1500 -2000)
*Precio unitario
*Stock actual (si es cero, no hay stock)

Se pide un programa que:
a- Declarar un tipo de dato que contenga la informacion del catalogo
b- Declarar un vector de estructuras del tipo de dato creado en el punto a.
c- Cargar en un vector de estructuras, los datos referentes a los puzzeles, Funcion INGRESO.
(Implementar minimamente una funcion para leer y validar un campo)
d- Indicar la cantidad de puzzeles de 1000 piezas con stock mayor que cero , Funcion PIEZAS1000
e- Obtener el precio unitario maximo para puzzeles de procedencia Importado, informando el codigo de
producto, descripcion y stock actual.(puede haber mas de uno)*/
#include <stdio.h>
#include <ctype.h>
#define CantProductos 3

typedef struct{
	int CodProd;
	char Descrip[61];
	char Proce;
	int CantPieza;
	float PreUni;
	int Stock;
} catalogo;

char LeeControlCaracter(char,char); 
void  INGRESO(catalogo [],int);
int PIEZAS1000(catalogo[],int);
float MAXIMO_PRECIO_IMPORTADO(catalogo[],int);
void INFORME_PRECIO_MAXIMO_IMPORTADO(catalogo[],int,float);


main()
{
 catalogo VC[CantProductos];
 int CantPiezas1000ConStock;	
 float PreMaxImportado;
 INGRESO(VC,CantProductos);
 CantPiezas1000ConStock = PIEZAS1000(VC,CantProductos);
 printf("Cantidad de puzzeles de 1000 piezas con stock mayor que cero %d",CantPiezas1000ConStock);
 PreMaxImportado = MAXIMO_PRECIO_IMPORTADO(VC,CantProductos);
 INFORME_PRECIO_MAXIMO_IMPORTADO(VC,CantProductos,PreMaxImportado);	
}
/////////////////////////////////////////////////////////////
void  INGRESO(catalogo V[],int CE)
{
  int I;
  printf("\n INGRESO DE DATOS DEL CATALOGO ");
  for(I=0; I<CE; I++)
  {
  	printf("\nIngresar codigo del producto ");
  	scanf("%d",&V[I].CodProd);
  	fflush(stdin);
  	printf("\nIngresar descripcion ");
  	gets(V[I].Descrip);
  	printf("\nIngresar procedencia ");
  	V[I].Proce = LeeControlCaracter('N','I'); 
  	printf("\nIngresar Cantidad de piezas ");
  	scanf("%d", &V[I].CantPieza );
  	printf("\nIngresar precio Unitario ");
  	scanf("%f", &V[I].PreUni );
  	printf("\nIngresar Cantidad en stock ");
  	scanf("%d", &V[I].Stock);
    }	
}
///////////////////////////////////////////////////////
char LeeControlCaracter(char caracter1, char caracter2)
{
  char Dato;
  do{
  	fflush(stdin);
	scanf("%c", &Dato);
	Dato = toupper(Dato);
  	if ( Dato != caracter1 && Dato != caracter2 )
  		printf("\nERROR, Ingresar nuevamene");
  	
  }while (Dato != caracter1 && Dato != caracter2);	
 
  return Dato;	
}
////////////////////////////////////////////////////////
int PIEZAS1000(catalogo V[],int CE)
{
 int I, cont = 0;
 for (I=0; I< CE; I++)
    if (V[I].CantPieza == 1000 && V[I].Stock >0)
    	   cont ++;	
 return cont;	
}
///////////////////////////////////////////////////////////
float MAXIMO_PRECIO_IMPORTADO(catalogo V[],int CE)
{
  int I, Bandera = 0;
  float PreMax ;
  for (I=0; I< CE; I++)
  	if (V[I].Proce == 'I')
  	      if (Bandera == 0 )
  			{
			 PreMax = V[I].PreUni;
  			 Bandera = 1;
  		      }
  		else
  		   if (V[I].PreUni> PreMax)
  		     PreMax = V[I].PreUni;
 
  return PreMax;
}
///////////////////////////////////////////////////////////////////
void INFORME_PRECIO_MAXIMO_IMPORTADO(catalogo V[],int CE,float P)
{
 int I;
 printf("\nPrecio unitario maximo para puzzeles de procedencia Importado %.2f", P);
 for (I=0; I< CE; I++)
   if (V[I].Proce == 'I'  && V[I].PreUni == P )
    printf("\ncodigo de producto: %d - descripcion:  %s - stock: %d", V[I].CodProd,V[I].Descrip,V[I].Stock);	
}
///////////////////////////////////////////////////////////////






