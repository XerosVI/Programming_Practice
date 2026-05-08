#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TOMBOLA 90

int f(int[],int);
int main(void){
    int array[TOMBOLA];
    for(int i=0; i<TOMBOLA; i++){
        array[i]=i+1;
    }
    srand(time(NULL));
    f(array,TOMBOLA);
    for(int i=0;i<TOMBOLA;i++)
        printf(" %d",array[i]);
    return 0;
}
int f(int v[], int c){
    int i,t,x;
    for(i=0;v[i]<TOMBOLA;i++){
        x=rand()%c;
        t=v[i];
        v[i]=v[x];
        v[x]=t;
    }
    return i;
}