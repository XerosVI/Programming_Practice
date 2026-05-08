#include<stdio.h>
int main(void){
    unsigned int n,f1=1,f2=1;
    printf("Inserire numero di elementi della sequenza di fibonacci da stampare:\t");
    scanf("%u",&n);
    if(n==1)
        printf("unico elemento: 1\n");
    else{
        printf("I numeri richiesti sono: 1 1 ");
        for(int i=0; i<n-2; i++){
            f1=f1+f2;
            printf("%u ",f1);
            f2=f1-f2;
        }
    }
    printf("\n");
    return 0;
}