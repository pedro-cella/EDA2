#include <stdio.h>
#include <stdlib.h>

#define FILHO_ESQ(i) (2 * i + 1)
#define FILHO_DIR(i) (2 * i + 2)
#define PAI(i) ((i - 1) / 2)

void troca(int* i, int* j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}


void sobeHeap(int v[], int pos){
    int corr = pos;
    while(corr > 0 && v[PAI(corr)] < v[corr]){
        troca(&v[corr], &v[PAI(corr)]);
        corr = PAI(corr);
    }
}

int insereHeap(int v[], int m, int x){
    v[m] = x;
    sobeHeap(v, m);
    return m + 1;
}

void desceHeap(int v[], int m, int pos){
    int corr = pos, filho;
    while(FILHO_ESQ(corr) < m){
        filho = FILHO_ESQ(corr);
        if(FILHO_DIR(corr) < m && v[FILHO_DIR(corr)] > v[filho])
            filho = FILHO_DIR(corr);
        if (v[filho] <= v[corr])
            break;
        troca(&v[corr], &v[filho]);
        corr = filho;
    }
}


int removeHeap(int v[], int m, int *px){
    *px = v[0];
    troca(&v[0], &v[m - 1]);
    desceHeap(v, m, 0);
    return m - 1;
}

void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}


int main() {
    int vetor1[] = {10, 9, 4, 7, 8, 3, 2, 6, 1, 5};
    int tamanho1 = sizeof(vetor1) / sizeof(vetor1[0]);

    imprimeVetor(vetor1, tamanho1);

    int max;
    int tamanho = removeHeap(vetor1, tamanho1, &max);

    printf("Elemento de maior prioridade removido: %d\n", max);
    imprimeVetor(vetor1, tamanho1);

    // int vetor2[] = {6, 3, 5, 2, 1, 4};
    // int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);

    // imprimeVetor(vetor2, tamanho2);

    return 0;
}
