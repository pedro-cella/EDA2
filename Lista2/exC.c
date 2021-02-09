#include <stdio.h>
#include <stdlib.h>

void merge(int *V, int l, int m, int r){
    for(int i = 0; i < r; i++){
        printf("%d ", V[i]);
    }
    printf("\n");
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
    int i = 0, vetor[100000];

    while(scanf("%d", &vetor[i]) != EOF){
        printf("%d ", vetor[i]);
        i++;
    }
    printf("\n");

    mergesort(vetor, 0, i-1);

    for(int x = 0; x < i; x++)
    {
        if(x == i - 1){
            printf("%d\n",vetor[i]);
        } else{
            printf("%d ",vetor[i]); 
        }
    }

    return 0;
}