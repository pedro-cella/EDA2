#include <stdio.h>
#include <stdlib.h>

void change(int* a, int* b);
void change_with_pointer(int** a, int** b);

int main(){

    // Mudando apenas o valor das variáveis
    // int a, b;

    // scanf("%d %d", &a, &b);

    // printf("A: %d\nB: %d\n", a, b);

    // printf("Endereço A: %p", &a);

    // change(&a, &b);

    // printf("A: %d\nB: %d\n", a, b);

    // Mudando o endereço de cada variável
    int a, b;

    scanf("%d %d", &a, &b);
    
    int* ptr_a = &a;
    int* ptr_b = &b;

    change_with_pointer(&ptr_a, &ptr_b);

    printf("A: %d\nB: %d\n", *ptr_a, *ptr_b);

    return 0;
}

void change(int* valorA, int* valorB){
    int temp;

    printf("Endereço A2: %p\n", &valorA);

    printf("Antes valorA: %d\n", *valorA);
    printf("Antes valorB: %d\n", *valorB);
    //Realiza a troca
    temp = *valorA;
    printf("temp: %d\n", temp);
    *valorA = *valorB;
    printf("Depois valorA: %d\n", *valorA);
    *valorB = temp;
    printf("Depois valorB: %d\n", *valorB);
}

void change_with_pointer(int** valorA, int** valorB){
    int *temp;

    printf("valorA*: %p\n", *valorA);
    printf("valorA**: %d\n", **valorA);

    temp = *valorA;
    *valorA = *valorB;
    *valorB = temp;
}