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

void imprime_rec_aux(celula *p) {
  if (p != NULL) {
    printf("%d -> ", p->dado);
    imprime_rec_aux(p->prox);
  } else {
    printf("NULL\n");
  }
}

void imprime_rec(celula *le) {
  if (le->prox != NULL) {
    imprime_rec_aux(le->prox);
  } else {
    printf("NULL\n");
  }
}