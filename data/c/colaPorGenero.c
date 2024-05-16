/*1. Se tiene una cola donde los hombres son muy traviesos, es por esto que
 se ordena dividir la cola en una de hombres y una de mujeres.
  Escriba un programa que haga esto.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct tipo_nodo{
	char sexo;
	struct tipo_nodo *sig;
}nodo;

typedef struct tipo_cola{
	nodo *primero, *ultimo;
}t_cola;

/*Funciones prototipo*/
void crear_cola(t_cola *cola);
void encolar(t_cola *cola, char sexo);
char desencolar(t_cola *cola);
int cola_vacia(t_cola cola);

main(){
	int mas_personas=1;
	char sexo;
	t_cola cola_orig, cola_M, cola_F;
	crear_cola(&cola_orig);
	crear_cola(&cola_M);
	crear_cola(&cola_F);
	/*Cuerpo del programa*/
	while(mas_personas){
		printf("\n Ingrese el sexo de la siguiente persona (M/F): \n");
		scanf(" %c", &sexo);
		encolar(&cola_orig, sexo);
		printf(" Encolar mas peronas? 1 para SI, 0 para NO \n");
		scanf(" %d", &mas_personas);
	}
	while(!cola_vacia(cola_orig)){ //compruebo que no esta vacia para desencolar
		sexo=desencolar(&cola_orig); //sexo va a ser M o F porque me retorna un char
		if(sexo=='M' || sexo=='m')
			encolar(&cola_M, sexo);
		else
			encolar(&cola_F, sexo);
	}
	printf("\n Cola de hombres: \n");
	while(!cola_vacia(cola_M))
		printf("%c-", desencolar(&cola_M));
	printf("\n Cola de mujeres: \n");
	while(!cola_vacia(cola_F))
		printf("%c-", desencolar(&cola_F));
	printf("\n");
	system("pause");
}

/*Definición de funciones*/
void crear_cola(t_cola *cola){
	cola->primero=NULL;
	cola->ultimo=NULL;
}
void encolar(t_cola *cola, char sexo){
	nodo *nuevo=(nodo *)malloc(sizeof(nodo));
	nuevo->sexo=sexo;
	nuevo->sig=NULL;
	if(cola->primero==NULL){
		cola->primero=nuevo;
		cola->ultimo=nuevo;
	}else{
		cola->ultimo->sig=nuevo;
		cola->ultimo=nuevo;
	}
}
/*Antes de invocar a descencolar debe
verificarse que la cola no este vacia*/
char desencolar(t_cola *cola){
	char sexo;
	nodo *aux;
	aux=cola->primero;
	cola->primero=aux->sig;
	sexo=aux->sexo;
	free(aux);
	return sexo; // me devuelve M o F
}
int cola_vacia(t_cola cola){
	if(cola.primero==NULL)
		return 1;
	else
		return 0;
}

