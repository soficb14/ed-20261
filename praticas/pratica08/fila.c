#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

typedef struct fila_t{
    No *inicio;
    No *fim;
} Fila;

Fila *fila_criar() 
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    if(f == NULL) 
        return NULL;
    
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int fila_esta_vazia(Fila *f) {
    return f != NULL && f->inicio == NULL;
}

void fila_destruir(Fila *f)
{
    if (f == NULL)
        return;

    No *atual = f->inicio;

    while (atual != NULL) {
        No *aux = atual;
        atual = atual->proximo;
        free(aux);
    }

    free(f);
}

void fila_enfileirar(Fila *f, int dado) 
{
    if (f == NULL)
        return;

    No *no = (No *) malloc(sizeof(No));

    if (no == NULL)
        return;

    no->valor = dado;
    no->proximo = NULL;

    if(fila_esta_vazia(f)) {
        f->inicio = no;
        f->fim = no;
        return;
    }

    f->fim->proximo = no;
    f->fim = no;
}

void fila_desenfileirar(Fila *f) 
{
    if (f == NULL || fila_esta_vazia(f))
        return;
    
    No *no = f->inicio;
    f->inicio = no->proximo;

    if(fila_esta_vazia(f)) {
        f->fim = NULL;
    }
    free(no);
}

int fila_inicio(Fila *f) 
{
    if (f == NULL || fila_esta_vazia(f))
        return -1;
    
    return f->inicio->valor;
}

void fila_exibir(Fila *f)
{
    if (f == NULL)
        return;

    No *aux = f->inicio;

    printf("Inicio -> ");

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }

    printf("<- Fim\n");
}