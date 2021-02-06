#include <stdio.h>
#include <stdlib.h>

void selectionsort(int *v, int l, int r){
    int min, i, j, temp;
    for(int i = l; i < r; i++){
        min = i;
        for(int j = i + 1; j <= r; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}


int main(){

    int numeros[1000], i = 0;

    while(scanf("%d", &numeros[i]) != EOF){
        i++;
    }

    selectionsort(numeros, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i - 1){
            printf("%d\n", numeros[x]);
        }else{
            printf("%d ", numeros[x]);
        }
    }


    return 0;
}