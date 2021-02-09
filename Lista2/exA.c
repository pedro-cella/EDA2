#include <stdio.h>
#include <stdlib.h>

void merge(int *V, int l, int m, int r){
    int *R = malloc(sizeof(int) * (r-l+1));
    int i=l, j=m+1, k=0;

    while(i<=m && j<=r){
        if(V[i] <= V[j])
            R[k++]=V[i++];
        else
            R[k++]=V[j++];
    }

    while(i<=m)
        R[k++]=V[i++];
    while(j<=r)
        R[k++]=V[j++];

    k=0;
    for(i=l;i<=r;i++)
        V[i]=R[k++];

    free(R);
}

int main(){
    int n, i, *ptr, sum = 0;

    scanf("%d", &n);

    // dynamic memory allocation using malloc()
    ptr = (int *) malloc(n*sizeof(int));

    if(ptr == NULL) // if empty array
    {
        printf("\n\nError! Memory not allocated\n");
        return 0;   // end of program
    }

    for(i = 0; i < n; i++)
    {
        // storing elements at contiguous memory locations
        scanf("%d", ptr+i);    
        sum = sum + *(ptr + i);
    }

    mergesort(ptr, 0, n-1);

    // printing the array elements using pointer to the location
    // printf("\n\nThe elements of the array are: ");
    for(i = 0; i < n; i++)
    {
        if(i == n - 1){
            printf("%d\n",ptr[i]);   // ptr[i] is same as *(ptr + i)
        } else{
            printf("%d ",ptr[i]); 
        }
    }

    free(ptr);

    return 0;
}