#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

int main() {
    int v[TAM];

    srand(time(NULL));

    // Gerar vetor
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    int alvo = v[50]; // pegar um valor existente

    clock_t inicio, fim;

    // Busca Linear
    inicio = clock();
    int pos = linear_search(v, TAM, alvo);
    fim = clock();

    double tempo_linear = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Linear Search: encontrou %d na posicao %d\n", alvo, pos);
    printf("Tempo: %f segundos\n\n", tempo_linear);

    // Quick Select
    int k = 10;

    inicio = clock();
    int kth = quick_select(v, 0, TAM - 1, k);
    fim = clock();

    double tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Quick Select: %d-esimo menor elemento = %d\n", k, kth);
    printf("Tempo: %f segundos\n", tempo_quick);

    return 0;
}
