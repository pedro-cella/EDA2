#include <stdio.h>
#include <stdlib.h>

// Nesse caso utilizamos do auxílio de funções macro para nos ajudar a realizar as tarefas
// O algoritmo Insertion Sort possui complexidade O(n^2)
// Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
// Dado a definição de estabilidade o algoritmo de ordenação Insertion Sort é um algoritmo de ordenação estável

// Porém esse algoritmo não se difere tanto do algoritmo do Bubble Sort, por isso consideramos essa implementação como lenta, vamos ver a outra implementação desse algorimto de ordenação

// Exemplo de teste do Insertion Sort
// Entrada: 7 3 2 5 4 3
// Saida: 2 3 3 4 5 7

typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionsortslow(Item *v, int l, int r){
    for(int i = l+1; i<=r; i++){
        for(int j = i; j > l; j--){
            cmpexch(v[j-1], v[j]);
        }
    }
}

int main(){

    Item vetor[1000]; 
    int i = 0;

    while(scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    insertionsortslow(vetor, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i-1){
            printf("%d\n", vetor[x]);
        }else{
            printf("%d ", vetor[x]);
        }
    }


    return 0;
}