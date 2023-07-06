#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int chave;
} Item;

typedef struct {
    Item *v;
    int n, tamanho;
} FP;

typedef FP * p_fp;

p_fp criar_filaprio(int tam);

void insere(p_fp fprio, Item item);

Item extrai_maximo(p_fp fprio);

int vazia(p_fp fprio);

int cheia(p_fp fprio);

void troca(Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam) {
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void insere(p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
}

Item extrai_maximo(p_fp fprio) {
    int j, max = 0;
    for (j = 1; j < fprio->n; j++)
        if (fprio->v[max].chave < fprio->v[j].chave)
            max = j;
    troca(&(fprio->v[max]), &(fprio->v[fprio->n-1]));
    fprio->n--;
    return fprio->v[fprio->n];
}

int vazia(p_fp fprio) {
    return fprio->n == 0;
}

int cheia(p_fp fprio) {
    return fprio->n == fprio->tamanho;
}

int main() {
    p_fp fprio = criar_filaprio(5);
    
    printf("Fila de prioridade vazia? %s\n", vazia(fprio) ? "Sim" : "Não");
    printf("Fila de prioridade cheia? %s\n", cheia(fprio) ? "Sim" : "Não");

    Item item1 = {"Item 1", 10};
    Item item2 = {"Item 2", 20};
    Item item3 = {"Item 3", 30};
    Item item4 = {"Item 4", 40};
    Item item5 = {"Item 5", 50};


    insere(fprio, item1);
    insere(fprio, item2);
    insere(fprio, item3);
    insere(fprio, item4);
    insere(fprio, item5);

    printf("Fila de prioridade vazia? %s\n", vazia(fprio) ? "Sim" : "Não");
    printf("Fila de prioridade cheia? %s\n", cheia(fprio) ? "Sim" : "Não");

    extrai_maximo(fprio);

    printf("Fila de prioridade vazia? %s\n", vazia(fprio) ? "Sim" : "Não");
    printf("Fila de prioridade cheia? %s\n", cheia(fprio) ? "Sim" : "Não");

    free(fprio->v);
    free(fprio);

    return 0;
}
