#include <stdio.h>
#define MAX_STR 50
#define MAX_PROD 100

typedef struct Prodotto{
    char nome[MAX_STR];
    int unita_vendute;
}Prodotto;

int leggi_prodotti(Prodotto array[],FILE *fp1);
void stampa(Prodotto array[], int n, FILE *fp2);
void minimo(Prodotto array[], int n, FILE *fp2);

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Errore: numero argomenti non corretto.\n");
        return 1;
    }
        FILE *fp1,*fp2;
    if((fp1=fopen(argv[1],"r"))==NULL){
        printf("Errore nell'apertura del file");
        return 1;
    }
    if((fp2=fopen(argv[2],"w"))==NULL){
        printf("Errore nell'apertura del file");
        fclose(fp1);
        return 1;
    }
    //nome unitavendute
    Prodotto array[MAX_PROD];
    int n=leggi_prodotti(array,fp1);
    fclose(fp1);
    if(n==0){
        printf("Nessun prodotto nel file");
        fclose(fp2);
        return 1;
    }
    stampa(array,n,fp2);
    minimo(array,n,fp2);
    fclose(fp2);

    return 0;
}

int leggi_prodotti(Prodotto array[],FILE *fp1){
    int n=0;
    while(n<MAX_PROD && fscanf(fp1,"%s %d",array[n].nome,&array[n].unita_vendute)==2){
        n++;
    }
    return n;
}

void stampa(Prodotto array[], int n, FILE *fp2){
    for(size_t i=0; i<n;i++){
        if(array[i].unita_vendute>8)
            fprintf(fp2,"%s\n",array[i].nome);  
    }
}

void minimo(Prodotto array[], int n, FILE *fp2){
    int min=array[0].unita_vendute;
    size_t o=0;
    for(size_t i=1; i<n;i++){
        if(array[i].unita_vendute<min){
            min=array[i].unita_vendute;
            o=i;
        }
            
    }
    fprintf(fp2,"\nMinor numero di vendite: %s",array[o].nome);
}
