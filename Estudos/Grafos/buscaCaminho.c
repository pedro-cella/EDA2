#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **adj; // matriz de adjacência
    int n;
} grafo;

grafo *cria_grafo(int n){
    grafo *g = malloc(sizeof(grafo));
    g->n = n;
    g->adj = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++)
        g->adj[i] = calloc(n, sizeof(int));
    return g;
}

void destroi_grafo(grafo *g){
    for(int i = 0; i < g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}

void insere_aresta(grafo *g, int u, int v){
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void remove_aresta(grafo *g, int u, int v){
    g->adj[u][v] = g->adj[v][u] = 0;
}

int busca_rec(grafo *g, int u, int v, int *visitado){
    visitado[u] = 1;
    if(u == v) return 1;
    for(int w = 0; w < g->n; w++)
        if(g->adj[u][w] && !visitado[w])
            if(busca_rec(g, w, v, visitado)) return 1;
    return 0;
}

int busca_caminho(grafo *g, int u, int v){
    int *visitado = calloc(g->n, sizeof(int));
    return busca_rec(g, u, v, visitado);
}

void imprime_grafo(grafo *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    grafo *g = cria_grafo(16);
    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 4);
    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 4);
    insere_aresta(g, 2, 3);
    insere_aresta(g, 2, 6);
    insere_aresta(g, 3, 7);
    insere_aresta(g, 6, 7);
    insere_aresta(g, 6, 11);
    insere_aresta(g, 7, 11);
    insere_aresta(g, 4, 8);
    insere_aresta(g, 8, 9);
    insere_aresta(g, 8, 12);
    insere_aresta(g, 8, 13);
    insere_aresta(g, 9, 5);
    insere_aresta(g, 9, 10);
    insere_aresta(g, 9, 12);
    insere_aresta(g, 5, 10);
    insere_aresta(g, 13, 12);
    insere_aresta(g, 10, 13);
    insere_aresta(g, 10, 14);
    insere_aresta(g, 14, 13);
    insere_aresta(g, 14, 15);

    imprime_grafo(g);
}