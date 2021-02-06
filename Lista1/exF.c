#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *v, int l, int r){
    int i, j, temp;

    for(int i = l + 1; i <= r; i++)
        for(j = i; j > l; j--)
            if(v[j - 1] > v[j]){
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
}

int main(){

    int numeros[5000], i = 0;

    while(scanf("%d", &numeros[i]) != EOF){
        i++;
    }

    insertionsort(numeros, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i - 1){
            printf("%d\n", numeros[x]);
        }else{
            printf("%d ", numeros[x]);
        }
    }

    return 0;
}