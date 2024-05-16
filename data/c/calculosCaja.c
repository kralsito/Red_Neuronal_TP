#include <stdio.h>

// Función para calcular el área de superficie de una caja
double calcularAreaSuperficie(double largo, double ancho, double alto) {
    return 2 * (largo * ancho + largo * alto + ancho * alto);
}

// Función para calcular el volumen de una caja
double calcularVolumen(double largo, double ancho, double alto) {
    return largo * ancho * alto;
}

int main() {
    double largo, ancho, alto;
    int opcion;
    int continuar = 1;

    while (continuar) {
        // Mostrar el menú de opciones
        printf("Seleccione una opción:\n");
        printf("1. Calcular el área de superficie de la caja\n");
        printf("2. Calcular el volumen de la caja\n");
        printf("3. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        if (opcion == 3) {
            continuar = 0;
            break;
        }

        // Solicitar al usuario las dimensiones de la caja
        printf("Ingrese el largo de la caja: ");
        scanf("%lf", &largo);
        printf("Ingrese el ancho de la caja: ");
        scanf("%lf", &ancho);
        printf("Ingrese el alto de la caja: ");
        scanf("%lf", &alto);

        // Realizar el cálculo basado en la opción seleccionada
        switch (opcion) {
            case 1:
                printf("El área de superficie de la caja es: %.2f\n", calcularAreaSuperficie(largo, ancho, alto));
                break;
            case 2:
                printf("El volumen de la caja es: %.2f\n", calcularVolumen(largo, ancho, alto));
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }

        // Preguntar si desea realizar otra operación
        printf("¿Desea realizar otra operación? (1: Sí, 0: No): ");
        scanf("%d", &continuar);
    }

    printf("Gracias por usar el programa.\n");
    return 0;
}
