#include <stdio.h>
#include <stdlib.h>


int main(){
    // celula *cabeca;
    // cabeca = (celula*) malloc(sizeof(celula));
    // cabeca->prox = NULL;

    // insere_inicio(cabeca, 10);
    // insere_inicio(cabeca, 20);
    // insere_inicio(cabeca, 30);
    // imprime(cabeca);

    int vetor[10];
    int *ptr;

    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;

    ptr = vetor;

    printf("Endereço primeira posição do vetor: %p\n", &vetor[0]);
    printf("Endereço da terceira posição do vetor: %p\n", &vetor[2]);
    printf("Endereço da terceira posição do vetor: %p\n", vetor+2);
    printf("Endereço ponteiro: %p\n", ptr);

    printf("Valor da primeira posição do vetor: %d\n", vetor[0]);
    printf("Valor do ponteiro: %d\n", *ptr);

    ptr = vetor+2;

    printf("Valor da terceira posição do vetor: %d\n", vetor[2]);
    printf("Valor da terceira posição do vetor: %d\n", *ptr);
    printf("Valor da terceira posição do vetor: %d\n", *(vetor+2));

}