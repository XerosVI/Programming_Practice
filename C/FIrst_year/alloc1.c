#include<stdio.h>
#include<stdlib.h>

int *crea_arr(size_t n);
int somma(int *a, size_t n);

int main(void){
    printf("Quanti numeri interi desideri inserire?\t");
    size_t dim;
    scanf("%zu",&dim);
    int *array=crea_arr(dim);
    printf("%d",somma(array, dim));
    free(array);
    return 0;
}

int *crea_arr(size_t n){
    int *a=malloc(n*sizeof(int));
    for(size_t i=0; i<n; i++){
        printf("\nInserire valore elemento %zu\t", i);
        scanf("%d",a+i);
    }
    return a;
}

int somma(int *a,size_t n){
    int s=0;
    for(size_t i=0; i<n; i++){
        s+=a[i];
    }
    return s;
}