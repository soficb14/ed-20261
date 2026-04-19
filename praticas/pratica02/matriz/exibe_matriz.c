#include <stdio.h>
#include <time.h>

#define SIZE 10

int main() {
    int matriz[SIZE][SIZE];
    int i, j, k;
    clock_t start, end;
    double cpu_time_used;

    // Inicializando a matriz com valores simples
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matriz[i][j] = i + j;
        }
    }

    // --- ABORDAGEM 1: Dois laços aninhados ---
    printf("Abordagem 1 (Dois laços):\n");
    start = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Apenas acessando o valor para simular o percurso
            int temp = matriz[i][j]; 
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo: %f segundos\n\n", cpu_time_used);


    // --- ABORDAGEM 2: Apenas um laço ---
    // Tratamos a matriz como um ponteiro para percorrer linearmente
    printf("Abordagem 2 (Um laço):\n");
    int *ptr = &matriz[0][0];
    int total_elementos = SIZE * SIZE;
    
    start = clock();
    for (k = 0; k < total_elementos; k++) {
        int temp = *(ptr + k);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo: %f segundos\n", cpu_time_used);

    return 0;
}
