#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

typedef struct lista_t Lista;

Lista *lista_criar();
int lista_vazia(Lista *l);
int lista_inserir_inicio(Lista *l, int valor);
int lista_inserir_final(Lista *l, int valor);
int lista_remover(Lista *l, int valor);
int lista_buscar(Lista *l, int valor);
void lista_destruir(Lista *l);
void lista_exibir(Lista *l);

#endif