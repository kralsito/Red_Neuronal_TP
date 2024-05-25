#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vuelo {
    int numeroVuelo;
    char origen[50];
    char destino[50];
    int plazasDisponibles;
};

struct NodoVuelo {
    struct Vuelo vuelo;
    struct NodoVuelo* siguiente;
};

struct NodoVuelo* listaVuelos = NULL;

void agregarVuelo(struct Vuelo v) {
    struct NodoVuelo* nuevoNodo = (struct NodoVuelo*)malloc(sizeof(struct NodoVuelo));
    nuevoNodo->vuelo = v;
    nuevoNodo->siguiente = NULL;

    if (listaVuelos == NULL) {
        listaVuelos = nuevoNodo;
    } else {
        struct NodoVuelo* temp = listaVuelos;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Vuelo agregado con éxito.\n");
}

void reservarVuelo(int numVuelo) {
    struct NodoVuelo* temp = listaVuelos;
    while (temp != NULL) {
        if (temp->vuelo.numeroVuelo == numVuelo) {
            if (temp->vuelo.plazasDisponibles > 0) {
                temp->vuelo.plazasDisponibles--;
                printf("Reserva realizada con éxito.\n");
                return;
            } else {
                printf("
