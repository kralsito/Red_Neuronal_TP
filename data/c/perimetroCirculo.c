#include<stdio.h>
#define pi 3.14

int main(){

    //variables:
    int radio;
    float perimetro;

    //Hacer:
    printf("Ingrese el radio n:");
    scanf("%d",&radio);
    perimetro = 2 * pi * radio;
    printf("El perimetro del circulo es : %f ", perimetro);
    return 0;


}
