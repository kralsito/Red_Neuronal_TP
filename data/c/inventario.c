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
                return;
            }
        }
        temp = temp->siguiente;
    }
    printf("Producto no encontrado en el inventario.\n");
}

void mostrarInventario() {
    struct NodoProducto* temp = inventario;
    while (temp != NULL) {
        printf("Código: %d, Nombre: %s, Cantidad: %d, Precio: $%.2f\n",
               temp->producto.codigo, temp->producto.nombre, temp->producto.cantidad, temp->producto.precio);
        temp = temp->siguiente;
    }
}

int main() {
    struct Producto prod1 = {1, "Camiseta", 100, 19.99};
    struct Producto prod2 = {2, "Pantalón", 50, 29.99};

    agregarProducto(prod1);
    agregarProducto(prod2);

    realizarPedido(1, 5);
    realizarPedido(2, 75);

    mostrarInventario();

    return 0;
}
