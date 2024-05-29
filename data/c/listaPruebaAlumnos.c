/*Suponer que se inscriben un conjunto de alumnos en una competencia de destreza f�sica.
Cada alumno se inscribe indica su nombre y su numero de participante.
Simular el proceso de inscripci�n de los alumnos y luego simular la finalizaci�n de la prueba
ingresando de cada alumno que la termina cu�l es el orden de llegada. El alumno que
abandona, no se ingresa informaci�n de llegada.
Obtener e imprimir la lista de inscriptos, el total de inscriptos, el porcentaje de alumnos que
terminaron la prueba.
Definir un algoritmo recursivo que permita imprimir el listado de alumnos indicando el puesto
obtenido de cada uno de ellos.
Datos de entrada:
De cada participante conocemos su nombre y su n�mero
No se sabe cuantos participantes se van a anotar
De la simulaci�n de llegada o finalizaci�n de la prueba, no sabemos cu�ntos participantes la
terminan. De cada participante que termina la prueba se ingresa su n�mero y el puesto u
orden en que lleg�.*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct participante{
        char nombre[20];
        int num;
        int puesto;
};
struct Lista
{
struct participante dato;
struct Lista *ps;
};
struct Lista *pin, *aux;
struct participante regpar;
void insertar ( struct Lista **L, struct participante p);
void imprimir ( struct Lista *L);
void impriRec ( struct Lista *L);

int main()
{
char resp;
int nume, pues;
int cantp=0;
int final=0;
float porc;
pin=NULL;
printf ("\nHay participante a inscribir?s/n");
scanf(" %s",&resp);
while (resp != 'n')
{
printf ("ingrese nombre del participante ");
scanf(" %s",regpar.nombre);
printf ("ingrese numero del participante ");
scanf("%d",&regpar.num);
regpar.puesto=0;
insertar (&pin, regpar);
cantp++;
printf ("\nHay participante a inscribir?s/n");
scanf(" %s",&resp);
}
imprimir(pin);
printf("\nTotal de inscriptos %d ", cantp );
printf ("\nLleg� aprticipante?s/n");
scanf(" %s",&resp);
}