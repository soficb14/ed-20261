#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    struct no_t *esquerda;
    int valor;
    struct no_t *direita;
} No;

typedef struct arvore_t {
    No *raiz;
} Arvore;

static No *criar_no(int dado)
{
    No *no = (No *)malloc(sizeof(No));

    if (no == NULL)
        return NULL;

    no->valor = dado;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

static No *inserir(No *no, int dado)
{
    if (no == NULL)
        return criar_no(dado);

    if (dado < no->valor)
        no->esquerda = inserir(no->esquerda, dado);
    else if (dado > no->valor)
        no->direita = inserir(no->direita, dado);

    return no;
}

static void pre_ordem(No *no) { 
    if (no == NULL)
        return;

    printf("[%d] ", no->valor);
    pre_ordem(no->esquerda);
    pre_ordem(no->direita);
}

static void em_ordem(No *no) {
    if (no == NULL)
        return;

    em_ordem(no->esquerda);
    printf("[%d] ", no->valor);
    em_ordem(no->direita);
}

static void pos_ordem(No *no) {
    if (no == NULL)
        return;

    pos_ordem(no->esquerda);
    pos_ordem(no->direita);
    printf("[%d] ", no->valor);
}

static void destruir_nos(No *no) {
    if (no == NULL)
        return;

    destruir_nos(no->esquerda);
    destruir_nos(no->direita);
    free(no);
}

//Funções da prática

Arvore *arvore_criar()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    if (arvore == NULL)
        return NULL;

    arvore->raiz = NULL;

    return arvore;
}

void arvore_inserir(Arvore *arvore, int dado)
{
    if (arvore == NULL)
        return;

    arvore->raiz = inserir(arvore->raiz, dado);
}

void arvore_exibir_pre_ordem(Arvore *arvore)
{
    if (arvore == NULL)
        return;

    pre_ordem(arvore->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore *arvore)
{
    if (arvore == NULL)
        return;

    em_ordem(arvore->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore *arvore)
{
    if (arvore == NULL)
        return;

    pos_ordem(arvore->raiz);
    printf("\n");
}

int arvore_esta_vazia(Arvore *arvore)
{
    return arvore != NULL && arvore->raiz == NULL;
}

void arvore_destruir(Arvore *arvore)
{
    if (arvore == NULL)
        return;

    destruir_nos(arvore->raiz);
    free(arvore);
}