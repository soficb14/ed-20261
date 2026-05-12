#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void copiarVetor(int original[], int copia[], int n) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}

int main() {
    int n = 100;
    int vetorOriginal[100];
    int vetorTeste[100];
    clock_t inicio, fim;
    double tempoGasto;

    // 1. Gerar vetor com 100 números aleatórios
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vetorOriginal[i] = rand() % 1000;
    }

    printf("--- Teste de Algoritmos de Ordenacao (100 elementos) ---\n\n");

    // 1. TESTE BUBBLE SORT 
    copiarVetor(vetorOriginal, vetorTeste, n);
    inicio = clock();
    bubble_sort(vetorTeste, n);
    fim = clock();
    tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Bubble Sort:    %f segundos\n", tempoGasto);

    // 2. TESTE SELECTION SORT
    copiarVetor(vetorOriginal, vetorTeste, n);
    inicio = clock();
    selection_sort(vetorTeste, n);
    fim = clock();
    tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f segundos\n", tempoGasto);

    // 3. TESTE QUICK SORT
    copiarVetor(vetorOriginal, vetorTeste, n);
    inicio = clock();
    // No quick_sort, passamos o índice inicial (0) e o final (n-1)
    quick_sort(vetorTeste, 0, n - 1);
    fim = clock();
    tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Quick Sort:     %f segundos\n", tempoGasto);

    return 0;
}