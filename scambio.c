#include<stdio.h>
int main(void){
    int n,t;
    int i=0,j=0;
    printf("inserire n\t");
    scanf("%d",&n);
    int m[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("inserire elem %d %d",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
    j=0;
    for(i=0;i<n;i++){
        t=m[i][j];
        m[i][j]=m[i][n-1-j];
        m[i][n-1-j]=t;
        j++;
    }
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
    }
    return 0;
}