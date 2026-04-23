#include <stdio.h>
#include "caixa_eletronico.h"
#include "media.h"
#include "imc.h"
#include "potencia.h"

int main (){

    //potencia
    printf("Teste: 5^0 = %d (Esperado: 1)\n", calcularPotencia(5, 0));  
    printf("Teste: 0^5 = %d (Esperado: 0)\n", calcularPotencia(0, 5));  

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

    printf("Teste Saque 1 real:\n");
    cQtdNotas(1); // Deve exibir a mensagem de erro 
    printf("Teste Saque 3 reais:\n");
    cQtdNotas(3);

    int valor;

    printf("Quanto voce quer sacar?\n");
    scanf("%d", &valor);
    cQtdNotas(valor);

    //media
    printf("\n4. Media:\n");
    printf("Teste 1: n = 0 (Caso de erro)\n");
    float m1 = calcularMedia(0); 
    
    printf("Teste 2: n = -5 (Caso de erro)\n");
    float m2 = calcularMedia(-5);

    printf("\nTeste 3: Entrada do usuário\n");
    printf("Digite de quantos números vai ser a média: ");
    int n;
    scanf("%d", &n);
    
    float mediaUsuario = calcularMedia(n);
    if (n > 0) {
        printf("Media final = %.2f\n", mediaUsuario);
    }
  

    return 0;
    }