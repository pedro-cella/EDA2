#include <stdio.h>
#include <stdlib.h>

// O algoritmo Selection Sort possui complexidade O(n^2)
// Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
// Dado a definição de estabilidade o algoritmo de ordenação Selection Sort não é um algoritmo de ordenação estável(Depende do algoritmo)

// O fato dele não ser estável é porque dependendo das trocas, ele não mantém a ordem relativa dos valores iguais. 
// Exemplo: [1, 7a, 7b, 2], chamei 7a e 7b apenas para ficar claro a ordem de cada um
// Na primeira iteração, o menor valor é 1 e, por isso, fica na posição em que está. Depois, na segunda iteração o menor valor é 2 e deve trocar de lugar com 7a. O resultado parcial é:
// Resultado parcial: [1, 2, 7b, 7a]
// Na terceira iteração 7b é o menor e fica no lugar em que está. Na última iteração 7a
// já o menor do array restante e fica no lugar em que está.
// Como resultado, temos que 7a
// vinha antes de 7b no array original, mas essa ordem relativa foi trocada depois da ordenação. Portanto, o algoritmo não é estável.

// Creditos do exemplo: https://joaoarthurbm.github.io/eda/posts/selection-sort/

// Exemplo de teste do Selection Sort
// Entrada: 7 3 2 5 4 3
// Saida: 2 3 3 4 5 7


typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(A,B)) exch(A,B); }

void selectionsort(Item *v, int l, int r){
    for(int i = l; i < r; i++){
        int min = i;
        for(int j = i+1; j <=r; j++){
            if(less(v[j], v[min])){
                min = j;
            }
        }
        exch(v[i], v[min]);
    }
}

int main(){

    Item vetor[1000];
    int i = 0;

    while(scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    selectionsort(vetor, 0, i-1);

    for(int x = 0; x < i; x++){
        if(x == i-1){
            printf("%d\n", vetor[x]);
        }else{
            printf("%d ", vetor[x]);
        }
    }


    return 0;
}