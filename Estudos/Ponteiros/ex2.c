#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    printf("Endereço A: %p\nEndereço B: %p\n", &a, &b);

    if(&a > &b){
        printf("Endereço A é o maior: %p\n", &a);
    }else{
        printf("Endereço B é o maior: %p\n", &b);
    }

    return 0;
}