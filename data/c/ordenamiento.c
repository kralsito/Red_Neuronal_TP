#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void seleccion(int *arreglo, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[min]) {
                min = j;
            }
        }
        if (min != i) {
            intercambiar(&arreglo[i], &arreglo[min]);
        }
    }
}

int main() {
    int arreglo[] = {5, 2, 8, 1, 3};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Arreglo original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    seleccion(arreglo, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
