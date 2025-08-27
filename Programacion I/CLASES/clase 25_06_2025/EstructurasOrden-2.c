/*Una empresa que tiene 25 sucursales desea obtener información de su producción de artículos.
Se sabe que cada sucursal fabrica a lo sumo 20 artículos diferentes y que un mismo artículo puede producirse
en más de una sucursal.
La informacion termina con Nombre de sucursal igual "FIN"
Se solicita :
a-)Ingrese los siguientes grupos de datos:
 Nombre de sucursal (string de 15 caracteres máximo)
 Número de articulo (int)
 Cantidad producida (int)
 Costo de producción unitario del articulo (float)
b-) Emita un listado ordenado alfabeticamente por nombre de sucursal informando los 4 atributos.
c-) Calcule e informe el costo total de producción de la empresa
d-) Determine e informe el porcentaje de sucursales que produjeron el articulo 2520. (es un nro. de articulo
que existe) */


#include<stdio.h>
#include<string.h>
#define CantSucursales 25



typedef struct 
{
    char[16] nombre;
    int  NroArt;
    int CantProd;
    float PU;
}sucursal;
