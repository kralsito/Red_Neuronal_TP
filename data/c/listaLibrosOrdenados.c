/*2. EN UNA ESCUELA PRIMARIA SE HA PEDIDO A LOS ALUMNOS QUE DONEN
UN LIBRO PARA ARMAR UNA BIBLIOTECA. SE DESEA:
INCORPORAR LOS DATOS DE LOS LIBROS A UNA LISTA, EN FORMA ORDENADA.
-LA INFORMACIÓN CORRESPONDIENTE A CADA LIBRO ES: TÍTULO, GÉNERO,
AUTOR, TEMA, EDITORIAL.
-INFORMAR LA CANTIDAD DE FÁBULAS Y CUENTOS INFANTILES DONADOS.
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipo_nodo{
    char titulo[20];
    char genero[20];
    char autor[20];
    char tema[10];
    char editorial[15];
    struct tipo_nodo *sig;

}nodo;

//funciones prototipo


void crear_lista(nodo **lista);
int comparar_cadenas_1(char s[],char t[]);
void insertar_ordenado(nodo **lista);

main(){
    int seguir=1;
    int fabula=0, cuento_inf=0;
    char f[15]="fabula";
    char ci[15]="cuento_inf";
    nodo *lista, *aux;
    crear_lista(&lista);
    //cuerpo del programa
    while(seguir){
        insertar_ordenado(&lista);
        printf("Ingrese 1 si quiere ingresar mas libros, 0 para salir...\n ");
        scanf("%d",&seguir);

    }
    aux=lista;
    while(aux!=NULL){
        if(strcmp(aux->genero,f)==0){
            fabula++;
        }
        if(strcmp(aux->genero,ci)==0){
            cuento_inf++;
        }
        aux=aux->sig;
    }

    printf("Hay %d fabulas y %d cuentos infantiles \n",fabula,cuento_inf);
    system("pause");

}

void crear_lista(nodo **lista){
    *lista=NULL;
}

void insertar_ordenado(nodo **lista){
        nodo *actual, *anterior;
        nodo *nuevo=(nodo *)malloc(sizeof(nodo));
        printf("Ingrese el titulo del libro: \n ");
        scanf("%s",nuevo->titulo);
        printf("Ingrese el genero del libro: \n ");
        scanf("%s",nuevo->genero);
        printf("Ingrese el autor del libro: \n ");
        scanf("%s",nuevo->autor);
        printf("Ingrese el tema del libro: \n ");
        scanf("%s",nuevo->tema);
        printf("Ingrese el editorial del libro: \n ");
        scanf("%s",nuevo->editorial);
        printf("\n");
        actual=*lista;
        anterior=NULL;
        while(actual!=NULL && strcmp(actual->titulo,nuevo->titulo)<0){
            anterior=actual;
            actual=actual->sig;
        }
        if(anterior!=NULL){//inserto en el cuerpo
            anterior->sig=nuevo;
            nuevo->sig=actual;
        }
        else{ //insrto al inicio
            nuevo->sig=*lista;
            *lista=nuevo;
        }
}
