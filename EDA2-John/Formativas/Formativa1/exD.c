#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *atual = le->prox;
    while(atual != NULL){
        if(atual->dado == x){
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

celula *busca_rec (celula *le, int x) {
    if (le == NULL) {
        return NULL;
    } else if (le->dado == x) {
        return le;
    } else {
        return busca_rec(le->prox, x);
    }
}
