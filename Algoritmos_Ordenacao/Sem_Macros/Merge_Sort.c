#include <stdio.h>
#include <stdlib.h>

// O algoritmo Merge Sort possui complexidade O(nlogn)
// Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
// Dado a definição de estabilidade o algoritmo de ordenação Merge Sort é um algoritmo de ordenação estável

// Exemplo de teste do Bubble Sort
// Entrada1: 6 (quantidade de termos a serem lidos)
// Entrada2: 7 3 2 5 4 3
// Saida: 2 3 3 4 5 7

void merge(int *v, int l, int m ,int r){

    int *R = malloc(sizeof(int)*(r-l+1));
    int i=l,j=m+1,k=0;

    while(i<=m && j<=r)
    {
        if(v[i] <= v[j])
            R[k++]=v[i++];
        else
            R[k++]=v[j++];
    }

    while(i<=m)
        R[k++]=v[i++];
    while(j<=r)
        R[k++]=v[j++];


    k=0;
    for(i=l;i<=r;i++)
        v[i]=R[k++];
    free(R);

}

void mergesort(int *v, int l, int r){
    if (l>= r) return;
    int meio=(l+r)/2;
    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v,l,meio,r);
}

int main(){

    int *vetor, n, i = 0;

    scanf("%d", &n);

    vetor = malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    mergesort(vetor, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i-1){
            printf("%d\n", vetor[x]);
        }else{
            printf("%d ", vetor[x]);
        }
    }

    return 0;
}