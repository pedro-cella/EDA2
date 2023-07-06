#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para encontrar o dígito de um número em uma determinada posição
int obterDigito(int numero, int posicao) {
    int divisor = 1;
    for (int i = 1; i <= posicao; i++) {
        divisor *= 10;
    }
    return (numero / divisor) % 10;
}

// Função auxiliar para encontrar o maior número no vetor
int encontrarMaior(int *vetor, int n) {
    int maior = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

// Função de ordenação Radix Sort
void radixSort(int *vetor, int n, int k) {
    int i, j, digito, divisor = 1;
    int **baldes = malloc(10 * sizeof(int *));
    
    // Aloca espaço para os baldes
    for (i = 0; i < 10; i++) {
        baldes[i] = malloc(n * sizeof(int));
    }

    // Executa o Radix Sort para cada dígito
    for (i = 1; i <= k; i++) {
        // Inicializa os baldes
        int contagem[10] = {0};
        
        // Coloca cada elemento do vetor nos baldes correspondentes
        for (j = 0; j < n; j++) {
            digito = obterDigito(vetor[j], i);
            baldes[digito][contagem[digito]] = vetor[j];
            contagem[digito]++;
        }
        
        // Reconstrói o vetor a partir dos baldes
        j = 0;
        for (digito = 0; digito < 10; digito++) {
            for (int l = 0; l < contagem[digito]; l++) {
                vetor[j] = baldes[digito][l];
                j++;
            }
        }
    }
    
    // Libera a memória alocada para os baldes
    for (i = 0; i < 10; i++) {
        free(baldes[i]);
    }
    free(baldes);
}

int main() {
    //int vetor[] = {31, 37, 43, 31, 87, 67, 63, 18, 38};
    int vetor[] = {61, 21, 43, 13, 65, 38, 58, 28};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int k = 2;
    
    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    radixSort(vetor, n, k);
    
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}