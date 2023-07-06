#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    celula *atual = le->prox;
    printf("%d", atual->dado);
    atual = atual->prox;
    while (atual != NULL) {
        printf(" -> %d", atual->dado);
        atual = atual->prox;
    }
    printf(" -> NULL\n");
}

void imprime_rec_aux(celula *p) {
  if (p != NULL) {
    printf("%d -> ", p->dado);
    imprime_rec_aux(p->prox);
  } else {
    printf("NULL\n");
  }
}

void imprime_rec(celula *le) {
  if (le->prox != NULL) {
    imprime_rec_aux(le->prox);
  } else {
    printf("NULL\n");
  }
}

void insere_inicio(celula *le, int x) {
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->dado = x;
    while (atual->prox != NULL && atual->prox->dado != y) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
}

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0;
    }
    celula *prox = p->prox;
    p->prox = prox->prox;
    int valor = prox->dado;
    free(prox);
    return valor;
}

void remove_elemento(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;
    while (atual != NULL) {
        if (atual->dado == x) {
            anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *anterior = le;
    celula *atual = le->prox;
    while (atual != NULL) {
        if (atual->dado == x) {
            anterior->prox = atual->prox;
            free(atual);
            atual = anterior->prox;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

celula *busca (celula *le, int x){
    celula *atual = le->prox;
    while(atual != NULL){
        if(atual->dado == x){
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

celula *busca_rec (celula *le, int x) {
    if (le == NULL) {
        return NULL;
    } else if (le->dado == x) {
        return le;
    } else {
        return busca_rec(le->prox, x);
    }
}

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *atual1 = l1->prox;
    celula *atual2 = l2->prox;
    celula *atual3 = l3;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->dado <= atual2->dado) {
            atual3->prox = atual1;
            atual1 = atual1->prox;
        } else {
            atual3->prox = atual2;
            atual2 = atual2->prox;
        }
        atual3 = atual3->prox;
    }

    if (atual1 != NULL) {
        atual3->prox = atual1;
    } else {
        atual3->prox = atual2;
    }
}

void imprime_lista_professor (celula *le) {
  le = le->prox;
  printf ("le");
  while (le != NULL) {
    printf (" -> %d", le->dado);
    le = le->prox;
  }
  printf (" -> NULL\n");
}

void mescla_listas_professor (celula *l1, celula *l2, celula *l3) {
  l1 = l1->prox;
  l2 = l2->prox;
  while (l1 != NULL && l2 != NULL) {
    if (l1->dado < l2->dado) {
      l3->prox = l1;
      l1 = l1->prox;
    }
    else {
      l3->prox = l2;
      l2 = l2->prox;
    }
    l3 = l3->prox;
  }

  if (l1 != NULL) l3->prox = l1;
  if (l2 != NULL) l3->prox = l2;
}

int main () {
  celula l1, l2, l3;
  celula celula1;
  celula celula2;
  celula celula3;
  celula celula7;
  celula celula8;
  celula celula9;
  celula celula10;

  celula1.dado = 1;
  celula2.dado = 2;
  celula3.dado = 3;
  celula7.dado = 7;
  celula8.dado = 8;
  celula9.dado = 9;
  celula10.dado = 10;

  l1.prox = &celula1;
  celula1.prox = &celula7;
  celula7.prox = &celula9;
  celula9.prox = &celula10;
  celula10.prox = NULL;
  
  l2.prox = &celula2;
  celula2.prox = &celula3;
  celula3.prox = &celula8;
  celula8.prox = NULL;

  imprime_lista (&l1);
  imprime_lista (&l2);

  mescla_listas (&l1, &l2, &l3);

  printf ("\n");
  imprime_lista (&l3);

  return 0;
}