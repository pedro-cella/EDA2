#include <stdio.h>
#include <stdlib.h>

int buscabinaria(int tamanho, int *vetor, int numero) {
   int e, m, d;
   e = 0; 
   d = tamanho - 1;
   while (e <= d) { 
      m = (e + d)/2; 
      if (vetor[m] == numero) {
		  return m;
      }
      if (vetor[m] < numero) {
      	e = m + 1;
      } 
      else {
      	d = m - 1;
      } 
   }
   return e;
}

int main(){

    int N, M, x;
    int *numeros_N, *numeros_M, resultado;

    scanf("%d %d", &N, &M);

    numeros_N = malloc(sizeof(int) * N);
    numeros_M = malloc(sizeof(int) * M);

    for(int i = 0; i < N; i++){
        scanf("%d", &numeros_N[i]);
    }
    

    for(int i = 0; i < M; i++){
        scanf("%d", &numeros_M[i]);
        resultado = buscabinaria(N, numeros_N, numeros_M[i]);
        printf("%d\n", resultado);
    }



    return 0;
}