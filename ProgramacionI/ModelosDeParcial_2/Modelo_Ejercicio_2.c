/*EJERCICIO 2: 5 (PUNTOS)
En negocio de venta de puzzeles (rompecabezas) dispone de un catálogo de sus 3000 productos.
De cada producto se conoce.
 Código del producto (entero de 4 cifras)
 Descripción del producto (máximo 60 caracteres)
 Procedencia (carácter - ‘N’ (Nacional) o ‘I’ (Importado)
 Cantidad de piezas del puzzele (entero- 500 – 1000 – 1500 -2000)
 Precio unitario
 Stock actual (si es cero, no hay stock)
   Se pide un programa que:
a- Declarar un tipo de dato que contenga la información del catalogo
b- Declarar un vector de estructuras del tipo de dato creado en el punto a.
c- Cargar en un vector de estructuras, los datos referentes a los puzzeles, Función INGRESO.
   (Implementar mínimamente una función para leer y validar un campo)
d- Indicar la cantidad de puzzeles de 1000 piezas con stock mayor que cero , Función PIEZAS1000
e- Obtener el precio unitario máximo para puzzeles de procedencia Importado, informando el código de
   producto, descripción y stock actual.(puede haber más de uno)

 */


#include<stdio.h>
#include<ctype.h>
#define CP 2

typedef struct 
{
    int Codigo;
    char descripcion[61];
    char Procedencia;
    int CantP;
    float PU;
    int Stock;
    
}Catalogo;
 int LeeControlRango(int,int);
 void INGRESO(Catalogo [],int);
 int PIEZAS1000(Catalogo [],int);
 void PuMAX(Catalogo [],int);
 char LeeControlCaracter(char,char);



///////////////
 int main(void)
 {


    Catalogo Cat[CP];
    int StkMil;

    INGRESO(Cat,CP);   
    StkMil=PIEZAS1000(Cat,CP);
    printf("\nCantidad de puzzeles de 1000 piezas con stock mayor a cero: %d",StkMil);
    PuMAX(Cat,CP);


    
 }
 //////////////
 void INGRESO(Catalogo Vc[],int CE)
 {
    int I ;
for(I=0;I<CE;I++)
{
   printf("\nIngrese el codigo del producto(4 cifras): ");
   Vc[I].Codigo=LeeControlRango(999,9999);

   printf("\nIngresar descripcion del producto: ");
   fflush(stdin);
   gets(Vc[I].descripcion);


   printf("\nIngrese Procedencia N para Nacional I para Importado: ");
   
   Vc[I].Procedencia=LeeControlCaracter('I','N');

   printf("\nIngrese cantidad de piezas (500,1000,1500,2000): ");
   scanf("%d",&Vc[I].CantP);

   printf("\nIngresar precio Unitario: ");
   scanf("%f",&Vc[I].PU);

   printf("\nIngresar stock disponible: ");
   scanf("%d",&Vc[I].Stock);

}

 }

///////////////////
int LeeControlRango(int DESDE,int HASTA)
{

   int DATO;

   do
   {
    scanf("%d",&DATO);
    if (DATO < DESDE || DATO > HASTA)
    {
        printf("\nERROR,Ingresar nuevamente: ");
    }
   } while (DATO < DESDE || DATO > HASTA);

   return DATO;

}
///////////////////
 int PIEZAS1000(Catalogo Vc[],int CE)
 {
    int I,stock=0;
    for (I=0; I < CE; I++)
    {
        if (Vc[I].CantP ==1000 && Vc[I].Stock >0)
        stock++;
        
    }    
   return stock;
 }
 //////////////////
  void PuMAX(Catalogo Vc[],int CE)
  {
    int I,Bandera=0;
    float MAX;

        for (I=0;I<CE;I++)
        {
            if(Vc[I].Procedencia == 'I')
                {
                    if(Bandera==0)
                  {
                     MAX=Vc[I].PU;
                     Bandera=1;
                  }
                  else
                     if(Vc[I].PU <MAX)
                        MAX=Vc[I].PU;

                }
                

       //  printf("\nEl codigo del puzzle Importado con mayor precio es: %d Descripcion:%s y Stock actual es %d",Vc[I].Codigo,Vc[I].descripcion,Vc[I].Stock);
        }
        


  }
////////////////////
char LeeControlCaracter(char caracter1,char caracter2)
{

char dato;

do{
   fflush(stdin);
   scanf("%c",&dato);
   dato=toupper(dato);
   if(dato != caracter1 && dato != caracter2)
      printf("\nERROR,Ingresar nuevamente");
}while (dato != caracter1 && dato != caracter2);






}