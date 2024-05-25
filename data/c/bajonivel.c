#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buffer[100];
    int file = open("archivo.txt", O_RDONLY);
    if (file == -1) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    ssize_t bytesLeidos = read(file, buffer, sizeof(buffer));
    if (bytesLeidos == -1) {
        perror("Error al leer el archivo");
        exit(EXIT_FAILURE);
    }

    printf("Contenido del archivo:\n%s\n", buffer);
    close(file);
    return 0;
}
