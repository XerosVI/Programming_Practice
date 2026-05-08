#include<stdio.h>
int main(void){
    int n,i,t=1,l=0;
    printf("inserire n");
    scanf("%d",&n);
    int matrice[n][n];
    while(t<=n*n){
    for(i=0+l;i<n-l;i++){
        matrice[0+l][i]=t;
        t++;
    }
    for(i=1+l;i<n-l;i++){
        matrice[i][n-1-l]=t;
        t++;
    }
    for(i=n-2-l;i>-1+l;i--){
        matrice[n-1-l][i]=t;
        t++;
    }
    for(i=n-2-l;i>0+l;i--){
        matrice[i][0+l]=t;
        t++;
    }
    l++;
    }
    for(i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf("%d ",matrice[i][j]);
        }
    }
    return 0;
}