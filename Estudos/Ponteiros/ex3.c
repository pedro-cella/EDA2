#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    printf("A: %d\nB: %d\n", a, b);

    if(&a > &b){
        printf("Endereço do A é maior! valor: %p\n", &a);
    }else{
        printf("Endereço do B é maior! valor: %p\n", &b);
    }

    return 0;
}