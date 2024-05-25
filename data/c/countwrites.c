#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalabras(const char *linea) {
    int palabras = 0;
    int longitud = strlen(linea);
    int i, dentroPalabra = 0;

    for (i = 0; i < longitud; i++) {
        if (linea[i] == ' ' || linea[i] == '\t' || linea[i] == '\n') {
            dentroPalabra = 0;
        } else if (!dentroPalabra) {
            dentroPalabra = 1;
            palabras++;
        }
    }

    return palabras;
}

int main() {
    FILE *archivo;
    char linea[1000];
    int totalPalabras = 0;

    archivo = fopen("texto.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fgets(linea, sizeof(linea), archivo)) {
        int palabrasLinea = contarPalabras(linea);
        totalPalabras += palabrasLinea;
        printf("Palabras en línea: %d\n", palabrasLinea);
    }

    fclose(archivo);

    printf("Total de palabras en el archivo: %d\n", totalPalabras);

    return 0;
}
