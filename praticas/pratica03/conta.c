#include <stdlib.h>
#include <stdio.h>
#include "conta.h"

struct conta_t {
    int numero; //id
    double saldo;
};

Conta* conta_criar(int id){
    Conta* c = malloc(sizeof(struct conta_t));
    //conferindo se a conta agora existe
    if(c != NULL){
        c->numero = id;
        //define saldo inicial = 0.0
        c->saldo = 0.0;
    }
    return c;
}


double conta_depositar(Conta *c, double n){
    if(c != NULL && n > 0){
        c->saldo += n;
        return c->saldo;
    }
    return 0.0;
}

int conta_sacar(Conta *c, double n){
    if(c != NULL &&  0 < n && n < c->saldo){
        c->saldo -= n;
        return 1;
    }
    return 0;
}


double conta_ver_saldo(Conta *c){
    if(c != NULL){
        return c->saldo;
    }
    return 0.0;
}

void conta_destruir(Conta *c){
    free(c);
}