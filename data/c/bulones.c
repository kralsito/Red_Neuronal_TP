#include <stdio.h>
#include <stdlib.h>

//Una fabrica industrial desea digitalizar sus ventas, en la cual fabrica y vende bulones. La misma produce 10 tipos de bulones, y se tiene de cada uno el codigo,
//nombre, stock y precio unitario de venta. Al comenzar el dia se hace la carga inicial de stock de cada tipo de bulon, para luego realizar las ventas de stock
//disponible hasta concluir el dia.
//Se desea realizar
//1-Por cada venta imprimir el ticket con: Nombre bulon, Precio Unitario, Cantidad vendida, Monto total de la venta.
//2-Al finalizar el dia, informar total vendido y total recaudado por tipo de bulon.


typedef struct bulones
{
    int codigo;
    char nombre [20];
    int stock;
    int cantidadventas, precio;
}T_bulones;

void imprimirdatos (T_bulones bulon[]);
void cargardatos (T_bulones bulon[]);
void menu (T_bulones bulon []);

int contador=0;


int main()
{
    T_bulones bulon;
    menu (&bulon);
    return 0;
}


void cargardatos (T_bulones bulon [])
{
    printf ("\nIngrese el codigo del bulon %d", contador+1);
    printf ("\n");
    scanf ("%d", &bulon[contador].codigo);

    printf ("\nIngresar nombre del tipo de bulon:");
    printf ("\n");
    fflush(stdin);
    gets(bulon[contador].nombre);

    printf ("\nIngresar el stock:");
    printf ("\n");
    scanf ("%d", &bulon[contador].stock);

    printf ("\nIngresar Precio Unitario del Bulon:");
    printf ("\n");
    scanf ("%d", &bulon[contador].precio);
    do
    {
        printf ("\nCantidad de ventas realizadas en el Dia:");
        printf ("\n");
        scanf ("%d", &bulon[contador].cantidadventas);
        if (bulon[contador].cantidadventas > bulon[contador].stock)
        {
            printf("ERROR NO SE PUEDE VENDER MAS DE LA CANTIDAD DEL STOCK, por favor volver a ingresar");
        }

    } while(bulon[contador].cantidadventas > bulon[contador].stock);

    contador++;


}

void imprimirdatos(T_bulones bulon [])
{
    for (int i=0; i < contador; i++)
    {
        printf ("\nCodigo del Bulon: %d", bulon[i].codigo);
        printf ("\nNombre del Bulon: ");
        puts(bulon[i].nombre);
        printf ("Stock inicial: %d", bulon[i].stock);
        printf ("\nPrecio por unidad: %d", bulon[i].precio);
        printf ("\nCantidad de Ventas realizadas en el dia: %d", bulon[i].cantidadventas);
        printf ("\nCantidad de stock que quedo finalizando el dia: %d", bulon[i].stock-bulon[i].cantidadventas);
        printf ("\nCantidad de lo recaudado en el dia: %d", bulon[i].cantidadventas*bulon[i].precio);
        printf ("\n=================================================");

    }


}