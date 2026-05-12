#ifndef CONTA_H
#define CONTA_H

//define estrutura da conta
typedef struct conta_t Conta;

//inicializa a conta com saldo = 0;
Conta* conta_criar(int id);

//define quanto vai depositar e soma com o saldo atual
double conta_depositar(Conta *c, double n);

//define quanto vai sacar
int conta_sacar(Conta *c, double n);

//printf o saldo atual
double conta_ver_saldo(Conta *c);

//libera memória após o uso
void conta_destruir(Conta *c);

#endif