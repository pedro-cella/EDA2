#include <stdio.h>
#include <stdlib.h>

int main(){

    int inteiro = 4, *ponteiro_int;
    float real = 2.5, *ponteiro_float;
    char caracter = 'a', *ponteiro_char;

    ponteiro_int = &inteiro;

    ponteiro_float = &real;

    ponteiro_char = &caracter;

    printf("ANTES\nponteiro de inteiro: %d\nponteior de real: %.2f\nponteiro de caractere: %c\n", *ponteiro_int, *ponteiro_float, *ponteiro_char);

    *ponteiro_int = 7;

    *ponteiro_float = 43.78;

    *ponteiro_char = 'd';

    printf("DEPOIS\nponteiro de inteiro: %d\nponteior de real: %.2f\nponteiro de caractere: %c\n", *ponteiro_int, *ponteiro_float, *ponteiro_char);

    return 0;
}