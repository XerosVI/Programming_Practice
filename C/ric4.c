#include<stdio.h>

int evensum(int n, int k);

int main(void){
    int k,n;
    printf("inserire k ed n");
    scanf("%d %d", &k, &n);
    printf("%d", evensum(n,k));
}

int evensum(int n, int k){
    if(n==0){
        return 0;
    }
    if(k%2==0){
        return k+2+evensum(n-1,k+2);
    }
    else{
        return k+1+evensum(n-1, k+1);
    }
}