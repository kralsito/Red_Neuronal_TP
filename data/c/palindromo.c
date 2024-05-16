#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para eliminar caracteres no alfabéticos y convertir a minúsculas
void limpiarCadena(char* origen, char* destino) {
    int j = 0;
    for (int i = 0; origen[i] != '\0'; i++) {
        if (isalpha(origen[i])) {
            destino[j++] = tolower(origen[i]);
        }
    }
    destino[j] = '\0';
}

// Función para verificar si una cadena es un palíndromo
int esPalindromo(char* cadena) {
    int izquierda = 0;
    int derecha = strlen(cadena) - 1;

    while (izquierda < derecha) {
        if (cadena[izquierda] != cadena[derecha]) {
            return 0;
        }
        izquierda++;
        derecha--;
    }
    return 1;
}

int main() {
    char texto[100];
    char textoLimpio[100];

    // Solicitar al usuario que ingrese una cadena de texto
    printf("Ingrese una cadena de texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';  // Eliminar el salto de línea

    // Limpiar la cadena de caracteres no alfabéticos y convertir a minúsculas
    limpiarCadena(texto, textoLimpio);

    // Verificar si la cadena limpia es un palíndromo
    if (esPalindromo(textoLimpio)) {
        printf("\"%s\" es un palíndromo.\n", texto);
    } else {
        printf("\"%s\" no es un palíndromo.\n", texto);
    }

    return 0;
}
