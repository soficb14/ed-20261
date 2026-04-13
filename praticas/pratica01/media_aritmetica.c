#include <stdio.h>
#include "media.h"

//1. funcao que calcula média
float calcularMedia(int n){
    int soma = 0;
    int numero;

//2. Scanf números i em loop
    for(int i = 0; i < n; i++){
        printf("Digite um número: ");
        scanf("%d", &numero);

        soma += numero;
    }

    float media = (float) soma/n;

    return media;
}



