#include <stdio.h>

int main() {
    int suma = 0;

    for (int i = 1; i <= 10; i++) {
        suma += i;
    }

    printf("La suma de los números del 1 al 10 es: %d\n", suma);

    return 0;
}
