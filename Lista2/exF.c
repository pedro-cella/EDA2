#include <stdio.h>
#include <stdlib.h>

// int buscabinaria(int tamanho, int *vetor, int n){
//     int ini = 0;
//     int fim = tamanho - 1;
//     int meio;

//     while(ini <= fim)
//     {
//         meio = (ini + fim)/2;
//         if(n < vetor[meio]){
//             fim = meio - 1;
//         }else if(n > vetor[meio]){
//             ini = meio + 1;
//         }else return meio;
//     }return -1;
// }

int buscabinaria(int tamanho, int *vetor, int numero) {
   int e, m, d;
   e = 0; 
   d = tamanho - 1;
   while (e <= d) { 
      m = (e + d)/2; 
      if (vetor[m] == numero) {
		  return 1;
      }
      if (vetor[m] < numero) {
      	e = m + 1;
      } 
      else {
      	d = m - 1;
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

    int N, vetor[140000], Pi, resultado;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }

    mergesort(vetor, 0, N);

    // for(int i = 0; i < N; i++){
    //     printf("%d ", vetor[i]);
    // }

   while(scanf("%d", &Pi) != EOF) {
		if(buscabinaria(N, vetor, Pi) == 1) {
			printf("sim\n");
		} else {
			printf("nao\n");
		}
	}


    return 0;
}