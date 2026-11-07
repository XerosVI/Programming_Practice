#include<stdio.h>
#include<stdlib.h>

int **matrice_trasposta(size_t new_rows, size_t new_cols, int matrice[][new_rows]);

int main(void){
    int matrix[2][4]={1,2,3,4,5,6,7,8};
    int **a=matrice_trasposta(4,2,matrix);
    for(size_t i=0; i<4; i++){
        for(size_t j=0; j<2; j++){
            printf("%d ",a[i][j]);
        }
    }
    for(size_t i=0; i<4; i++){
        free(a[i]);
    }
    free(a);
    return 0;
}

int **matrice_trasposta(size_t new_rows, size_t new_cols, int matrice[][new_rows]){
    int **a=malloc(new_rows*sizeof(int *));
    for(size_t i=0; i<new_rows; i++){
        a[i]=malloc(new_cols*sizeof(int));
    }
    for(size_t i=0; i<new_rows; i++){
        for(size_t j=0; j<new_cols; j++){
            a[i][j]=matrice[j][i];
        }
    }

    return a;
}