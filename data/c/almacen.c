#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int codigo;
    char nombre[50];
    int cantidad;
    float precio;
};

struct NodoProducto {
    struct Producto producto;
    struct NodoProducto* siguiente;
};

struct NodoProducto* inventario = NULL;

void agregarProducto(struct Producto prod) {
    struct NodoProducto* nuevoNodo = (struct NodoProducto*)malloc(sizeof(struct NodoProducto));
    nuevoNodo->producto = prod;
    nuevoNodo->siguiente = NULL;

    if (inventario == NULL) {
        inventario = nuevoNodo;
    } else {
        struct NodoProducto* temp = inventario;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Producto agregado al inventario.\n");
}

void realizarPedido(int codigo, int cantidad) {
    struct NodoProducto* temp = inventario;
    while (temp != NULL) {
        if (temp->producto.codigo == codigo) {
            if (temp->producto.cantidad >= cantidad) {
                temp->producto.cantidad -= cantidad;
                printf("Pedido realizado con éxito.\n");
                return;
            } else {
                printf("No hay suficiente stock para realizar el pedido.\n");
                return
