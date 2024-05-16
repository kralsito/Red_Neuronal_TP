/* SE TIENE UNA LISTA DE PRECIOS DE PRODUCTOS VENDIDOS
 EN CARREFOUR Y OTRA LISTA CON LOS PRECIOS DE LOS MISMOS
 PRODUCTOS VENDIDOS EN DISCO. SE DESEA OBTENER UNA TERCERA
LISTA CON LOS NOMBRES DE CADA UNO DE LOS PRODUCTOS Y EL
NOMBRE DEL SUPERMERCADO DONDE ME CONVIENE COMPRARLOS.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipo_nodo{
    int id;
    char nombre[20];
    float precio;
    struct tipo_nodo *sig;

}nodo;

typedef struct tipo_nodo_mejor{
    int id;
    char nombre[20];
    float precio;
    struct tipo_nodo_mejor *sig;
}nodo_mejor;

/*
typedef struct tipo_nodo_mejor{
    char nombreSuper[20];
    nodo* producto;//guardo un puntero a un nodo de las lista de carrefour/disco
    struct tipo_nodo_mejor *sig;
}nodo_mejor;
*/




void crear_lista(nodo **lista);
void insertar_ordenado(nodo **lista,nodo *nuevo);
nodo * crear_nodo();
void crearListaFinal(nodo_mejor **listaMejor, nodo *listaCarrefour, nodo *listaDisco);
void agregarNodoMejor(nodo_mejor **listaMejor, nodo* Nodolista, int nombreSuper);
void imprimirListaFinal(nodo_mejor *listaMejor);

int main(){
    nodo *listaCarrefour;
    nodo *listaDisco;
    nodo_mejor *listaMejor;

    crear_lista(&listaCarrefour);
    crear_lista(&listaDisco);
    crear_lista (&listaMejor);

    int seguir=1;

    printf("Bienvenido a Carrefour... \n");
    while(seguir){
        insertar_ordenado(&listaCarrefour,crear_nodo());

        printf("Desea comprar  productos en carrefour? 1-si/0-no\n");
        scanf("%d",&seguir);

    }

    seguir=1;
    printf("Bienvenido a Disco... \n");
    while(seguir){
        insertar_ordenado(&listaDisco,crear_nodo());
        printf("Desea comprar mas productos en Disco? 1-si/0-no\n");
        scanf("%d",&seguir);
    }


    //unir los datos de las 2 listas
    crearListaFinal(&listaMejor, listaCarrefour, listaDisco);
    /////////////////////////////////

    //imprimo ListaFinal
    imprimirListaFinal(listaMejor);
}










void crear_lista(nodo **lista){
    *lista=NULL;
}

nodo * crear_nodo(){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    printf("Ingrese el id del producto:\n");
    scanf("%d",&nuevo->id);
    printf("Ingrese el nombre del producto:\n");
    scanf("%s",nuevo->nombre);
    printf ("Ingrese el precio del producto:\n");
    scanf("%f",&nuevo->precio);
    return nuevo;
}

void insertar_ordenado(nodo **lista,nodo *nuevo){
    nodo *actual,*anterior;
    actual=*lista;
    anterior=NULL;
    while(actual!=NULL && (actual->id < nuevo->id)){
        anterior=actual;
        actual=actual->sig;
    }
    if(anterior!=NULL){ //insertar en el cuerpo
        anterior->sig=nuevo;
        nuevo->sig=actual;
    }
    else{ //insertar al inicio
        nuevo->sig=*lista;
        *lista=nuevo;
    }
}

//[1] -> [2] -> [3]

void crearListaFinal(nodo_mejor **listaMejor, nodo *listaCarrefour, nodo *listaDisco)
{
    nodo* base = listaDisco;
    //por cada nodo en carrefour:
    while(listaCarrefour!=NULL)
    {
        //por cada nodo en Disco
        listaDisco = base;
        while(listaDisco != NULL)
        {
            //caso coincide el producto
            if (listaCarrefour->id == listaDisco->id)
            {
                //si el de carrefour era mas barato
                if (listaCarrefour->precio <= listaDisco->precio)
                {
                    //agregarNodo en la lista final un nodo de Carrefour
                    agregarNodoMejor(&(*listaMejor), listaCarrefour, 0);
                }
                else
                {
                    //agregarNodo en la lista final un nodo de Disco
                    agregarNodoMejor(&(*listaMejor), listaDisco, 1);
                }

            }
            listaDisco = listaDisco->sig;
        }

        listaCarrefour = listaCarrefour->sig;
    }
};

void agregarNodoMejor(nodo_mejor **listaMejor, nodo* Nodolista, int nombreSuper)
{
    //creo un nodo de listaMejor y lo cargo con los datos del nodo de un super
    nodo_mejor *nuevo=(nodo_mejor*)malloc(sizeof(nodo_mejor));
    nuevo->id = Nodolista->id;
    nuevo->precio = Nodolista->precio;
    nuevo->sig = NULL;
    //selecciono el nombre
    switch (nombreSuper)
    {
    case 0:
        strcpy(nuevo->nombre, "Carrefour");
        break;
    case 1:
        strcpy(nuevo->nombre, "Disco");
        break;
    default:
        break;
    }
    //enpilar
    nuevo->sig = *listaMejor;
    *listaMejor = nuevo;
}

void imprimirListaFinal(nodo_mejor *listaMejor)
{

    while(listaMejor != NULL)
    {
        //impresion:
        printf("nombre Super:%s\n",listaMejor->nombre);
        printf("Producto:%d\n",listaMejor->id);
        printf("Precio:%.2f\n",listaMejor->precio);
        //

        listaMejor = listaMejor->sig;
    }
    return;
};
