#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libro {
    char titulo[100];
    char autor[50];
    int anio;
};

struct Nodo {
    struct Libro libro;
    struct Nodo* siguiente;
};

struct Nodo* biblioteca = NULL;

void agregarLibro() {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    printf("Ingrese el título del libro: ");
    scanf(" %[^\n]", nuevoNodo->libro.titulo);
    printf("Ingrese el autor del libro: ");
    scanf(" %[^\n]", nuevoNodo->libro.autor);
    printf("Ingrese el año de publicación del libro: ");
    scanf("%d", &nuevoNodo->libro.anio);
    nuevoNodo->siguiente = NULL;

    if (biblioteca == NULL) {
        biblioteca = nuevoNodo;
    } else {
        struct Nodo* temp = biblioteca;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Libro agregado con éxito.\n");
}

void buscarLibro(char clave[]) {
    struct Nodo* temp = biblioteca;
    int encontrado = 0;
    while (temp != NULL) {
        if (strstr(temp->libro.titulo, clave) != NULL || strstr(temp->libro.autor, clave) != NULL) {
            printf("Título: %s\n", temp->libro.titulo);
            printf("Autor: %s\n", temp->libro.autor);
            printf("Año: %d\n", temp->libro.anio);
            encontrado = 1;
        }
        temp = temp->siguiente;
    }
    if (!encontrado) {
        printf("No se encontraron libros con la clave especificada.\n");
    }
}

void mostrarLibros() {
    struct Nodo* temp = biblioteca;
    if (temp == NULL) {
        printf("No hay libros en la biblioteca.\n");
    } else {
        while (temp != NULL) {
            printf("Título: %s\n", temp->libro.titulo);
            printf("Autor: %s\n", temp->libro.autor);
            printf("Año: %d\n", temp->libro.anio);
            temp = temp->siguiente;
        }
    }
}

int main() {
    int opcion;
    char clave[100];

    do {
        printf("\n1. Agregar libro\n2. Buscar libro\n3. Mostrar todos los libros\n4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarLibro();
                break;
            case 2:
                printf("Ingrese el título o autor a buscar: ");
                scanf(" %[^\n]", clave);
                buscarLibro(clave);
                break;
            case 3:
                mostrarLibros();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
