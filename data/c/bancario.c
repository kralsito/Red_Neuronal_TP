#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    int id;
    char nombre[50];
    float saldo;
};

struct NodoCliente {
    struct Cliente cliente;
    struct NodoCliente* siguiente;
};

struct NodoCliente* listaClientes = NULL;

void abrirCuenta(struct Cliente cli) {
    struct NodoCliente* nuevoNodo = (struct NodoCliente*)malloc(sizeof(struct NodoCliente));
    nuevoNodo->cliente = cli;
    nuevoNodo->siguiente = NULL;

    if (listaClientes == NULL) {
        listaClientes = nuevoNodo;
    } else {
        struct NodoCliente* temp = listaClientes;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Cuenta abierta con éxito.\n");
}

void realizarDeposito(int id, float monto) {
    struct NodoCliente* temp = listaClientes;
    while (temp != NULL) {
        if (temp->cliente.id == id) {
            temp->cliente.saldo += monto;
            printf("Depósito realizado con éxito.\n");
            return;
        }
        temp = temp->siguiente;
    }
    printf("Cliente no encontrado.\n");
}

void realizarRetiro(int id, float monto) {
    struct NodoCliente* temp = listaClientes;
    while (temp != NULL) {
        if (temp->cliente.id == id) {
            if (temp->cliente.saldo >= monto) {
                temp->cliente.saldo -= monto;
                printf("Retiro realizado con éxito.\n");
                return;
            } else {
                printf("Saldo insuficiente para realizar el retiro.\n");
                return;
            }
        }
        temp = temp->siguiente;
    }
    printf("Cliente no encontrado.\n");
}

void consultarSaldo(int id) {
    struct NodoCliente* temp = listaClientes;
    while (temp != NULL) {
        if (temp->cliente.id == id) {
            printf("Saldo actual para %s: $%.2f\n", temp->cliente.nombre, temp->cliente.saldo);
            return;
        }
        temp = temp->siguiente;
    }
    printf("Cliente no encontrado.\n");
}

int main() {
    struct Cliente cli1 = {1, "Juan Pé
