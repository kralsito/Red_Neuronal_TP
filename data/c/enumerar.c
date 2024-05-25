#include <stdio.h>

enum Dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES };

int main() {
    enum Dia dia = MARTES;

    switch (dia) {
        case LUNES:
            printf("Es lunes.\n");
            break;
        case MARTES:
            printf("Es martes.\n");
            break;
        case MIERCOLES:
            printf("Es miércoles.\n");
            break;
        case JUEVES:
            printf("Es jueves.\n");
            break;
        case VIERNES:
            printf("Es viernes.\n");
            break;
        default:
            printf("Día no válido.\n");
            break;
    }

    return 0;
}
