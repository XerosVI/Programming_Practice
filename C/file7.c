#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *fp;
    if((fp=fopen("matrice.txt","r"))==NULL){
        printf("NULL");
        return -1;
    }
    size_t righe,colonne;
    fscanf(fp,"%zu %zu\n",&righe,&colonne);
    int *array=malloc(righe*colonne*sizeof(int));
    if(array==NULL){
        fclose(fp);
        return 1;
    }
    for(size_t i=0;i<righe;i++){
        for(size_t j=0;j<colonne;j++){
            fscanf(fp,"%d ",array+i*colonne+j);
        }
    }
    fclose(fp);
    
    int sum;
    for(size_t i=0;i<righe;i++){
        sum=0;
        for(size_t j=0;j<colonne;j++){
            sum+=array[i+j*colonne];
        }
        printf("Somma della colonna %zu = %d\n",i,sum);
    }

    free(array);
    return 0;
}