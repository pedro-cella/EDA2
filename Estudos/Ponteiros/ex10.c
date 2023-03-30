#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[6];

    int* ptr = array;

    printf("array[0] = %p\n", array);
    printf("ponteiro = %p\n", ptr);

    for(int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("array[%d] = %d\n", i, array[i]);
        printf("2 * array[%d] = %d\n", i, 2*(*ptr + i));
    }

    return 0;
}