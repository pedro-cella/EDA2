<h1>Anotações de ED2</h1>

<h2>Conteudo Primeira Prova</h2>

<h3>O que vamos ordenar ?</h3>

<p>Arquivos de itens -> chaves(keys)</p>

<h3>Qual o objetivo dos algoritmos de ordenação ?</h3>

<p>O Objetivo dos Algoritmos de Ordenação é de rearranjar os itens de forma que as chaves respeitem a ordem definida.</p>

<h3>O arquivo cabe na memória ?</h3>

<p>
Se sim: Ordenação Interna;<br>
Se não: Ordenação Extera;
</p>

<h3>Convenções</h3>

`typedef int Item;`

<p>O Item representa elementos de vários tipos</p>

`#define key(A)`

<p>A key retorna qual a chave que "eu" precisarei ordenar. Ex:</p>

`struct {int chave, chave home[100]};`

`key(A) retorna (A.chave)`

`#define less(A,B) (key(A) < key(B))`

<p>Retorna o menor valor</p>

`#define exch(A, B) { Item t = A; A = B; B = t; }`

<p>Trocará o elemento que está no item A para o que está no item B</p>

`#define cmpexch(A, B) { if(less(B, A)) exch(A, B); }`

<p>Compara duas chaves e troca</p>

<h3>Algoritmos de Ordenação Estáveis</h3>

<p>O algoritmo de ordenação estável tem a have com a posição dos elementos, ou seja, ele garante que itens com chaves idênticas permaneçam na mesma posição relativa no vetor, ou qualquer conjunto de dados que estão armazenando. Ex:</p>

<p>Organize da maior nota para a menor nota</p>
<ul>
    <li>Bruno 90</li>
    <li>Rose 105</li>
    <li>Nina 90</li>
</ul>

<p>O resultado são duas possibilidades</p>

<ul>
    <li>Bruno 90</li>
    <li>Nina 90</li>
    <li>Rose 105</li>
</ul>

ou

<ul>
    <li>Nina 90</li>
    <li>Bruno 90</li>
    <li>Rose 105</li>
</ul>

<p>Ai fica a dúvida, quem deve vir antes, Bruno, Nina ou tanto faz ?</p>
<p>Nesse caso se ele for um algoritmo de ordenação estável ele garante que o Bruno vai vir antes de Nina, porque Nina já estava no fim do vetor quando começamos a ordenar, mas caso ele não seja então não teremos certeza de quem deve ficar em cima, ficará algo incerto.</p>

<h3>Algoritmos de Ordenação</h3>

<h3>Bubble Sort</h3>

<p align="center">
    <img  src="https://media.giphy.com/media/BdXrpSYzVOf0A/giphy.gif">
</p>

<p>O Bubble Sort é bem parecido com as bolhas de um refrigerante,  a ideia da bolha é que você vai começar a "flutuar" os elementos mais leves enquanto que os elementos mais pesados vão começar a pesar dentro do seu vetor</p>

<p>Vamos implementar!</p>

`void bubblesort(Item *v, int l, int r)`

<p>Nossos parâmetros são: um conjunto de itens armazenados em um vetor, e o intervalo que esse vetor está armazenado, sendo o item mais a esquerda l, e o item mais a direita r, sempre considerando que é um intervalo fechado de elementos.</p>

```

void bubblesort(Item *v, int l, int r)
{
    for(i = l; i < r; i++)
        for(int j = l; j < r; j++)
            if(less(v[j+1], v[j]))
                exch(v[j+1], v[j]);
}

```

<p>Podemos também usar umas das outras funções macro que criamos</p>

```
void bubblesort(Item *v, int l, int r)
{
    for(i = l; i < r; i++)
        for(int j = l; j < r; j++)
            cmpexch(v[j], v[j+1]);
}
```

<p>Dentre os algoritmo de ordenação o bubble sort é o que se comporta pior pelo fato de mesmo tendo um vetor já ordenado ele ainda irá fazer a iteração para saber se os valores já estão ou não ordenados.</p>

<p>OBS: O Bubble Sort é um algoritmo de ordenação estável, ou seja, ele mantém a ordem relativa dos elementos da mesma maneira que eles aparecem no vetor.</p>

<h3>Selection Sort</h3>

<p>Diferentemente do Bubble Sort o selection sort faz uma varredura no vetor sempre procurando o menor elemento, dessa forma o elemento mais a esquerda [e o menor e o elemento mais a direita é o maior</p>

<p>Implementação Recursiva</p>

```
void selectionsort(Item *v, int l, int r)
{
    int min = l;
    for(int j = l+1; j <= r; j++)
    {
        if(less(v[j], v[j+1]))
            min = j;
    }
    exch(v[min], v[l]);
    selectionsort(v, l+1, r);
}

```

<p>Implementação Iterativa</p>

```
void selectionsort(Item *v, int l, int r)
{

    for(int i = l; i < r; i++)
        int min = i;
        for(int j = i + 1; j <= r; j++)
            if(v[j] < v[min]){
                min = j;
            }
        exch(v[min], v[l]);

```

<p>Para comparar o tempo basta usar</p>
 
 ```
time ./meuprograma
 ```

 <p>OBS: o algoritmo de ordenação Selection Sort não é um algoritmo estável, ou seja, ele qubra a propriedade de estabilidade.</p>

 <h3>Insertion Sort</h3>

 <p>O Insertion Sort funciona da seguinte maneira: ele observa os valores que os valores primos ao númeor que ele quer ordenar são maiores</p>

 <p>Maneira Simples "Slow"</p>

```
void insertionsort(Item *v, int l, int r)
{
   for(int i = l + 1; i <= r; i++)
       for(j = i; j > l; j--)
           compexch(v[j], v[j-1])
}

```

<p>Maneira mais Eficiente</p>

```
void insertionsort(Item *v, int l, int r)
{
   for(int i = r; i > l; i--)
       cmpexch(v[i - 1], v[i]);

   for(int i = l + 2; i <= r; i++>)
   {
       int j = i;
       Item temp = v[j];
       while(less(temp, v[j-1]))
       {
           v[j] = v[j-1];
           j--;
       }
       v[j] = temp;
   }
}

```

<p>OBS: O algoritmo de ordenação Insertion Sort é um algoritmo estável</p>

<h3>Merge Sort</h3>

<p>O Merge Sort tem uma vantagem de possuir uma complexidade cnstante de O(nlogn), porém diferentemente dos algoritmos de ordenação elementares vistos antes, o merge é "burro" pois depende de uma outra função para ordenar os elementos do vetor, ou seja, ele não consegue ordenar vetores de tamanho maior que 1, visto que 1 o merge sort sabe que o vetor já está ordenado.</p>

```
void merge (Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;
    while(i <= r1 && j <= r2){
        if(less(v[i], v[j]))
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }
    while(i <= r1)
        v2[k++] = v[i++];
    while(i <= r2)
        v2[k++] = v[j++];
    k = 0;
    for(i = l; i <= r2; i++)
        v[i] = v2[k++];
    free(v2);
}
```

```
void mergesort(Item *v, int l, int r){
    if (l >= r) return;
    int meio = (r+l)/2;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    mergeAB(v, l, meio, r);
}
```
