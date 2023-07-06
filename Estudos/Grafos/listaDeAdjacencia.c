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

p_grafo criar_grafo(int n);
void destroi_grafo(p_grafo g);
void insere_aresta(p_grafo g, int u, int v);
void remove_aresta(p_grafo g, int u, int v);
int tem_aresta(p_grafo g, int u, int v);
void imprime_arestas(p_grafo g);

p_grafo criar_grafo(int n) {
    int i;
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adjacencia = malloc(n * sizeof(p_no));
    for (i = 0; i < n; i++)
        g->adjacencia[i] = NULL;
    return g;
}

void libera_lista(p_no lista) {
    if (lista != NULL) {
        libera_lista(lista->prox);
        free(lista);
    }
}

void destroi_grafo(p_grafo g) {
    int i;
    for (i = 0; i < g->n; i++)
        libera_lista(g->adjacencia[i]);
    free(g->adjacencia);
    free(g);
}


p_no insere_na_lista(p_no lista , int v) {
    p_no novo = malloc(sizeof(struct no));
    novo->v = v;
    novo->prox = lista;
    return novo;
}

void insere_aresta(p_grafo g, int u, int v) {
    g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
    g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
}

p_no remove_da_lista(p_no lista , int v) {
    p_no proximo;
    if (lista == NULL)
        return NULL;
    else if (lista->v == v) {
        proximo = lista->prox;
        free(lista);
        return proximo;
    } else {
        lista->prox = remove_da_lista(lista->prox , v);
        return lista;
    }
}

void remove_aresta(p_grafo g, int u, int v) {
    g->adjacencia[u] = remove_da_lista(g->adjacencia[u], v);
    g->adjacencia[v] = remove_da_lista(g->adjacencia[v], u);
}

int tem_aresta(p_grafo g, int u, int v) {
    p_no t;
    for (t = g->adjacencia[u]; t != NULL; t = t->prox)
        if (t->v == v)
            return 1;
    return 0;
}

void imprime_arestas(p_grafo g) {
    int u;
    p_no t;
    for (u = 0; u < g->n; u++)
        for (t = g->adjacencia[u]; t != NULL; t = t->prox)
            printf("{%d,%d}\n", u, t->v);
}

void imprimeGrafo(p_grafo g) {
    if (g == NULL) {
        printf("Grafo vazio.\n");
        return;
    }

    int u;
    p_no t;
    for (u = 0; u < g->n; u++) {
        printf("Vértice %d:", u);
        
        // Cria um array para armazenar os vértices adjacentes
        int *adjacentes = malloc(g->n * sizeof(int));
        int numAdjacentes = 0;

        // Percorre a lista de adjacência e armazena os vértices adjacentes no array
        for (t = g->adjacencia[u]; t != NULL; t = t->prox) {
            adjacentes[numAdjacentes] = t->v;
            numAdjacentes++;
        }

        // Imprime os vértices adjacentes em ordem reversa
        for (int i = numAdjacentes - 1; i >= 0; i--) {
            printf(" %d", adjacentes[i]);
        }

        // Libera a memória alocada para o array de vértices adjacentes
        free(adjacentes);

        printf("\n");
    }
}



int main() {
    p_grafo g = criar_grafo(5);

    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 4);
    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 1, 4);
    insere_aresta(g, 2, 3);
    insere_aresta(g, 3, 4);

    //imprime_arestas(g);
    imprimeGrafo(g);

    destroi_grafo(g);

    // Resultado
    // {0,4}
    // {0,1}
    // {1,4}
    // {1,3}
    // {1,2}
    // {1,0}
    // {2,3}
    // {2,1}
    // {3,4}
    // {3,2}
    // {3,1}
    // {4,3}
    // {4,1}
    // {4,0}    

    return 0;
}
