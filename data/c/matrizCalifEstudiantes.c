#include <stdio.h>
#include <stdlib.h>

#define MAX_ESTUDIANTES 50
#define MAX_ASIGNATURAS 5

// Función para ingresar las calificaciones de los estudiantes
void ingresarCalificaciones(float calificaciones[MAX_ESTUDIANTES][MAX_ASIGNATURAS], int numEstudiantes, int numAsignaturas) {
    for (int i = 0; i < numEstudiantes; i++) {
        printf("\nIngrese las calificaciones del estudiante #%d:\n", i + 1);
        for (int j = 0; j < numAsignaturas; j++) {
            printf("Calificación en la asignatura #%d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
}

// Función para calcular el promedio de calificaciones de los estudiantes
void calcularPromedio(float calificaciones[MAX_ESTUDIANTES][MAX_ASIGNATURAS], int numEstudiantes, int numAsignaturas, float promedio[MAX_ESTUDIANTES]) {
    for (int i = 0; i < numEstudiantes; i++) {
        float suma = 0;
        for (int j = 0; j < numAsignaturas; j++) {
            suma += calificaciones[i][j];
        }
        promedio[i] = suma / numAsignaturas;
    }
}

// Función para mostrar las calificaciones y el promedio de cada estudiante
void mostrarResultados(float calificaciones[MAX_ESTUDIANTES][MAX_ASIGNATURAS], float promedio[MAX_ESTUDIANTES], int numEstudiantes, int numAsignaturas) {
    printf("\nCalificaciones de los estudiantes:\n");
    for (int i = 0; i < numEstudiantes; i++) {
        printf("\nEstudiante #%d:\n", i + 1);
        for (int j = 0; j < numAsignaturas; j++) {
            printf("Asignatura #%d: %.2f\n", j + 1, calificaciones[i][j]);
        }
        printf("Promedio: %.2f\n", promedio[i]);
    }
}

int main() {
    int numEstudiantes, numAsignaturas;
    float calificaciones[MAX_ESTUDIANTES][MAX_ASIGNATURAS];
    float promedio[MAX_ESTUDIANTES];

    // Solicitar al usuario el número de estudiantes y el número de asignaturas
    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &numEstudiantes);
    printf("Ingrese el número de asignaturas: ");
    scanf("%d", &numAsignaturas);

    // Ingresar las calificaciones de los estudiantes
    ingresarCalificaciones(calificaciones, numEstudiantes, numAsignaturas);

    // Calcular el promedio de calificaciones de los estudiantes
    calcularPromedio(calificaciones, numEstudiantes, numAsignaturas, promedio);

    // Mostrar las calificaciones y el promedio de cada estudiante
    mostrarResultados(calificaciones, promedio, numEstudiantes, numAsignaturas);

    return 0;
}
