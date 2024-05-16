/*Suponer que se inscriben un conjunto de alumnos en una competencia de destreza física.
Cada alumno se inscribe indica su nombre y su numero de participante.
Simular el proceso de inscripción de los alumnos y luego simular la finalización de la prueba
ingresando de cada alumno que la termina cuál es el orden de llegada. El alumno que
abandona, no se ingresa información de llegada.
Obtener e imprimir la lista de inscriptos, el total de inscriptos, el porcentaje de alumnos que
terminaron la prueba.
Definir un algoritmo recursivo que permita imprimir el listado de alumnos indicando el puesto
obtenido de cada uno de ellos.
Datos de entrada:
De cada participante conocemos su nombre y su número
No se sabe cuantos participantes se van a anotar
De la simulación de llegada o finalización de la prueba, no sabemos cuántos participantes la
terminan. De cada participante que termina la prueba se ingresa su número y el puesto u
orden en que llegó.*/

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
printf ("\nLlegó aprticipante?s/n");
scanf(" %s",&resp);
while (resp != 'n')
{
printf ("ingrese numero del participante ");
scanf("%d",&nume);
printf ("ingrese puesto de llegada del participante ");
scanf("%d",&pues);
final++;
aux=pin;
while ( aux != NULL)
{
if ( aux->dato.num == nume)
{
aux ->dato.puesto=pues;
}
aux= aux -> ps;
}
printf ("\nllegó otro participante ?s/n");
scanf(" %s",&resp);

}
porc=final*100/cantp;
printf("\n Porcentaje de alumnos que finalizaron la prueba %f ", porc );
impriRec (pin);
return 0;
}
void insertar ( struct Lista **L, struct participante par)
{
struct Lista *nuevo=malloc(sizeof(struct Lista));
nuevo->dato=par;
nuevo->ps=*L;
*L=nuevo;
}
void imprimir ( struct Lista *L)
{
struct Lista *aux;
printf("\n ********************************");
printf("\n listado de participantes inscriptos");
aux=L;
while (aux != NULL)
{
printf ("\nNombre: ");
printf( "%s",aux->dato.nombre);
printf(" Numero: ");
printf("%d",aux->dato.num);
aux=aux->ps;
}
}
void impriRec ( struct Lista *L)
{
if (L != NULL)
{
if( aux->dato.puesto !=0)
{
printf ("\nNombre: ");
printf( "%s",aux->dato.nombre);
printf(" Puesto: ");
printf("%d",aux->dato.puesto);
}
impriRec(aux->ps);
}
}
