#include <stdio.h>

// Función para convertir de Fahrenheit a Celsius
double fahrenheitACelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    double fahrenheit, celsius;
    int continuar = 1;

    while (continuar) {
        // Solicitar al usuario la temperatura en Fahrenheit
        printf("Ingrese la temperatura en Fahrenheit: ");
        scanf("%lf", &fahrenheit);

        // Realizar la conversión
        celsius = fahrenheitACelsius(fahrenheit);

        // Mostrar el resultado
        printf("La temperatura en Celsius es: %.2f\n", celsius);

        // Preguntar si desea realizar otra conversión
        printf("¿Desea realizar otra conversión? (1: Sí, 0: No): ");
        scanf("%d", &continuar);
    }

    printf("Gracias por usar el programa.\n");
    return 0;
}
