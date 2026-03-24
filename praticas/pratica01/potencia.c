#include <stdio.h>


//1. funcao calculo da potencia
int calcularPotencia(int base, int expoente){
    int resultado = 1;

//2. loop de repeticao de base^n
    for (int i = expoente; i > 0; i--){
        resultado = resultado * base;
    }

    return resultado;
}

int main (){

//3. casos
    int resultado = calcularPotencia(3, 5);
    printf("3^5 = %d\n", resultado);

    resultado = calcularPotencia(2, 4);
    printf("2^4 = %d\n", resultado);

    resultado = calcularPotencia(8, 2);
    printf("8^2 = %d\n", resultado);

    resultado = calcularPotencia(10, 6);
    printf("10^6 = %d\n", resultado);

    return 0;

}