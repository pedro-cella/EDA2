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

void inserir_depois(celula *le, int x){
    celula* novo = malloc(sizeof(celula));
    celula* atual = malloc(sizeof(celula));
    
    novo->dado = x;
    atual = le->prox;

    if(le->prox == NULL){
        le->prox = novo;
        novo->prox = NULL;
    }else{
        while(atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novo;
        novo->prox = NULL;
    }
}

int main(){

    // Alocação Dinâmica
    // celula* l1 = malloc(sizeof(celula));
    // celula* l2 = malloc(sizeof(celula));
    // celula* l3 = malloc(sizeof(celula));

    // celula* valor1 = malloc(sizeof(celula));
    // celula* valor7 = malloc(sizeof(celula));
    // celula* valor9 = malloc(sizeof(celula));
    // celula* valor10 = malloc(sizeof(celula));

    // valor1->dado = 1;
    // valor7->dado = 7;
    // valor9->dado = 9;
    // valor10->dado = 10;

    // l1->prox = valor1;
    // valor1->prox = valor7;
    // valor7->prox = valor9;
    // valor9->prox = valor10;
    // valor10->prox = NULL;

    // Alocação Automática

    // celula l1;
    // celula l2;
    // celula l3;

    // celula valor1;
    // celula valor7;
    // celula valor9;
    // celula valor10;

    // valor1.dado = 1;
    // valor7.dado = 7;
    // valor9.dado = 9;
    // valor10.dado = 10;

    // l1.prox = &valor1;
    // valor1.prox = &valor7;
    // valor7.prox = &valor9;
    // valor9.prox = &valor10;
    // valor10.prox = NULL;

    celula* l1 = malloc(sizeof(celula));
    l1->prox = NULL;

    inserir_depois(l1, 34);

    imprime(l1);

    return 0;
}