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

