#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int obtenerMovimientoComputadora() {
    srand(time(NULL));
    return rand() % 3;
}

int main() {
    char* opciones[] = {"Piedra", "Papel", "Tijeras"};
    int movimientoUsuario, movimientoComputadora;

    printf("Bienvenido al juego Piedra, Papel, Tijeras!\n");
    printf("0 - Piedra, 1 - Papel, 2 - Tijeras\n");

    printf("Elige tu movimiento: ");
    scanf("%d", &movimientoUsuario);

    if (movimientoUsuario < 0 || movimientoUsuario > 2) {
        printf("Movimiento no válido. Inténtalo de nuevo.\n");
        return 1;
    }

    movimientoComputadora = obtenerMovimientoComputadora();

    printf("Tu eliges %s.\n", opciones[movimientoUsuario]);
    printf("La computadora elige %s.\n", opciones[movimientoComputadora]);

    if (movimientoUsuario == movimientoComputadora) {
        printf("Empate!\n");
    } else if ((movimientoUsuario == 0 && movimientoComputadora == 2) ||
               (movimientoUsuario == 1 && movimientoComputadora == 0) ||
               (movimientoUsuario == 2 && movimientoComputadora == 1)) {
        printf("¡Ganaste!\n");
    } else {
        printf("¡Perdiste!\n");
    }

    return 0;
}
