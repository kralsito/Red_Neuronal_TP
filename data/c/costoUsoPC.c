#include<stdio.h>

#define COSTO_POR_MINUTO 10
#define COSTO_POR_HOJA 15

/*EJERCICIO 2: UN CIBER COBRA $10 EL MINUTO DE USO DE UNA COMPUTADORA CON CONEXIÓN A INTERNET, Y $15 LA HOJA IMPRESA.
EXISTE UN CARGO ADICIONAL CONSISTENTE EN $5 * X, SIENDO X EL 1% DEL TIEMPO UTILIZADO, EN CONCEPTO DE SEGURO. SE QUIERE
IMPRIMIR EL RECIBO DE USO DE UN CLIENTE, EN EL QUE SE DETALLEN TODOS LOS CONCEPTOS. */

int main(){
    // Variables
    float tiempo, seguro, precio_min, precio_hojas, total;
    int cant_hojas;

    // Solicitar al usuario la cantidad de tiempo utilizado y la cantidad de hojas impresas
    printf("Ingrese el tiempo de uso en minutos: ");
    scanf("%f", &tiempo);
    printf("Ingrese la cantidad de hojas impresas: ");
    scanf("%d", &cant_hojas);

    // Calcular el costo de uso de la computadora, el seguro y el costo total
    precio_min = tiempo * COSTO_POR_MINUTO;
    precio_hojas = cant_hojas * COSTO_POR_HOJA;
    seguro = (tiempo / 100) * 5;
    total = precio_min + precio_hojas + seguro;

    // Imprimir el recibo detallado
    printf("\nRECIBO DE USO DE LA COMPUTADORA\n");
    printf("-------------------------------\n");
    printf("Tiempo de uso (internet): $%.2f\n", precio_min);
    printf("Costo de hojas impresas: $%.2f\n", precio_hojas);
    printf("Cargo adicional por seguro: $%.2f\n", seguro);
    printf("-------------------------------\n");
    printf("TOTAL: $%.2f\n", total);

    return 0;
}
