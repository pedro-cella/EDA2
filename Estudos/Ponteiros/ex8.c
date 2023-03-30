#include <stdio.h>
#include <stdlib.h>

int main(){

    float array[11];

    float* endereco_array = array;

    // printf("Endereço array[0]: %p\n", &array[0]);
    // printf("Endereço ponteiro: %p\n", endereco_array);

    for(int i = 0; i < 11; i++){
        printf("Endereço array[%d]: %p\n", i, &array[i]);
    }

    return 0;
}