#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int codigo;
    char nombre[100];
    float precio;
};

struct NodoProducto {
    struct Producto producto;
    int cantidad;
    struct NodoProducto* siguiente;
};

struct NodoProducto* carrito = NULL;
struct NodoProducto* historialCompras = NULL;

void agregarProductoCarrito(struct Producto prod, int cantidad) {
    struct NodoProducto* nuevoNodo = (struct NodoProducto*)malloc(sizeof(struct NodoProducto));
    nuevoNodo->producto = prod;
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->siguiente = NULL;

    if (carrito == NULL) {
        carrito = nuevoNodo;
    } else {
        struct NodoProducto* temp = carrito;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Producto agregado al carrito.\n");
}

void realizarCompra() {
    if (carrito == NULL) {
        printf("El carrito está vacío. No se puede realizar la compra.\n");
    } else {
        float total = 0;
        struct NodoProducto* temp = carrito;
        while (temp != NULL) {
            total += temp->producto.precio * temp->cantidad;
            temp = temp->siguiente;
        }

        printf("Total a pagar: $%.2f\n", total);

        // Mover productos del carrito al historial de compras
        while (carrito != NULL) {
            struct NodoProducto* temp = carrito;
            carrito = carrito->siguiente;
            temp->siguiente = historialCompras;
            historialCompras = temp;
        }

        printf("Compra realizada con éxito. Gracias por su compra.\n");
    }
}

void mostrarHistorialCompras() {
    struct NodoProducto* temp = historialCompras;
    if (temp == NULL) {
        printf("No hay historial de compras.\n");
    } else {
        printf("Historial de compras:\n");
        while (temp != NULL) {
            printf("Producto: %s, Cantidad: %d, Precio unitario: $%.2f\n",
                   temp->producto.nombre, temp->cantidad, temp->producto.precio);
            temp = temp->siguiente;
        }
    }
}

int main() {
    struct Producto producto1 = {1, "Camiseta", 19.99};
    struct Producto producto2 = {2, "Pantalón", 29.99};
    struct Producto producto3 = {3, "Zapatos", 49.99};

    agregarProductoCarrito(producto1, 2);
    agregarProductoCarrito(producto2, 1);
    agregarProductoCarrito(producto3, 1);

    realizarCompra();
    mostrarHistorialCompras();

    return 0;
}
