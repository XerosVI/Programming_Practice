#include<stdio.h>
int main (void){
    unsigned int i;
    unsigned long int n;

    printf("Inserire numero:\t");
    scanf("%lu",&n);

    for(i=n;i>1;i--){
        n*=(i-1);
    }

    if(n==0)
        n=1;

    printf("fattoriale=%lu\n",n);

    return 0;
}