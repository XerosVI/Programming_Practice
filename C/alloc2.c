#include<stdio.h>
#include<stdlib.h>

int get_element(int array[], size_t num_colonne, size_t get_riga, size_t get_colonna);
void set_element(int value, int array[], size_t num_colonne, size_t set_riga, size_t set_colonna);

int main(void){
    size_t rows, cols;
    printf("Inserire righe e colonne matrice:\t");
    scanf("%zu %zu",&rows,&cols);
    int *array1d= malloc(rows*cols*sizeof(int));
    for(size_t i=0; i<rows; i++){
        for(size_t j=0; j<cols; j++){
            printf("\nInserire elemento [%zu] [%zu]:\t",i, j);
            scanf("%d",array1d+i*cols+j);
        }
    }
    printf("\nelemento [0] [1] = %d",get_element(array1d,cols,0,1));
    set_element(-1,array1d,cols,0,1);
    printf("\nelemento [0] [1] = %d",get_element(array1d,cols,0,1));
    free(array1d);
    return 0;
}

int get_element(int array[], size_t num_colonne, size_t get_riga, size_t get_colonna){
    return *(array+get_riga*num_colonne+get_colonna);
}

void set_element(int value, int array[], size_t num_colonne, size_t set_riga, size_t set_colonna){
    *(array+set_riga*num_colonne+set_colonna)=value;
}