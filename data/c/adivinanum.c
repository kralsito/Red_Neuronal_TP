#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numeroSecreto = rand() % 100 + 1;
    int intentos = 0;
    int intentoUsuario;

    printf("Bienvenido al juego Adivina el Número!\n");
    printf("Tienes que adivinar un número entre 1 y 100.\n");

    do {
        printf("Introduce tu número: ");
        scanf("%d", &intentoUsuario);
        intentos++;

        if (intentoUsuario > numeroSecreto) {
            printf("Demasiado alto. Intenta de nuevo.\n");
        } else if (intentoUsuario < numeroSecreto) {
            printf("Demasiado bajo. Intenta de nuevo.\n");
        }
    } while (intentoUsuario != numeroSecreto);

    printf("¡Felicidades! Has adivinado el número en %d intentos.\n", intentos);

    return 0;
}
