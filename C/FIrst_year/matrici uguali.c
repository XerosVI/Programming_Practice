#include<stdio.h>
#define N 3
#define M 4
int main(void){
    int matrix1 [N][M]={3,4,5,6, 1,2,3,4, 6,7,8,9};
    int matrix2 [N][M]={{3,4,5,6},{1,2,3,4},{6,7,1,9}};
    for(int i=0; i<N; i++){
        for(int j=0;j<M;j++){
            if(matrix1[i][j]!=matrix2[i][j]){
                printf("Diversi");
                return 0;
            }
        }
    }
    printf("Uguali");
    return 0;
}