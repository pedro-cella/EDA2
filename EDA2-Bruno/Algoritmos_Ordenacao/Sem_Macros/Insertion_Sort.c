#include <stdio.h>
#include <stdlib.h>

// Nesse caso utilizamos do auxílio de funções macro para nos ajudar a realizar as tarefas
// O algoritmo Insertion Sort possui complexidade O(n^2)
// Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
// Dado a definição de estabilidade o algoritmo de ordenação Insertion Sort é um algoritmo de ordenação estável

// Exemplo de teste do Insertion Sort
// Entrada: 7 3 2 5 4 3
// Saida: 2 3 3 4 5 7

void insertionsort(int *v, int l, int r){
    for(int i = r; i > l; i--){
        if(v[i] < v[i - 1]){
           int temp = v[i];
           v[i] = v[i - 1];
           v[i - 1] = temp;
        }
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

    int vetor[50000], i = 0;

    while(scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    insertionsort(vetor, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i-1){
            printf("%d\n", vetor[x]);
        }else{
            printf("%d ", vetor[x]);
        }
    }


    return 0;
}