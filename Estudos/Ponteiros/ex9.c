#include <stdio.h>
#include <stdlib.h>

int main(){

    float matriz[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("matriz[%d][%d] de endereço %p\n", i, j, &matriz[i][j]);
        }
    }

    return 0;
}