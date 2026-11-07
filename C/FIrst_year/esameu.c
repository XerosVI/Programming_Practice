#include <stdio.h>
#define MAX_STR 50
#define MAX_ARR 100
typedef struct Dispositivo{
    char nome[MAX_STR];
    int h_on;
    double consumo_h;
}Dispositivo;

int leggi_file(Dispositivo *dispositivi, FILE *fin, int max);
void consumo_tot(Dispositivo *dispositivi, double *consumi, int n);
void stampa(Dispositivo *dispositivi, double *consumi, int n,FILE *fout);
void stampa_min(Dispositivo *dispositivi, double *consumi, int n,FILE *fout);
void stampa_max(Dispositivo *dispositivi, double *consumi, int n,FILE *fout);

int main (int argc, char *argv[]){
    if(argc!=3){
        printf("Errore parametri\n");
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
    Dispositivo dispositivi[MAX_ARR];
    int n=leggi_file(dispositivi, fin, MAX_ARR);
    fclose(fin);
    if(n==0){
        printf("File input vuoto\n");
        fclose(fout);
        return 1;
    }
    double consumi[n];
    consumo_tot(dispositivi,consumi,n);
    stampa(dispositivi,consumi,n,fout);
    stampa_min(dispositivi,consumi,n,fout);
    stampa_max(dispositivi,consumi,n,fout);
    fclose(fout);
    return 0;
}

int leggi_file(Dispositivo *dispositivi, FILE *fin, int max){
    int n=0;
    while(n<max && fscanf(fin,"%49s %d %lf",dispositivi[n].nome,&dispositivi[n].h_on,&dispositivi[n].consumo_h)==3){
        n++;
    }
    return n;
}

void consumo_tot(Dispositivo *dispositivi, double *consumi, int n){
    for(int i=0; i<n; i++){
        consumi[i]=dispositivi[i].h_on*dispositivi[i].consumo_h;
    }
}

void stampa(Dispositivo *dispositivi, double *consumi, int n,FILE *fout){
    fprintf(fout,"Elenco dispositivi con consumo tot >100:\n");
    for(int i=0;i<n;i++){
        if(consumi[i]>100){
            fprintf(fout,"%s\n",dispositivi[i].nome);
        }
    }
}

void stampa_min(Dispositivo *dispositivi, double *consumi, int n,FILE *fout){
    double min=consumi[0];
    int o=0;
    for(int i=1; i<n; i++){
        if(consumi[i]<min){
            o=i;
            min=consumi[i];
        }
    }
    fprintf(fout,"Dispositivo con consumo minimo: %s\n",dispositivi[o].nome);
}

void stampa_max(Dispositivo *dispositivi, double *consumi, int n,FILE *fout){
    double max=consumi[0];
    int o=0;
    for(int i=1; i<n; i++){
        if(consumi[i]>max){
            o=i;
            max=consumi[i];
        }
    }
    fprintf(fout,"Dispositivo con consumo massimo: %s\n",dispositivi[o].nome);
}
