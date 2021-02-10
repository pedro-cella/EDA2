#include <stdio.h>
#include <stdlib.h>

int *intercala(int *a, int la, int ra, int *b, int lb, int rb)
{
    int ta = (ra - la + 1);
    int tb = (rb - lb + 1);

    int *c = malloc(sizeof(int) * (ta + tb));
    int lc = 0;
    int rc = (ta + tb - 1);
    int ia = la;
    int ib = lb;
    int ic = 0;

    while(ia <= ra && ib <= rb){
        if(a[ia] <= b[ib]){
            c[ic] = a[ia];
            ic++;
            ia++;
        }
        else{
            c[ic] = b[ib];
            ic++;
            ib++;
        }
    }

    while(ia <= ra)
        c[ic++] = a[ia++];
    while(ib <= rb)
        c[ic++] = b[ib++];

    return c;
}

int main(){

    int *vetor, Si, somador=0, *vetor_resultante;

    for(int i = 0; i < 8; i++){
        scanf("%d", &Si);
        vetor = malloc(sizeof(int) * Si);

        for(int j = 0; j < Si; j++){
            scanf("%d", &vetor[j]);
        }

        vetor_resultante = intercala(vetor, 0, Si-1, vetor_resultante, 0, somador-1);
        somador+=Si;
    }

    for(int i = 0; i < somador; i++){
        if(i == somador - 1){
            printf("%d\n", vetor_resultante[i]);
        }else{
            printf("%d ", vetor_resultante[i]);
        }
    }

    free(vetor);

    return 0;
}
