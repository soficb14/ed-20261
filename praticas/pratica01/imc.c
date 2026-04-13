#include <stdio.h>
#include "imc.h"

//1. funcao para calcular imc
void calcularIMC (float peso, float altura){
    float imc = peso/(altura*altura);

//2. classificacao
    if (peso <= 0  || altura <= 0){
        printf("Erro! Altura e/ou peso inválido(s)\n");
    } else if (imc < 18.5) {
        printf("IMC = %.2f, Classificação: Abaixo do peso\n", imc);
    } else if (imc <= 24.9) {
        printf("IMC = %.2f, Classificação: Peso normal\n", imc);
    } else if (imc <= 29.9) {
        printf("IMC = %.2f, Classificação: Sobrepeso\n", imc);
    } else {
        printf("IMC = %.2f, Classificação: Obesidade\n", imc);
    }

    printf("--------------------\n");

}