#include<stdio.h>
int fibonacci(int);

int main(void){
    int n;
    printf("Inserire numero di cui calcolare la funzione di fibonacci:\t");
    scanf("%d", &n);
    printf("Fibonacci=%d\n", fibonacci(n));
    return 0;
}

int fibonacci(int x){
    if (x<=1)
        return x;
    else   
        x=fibonacci(x-1)+fibonacci(x-2);
}