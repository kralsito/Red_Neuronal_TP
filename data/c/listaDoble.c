#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista doblemente enlazada
struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al principio de la lista
void insertarAlInicio(struct Nodo** cabeza, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevoNodo;
        *cabeza = nuevoNodo;
    }
    printf("Se ha insertado %d al inicio de la lista.\n", dato);
}

// Función para mostrar la lista de principio a fin
void mostrarLista(struct Nodo* cabeza) {
    printf("Contenido de la lista (de izquierda a derecha): ");
    while (cabeza != NULL) {
        printf("%d ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("\n");
}

// Función principal
int main() {
    struct Nodo* cabeza = NULL;

    // Insertar algunos elementos al principio de la lista
    insertarAlInicio(&cabeza, 10);
    insertarAlInicio(&cabeza, 20);
    insertarAlInicio(&cabeza, 30);

    // Mostrar la lista
    mostrarLista(cabeza);

    // Liberar memoria al final del programa
    while (cabeza != NULL) {
        struct Nodo* nodoAEliminar = cabeza;
        cabeza = cabeza->siguiente;
        free(nodoAEliminar);
    }

    return 0;
}
