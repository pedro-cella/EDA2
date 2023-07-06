#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int *v, int n, int l, int u) {
    int *c = calloc(u - l + 1, sizeof(int));
    int k = 0;

    for (int i = 0; i < n; i++)
        c[v[i] - l]++; // porque fazer isso ?

    for (int i = 0; i < u - l + 1; i++)
        while (c[i] > 0) {
            v[k] = i + l; // ???
            k++;
            c[i]--;
        }

    free(c);
}

int main() {
    // Definir o limite inferior (l) e o limite superior (u)
    int l = 1;
    int u = 31;

    // Definir o tamanho do conjunto de fluxo de caixa
    int n = 20;

    // Gerar aleatoriamente o conjunto de fluxo de caixa
    int *fluxo_caixa = malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fluxo_caixa[i] = (rand() % (u - l + 1)) + l;
    }

    // Imprimir o conjunto de fluxo de caixa não ordenado
    printf("Conjunto de fluxo de caixa nao ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fluxo_caixa[i]);
    }
    printf("\n");

    // Ordenar o conjunto de fluxo de caixa usando o Counting Sort
    countingSort(fluxo_caixa, n, l, u);

    // Imprimir o conjunto de fluxo de caixa ordenado
    printf("Conjunto de fluxo de caixa ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fluxo_caixa[i]);
    }
    printf("\n");

    free(fluxo_caixa);

    // Resultado

    // Conjunto de fluxo de caixa nao ordenado:
    // 8 8 24 20 15 10 8 22 2 4 29 24 6 16 5 24 20 16 19 6 
    // Conjunto de fluxo de caixa ordenado:
    // 2 4 5 6 6 8 8 8 10 15 16 16 19 20 20 22 24 24 24 29 

    return 0;
}
