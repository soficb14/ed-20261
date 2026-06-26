#include <stdio.h>
#include "tabela_hash.h"

int main() {

    TabelaHash *hash = hash_criar(10);

    if (hash_esta_vazia(hash))
        printf("Tabela hash vazia.\n");

    hash_inserir(hash, 15);
    hash_inserir(hash, 25);
    hash_inserir(hash, 35);
    hash_inserir(hash, 12);
    hash_inserir(hash, 22);
    hash_inserir(hash, 42);

    printf("\nTabela hash:\n");
    hash_exibir(hash);

    printf("\nProcurando 25: ");

    if (hash_buscar(hash, 25) != -1)
        printf("Valor encontrado.\n");
    else
        printf("Valor nao encontrado.\n");

    printf("\nRemovendo 25...\n");
    hash_remover(hash, 25);

    printf("\nTabela hash apos remocao:\n");
    hash_exibir(hash);

    printf("\nProcurando 25 de novo: ");

    if (hash_buscar(hash, 25) != -1)
        printf("Valor encontrado.\n");
    else
        printf("Valor nao encontrado.\n");

    hash_destruir(hash);

    return 0;
}