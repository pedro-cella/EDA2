#include <stdio.h>
#include <stdlib.h>

void insertionsorteficiente(int *v, int l, int r){
    for(int i = r; i > l; i--)
        if(v[i] < v[i - 1]){
           int temp = v[i];
           v[i] = v[i - 1];
           v[i - 1] = temp;
        }

    for(int i = l + 2; i <= r; i++)
    {
        int j = i;
        int temp = v[j];
        while(temp < v[j - 1])
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    } 
}

int main(){

    int numeros[50000], i = 0;

    while(scanf("%d", &numeros[i]) != EOF){
        i++;
    }

    insertionsorteficiente(numeros, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i - 1){
            printf("%d\n", numeros[x]);
        }else{
            printf("%d ", numeros[x]);
        }
    }

    return 0;
}