#include <stdio.h>

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



int main (){
    int n;

    //3. Scanf quantos números (n)
    printf("Digite de quantos números vai ser a média\n");
    scanf("%d", &n);

    if(n <= 0 || n > 100){
        printf("Inválido! Tente um número maior do que 0 e menor do que 100.\n");
        return 1;
        }
    //4. Chamar calcularMedia
        float media = calcularMedia(n);
        printf("Media = %.2f\n", media);

        return 0;
}