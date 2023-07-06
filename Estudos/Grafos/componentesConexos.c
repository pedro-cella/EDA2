#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no {
    int v;
    p_no prox;
};

typedef struct grafo *p_grafo;

struct grafo {
    p_no *adjacencia;
    int n;
};

p_grafo criar_grafo(int n) {
    int i;
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adjacencia = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++)
        g->adjacencia[i] = NULL;
    return g;
}

p_no insere_na_lista(p_no lista, int v) {
    p_no novo = malloc(sizeof(struct no));
    novo->v = v;
    novo->prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v) {
    g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
    g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
}

void visita(p_grafo g, int* comp, int c, int v) {
    comp[v] = c;
    for (p_no t = g->adjacencia[v]; t != NULL; t = t->prox)
        if (!comp[t->v])
            visita(g, comp, c, t->v);
}

int* componentes(p_grafo g) {
    int c = 0;
    int* comp = calloc(g->n, sizeof(int));
    for (int v = 0; v < g->n; v++) {
        if (!comp[v]) {
            c++;
            visita(g, comp, c, v);
        }
    }
    return comp;
}

void imprimeGrafo(p_grafo g) {
    if (g == NULL) {
        printf("Grafo vazio.\n");
        return;
    }

    for (int u = 0; u < g->n; u++) {
        printf("Vértice %d:", u);
        p_no t = g->adjacencia[u];
        if (t == NULL) {
            printf(" Nenhum vértice adjacente\n");
        } else {
            while (t != NULL) {
                printf(" %d", t->v);
                t = t->prox;
            }
            printf("\n");
        }
    }
}

int main() {
    p_grafo g = criar_grafo(10);

    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 3);
    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 3);

    insere_aresta(g, 6, 4);
    insere_aresta(g, 4, 5);

    insere_aresta(g, 7, 8);

    // Vértice 9 não possui arestas

    imprimeGrafo(g);

    free(g);

    return 0;
}
