#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *atual1 = l1->prox;
    celula *atual2 = l2->prox;
    celula *atual3 = l3;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->dado <= atual2->dado) {
            atual3->prox = atual1;
            atual1 = atual1->prox;
        } else {
            atual3->prox = atual2;
            atual2 = atual2->prox;
        }
        atual3 = atual3->prox;
    }

    if (atual1 != NULL) {
        atual3->prox = atual1;
    } else {
        atual3->prox = atual2;
    }
}
