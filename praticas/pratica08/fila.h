#ifndef FILA_H
#define FILA_H

typedef struct fila_t Fila;

Fila *fila_criar();
void fila_destruir(Fila *f);
void fila_enfileirar(Fila *f, int dado); //enqueue
void fila_desenfileirar(Fila *f); //dequeue
int fila_esta_vazia(Fila *f);
int fila_inicio(Fila *f);
void fila_exibir(Fila *f);


#endif