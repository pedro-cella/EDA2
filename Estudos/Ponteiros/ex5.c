#include <stdio.h>
#include <stdlib.h>

void comparing(int** valorA, int** valorB);

int main(){

    int a, b;

    scanf("%d %d", &a, &b);

    printf("Valor A: %d\nValor B: %d\n", a, b);

    int* ptr_a = &a;
    int* ptr_b = &b;

    comparing(&ptr_a, &ptr_b);

    return 0;
}

void comparing(int** valorA, int** valorB){
    if(**valorA > **valorB){
        printf("Maior: %d\nMenor: %d\n", **valorA, **valorB);
    }else{
        printf("Maior: %d\nMenor: %d\n", **valorB, **valorA);
    }
}