#include<stdio.h> //chiedere righe e colonne, valori, prima righa txt ha righe e colonne
#include<stdlib.h>
int main (void){
    FILE *fp;
    if((fp=fopen("matrice.txt","w"))==NULL){
        printf("NULL");
        return -1;
    }
    size_t righe, colonne;
    printf("Inserire righe e colonne:\n");
    scanf("%zu %zu",&righe,&colonne);
    fprintf(fp,"%zu %zu",righe,colonne);
    /*int *matrice=malloc(righe*colonne*sizeof(int));
    for(size_t i=0;i<righe;i++){
        fprintf(fp,"\n");
        for(size_t j=0;j<colonne;j++){
            matrice[i*colonne+j]=i*j;
            fprintf(fp,"%d ",matrice[i*colonne+j]);
        }
    }
    fclose(fp);
    free(matrice);
    */


    /*int **matrice=malloc(righe*sizeof(int *));
    for(size_t i=0; i<righe;i++){
        matrice[i]=malloc(colonne*sizeof(int));
    }
    for(size_t i=0;i<righe;i++){
        fprintf(fp,"\n");
        for(size_t j=0;j<colonne;j++){
            matrice[i][j]=i*j;
            fprintf(fp,"%d ",matrice[i][j]);
        }
    }
    fclose(fp);
    for(size_t i=0; i<righe;i++){
        free(matrice[i]);
    }
    free(matrice);*/

    /*int (*matrice)[colonne]=malloc(righe*sizeof(*matrice));
    for(size_t i=0;i<righe;i++){
        fprintf(fp,"\n");
        for(size_t j=0;j<colonne;j++){
            matrice[i][j]=i*j;
            fprintf(fp,"%d ",matrice[i][j]);
        }
    }
    fclose(fp);
    free(matrice);
    */

    for(size_t i=0;i<righe;i++){
        fprintf(fp,"\n");
        for(size_t j=0;j<colonne;j++){
            fprintf(fp,"%d ",i*j);
        }
    }
    fclose(fp);
    return 0;
}