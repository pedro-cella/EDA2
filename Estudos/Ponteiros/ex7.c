#include <stdio.h>
#include <stdlib.h>

void soma(int* valorA, int* valorB);

int main(){

    int a, b;

    scanf("%d %d", &a, &b);

    printf("A: %d\nB: %d\n", a, b);

    soma(&a, &b);

    printf("Soma em A: %d\n", a); 

    return 0;
}

void soma(int* valorA, int* valorB){
    int soma = 0;

    soma = *valorA + *valorB;
    *valorA = soma;
}