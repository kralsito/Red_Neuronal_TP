#include <stdio.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main() {
    int a = 10;
    int b = 15;

    int maximo = MAX(a, b);
    printf("El máximo entre %d y %d es %d.\n", a, b, maximo);

    return 0;
}
