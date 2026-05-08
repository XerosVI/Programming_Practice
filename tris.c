#include<stdio.h>
#include<stdbool.h>
#define N 3

bool vincitore(char matrix[][N],char p);
void stampa(char matrix[][N]);

int main(void){
    int r,c;
    char matrice[N][N]={'.','.','.','.','.','.','.','.','.'};
    while(!vincitore(matrice,'X')&&!vincitore(matrice,'O')){
        printf("Giocatore X inserisca carattere nella cella desiderata\t");
        scanf("%d %d",&r,&c);
        matrice[r-1][c-1]='X';
        
        stampa(matrice);
        
        if(vincitore(matrice,'X')){
            printf("Ha vinto X");
            return 0;
        }

        printf("Giocatore O inserisca carattere nella cella desiderata\t");
        scanf("%d %d",&r,&c);
        matrice[r-1][c-1]='O';

        stampa(matrice);

        if(vincitore(matrice,'O')){
            printf("Ha vinto O");
            return 0;
        }
    }
}

bool vincitore(char matrix[][N],char p){
    if((p==matrix[0][0]&&matrix[1][1]==p&&p==matrix[2][2])||(p==matrix[0][2]&&matrix[1][1]==p&&p==matrix[2][0]))
        return true;
    for(int i=0;i<N;i++){
        if((p==matrix[i][0]&&p==matrix[i][1]&&p==matrix[i][2])||(p==matrix[0][i]&&p==matrix[1][i]&&p==matrix[2][i]))
            return true;
    }
    return false;
}

void stampa(char matrix[][N]){
    for(int i=0;i<N;i++){
        printf("\n");
        for(int j=0;j<N;j++){
            printf("%c ",matrix[i][j]);
        }
    }
}