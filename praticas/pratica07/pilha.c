#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

typedef struct pilha_t{
    No *topo;
} Pilha;

Pilha *criar() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if(pilha == NULL) {
        return NULL;
    }
    pilha->topo = NULL;
    return pilha;
}

int pilha_vazia(Pilha *pilha) {
    return pilha != NULL && pilha->topo == NULL;
}

int pilha_topo(Pilha *pilha)
{
    if (pilha == NULL || pilha->topo == NULL)
        return -1;

    return pilha->topo->valor;
}

void empilhar(Pilha *pilha, int valor) {

    if (pilha == NULL)
        return;

    No *no = (No *)malloc(sizeof(No));

    if(no == NULL) 
        return;

    no->valor = valor;
    no->proximo = pilha->topo;
    pilha->topo = no;
}

void desempilhar(Pilha *pilha)
{
    if (pilha == NULL || pilha->topo == NULL)
        return;

    No *no = pilha->topo;
    pilha->topo = no->proximo;
    free(no);
}

void pilha_destruir(Pilha *pilha)
{
    if (pilha == NULL)
        return;

    No *atual = pilha->topo;

    while(atual != NULL) {
        No *aux = atual;
        atual = atual->proximo;
        free(aux);
    }

    free(pilha);
}

void pilha_exibir(Pilha *pilha)
{
    if (pilha == NULL)
        return;
        
    No *aux = pilha->topo;

    printf("Topo -> ");

    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}