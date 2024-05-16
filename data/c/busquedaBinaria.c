#include <stdio.h>

// Función que realiza la búsqueda binaria
int busquedaBinaria(int arr[], int tam, int objetivo) {
    int izquierda = 0;
    int derecha = tam - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Verificar si el objetivo está en el medio
        if (arr[medio] == objetivo) {
            return medio;
        }

        // Si el objetivo es mayor, ignorar la mitad izquierda
        if (arr[medio] < objetivo) {
            izquierda = medio + 1;
        }
        // Si el objetivo es menor, ignorar la mitad derecha
        else {
            derecha = medio - 1;
        }
    }

    // El objetivo no está presente en el arreglo
    return -1;
}

int main() {
    int tam, objetivo;

    // Solicitar al usuario el tamaño del arreglo
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    int arr[tam];

    // Solicitar al usuario los elementos del arreglo
    printf("Ingrese %d elementos en orden ascendente:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arr[i]);
    }

    // Solicitar al usuario el valor objetivo
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &objetivo);

    // Llamar a la función de búsqueda binaria
    int resultado = busquedaBinaria(arr, tam, objetivo);

    // Imprimir el resultado de la búsqueda
    if (resultado != -1) {
        printf("Elemento encontrado en el índice %d\n", resultado);
    } else {
        printf("Elemento no encontrado en el arreglo\n");
    }

    return 0;
}

