#include <stdio.h>
#include "fila.h"

int main() {

    Fila *f = fila_criar();

    if (fila_esta_vazia(f))
        printf("Fila vazia.\n");

    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);
    fila_enfileirar(f, 50);

    printf("\nElementos da fila:\n");
    fila_exibir(f);

    printf("Inicio da fila: %d\n", fila_inicio(f));

    fila_desenfileirar(f);
    fila_desenfileirar(f);

    printf("\nApos desenfileirar:\n");
    fila_exibir(f);

    printf("Inicio da fila: %d\n", fila_inicio(f));

    fila_enfileirar(f, 60);
    fila_enfileirar(f, 70);

    printf("\nDepois dos novos novos enfileiramentos:\n");
    fila_exibir(f);

    fila_destruir(f);

    return 0;
}