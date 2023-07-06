#include <stdio.h>
#include <stdlib.h>

void troca(int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void desce_no_heap(int *v, int n, int i) {
    int fe = 2 * i + 1;
    int fd = fe + 1;
    int maior = i;

    if (fe < n && v[fe] > v[maior]) {
        maior = fe;
    }
    if (fd < n && v[fd] > v[maior]) {
        maior = fd;
    }

    if (maior != i) {
        troca(v, i, maior);
        desce_no_heap(v, n, maior);
    }
}

void constroi_heap(int *v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce_no_heap(v, n, i);
    }
}

void heapSort(int *v, int n) {
    constroi_heap(v, n);
    for (int i = n - 1; i >= 1; i--) {
        troca(v, 0, i);
        desce_no_heap(v, i, 0);
    }
}

int main() {
    int vetor[] = {31, 37, 43, 31, 87, 67, 63, 18, 38};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    heapSort(vetor, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Resultado

    // Vetor original: 31 37 43 31 87 67 63 18 38 
    // Vetor ordenado: 18 31 31 37 38 43 63 67 87

    return 0;
}
