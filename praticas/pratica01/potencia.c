#include <stdio.h>
#include "potencia.h"


//1. funcao calculo da potencia
int calcularPotencia(int base, int expoente){
    int resultado = 1;

//2. loop de repeticao de base^n
    for (int i = expoente; i > 0; i--){
        resultado = resultado * base;
    }

    return resultado;
}
