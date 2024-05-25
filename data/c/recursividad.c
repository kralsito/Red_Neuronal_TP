#include <stdio.h>

struct Factorial {
    int numero;
    unsigned long resultado;
};

unsigned long calcularFactorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * calcularFactorial(num - 1);
    }
}

int main() {
    struct Factorial fact;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &fact.numero);

    fact.resultado = calcularFactorial(fact.numero);
    printf("El factorial de %d es %lu\n", fact.numero, fact.resultado);

    return 0;
}
