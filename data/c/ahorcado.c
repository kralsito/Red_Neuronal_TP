#include <stdio.h>
#include <string.h>
#include <ctype.h>

void mostrarPalabra(char palabra[], int letrasAdivinadas[]) {
    for (int i = 0; i < strlen(palabra); i++) {
        if (letrasAdivinadas[i]) {
            printf("%c ", palabra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char palabraSecreta[] = "elefante";
    int letrasAdivinadas[strlen(palabraSecreta)];
    int intentosRestantes = 6;

    for (int i = 0; i < strlen(palabraSecreta); i++) {
        letrasAdivinadas[i] = 0;
    }

    printf("Bienvenido al juego Ahorcado!\n");
    printf("Tienes que adivinar la palabra secreta.\n");

    while (intentosRestantes > 0) {
        printf("Intentos restantes: %d\n", intentosRestantes);
        mostrarPalabra(palabraSecreta, letrasAdivinadas);

        char letra;
        printf("Introduce una letra: ");
        scanf(" %c", &letra);

        int acierto = 0;
        for (int i = 0; i < strlen(palabraSecreta); i++) {
            if (tolower(letra) == tolower(palabraSecreta[i])) {
                letrasAdivinadas[i] = 1;
                acierto = 1;
            }
        }

        if (!acierto) {
            intentosRestantes--;
            printf("Letra incorrecta.\n");
        }

        int completado = 1;
        for (int i = 0; i < strlen(palabraSecreta); i++) {
            if (!letrasAdivinadas[i]) {
                completado = 0;
                break;
            }
        }

        if (completado) {
