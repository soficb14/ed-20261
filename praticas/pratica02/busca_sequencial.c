#include <stdio.h>

int buscaS(int v[], int n){
    int i = 0;

    while(i < 100 && v[i] != n) {
        i++;
    }

    if (i < 100) {
        return i;
    } else{
        return -1;
    }
}

int main () {
    int v[100];
    int n;

    //preencher esse vetor
    for(int i = 0; i < 100; i++) {
        v[i] = i; // numeros entre 0 e 99
    }

    printf("Que numero de 0 a 99 voce deseja buscar?\n");
    scanf("%d", &n);


    int pos = buscaS(v, n);

    if(pos != -1){
    printf("O valor %d foi encontrado na posição %d do vetor.\n", n, pos);
    } else {
        printf("nao encontrado\n");
    }
   
    printf("O programa tem complexidade:\n  -Melhor caso: O(1) (achou na primeira posição)\n  -Pior caso: O(n)\n");
}