#include <stdio.h>

int main() {
    FILE* archivo = fopen("datos.txt", "w");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Hola, mundo!\n");
    fprintf(archivo, "Este es un archivo de prueba.\n");
    fclose(archivo);

    char linea[100];
    archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo.\n");
        return 1;
    }

    printf("Contenido del archivo:\n");
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
    return 0;
}
