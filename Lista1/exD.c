#include <stdio.h>

void bubblesort(int *v, int l, int r){
    int i, j, temp;
    for(i = l; i < r; i++)
        for(int j = l; j < r; j++)
            if(v[j+1] < v[j]){
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
}

int main(){

    int numero[1000], i = 0, contador = 0;

    while(scanf("%d", &numero[i]) != EOF){
        i++;
    }

    bubblesort(numero, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i-1){
            printf("%d\n", numero[x]);
        }else{
            printf("%d ", numero[x]);
        }
    }

    return 0;
}