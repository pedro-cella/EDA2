#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero, contador = 0;

    while(scanf("%d", &numero) != EOF){
        contador++;
    }

    printf("%d\n", contador);

    return 0;
}