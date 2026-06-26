#include <stdio.h>
#include "lista_linear.h"

int main() {

    Lista *lista = lista_criar();

    lista_inserir_inicio(lista, 15);
    lista_inserir_inicio(lista, 10);

    lista_inserir_final(lista, 25);
    lista_inserir_final(lista, 35);

    lista_exibir(lista);

    if (lista_buscar(lista, 25))           //valor que existe na lista
        printf("Valor 25 encontrado.\n");
    else
        printf("Valor 25 nao encontrado.\n");

    if (lista_buscar(lista, 40))           //valor que não existe
        printf("Valor 40 encontrado.\n");
    else
        printf("Valor 40 nao encontrado.\n");

    printf("\nRemovendo 15:\n");

    lista_remover(lista, 15);
    lista_exibir(lista);

    printf("\nRemovendo 10:\n");

    lista_remover(lista, 10);
    lista_exibir(lista);

    printf("\nRemovendo 35:\n");

    lista_remover(lista, 35);
    lista_exibir(lista);

    lista_destruir(lista);

    return 0;
}