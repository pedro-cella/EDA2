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

int tem_aresta(grafo *g, int u, int v){
    return g->adj[u][v];
}


// Algoritmo John
grafo *le_grafo(){
    int n, u, v;
    scanf("%d", &n);
    grafo *g = cria_grafo(n);
    while(scanf("%d%d", &u, &v) != EOF)
        insere_aresta(g, u, v);
    return g;
}

int grau(grafo *g, int u){
    int grau = 0;
    for(int v = 0; v < g->n; v++)
        if(g->adj[u][v]) grau++;

    return grau;
}

// Código relacionado ao problema passado pelo professor:
/*
    Temos um grago G que representa conexões de n pesssoas no Facebook.
    Faça um algoritmo para recomendar amigos da seguinte forma:
    dada uma pessoa qualquer, suas recomendações serão amigos de amigos
    não pertencentes à sua lista de amizade
*/

// Algoritmo
void recomenda(grafo *g, int u){
    int *rec = calloc(g->n, sizeof(int));
    for(int v = 0; v < g->n; v++)
        if(g->adj[u][v])
            for(int w = 0; w < g->n; w++)
                if(g->adj[v][w] && g->adj[u][w] == 0 && w != u && !rec[w]){
                    printf("%d", w);
                    rec[w] = 1;
                }
}

void imprime_grafo(grafo *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}


int main() {
    grafo *g = cria_grafo(5);
    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 3);
    insere_aresta(g, 2, 4);

    int grau_vertice_zero = grau(g, 0);
    int grau_vertice_dois = grau(g, 2);

    printf("Grafo:\n");
    imprime_grafo(g);

    printf("Grau do vértice 0: %d\n", grau_vertice_zero);
    printf("Grau do vértice 2: %d\n", grau_vertice_dois);


    destroi_grafo(g);

    return 0;
}
