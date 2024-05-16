/*1. Lea una palabra e imprima un mensaje indicando si es pal�ndromo o no.
 Use pilas. Una palabra es pal�ndromo cuando se lee igual hacia adelante
 que hacia atr�s. Ejemplo: oso, radar, reconocer, rotor, seres, somos, etc. */

#include<stdio.h>
#include<stdlib.h>

typedef struct tipo_nodo{
    char letra;
    struct tipo_nodo *sig;
} nodo;

/*Funciones prototipo*/
void crear_pila(nodo **pila);
void apilar(nodo **pila, char letra);
int desapilar(nodo **pila);
int pila_vacia(nodo *pila);


main()
{
    int palindromo=1;
    nodo *pila;
    int i=0;
    char palabra[20];
    crear_pila(&pila);
    printf("Ingrese una palabra: \n");
    scanf("%s", palabra);
    while(palabra[i]!='\0')
        apilar(&pila, palabra[i++]);
    i=0;
    while(palabra[i]!='\0'){
         if(desapilar(&pila)!=palabra[i])
        {
            palindromo=0;
            break;
        }
        i++;
    }

    if(palindromo)
        printf("\n La palabra es palindromo");
    else
        printf("\n La palabra NO es palindromo");
    system("pause");
}
/*Definici�n de funciones*/
void crear_pila(nodo **pila)
{
    *pila=NULL;
}
void apilar(nodo **pila, char letra)
{
    nodo *nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->letra=letra;
    nuevo->sig=*pila;
    *pila=nuevo;
}

int desapilar(nodo **pila)
{
    char letra;
    nodo *aux;
    aux=*pila;
    *pila=aux->sig;
    letra=aux->letra;
    free(aux);
    return letra;
}
int pila_vacia(nodo *pila)
{
    if(pila==NULL)
        return 1;
    else
        return 0;
}
