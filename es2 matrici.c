#include<stdio.h>
#include<stdbool.h>
int conteggio(int righe, int colonne, int[][colonne], int ricerca);
bool presenza(int righe, int colonne, int[][colonne], int ricerca);

int main(void){
    int n,m,k,c=0;
    printf("inserire n, m, k\t");
    scanf("%d %d %d",&n,&m,&k);
    int matrix[n][m];
    printf("riempire array\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("inserire elemento %d %d\t",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    if(presenza(n,m,matrix,k)) printf("\n c'e' pippo");
    else printf("non c'e' pippo");
    printf("\nci sono %d k",conteggio(n,m,matrix,k));
    return 0;
}

int conteggio(int righe,int colonne, int matrice[][colonne],int ricerca){
    int c=0;
    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            if(matrice[i][j]==ricerca) c++;
        }
    }
    return c;
}

bool presenza(int righe,int colonne, int matrice[][colonne],int ricerca){
    if(conteggio(righe,colonne,matrice,ricerca)>0)
        return true;
    else
    return false;
}