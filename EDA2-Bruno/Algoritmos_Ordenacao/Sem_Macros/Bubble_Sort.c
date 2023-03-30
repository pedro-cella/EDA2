#include <stdio.h>
#include <stdlib.h>

// O algoritmo Bubble Sort possui complexidade O(n^2)
// Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
// Dado a definição de estabilidade o algoritmo de ordenação Bubble Sort é um algoritmo de ordenação estável

// Exemplo de teste do Bubble Sort
// Entrada: 7 3 2 5 4 3
// Saida: 2 3 3 4 5 7

void bubblesort(int *v, int l, int r){
    for(int i = l; i < r; i++){
        for(int j = l; j < r; j++){
            if(v[j+1] < v[j]){
                int temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main(){

    int vetor[1000], i = 0;

    while(scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    bubblesort(vetor, 0, i-1);
    // Acrescentamos i-1 pois durante o while o i receberá um elemento à mais, por isso decrescentamos 1 

    for(int x = 0; x < i; x++){
        if(x == i - 1){
            printf("%d\n", vetor[x]);
        }else{
            printf("%d ", vetor[x]);
        }
    }


    return 0;
}