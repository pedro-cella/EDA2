#include <stdio.h>
#include <stdlib.h>

typedef struct fp {
    int dado;
    struct fp *prox;
} fp;

void insere_fila(fp *fila, int dado) {
    fp *novo = malloc(sizeof(fp));
    novo->dado = dado;
    novo->prox = NULL;

    if (fila->prox == NULL) {
        fila->prox = novo;
    } else {
        fp *atual = fila->prox;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void insere_prioridade(fp *fila, int dado) {
    fp *novo = malloc(sizeof(fp));
    novo->dado = dado;

    if (fila->prox == NULL || dado > fila->prox->dado) {
        novo->prox = fila->prox;
        fila->prox = novo;
    } else {
        fp *anterior = fila->prox;
        fp *atual = anterior->prox;
        
        while (atual != NULL && dado <= atual->dado) {
            anterior = atual;
            atual = atual->prox;
        }
        
        anterior->prox = novo;
        novo->prox = atual;
    }
}

void remove_fila(fp **fila) {
    if (*fila == NULL || (*fila)->prox == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    fp *temp = *fila;

    *fila = (*fila)->prox;

    free(temp);

    printf("O elemento foi removido!\n");
}

void exibe_fila(fp *fila) {
    if (fila == NULL || fila->prox == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    fp *atual = fila->prox;

    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }

    printf("\n");
}

int main() {
    fp *fila = malloc(sizeof(fp));
    fila->prox = NULL;

    insere_fila(fila, 3);
    insere_fila(fila, 1);
    insere_fila(fila, 4);
    insere_fila(fila, 2);

    exibe_fila(fila);

    insere_prioridade(fila, 5);
    insere_prioridade(fila, 0);

    exibe_fila(fila);

    remove_fila(&fila);
    remove_fila(&fila);

    exibe_fila(fila);

    // Resultado
    // 3 1 4 2 
    // 5 3 1 4 2 0 
    // O elemento foi removido!
    // O elemento foi removido!
    // 1 4 2 0 

    return 0;
}
