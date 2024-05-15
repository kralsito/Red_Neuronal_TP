#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define BUFFERSIZE 3 // tamano del buffer 

/* Variables globales */

pthread_mutex_t candado; //mutex de acceso compartido al buffer
pthread_cond_t producido; // condicion de llenado del buffer
pthread_cond_t consumido; // condicion de vaciado del buffer
char buffer[BUFFERSIZE]; //buffer comun
int contador; //numero de elementos en el buffer
int entrada;
int salida;
int posFrase;
int posLlave;
int producidos;
int consumidos;
FILE *file;
FILE *cesar;
char *llave;
char dato;
static char *archivo;

/* Declaracion de Metodos */

void getElement(void);
void putElement(void);
void init();
int readChar(FILE *file);
void writeChar(FILE *Cesar, char dato);
int getTamFile(FILE *file);
char * substract(char *s);

/* Implementacion de Metodos */

char * substract(char *s) {
  int len = strlen(s);
  char buf[len-1];
  int i;
  for(i = 0; i < len-6; i++){
    buf[i] = s[i];
  }
  buf[i] = 0;
    return strdup(buf);
}

void writeChar(FILE *Cesar, char dato) {
  fprintf(Cesar, "%c", dato);
}

int readChar(FILE *file) {
  return fgetc(file);
}

int getTamFile(FILE *file) {
  fseek(file, 0, SEEK_END);
  int aux = ((ftell(file)));
  fseek(file, 0, SEEK_SET);
  return aux;
}

void init() {
  printf("Inicializando Variables \n");
  entrada = 0;
  salida = 0;
  contador = 0;
  posLlave = 0;
  consumidos = getTamFile(file);
  producidos = getTamFile(file);

  pthread_mutex_init(&candado, NULL);
  pthread_cond_init(&producido, NULL);
  pthread_cond_init(&consumido, NULL);
}

void getElement(void) {
  while (consumidos != 0) {
    pthread_mutex_lock(&candado);
    while (contador == 0) {//buf vacio
      pthread_cond_wait(&producido, &candado); //esperando
    }
    if (consumidos > 0) {
      char dato = buffer[salida];
      salida = (salida + 1) % BUFFERSIZE;
      contador = contador - 1;
      consumidos = consumidos > 0 ? (consumidos - 1) : 0;

      writeChar(cesar, dato);
    }
    pthread_mutex_unlock(&candado);
    pthread_cond_signal(&consumido); //señaliza la extraccion de datos
  }
}

void putElement(void) {
  while (!feof(file)) {
    pthread_mutex_lock(&candado);
    while (contador == BUFFERSIZE) {//buffer lleno
      pthread_cond_wait(&consumido, &candado); //esperando 
    }
    if (!feof(file)) {
      int val = readChar(file);

      char dato = val - llave[posLlave] == 0 ? val : val - llave[posLlave];

      buffer[entrada] = dato;
      posLlave = (posLlave + 1) % strlen(llave);
      producidos = producidos - 1;
      entrada = (entrada + 1) % BUFFERSIZE;
      contador = contador + 1;
    }
    pthread_mutex_unlock(&candado);
    pthread_cond_signal(&producido); //señaliza que metio datos
  }
}

int main(int argc, char **argv) {

  archivo = argv[1];
  file = fopen(archivo, "rb");

  if (!file) {
    printf("El archivo no existe..");
  } else {
    
    archivo = substract(archivo);
    cesar = fopen(archivo, "w");

    init();
    printf("Inicio del programa \n");

    printf("Digite la llave para el cifrado del archivo: ");
    llave = (char*) malloc(sizeof (char*));
    scanf("%[^\n]", llave);
    fflush(stdin);
    fflush(stdout);

    int numHilos;
    printf("Digite el numero de hilos: ");
    scanf("%i", &numHilos);
    fflush(stdin);
    fflush(stdout);
    
    pthread_t thread[numHilos];
    for (int i = 1; i <= numHilos; i++) {
      if (i % 2 == 0) {
        pthread_create(&thread[i], NULL, (void *) &getElement, NULL);
      } else {
        pthread_create(&thread[i], NULL, (void *) &putElement, NULL);
      }
    }

    for (int i = 1; i <= numHilos; i++) {
      pthread_join(thread[i], NULL);
    }

    pthread_mutex_destroy(&candado);
    pthread_cond_destroy(&producido);
    pthread_cond_destroy(&consumido);

    free(llave);
    fclose(file);
    fclose(cesar);
    printf("\n<=Archivo Descodificado=>");
  }
  return 0;
}