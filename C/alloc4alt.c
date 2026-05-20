#include<stdio.h>
#include<stdlib.h>

void *matrice_trasposta(size_t new_rows, size_t new_cols, int matrice[][new_rows]);

int main(void){
    int matrix[2][4]={1,2,3,4,5,6,7,8};
    int (*a)[2]=matrice_trasposta(4,2,matrix);
    for(size_t i=0; i<4; i++){
        for(size_t j=0; j<2; j++){
            printf("%d ",a[i][j]);
        }
    }
    free(a);
    return 0;
}

void *matrice_trasposta(size_t new_rows, size_t new_cols, int matrice[][new_rows]){
    int (*a)[new_cols]=malloc(new_rows*new_cols*sizeof(int));
    for(size_t i=0; i<new_rows; i++){
        for(size_t j=0; j<new_cols; j++){
            a[i][j]=matrice[j][i];
        }
    }

    return a;
}