# Árvores

- Uma árvore é uma estrutura de dados **não-linear** composta por **nós** interligados entre si de tal forma que um nó especial é chamado de ***raiz***. E
os demais nós ligam-se a raiz e formam m>=0 conjuntos disjuntos chamados *subárvores*.


[depois coloque uma imagem que mostre a raiz e as subavores, de uma arvore aleatoria]()

## Conceitos

**Grau**: É a quantidade de subárvore originárias de um nó.

**Folha**: É um nó com grau zero.

**Distância**: É a distância de um nó a outro é a quantidade de arestas entre eles.

**Nível**: É distância de um nó a raiz. 


**Árvore binária**: É uma árvore em que todos os vérticies tem grau menor ou igual a 2.

[coloque uma imagem de uma árvore binária aqui, com todos os níves dela]()

Com isso, temos que, numa árvore binária:
  * Num nível k, podemos ter, no máximo 2<sup>k</sup> nós.
  * Numa árvore com m níveis:

  2<sup>0</sup> + 2<sup>1</sup> + 2<sup>2</sup> + 2<sup>m</sup> = 

  1 * (2 <sup>m+1</sup> - 1)/2-1 =

  2<sup>m+1</sup> - 1<sup>

  [imagem de duas árvores isomorfas (binárias)]()

      OBS: Ás ávores devem ser diferentes, porém isomorfas

## Percursos em árvores binárias

Há 3 formas padrão de se percorrer ávores binárias:
  1. Pré-order (root)
    
    * "visita" a raiz;
    * "visita" a subárvores a esquerda
    * "visite" subárvores a esquerda

  2. Em ordem (erd)

  * Visita a esquerda
  * Visita a raiz
  * Visita a direita


  3. Pós-ordem (edr)

    * Visita a esquerda
    * Visita a direita
    * Visita a raiz

  Ex: Tente pegar o mesmo gŕafico, e ver a ordem da impresdsão dos nós em cada caso.

  [adicione uma imagem com percurso em pré-ordem]()
  [adicione uma imagem com percurso em ordem]()
  [adicione uma imagem com percurso em pós-ordem]()


  Exércicio: Faça os percursos na seguinte árvore



  Pré-order: 8, 4, 3, 2, 18, 7, 6, 10, 11, 13

  Em ordem: 3, 2, 4, 7, 18, 6, 8, 11, 13, 10

  Pós-ordem: 2, 3, 7, 6, 18, 4, 13, 11, 10, 8


  ## Implementação

  ```
    typedef struct no {
      int dado;
      strcut no *esq, *direita;
    } no;

  Duble linked list para representar as árvores


  void preordem ( no *raiz) {
    if (raiz == NULL) return;
    printf("%d", raiz->dado);

    preordem(raiz ->esq);
    preordem(raiz ->dir);
  }
  ```

  * Desafio: Como implementar o algoritmo sem recursão 


  ## Mais alguns conceitos

  1. Altura: A altura da um nó qualquer da árvore é a maior disntância dele a uma folha.

  2. Profundidade: A profundidade de um nó da árvore a sua distnância a raiz.

  * Uma árvore binária é dita **balanceada** se:
    
    * a profundidade das folhas forem iguais ou quase iguais(depende do tamanho da árvore, de 1 a 2, podem ser um pouco mais) E:
    * para todo nó da árvore, a altura da subárvore esquerda, é igual ou quase igual a folha da direita.


    [Coloque um exemplo de árvore balanceada]()

    [Coloque um exemplo de árvore não balanceada]()


É um algoritmo de pré-ordem
```
  int altura (no *raiz) {
    if (raiz == NULL) return -1;
    else {
      int he = altura(raiz->esq);
      int (he > hd) return he + 1;
      else return hd + 1;
    }
  }
```

Complexidade: O<sup>n</sup>


## Árvore binária de busca (ABB) - Ela tende a ser desbalanceda

Uma ABB, é uma árvore tal que, dada uma raiz r de qualquer subárvore:

    e -> chave <= r->chave <= d->chave;

  onde **e** é qualquer nó da subárvore esquerda e **d** é qualquer nó da direita.


- Para cada raiz r da árvore ou qualquer subárvore,

    e -> chave <= r-> chave <= d->chave

  para todo nó da subárvore esquerda e d da direita.


Queremos implementar as seguintes operações:

- inserção
- remoção
- busca
- mínimo
- máximo 

Num vertor ordenado, essas operações custam:

- inserção: O(n)
- remoção: O(n)
- busca: O (lg n)
- mínimo: O (1)
- máximo: O (1)


      OBS: A manutenção do vetor que custa caro

### Busca


              8
          5        12
        2   6   9      13
      1  3        10


Código de busca
```
  no* busca(no *raiz, intx x) {
    if (raiz == NULL || raiz->chave == x) return raiz; // se for contrário pode dar erro(Segmentation Fault), pois o C vê da esquerda para direita

    if (x < raiz -> chave) {
      return busca( raiz->esq, x);
    }
    else {
      return busca(raiz->dir, x);
    }
  }

```

NOTA: depois tente implementar o algoritmo de busca de forma iterativa, não precisa nem de pilha

Complexidade: O(H), onde H é altura árvore (linear)

OBS: Se a árvore for balanceada, a complexidade é O(lg n)

### Inserção:

Inserir (3) na árvore abaixo

              8
          5         12
        2   6    9      13
              

Árvore depois de inserir o 3:


                 8
            5           12
         2     6     9      13
          3   
   

Código:

```
  no *insere(*no raiz, int x) {
    if (raiz == NULL){
      no *novo = malloc(sizeof(no));
      novo -> chave = x;
      novo -> esq = NULL;
      novo -> dir = NULL;
      return novo;
    } 
    if (x < raiz -> chave) {
      raiz -> esq = insere(raiz -> esq, x);
    }
    else {
      raiz -> dir = insere(raiz -> dir, x);
    }
    return raiz;
  }
```
Complexidade: O(h)



### Mínimo

Árvore de exemplo:

                 8
            5           12
        2       6    9      13
          3   


```
no *minimo(no *raiz) {
  if (raiz -> esq == NULL) return raiz;
  return minimo(raiz -> esq);
}
```

Complexidade: O(h)

OBS:: O máximo é o elemento mais a direita.


### Remoção

                  8
            5            12
        2       7     9      13
      1   3   6         11
                      10

Remove(8)


                  8
            5            12
        2       7     11    13
                    10
      1   3   6         
                      
```


```

Se é o sucessor númerico, não tem filho a esquerda. Ex: o sucessor NÚMERICO de 8 é o 9



