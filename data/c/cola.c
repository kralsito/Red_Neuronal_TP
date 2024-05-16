#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la cola
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Definición de la estructura de la cola
struct Cola {
    struct Nodo* frente;
    struct Nodo* final;
};

// Función para crear una nueva cola vacía
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    if (cola == NULL) {
        printf("Error: No se pudo asignar memoria para la cola.\n");
        exit(1);
    }
    cola->frente = NULL;
    cola->final = NULL;
    return cola;
}

// Función para verificar si la cola está vacía
int colaVacia(struct Cola* cola) {
    return cola->frente == NULL;
}

// Función para encolar un elemento en la cola
void encolar(struct Cola* cola, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (colaVacia(cola)) {
        cola->frente = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
    }
    cola->final = nuevoNodo;
    printf("Se ha encolado el elemento %d.\n", dato);
}

// Función para desencolar un elemento de la cola
int desencolar(struct Cola* cola) {
    if (colaVacia(cola)) {
        printf("Error: La cola está vacía, no se puede desencolar.\n");
        exit(1);
    }
    int dato = cola->frente->dato;
    struct Nodo* nodoAEliminar = cola->frente;
    cola->frente = cola->frente->siguiente;
    free(nodoAEliminar);
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    return dato;
}

// Función para mostrar el primer elemento de la cola
int primerElemento(struct Cola* cola) {
    if (colaVacia(cola)) {
        printf("Error: La cola está vacía, no hay elementos para mostrar.\n");
        exit(1);
    }
    return cola->frente->dato;
}

// Función principal
int main() {
    // Crear una cola vacía
    struct Cola* cola = crearCola();

    // Encolar algunos elementos
    encolar(cola, 10);
    encolar(cola, 20);
    encolar(cola, 30);

    // Mostrar el primer elemento de la cola
    printf("Primer elemento de la cola: %d\n", primerElemento(cola));

    // Desencolar algunos elementos y mostrarlos
    printf("Elemento desencolado: %d\n", desencolar(cola));
    printf("Elemento desencolado: %d\n", desencolar(cola));
    printf("Elemento desencolado: %d\n", desencolar(cola));

    // Intentar desencolar un elemento cuando la cola está vacía
    // Esto debería mostrar un mensaje de error y terminar el programa
    // printf("Elemento desencolado: %d\n", desencolar(cola));

    // Liberar memoria al final del programa
    free(cola);

    return 0;
}
