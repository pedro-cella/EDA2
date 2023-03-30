#include <stdio.h>

int main(){

    int N, numero_registro, lista_presenca[1123456], contador = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &numero_registro);
        if(lista_presenca[numero_registro] == 0){
            lista_presenca[numero_registro] = 1;
            contador += 1;
        }
    }

    printf("%d\n", contador);
    return 0;
}