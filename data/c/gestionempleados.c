#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Empleado {
    int id;
    char nombre[50];
    char departamento[50];
    float salario;
};

struct NodoEmpleado {
    struct Empleado empleado;
    struct NodoEmpleado* siguiente;
};

struct NodoEmpleado* listaEmpleados = NULL;

void agregarEmpleado(struct Empleado emp) {
    struct NodoEmpleado* nuevoNodo = (struct NodoEmpleado*)malloc(sizeof(struct NodoEmpleado));
    nuevoNodo->empleado = emp;
    nuevoNodo->siguiente = NULL;

    if (listaEmpleados == NULL) {
        listaEmpleados = nuevoNodo;
    } else {
        struct NodoEmpleado* temp = listaEmpleados;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    printf("Empleado agregado con éxito.\n");
}

void calcularSalario(int id) {
    struct NodoEmpleado* temp = listaEmpleados;
    while (temp != NULL) {
        if (temp->empleado.id == id) {
            float salarioTotal = temp->empleado.salario * 1.1; // Aumento del 10%
            printf("El salario total para %s del departamento %s es: $%.2f\n",
                   temp->empleado.nombre, temp->empleado.departamento, salarioTotal);
            return;
        }
        temp = temp->siguiente;
    }
    printf("No se encontró al empleado con ID %d.\n", id);
}

void mostrarEmpleadosPorDepartamento(char depto[]) {
    struct NodoEmpleado* temp = listaEmpleados;
    while (temp != NULL) {
        if (strcmp(temp->empleado.departamento, depto) == 0) {
            printf("ID: %d, Nombre: %s\n", temp->empleado.id, temp->empleado.nombre);
        }
        temp = temp->siguiente;
    }
}

int main() {
    struct Empleado emp1 = {1, "Juan Pérez", "Ventas", 2500.00};
    struct Empleado emp2 = {2, "María López", "Contabilidad", 3000.00};

    agregarEmpleado(emp1);
    agregarEmpleado(emp2);

    calcularSalario(1);
    mostrarEmpleadosPorDepartamento("Contabilidad");

    return 0;
}
