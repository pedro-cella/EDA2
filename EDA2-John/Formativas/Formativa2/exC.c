#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 150000 // tamanho da tabela hash

typedef struct celula {
    int chave, ocorr;
    struct celula *prox;
} celula;

int hash(int chave);
void inicializa_hash(celula *th);
void insere_hash(celula *th, int chave);
int busca_numero_proibido(celula *th, int chave);

int hash(int chave) {
    return chave % TABLE_SIZE;
}

void inicializa_hash(celula *th) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        th[i].prox = NULL;
    }
}

void insere_hash(celula *th, int chave) {
    int pos = hash(chave);
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->chave = chave;
    nova->ocorr = 1;
    nova->prox = th[pos].prox;
    th[pos].prox = nova;
}

int busca_numero_proibido(celula *th, int chave) {
    int pos = hash(chave);
    celula *elem = th[pos].prox;
    while (elem != NULL) {
        if (elem->chave == chave && elem->ocorr >= 1) {
            return 1;
        }
        elem = elem->prox;
    }
    return 0;
}

int main() {
    int n, numero_proibido, numero;

    scanf("%d", &n);

    celula *th = (celula *) malloc(TABLE_SIZE * sizeof(celula));
    inicializa_hash(th);

    for (int i = 0; i < n; i++) {
        scanf("%d", &numero_proibido);
        insere_hash(th, numero_proibido);
    }

    while (scanf("%d", &numero) != EOF) {
        if (busca_numero_proibido(th, numero) == 1) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    free(th);

    return 0;
}
