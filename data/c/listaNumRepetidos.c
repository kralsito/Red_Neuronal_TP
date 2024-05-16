/*SE LEE UNA SECUENCIA DE NÚMEROS QUE SE ALMACENA EN UNA LISTA ENCADENADA.
 ADEMÁS SE LEE OTRO NÚMERO POR TECLADO. SE DESEA:
-DETERMINAR CUÁNTAS VECES APARECE ESE NÚMERO EN LA LISTA
-ELIMINARLO SI APARECE UNA SOLA VEZ, SI NO EXISTE IMPRIMIR UN MENSAJE INDICANDO ESTE HECHO.
*/


#include <stdio.h>
#include<stdlib.h>

typedef struct tipo_nodo{
    int valor;
    struct tipo_nodo *sig;

}nodo;

//funciones prototipo
void crear_lista(nodo **lista);
void inserar_ordenado(nodo **lista, int dato);
int contar(nodo **lista, int num);
void eliminar_nodo(nodo **lista, int dato);
void imprimir_lista(nodo *lista);

main(){
    int num,veces,numero;
    nodo *lista;
    crear_lista(&lista);
    //cuerpo del programa
    while(num!=0){

        printf("Ingrese un numero, 0 para terminar: \n");
        scanf("%d",&num);
    inserar_ordenado(&lista,num);

    }
    printf("Ingrese un numero para determinar si esta en la lista: \n");
    scanf("%d",&numero);
    veces=contar(lista,numero);
    if(veces==0){
            printf("El numero no esta en la lista \n");
    }

    else if(veces==1){
        eliminar_nodo(&lista,numero);
        printf("Numero eliminado, aparecia una vez\n");
    }
    else{
        printf("El numero aparecia %d veces\n",veces);
        printf("\n");

    }

    imprimir_lista(lista);

    system("pause");

}



void crear_lista(nodo **lista){
    *lista = NULL;
}

void inserar_ordenado(nodo **lista, int dato){
    nodo *actual;
    nodo *anterior;
    nodo *nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->valor=dato;
    nuevo->sig = NULL;
    actual=*lista;
    anterior=NULL;
    while(actual!=NULL && actual->valor<dato){
        anterior=actual;
        actual=actual->sig;
    }
    if (anterior!=NULL){ //inserto en el cuerpo
        anterior->sig=nuevo;
        nuevo->sig=actual;
    }
    else{ //inserto al inicio
        nuevo->sig=*lista;
        *lista=nuevo;
    }

}

int contar(nodo **lista,int num){
    int cuenta=0;
    nodo *aux;
    aux = lista;
    while(aux!=NULL){
        if(aux->valor==num)
            cuenta++;
        aux=aux->sig;
    }
    return cuenta;
}

void eliminar_nodo (nodo **lista, int dato){
    nodo *actual,*anterior;
    actual=*lista;
    anterior=NULL;
    while(actual!=NULL && actual->valor!=dato){
        anterior=actual;
        actual=actual->sig;
    }
    if(actual!=NULL){//dato encontrado
        if(anterior!=NULL){//borrar del cuerpo
                anterior->sig=actual->sig;
    }
    else{ //borrar del inicio
        *lista=actual->sig;
    }
    free(actual);

}
}

void imprimir_lista(nodo *lista){
    nodo *aux;
    aux= lista;
    printf("Imprimiendo lista...\n");
    while(aux!=NULL){

        printf("%d \n",aux->valor);
        aux=aux->sig;
    }
}
