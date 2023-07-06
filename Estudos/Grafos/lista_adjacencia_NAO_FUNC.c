#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó de uma lista de adjacência
typedef struct no {
    int destino;
    struct no* proximo;
} no;

// Estrutura do grafo
typedef struct grafo {
    int numVertices;
    no** adj;
} grafo;

// Função para criar um novo nó
no* criarNo(int destino) {
    no* novoNo = malloc(sizeof(no));
    novoNo->destino = destino;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para criar um grafo com um número especificado de vértices
grafo* criaGrafo(int numVertices) {
    grafo* g = malloc(sizeof(grafo));
    g->numVertices = numVertices;

    g->adj = malloc(numVertices * sizeof(no*));
    for (int i = 0; i < numVertices; i++)
        g->adj[i] = NULL;

    return g;
}

// Função para destruir um grafo
void destroiGrafo(grafo* g) {
    if (g == NULL)
        return;

    int i;
    for (i = 0; i < g->numVertices; i++) {
        no* atual = g->adj[i];
        while (atual != NULL) {
            no* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }

    free(g->adj);
    free(g);
}

// Função para inserir uma aresta direcionada em um grafo
void insereAresta(grafo* g, int origem, int destino) {
    if (g == NULL || origem >= g->numVertices || destino >= g->numVertices)
        return;

    no* novoNo = criarNo(destino);
    novoNo->proximo = g->adj[origem];
    g->adj[origem] = novoNo;
}

// Função para remover uma aresta direcionada de um grafo
void removeAresta(grafo* g, int origem, int destino) {
    if (g == NULL || origem >= g->numVertices || destino >= g->numVertices)
        return;

    no* atual = g->adj[origem];
    no* anterior = NULL;

    while (atual != NULL) {
        if (atual->destino == destino) {
            if (anterior == NULL)
                g->adj[origem] = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }
}

// Função para verificar se uma aresta existe em um grafo
int temAresta(grafo* g, int origem, int destino) {
    if (g == NULL || origem >= g->numVertices || destino >= g->numVertices)
        return 0;

    no* atual = g->adj[origem];

    while (atual != NULL) {
        if (atual->destino == destino)
            return 1;

        atual = atual->proximo;
    }

    return 0;
}

void imprimirGrafo(grafo* g) {
    if (g == NULL) {
        printf("Grafo vazio.\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++) {
        printf("Vértice %d:", i);

        no* atual = g->adj[i];
        if (atual == NULL) {
            printf(" Nenhum vértice adjacente\n");
        } else {
            while (atual != NULL) {
                printf(" %d", atual->destino);
                atual = atual->proximo;
            }
            printf("\n");
        }
    }
}


// Exemplo de uso das funções
int main() {
    // Cria um grafo com 5 vértices
    grafo* g = criaGrafo(5);

    // Insere algumas arestas no grafo
    insereAresta(g, 0, 1);
    insereAresta(g, 0, 4);
    insereAresta(g, 1, 2);
    insereAresta(g, 1, 3);
    insereAresta(g, 1, 4);
    insereAresta(g, 2, 3);
    insereAresta(g, 3, 4);

    // Imprime o grafo
    printf("Grafo:\n");
    imprimirGrafo(g);

    // Verifica se uma aresta existe no grafo
    if (temAresta(g, 1, 4))
        printf("Aresta entre 1 e 4 existe\n");
    else
        printf("Aresta entre 1 e 4 não existe\n");

    if (temAresta(g, 2, 4))
        printf("Aresta entre 2 e 4 existe\n");
    else
        printf("Aresta entre 2 e 4 não existe\n");

    // Remove uma aresta do grafo
    removeAresta(g, 1, 4);

    // Verifica se a aresta removida existe no grafo
    if (temAresta(g, 1, 4))
        printf("Aresta entre 1 e 4 existe\n");
    else
        printf("Aresta entre 1 e 4 não existe\n");

    // Imprime o grafo atualizado
    printf("Grafo atualizado:\n");
    imprimirGrafo(g);

    // Destroi o grafo
    destroiGrafo(g);

    return 0;
}
