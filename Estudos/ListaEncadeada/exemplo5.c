#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int         conteudo;
   struct reg *prox;
} celula;

int main (void) {
   printf ("sizeof (celula) = %ld\n", 
            sizeof (celula));
   return EXIT_SUCCESS;
}