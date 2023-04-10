#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    celula *atual = le->prox;
    printf("%d", atual->dado);
    atual = atual->prox;
    while (atual != NULL) {
        printf(" -> %d", atual->dado);
        atual = atual->prox;
    }
    printf(" -> NULL\n");
}

void insere_inicio(celula *le, int x) {
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->dado = x;
    while (atual->prox != NULL && atual->prox->dado != y) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
}

int main () {
  celula *le;
  le = malloc(sizeof(celula));
  le->prox = NULL;
  insere_inicio(le, 10);
  insere_inicio(le, 20);
  insere_inicio(le, 30);
  imprime(le);
  return 0;
}



