#include <stdio.h>

//1. Fatorial por repeticao
    /*  1.1 ler o número n
        1.2 funcao de fatorial n!:
            fatorial *= i, tal que 0 < i <= n, i++                
        */

//variavel auxiliar
unsigned long long fatorial = 1;

int fatRep(int n){
    for(int i = 1; i <= n; i++){
        fatorial *= i;
    }
    return fatorial;
}

//2. Fatorial por recursividade
    /*  2.1 caso base
        2.2 funcao recursiva de n! */

int fatRecurs(int n){
    if (n <= 1){
        return 1;
    } else {
        fatorial = n * fatRecurs(n-1);
        return fatorial;
    }
}

//3. main para chamar ambas as funcoes
int main(){
    int n;

    printf("Digite um número maior do que 1:\n");
    scanf("%d", &n);

    fatRep(n);
    printf("Por repeticao (for): %d! = %llu\n", n, fatorial);
    fatorial = 1;
    
    fatRecurs(n);
    printf("Por recursividade: %d! = %d\n", n, fatRecurs(n));

    printf("De acordo com os testes, conclui-se que o método iterativo é mais eficiente, porque a notacao big o é o(1) e a da recursiva é o(n), por ser em stack e alcançar rapidamente o overflow.\n");
}