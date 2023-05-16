#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Árvore Binária

typedef struct no {
    int dado;
    struct no* esq;
    struct no* dir;
} no;

// Pilha

typedef struct {
    no* data[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, no* value) {
    if (isFull(stack)) {
        printf("Erro: a pilha está cheia.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

no* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia.\n");
        return NULL;
    }
    return stack->data[stack->top--];
}

void freeStack(Stack* stack) {
    free(stack);
}


// Árvore Binária

void preOrdemIterativa(no* raiz) {
    if (raiz == NULL) return;
    
    // Cria uma pilha para armazenar os nós
    Stack* pilha = createStack();
    
    // Empilha a raiz
    push(pilha, raiz);
    
    while (!isEmpty(pilha)) {
        // Desempilha o nó atual e imprime o valor
        no* atual = pop(pilha);
        printf("%d ", atual->dado);
        
        // Empilha o filho direito primeiro para ser processado depois do filho esquerdo
        if (atual->dir != NULL)
            push(pilha, atual->dir);
        
        // Empilha o filho esquerdo
        if (atual->esq != NULL)
            push(pilha, atual->esq);
    }
    
    // Libera a pilha
    freeStack(pilha);
}

void emOrdemIterativa(no* raiz) {
    Stack* pilha = createStack();
    no* atual = raiz;
    
    while (!isEmpty(pilha) || atual != NULL) {
        if (atual != NULL) {
            // Empilha o nó atual e vai para o filho esquerdo
            push(pilha, atual);
            atual = atual->esq;
        } else {
            // Quando o nó atual for NULL, desempilha um nó, imprime seu valor e vai para o filho direito
            atual = pop(pilha);
            printf("%d ", atual->dado);
            atual = atual->dir;
        }
    }
    
    freeStack(pilha);
}

void posOrdemIterativa(no* raiz) {
    Stack* pilha1 = createStack();
    Stack* pilha2 = createStack();
    
    push(pilha1, raiz);
    
    while (!isEmpty(pilha1)) {
        no* atual = pop(pilha1);
        push(pilha2, atual);
        
        if (atual->esq != NULL)
            push(pilha1, atual->esq);
        
        if (atual->dir != NULL)
            push(pilha1, atual->dir);
    }
    
    while (!isEmpty(pilha2)) {
        no* atual = pop(pilha2);
        printf("%d ", atual->dado);
    }
    
    freeStack(pilha1);
    freeStack(pilha2);
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

    preOrdemIterativa(raiz);
    printf("\n");
    emOrdemIterativa(raiz);
    printf("\n");
    posOrdemIterativa(raiz);

    printf("\n");

    return 0;
}