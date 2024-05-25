#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void* calcular(void* arg) {
    int id = *(int*)arg;
    printf("Hilo %d: Calculando...\n", id);
    // Lógica de cálculo
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, calcular, &threadIds[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
