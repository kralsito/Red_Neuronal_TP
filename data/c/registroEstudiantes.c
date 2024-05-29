#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float calificacion;
};

// Función para ingresar la información de un estudiante
void ingresarInformacion(struct Estudiante* estudiante) {
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", estudiante->nombre);
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &estudiante->edad);
    printf("Ingrese la calificación del estudiante: ");
    scanf("%f", &estudiante->calificacion);
}

int main() {
    int numEstudiantes;

    // Solicitar al usuario el número de estudiantes
    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &numEstudiantes);

    // Crear un arreglo de estructuras para almacenar la información de los estudiantes
    struct Estudiante* estudiantes = (struct Estudiante*)malloc(numEstudiantes * sizeof(struct Estudiante));
    if (estudiantes == NULL) {
        printf("Error: No se pudo asignar memoria para los estudiantes.\n");
        exit(1);
    }

    // Ingresar la información de cada estudiante
    for (int i = 0; i < numEstudiantes; i++) {
        printf("\nIngresando información para el estudiante #%d:\n", i + 1);
        ingresarInformacion(&estudiantes[i]);
    }

    return 0;
}
