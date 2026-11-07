#include<stdio.h>

int linear_search(int [], int, int);

int main(void){
    int arr[5]={1,2,3,4,5};
    printf("%do indice a partire da 1", linear_search(arr,5,4)+1);
    if(linear_search(arr,5,6)>=5)
    printf("Non trovato");
}

int linear_search(int v[], int n, int x){
    if(n==0||v[0]==x){
        return 0;
    }
    else
        return 1+linear_search(v+1, n-1, x);
}
