#include <stdio.h>
#include <stdlib.h>

int dobro_e_soma(int* valorA, int* valorB);

int main(){

    int a, b, soma = 0;

    scanf("%d %d", &a, &b);

    printf("A: %d\nB: %d\n", a, b);

    soma = dobro_e_soma(&a, &b);

    printf("A: %d\nB: %d\n", a, b);

    printf("soma: %d\n", soma);

    return 0;
}

int dobro_e_soma(int* valorA, int* valorB){
    int soma = 0;

    *valorA = 2*(*valorA);

    *valorB = 2*(*valorB);

    soma = *valorA + *valorB;

    return soma;
}