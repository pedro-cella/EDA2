#include <stdio.h>
#include <stdlib.h>

void merge(int *V, int l, int m, int r){
    int *R = malloc(sizeof(int) * (r-l+1));
    int i=l, j=m+1, k=0;

    while(i<=m && j<=r){
        if(V[i] <= V[j])
            R[k++]=V[i++];
        else
            R[k++]=V[j++];
    }

    while(i<=m)
        R[k++]=V[i++];
    while(j<=r)
        R[k++]=V[j++];

    k=0;
    for(i=l;i<=r;i++)
        V[i]=R[k++];

    free(R);
}

void mergesort(int *V, int l, int r){
    if (l>=r) return;
    int meio=(l+r)/2;
    mergesort(V,l,meio);
    mergesort(V,meio+1,r);
    merge(V,l,meio,r);
}

int main(){

    int numero, *vetor, contador = 0;
    int tamanho = 20;

    vetor = malloc(sizeof(int) * tamanho);

    while(scanf("%d", (vetor+contador)) != EOF){
        contador++;
        if(contador == tamanho){
            tamanho += 50;
            vetor = realloc(vetor, sizeof(int) * tamanho);
        }
    }

    mergesort(vetor, 0, contador-1);

    for(int i = 0; i < contador; i++){
        if(i == contador-1){
            printf("%d\n", *(vetor + i));
        }else{
            printf("%d ", *(vetor + i));
        }
    }


    return 0;
}
