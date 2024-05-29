/*2. EN UNA ESCUELA PRIMARIA SE HA PEDIDO A LOS ALUMNOS QUE DONEN
UN LIBRO PARA ARMAR UNA BIBLIOTECA. SE DESEA:
INCORPORAR LOS DATOS DE LOS LIBROS A UNA LISTA, EN FORMA ORDENADA.
-LA INFORMACI�N CORRESPONDIENTE A CADA LIBRO ES: T�TULO, G�NERO,
AUTOR, TEMA, EDITORIAL.
-INFORMAR LA CANTIDAD DE F�BULAS Y CUENTOS INFANTILES DONADOS.
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
}
