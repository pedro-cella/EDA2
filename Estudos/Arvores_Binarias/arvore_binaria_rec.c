#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no* esq;
    struct no* dir;
} no;

void preordem(no* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->dado);
    preordem(raiz->esq);
    preordem(raiz->dir);
}

void emordem(no* raiz) {
    if (raiz == NULL) return;
    emordem(raiz->esq);
    printf("%d ", raiz->dado);
    emordem(raiz->dir);
}

void posordem(no* raiz) {
    if (raiz == NULL) return;
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d ", raiz->dado);
}

int main(){

    no* raiz = malloc(sizeof(no));
    no* raiz_tres = malloc(sizeof(no));
    no* raiz_dezoito = malloc(sizeof(no));
    no* raiz_dois = malloc(sizeof(no));
    no* raiz_sete = malloc(sizeof(no));
    no* raiz_seis = malloc(sizeof(no));

    raiz->dado = 4;
    raiz_tres->dado = 3;
    raiz_dezoito->dado = 18;
    
    raiz_dois->dado = 2;
    raiz_sete->dado = 7;
    raiz_seis->dado = 6;


    raiz->esq = raiz_tres;
    raiz->dir = raiz_dezoito;

    raiz_tres->esq = NULL;
    raiz_tres->dir = raiz_dois;

    raiz_dois->esq = NULL;
    raiz_dois->dir = NULL;

    raiz_dezoito->esq = raiz_sete;
    raiz_dezoito->dir = raiz_seis;

    raiz_sete->esq = NULL;
    raiz_sete->dir = NULL;

    raiz_seis->esq = NULL;
    raiz_seis->dir = NULL;

    preordem(raiz);
    printf("\n");
    emordem(raiz);
    printf("\n");
    posordem(raiz);

    printf("\n");

    return 0;
}
