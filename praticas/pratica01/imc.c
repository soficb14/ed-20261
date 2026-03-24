#include <stdio.h>

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

int main (){

//3. casos

    printf("Peso: 0kg, Altura: 1.75m\n");
    calcularIMC(0, 1.75);

    printf("Peso: 10kg, Altura: 1.75m\n");
    calcularIMC(10, 1.75);

    printf("Peso: 70kg, Altura: 1.75m\n");
    calcularIMC(70, 1.75);

    printf("Peso: 90kg, Altura: 1.75m\n");
    calcularIMC(90, 1.75);

    printf("Peso: 110kg, Altura: 1.75m\n");
    calcularIMC(110, 1.75);

    return 0;

}