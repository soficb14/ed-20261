#include <stdio.h>
#include <stdlib.h>
#include <assert.h> //confere se a condicao é verdadeira
#include "conta.h"

int main (void){
    printf("=== Teste do TDA Conta");

    //Criação do TDA
    Conta *c = conta_criar(123);
    assert(c != NULL);
    printf("Criar calculadora... OK\n\n");

    //Teste 1: valor inicial
    assert(conta_ver_saldo(c) - 0.0 == 0.0);
    printf("Valor inicial... OK\n\n");

    //Teste 2: deposito
    double novo_saldo = conta_depositar(c, 50.0);
    assert(novo_saldo == 50.0);
    printf("Deposito de 50.0... OK\n\n");

    //Teste 3: saque
    int deu_certo = conta_sacar(c, 20.0); 
    assert(deu_certo == 1); // verifica se deu certo
    assert(conta_ver_saldo(c) == 30.0);
    printf("Saque de 20.0... OK\n");

}
