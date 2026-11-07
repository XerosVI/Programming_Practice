#include<stdio.h>
#define MAX_STR 50
#define MAX_SITI 100
typedef struct Sito{
    char nome[MAX_STR+1];
    int visite;
}Sito;

int leggi_siti(Sito siti[],FILE *fin, int max){
    int n=0;
    while(n<max&&fscanf(fin,"%50s %d",siti[n].nome,&siti[n].visite)==2){
        n++;
    }
    return n;
}

double media(Sito siti[],int n){
    int somma=0;
    for(int i=0; i<n; i++){
        somma+=siti[i].visite;
    }
    return (double)somma/n;
}

void stampa(Sito siti[], double media, int n, FILE *fout){
    fprintf(fout,"Visite medie: %lf\n",media);
    for(int i=0; i<n; i++){
        if((double)siti[i].visite>media){
            fprintf(fout,"%s\n",siti[i].nome);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Numero di parametri non corretto\n");
        return 1;
    }
    FILE *fin=fopen(argv[1],"r");
    if(fin==NULL){
        printf("Errore apertura file input\n");
        return 1;
    }
    FILE *fout=fopen(argv[2],"w");
    if(fout==NULL){
        printf("Errore apertura file output\n");
        fclose(fin);
        return 1;
    }
    Sito siti[MAX_SITI];
    int n=leggi_siti(siti,fin, MAX_SITI);
    fclose(fin);
    if(n==0){
        printf("Nessun sito nel file input\n");
        fclose(fout);
        return 1;
    }
    double m=media(siti,n);
    stampa(siti,m,n,fout);
    fclose(fout);
    return 0;
}