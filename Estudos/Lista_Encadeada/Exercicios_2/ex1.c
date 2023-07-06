#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

// Versão iterativa
int contador_celulas_iterativo(celula *le) {
    int contador = 0;
    celula *atual = le->prox;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

// Versão recursiva
int contador_celulas_recursivo(celula *le) {
    if (le->prox == NULL) {
        return 0;
    } else {
        return 1 + contador_celulas_recursivo(le->prox);
    }
}

int main() {
    celula *le = malloc(sizeof(celula));
    celula *cabeca_1 = malloc(sizeof(celula));
    celula *cabeca_2 = malloc(sizeof(celula));
    
    le->prox = cabeca_1;
    cabeca_1->prox = cabeca_2;
    cabeca_2->prox = NULL;

    printf("Número de células (iterativo): %d\n", contador_celulas_iterativo(le));
    printf("Número de células (recursivo): %d\n", contador_celulas_recursivo(le));

    free(cabeca_2);
    free(cabeca_1);
    free(le);

    return 0;
}
