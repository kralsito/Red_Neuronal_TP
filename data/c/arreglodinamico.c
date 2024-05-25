#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &n);

    // Asignación dinámica de memoria para el arreglo
    int *arreglo = (int *)malloc(n * sizeof(int));

    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    printf("Números ingresados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }

    // Liberar la memoria asignada
    free(arreglo);

    return 0;
}

