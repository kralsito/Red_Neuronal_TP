#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    unsigned int semilla = time(NULL); // Obtener una semilla inicial
    unsigned int numAleatorio;

    for (int i = 0; i < 5; i++) {
        numAleatorio = rand_r(&semilla) % 50 + 10; // Genera un número entre 10 y 59
        printf("%u\n", numAleatorio);
    }

    return 0;
}


int main() {
    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios

    // Generar y mostrar 5 números aleatorios entre 1 y 100
    for (int i = 0; i < 5; i++) {
        int num = rand() % 100 + 1; // Genera un número entre 1 y 100
        printf("%d\n", num);
    }

    return 0;
}
