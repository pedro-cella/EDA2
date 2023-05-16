#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int chave, ocorr;
  struct celula *prox;
} celula;

int hash (int chave, int M);
void inicializa_hash (celula *th, int M);
int insere_hash (celula *th, int chave, int M);
int busca_maior_ocorr(celula *th, int M);

int hash (int chave, int M) {
  return chave % M;
}

void inicializa_hash (celula *th, int M) {
  for (int i = 0; i < M; i++) th[i].prox = NULL;
}

int insere_hash (celula *th, int chave, int M) {
  celula *elem;
  int pos = hash (chave, M);

  for (elem = th[pos].prox;
       elem != NULL && elem->chave != chave;
       elem = elem->prox);

  if (elem != NULL) elem->ocorr++;
  else {
    celula *nova = malloc (sizeof (celula));
    if (nova == NULL) return 1;
    nova->chave = chave;
    nova->ocorr = 1;
    nova->prox = th[pos].prox;
    th[pos].prox = nova;
  }

  return 0;
}

int busca_maior_ocorr(celula *th, int M){

    int maior_ocorr = 0, maior_nota = 0;
    celula *elem;

    for(int i = 0; i < M; i++){
        elem = th[i].prox;
        //elem = (th + i)->prox;
        while(elem != NULL){
            if(elem->ocorr > maior_ocorr){
                maior_ocorr = elem->ocorr;
                maior_nota = elem->chave;
            }else if(elem->ocorr == maior_ocorr && elem->chave > maior_nota){
                maior_nota = elem->chave;
            }
            elem = elem->prox;
        }
    }

    return maior_nota;

}

int main(){

    int N, nota;

    scanf("%d", &N);

    celula th[N];

    inicializa_hash(th, N);

    for(int i = 0; i < N; i++){
        scanf("%d", &nota);
        insere_hash(th, nota, N);
    }

    printf("%d\n", busca_maior_ocorr(th, N));

    return 0;
}
