#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 1000

int main() {
    FILE *archivo;
    char linea[MAX_LINEA];
    char *token;
    int sumaEdades = 0;
    int contador = 0;

    archivo = fopen("personas.csv", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Ignoramos la primera línea que contiene los encabezados
    fgets(linea, MAX_LINEA, archivo);

    while (fgets(linea, MAX_LINEA, archivo)) {
        token = strtok(linea, ",");
        // token apunta al nombre (primera columna), no lo usamos en este ejemplo

        token = strtok(NULL, ",");
        if (token != NULL) {
            int edad = atoi(token); // Convertimos la cadena a entero
            sumaEdades += edad;
            contador++;
        }
    }

    fclose(archivo);

    if (contador > 0) {
        float promedioEdades = (float)sumaEdades / contador;
        printf("Promedio de edades: %.2f\n", promedioEdades);
    } else {
        printf("No se encontraron datos para calcular el promedio.\n");
    }

    return 0;
}
