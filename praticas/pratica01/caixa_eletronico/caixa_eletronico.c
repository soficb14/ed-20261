#include <stdio.h>

//1. funcao de minimizacao (resto da divisão pela nota de maior valor possível)
void cQtdNotas(int valor){

    // teste de validacao
    if(valor < 1 || valor > 1000){
        printf("Invalido! Tente um valor menor do que 1000 e maior do que 1.\n");
        return;
    }

    // vetor com as notas disponiveis e um com a quantidade de notas
    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    int qtdNotas[7] = {0};

    //vetor auxiliar resto da divisao
    int resto = valor;

    // loop de teste se a maior nota e menor do que o valor do saque
    for(int i = 0; i < 7; i++){
        if(notas[i] <= resto){
            qtdNotas[i] = resto / notas[i];
            resto = resto % notas[i];
        } 
    }    

    if (resto == 1){
        printf("Nao conseguimos imprimir esse valor exatamente em notas.\n");
        return;
    }

    printf("Distribuicao de notas:\n");
    for (int i = 0; i < 7; i++){
        if(qtdNotas[i] > 0){
            printf("%d nota(s) de %d\n", qtdNotas[i], notas[i]);
        }
    }
}


int main (){
    int valor;

    //2. scanf quanto quer sacar
    printf("Quanto voce quer sacar?\n");
    scanf("%d", &valor);

    

    //4. chamar funcao
    cQtdNotas(valor);

    return 0;

}
