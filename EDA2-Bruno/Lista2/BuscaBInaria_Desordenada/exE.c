#include <stdio.h>
#include <stdlib.h>


int buscabinaria(int chave,int *vetor, int tamanho, int *vetor_nao_ordenado){
    int n=tamanho;// aqui eu informo o tamanhão do vetor
    int ini=0, fim=n-1, meio, i = 0;
    while(ini<=fim){
        meio = (ini+fim)/2;
        if(chave == vetor[meio]){
            while(vetor_nao_ordenado[i] != chave){
                i++;
                if(vetor_nao_ordenado[i] == vetor[meio]){
                    return i;
                }
            }
        }else if(chave > vetor[meio]){
                ini = meio+1;
        }else{
            fim = meio-1;
        }
    }
    return -1;
}

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

    int N, M, *numeros_N, *numeros_N_desorg, *numeros_M;

    scanf("%d %d", &N, &M);

    numeros_N = malloc(sizeof(int) * N);
    numeros_N_desorg = malloc(sizeof(int) * N);
    numeros_M = malloc(sizeof(int) * M);

    for(int i = 0; i < N; i++){
        scanf("%d", &numeros_N[i]);
        numeros_N_desorg[i]  = numeros_N[i];
    }

    mergesort(numeros_N, 0, N);

    // for(int i = 0; i < N; i++){
    //     printf("%d ", numeros_N[i]);
    // }
    
    // printf("\n");

    // for(int i = 0; i < N; i++){
    //     printf("%d ", numeros_N_desorg[i]);
    // }
    
    // printf("\n");

    for(int i = 0; i < M; i++){
        scanf("%d", &numeros_M[i]);
        printf("%d\n", buscabinaria(numeros_M[i], numeros_N, N, numeros_N_desorg));
    }

    return 0;
}