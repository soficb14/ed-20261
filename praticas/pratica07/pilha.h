#ifndef PILHA_H
#define PILHA_H

typedef struct pilha_t Pilha;

Pilha *criar();
int pilha_vazia(Pilha *pilha);
int pilha_topo(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
void desempilhar(Pilha *pilha);
void pilha_destruir(Pilha *pilha);
void pilha_exibir(Pilha *pilha);

#endif