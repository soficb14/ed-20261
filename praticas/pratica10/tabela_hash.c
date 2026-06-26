#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

typedef struct hash_t {
    No **tabela;
    int tamanho;
} TabelaHash;

static int calcular_hash(TabelaHash *hash, int x) {
    return x % hash->tamanho;
}

TabelaHash *hash_criar(int tamanho) 
{
    TabelaHash *hash = (TabelaHash *)malloc(sizeof(TabelaHash));

    if (hash == NULL)
        return NULL;

    hash->tabela = (No **)malloc(sizeof(No *) * tamanho);

    if (hash->tabela == NULL) {
        free(hash);
        return NULL;
    }

    memset(hash->tabela, 0, sizeof(No *) * tamanho);
    hash->tamanho = tamanho;

    return hash;
}

void hash_inserir(TabelaHash *hash, int valor) {
    if (hash == NULL)
        return;

    int indice = calcular_hash(hash, valor);

    No *no = (No *)malloc(sizeof(No));

    if (no == NULL)
        return;

    no->valor = valor;
    no->proximo = hash->tabela[indice];

    hash->tabela[indice] = no;
}

int hash_buscar(TabelaHash *hash, int valor) {
    if (hash == NULL)
        return -1;

    int indice = calcular_hash(hash, valor);

    No *no = hash->tabela[indice];

    while (no != NULL) 
    {
        if (no->valor == valor)
            return indice;

        no = no->proximo;
    }
    return -1;
}

void hash_remover(TabelaHash *hash, int valor) {
    if (hash == NULL)
        return;

    int indice = calcular_hash(hash, valor);

    No *no = hash->tabela[indice];
    No *anterior = NULL;

    while (no != NULL) 
    {
        if (no->valor == valor) 
        {
            if (anterior == NULL)
                hash->tabela[indice] = no->proximo;
            else
                anterior->proximo = no->proximo;

            free(no);
            return;
        }
        anterior = no;
        no = no->proximo;
    }
}

void hash_exibir(TabelaHash *hash) {
    if (hash == NULL)
        return;

    for (int i = 0; i < hash->tamanho; i++) 
    {
        printf("%d: ", i);

        No *no = hash->tabela[i];

        while (no != NULL) {
            printf("%d ", no->valor);
            no = no->proximo;
        }
        printf("\n");
    }
}

int hash_esta_vazia(TabelaHash *hash) {
    if (hash == NULL)
        return 1;

    for (int i = 0; i < hash->tamanho; i++) {

        if (hash->tabela[i] != NULL)
            return 0;
    }

    return 1;
}

void hash_destruir(TabelaHash *hash) {
    if (hash == NULL)
        return;

    for (int i = 0; i < hash->tamanho; i++) 
    {
        No *atual = hash->tabela[i];

        while (atual != NULL) 
        {
            No *aux = atual;
            atual = atual->proximo;

            free(aux);
        }
    }
    free(hash->tabela);
    free(hash);
}