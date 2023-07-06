#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct {
    Item *v;
    int n;      // n -> quantidade de elementos
    int tam;    // tam -> tamanho do vetor
} FP;

// Função para imprimir o vetor da fila de prioridade
void imprime_vetor(FP *fp) {
    for (int i = 0; i < fp->n; i++) {
        printf("%d ", fp->v[i]);
    }
    printf("\n");
}

void troca(Item *v, int i, int j) {
    Item tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void sobe_no_heap(FP *fp, int i) {
    int pai = (i - 1) / 2;
    if (i > 0 && fp->v[pai] < fp->v[i]) { //i > 0 ? porque usar
        //printf("entrou: i = %d\n", i);
        troca(fp->v, i, pai);
        sobe_no_heap(fp, pai);
    }
}

// Função auxiliar para obter o valor máximo entre dois itens
Item max(Item a, Item b) {
    return (a > b) ? a : b;
}

// Função auxiliar para obter o índice do item de maior valor
int maxind(Item *v, int a, int b) {
    if(v[a] > v[b]){
        return a;
    }else {
        return b;
    }
}

void desce_no_heap(FP *fp, int i) {
    int fe = 2 * i + 1;
    int fd = 2 * i + 2; // ou fd = fe + 1;

    printf("fp->n: %d\n", fp->n);

    if (fe >= fp->n) return;
    if (fd >= fp->n) fd = fe;

    if(i < fp->n && fp->v[i] < max(fp->v[fe], fp->v[fd])){
        troca(fp->v, i, maxind(fp->v, fe, fd));
        desce_no_heap(fp, maxind(fp->v, fe, fd));
    }
}

// Inserção
void insere(FP *fp, Item it) {
    if (fp->n == fp->tam) {
        fp->v = realloc(fp->v, 2 * fp->tam * sizeof(Item));
        fp->tam *= 2;
    }
    fp->v[fp->n] = it;
    sobe_no_heap(fp, fp->n);
    fp->n++;
}

// Remoção
Item remove_elem(FP *fp) {
    if (fp->n > 0) {
        troca(fp->v, 0, fp->n - 1);
        fp->n--;
        
        imprime_vetor(fp);

        desce_no_heap(fp, 0);
        return fp->v[fp->n+1];
    }
}

int main() {
    // Exemplo de uso
    FP fp;
    fp.tam = 10;
    fp.v = malloc(fp.tam * sizeof(Item));
    fp.n = 0;

    // insere(&fp, 5);
    // insere(&fp, 2);
    // insere(&fp, 8);

    // Exemplo John

    imprime_vetor(&fp);

    insere(&fp, 10);
    imprime_vetor(&fp);
    insere(&fp, 9);
    imprime_vetor(&fp);
    insere(&fp, 4);
    imprime_vetor(&fp);
    insere(&fp, 7);
    imprime_vetor(&fp);
    insere(&fp, 8);
    imprime_vetor(&fp);
    insere(&fp, 6);
    imprime_vetor(&fp);
    insere(&fp, 1);
    imprime_vetor(&fp);
    insere(&fp, 5);
    imprime_vetor(&fp);
    insere(&fp, 3);
    imprime_vetor(&fp);
    insere(&fp, 2);
    imprime_vetor(&fp);

    insere(&fp, 11);

    // Exemplo professora UFScar

    // insere(&fp, 6);
    // insere(&fp, 3);
    // insere(&fp, 5);
    // insere(&fp, 2);
    // insere(&fp, 1);
    // insere(&fp, 4);

    // Imprimir os elementos
    imprime_vetor(&fp);

    printf("\nRemocao\n");

    remove_elem(&fp);
    // Imprimir os elementos
    imprime_vetor(&fp);

    free(fp.v);

    // Resultado
    // 8 2 5 
    // Elemento removido: 5
    // 8 2 

    // Resultado John

    // 10 9 6 7 8 4 1 5 3 2 
    // Elemento removido: 2
    // 9 8 6 7 10 4 1 5 3

    // Resultado professora UFScar
    // 6 3 5 2 1 4 
    // Elemento removido: 4
    // 5 3 6 2 1 

    return 0;
}
