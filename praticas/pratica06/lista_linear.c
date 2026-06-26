#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} No;

struct lista_t {
    No *primeiro;
    No *ultimo;
};

Lista *lista_criar() {
    Lista *l = (Lista *) malloc(sizeof(Lista));

    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }

    return l;
}

int lista_vazia(Lista *l) {
    return (l == NULL || l->primeiro == NULL);
}

int lista_inserir_inicio(Lista *l, int valor) {

    if (l == NULL) return 0;

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = l->primeiro;

    if (l->primeiro != NULL)
        l->primeiro->anterior = novo;
    else
        l->ultimo = novo;

    l->primeiro = novo;

    return 1;
}

int lista_inserir_final(Lista *l, int valor) {

    if (l == NULL) return 0;

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (l->ultimo != NULL)
        l->ultimo->proximo = novo;
    else
        l->primeiro = novo;

    l->ultimo = novo;

    return 1;
}

int lista_buscar(Lista *l, int valor) {

    if (l == NULL) return 0;

    No *aux = l->primeiro;

    while (aux != NULL) 
    {
        if (aux->valor == valor) return 1;
        aux = aux->proximo;
    }

    return 0;
}

int lista_remover(Lista *l, int valor) {

    if (l == NULL) return 0;

    No *aux = l->primeiro;

    while (aux != NULL && aux->valor != valor) {
        aux = aux->proximo;
    }

    if (aux == NULL) return 0;

    if (aux->anterior != NULL) 
        aux->anterior->proximo = aux->proximo;
    else 
        l->primeiro = aux->proximo;
    
    if (aux->proximo != NULL)
        aux->proximo->anterior = aux->anterior;
    else
        l->ultimo = aux->anterior;

    free(aux);

    return 1;
}

void lista_exibir(Lista *l) 
{
    if (l == NULL) {
        printf("Lista inexistente.\n");
        return;
    }

    No *aux = l->primeiro;

    printf("Lista: ");

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}

void lista_destruir(Lista *l) 
{
    if (l == NULL) return;

    No *aux = l->primeiro;

    while (aux != NULL) {
        No *temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    free(l);
}