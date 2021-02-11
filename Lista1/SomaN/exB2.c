#include <stdio.h>

int main(){

    int N, numero, soma = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &numero);

        soma += numero;
    }

    printf("%d\n", soma);

    return 0;
}