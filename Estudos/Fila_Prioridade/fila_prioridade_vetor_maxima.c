#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vetor;
    int contador;
} FilaPrioridade;

void inicializarFilaPrioridade(FilaPrioridade *fila, int tamanhoMaximo) {
    fila->vetor = malloc(tamanhoMaximo * sizeof(int));
    fila->contador = 0;
}

void inserirPrioridadeMaxima(FilaPrioridade *fila, int valor) {
    int i = fila->contador;
    fila->vetor[i] = valor;

    while (i > 0 && fila->vetor[i] > fila->vetor[(i - 1) / 2]) {
        int temp = fila->vetor[i];
        fila->vetor[i] = fila->vetor[(i - 1) / 2];
        fila->vetor[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

    fila->contador++;
}

int removerMaximo(FilaPrioridade *fila) {
    if (fila->contador == 0) {
        printf("Fila vazia!\n");
        return -1;
    }

    int valorMaximo = fila->vetor[0];
    fila->contador--;

    fila->vetor[0] = fila->vetor[fila->contador];

    int i = 0;
    while (1) {
        int filhoEsquerda = 2 * i + 1;
        int filhoDireita = 2 * i + 2;
        int maior = i;

        if (filhoEsquerda < fila->contador && fila->vetor[filhoEsquerda] > fila->vetor[maior]) {
            maior = filhoEsquerda;
        }
        if (filhoDireita < fila->contador && fila->vetor[filhoDireita] > fila->vetor[maior]) {
            maior = filhoDireita;
        }

        if (maior != i) {
            int temp = fila->vetor[i];
            fila->vetor[i] = fila->vetor[maior];
            fila->vetor[maior] = temp;
            i = maior;
        } else {
            break;
        }
    }

    return valorMaximo;
}

void liberarFilaPrioridade(FilaPrioridade *fila) {
    free(fila->vetor);
}

void imprimirFilaPrioridade(FilaPrioridade *fila) {
    if (fila->contador == 0) {
        printf("Fila vazia!\n");
        return;
    }

    for (int i = 0; i < fila->contador; i++) {
        printf("%d ", fila->vetor[i]);
    }

    printf("\n");
}

int main() {
    FilaPrioridade fila;
    inicializarFilaPrioridade(&fila, 10);

    inserirPrioridadeMaxima(&fila, 5);
    inserirPrioridadeMaxima(&fila, 2);
    inserirPrioridadeMaxima(&fila, 8);

    printf("Fila de prioridade: ");
    imprimirFilaPrioridade(&fila);

    int maximo = removerMaximo(&fila);
    printf("Elemento de maior prioridade: %d\n", maximo);

    liberarFilaPrioridade(&fila);

    // Resultado
    // Fila de prioridade: 8 2 5 
    // Elemento de maior prioridade: 8

    return 0;
}
