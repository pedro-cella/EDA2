#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 24036583

typedef struct {
    unsigned int chave;
    char caractere;
} celula;

celula th[TABLE_SIZE];

void inicializa_hash();
unsigned int hash(unsigned int chave);
int sondagemLinear(int pos);
void insert(unsigned int chave, char caractere);
void imprimir();

int main() {
    inicializa_hash();
    unsigned int chave;
    char caractere;

    while (scanf("%u %c", &chave, &caractere) != EOF) {
        insert(chave, caractere);
    }

    imprimir();

    return 0;
}

void inicializa_hash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        th[i].chave = 0;
    }
}

unsigned int hash(unsigned int chave) {
    return chave % TABLE_SIZE;
}

int sondagemLinear(int pos) {
    return (pos + 1) % TABLE_SIZE;
}

void insert(unsigned int chave, char caractere) {
    int pos = hash(chave);
    int initialPos = pos;

    while (th[pos].chave != 0) {
        if (th[pos].chave == chave && th[pos].caractere == caractere) {
            return;
        }
        pos = sondagemLinear(pos);
        if (pos == initialPos) {
            return;
        }
    }

    th[pos].chave = chave;
    th[pos].caractere = caractere;
}

void imprimir() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (th[i].chave != 0) {
            printf("%c", th[i].caractere);
        }
    }
    printf("\n");
}
