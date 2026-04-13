#include <stdio.h>
#include "caixa_eletronico.h"
#include "media.h"
#include "imc.h"
#include "potencia.h"

int main (){

    //potencia
    printf("1. Potencia:\n");
         int resultado = calcularPotencia(3, 5);
    printf("3^5 = %d\n", resultado);

    resultado = calcularPotencia(2, 4);
    printf("2^4 = %d\n", resultado);

    resultado = calcularPotencia(8, 2);
    printf("8^2 = %d\n", resultado);

    resultado = calcularPotencia(10, 6);
    printf("10^6 = %d\n", resultado);

    //imc
    printf("\n2. IMC:\n");
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

    //caixa
    printf("\n3. Caixa Eletronico:\n");
    int valor;

    printf("Quanto voce quer sacar?\n");
    scanf("%d", &valor);
    cQtdNotas(valor);

    //media
    printf("\n4. Media:\n");
    int n;

    printf("Digite de quantos números vai ser a média\n");
    scanf("%d", &n);

    if(n <= 0 || n > 100){
        printf("Inválido! Tente um número maior do que 0 e menor do que 100.\n");
        return 1;
        }
        float media = calcularMedia(n);
        printf("Media = %.2f\n", media);
  

    return 0;
    }