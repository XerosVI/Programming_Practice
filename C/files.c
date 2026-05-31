#include<stdio.h>
#include"files.h"

void scrivo_su_file(const char filename[]){
    FILE *fp;
    if((fp=fopen(filename,"w"))==NULL){
        printf("ERRORE");
    }
    else{
        int check=0;
        char articolo[30];
        while(check==0){
            printf("Inserire articolo: ");
            scanf("%s",articolo);
            fprintf(fp,"%s ", articolo);
            printf("continuare? 0=si 1=no: ");
            scanf("%d", &check);
        }
        fclose(fp);
    }
}

void leggo_da_file(const char filename[]){
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL){
        printf("ERRORE");
    }
    else{
        char buf[80];
        while(fscanf(fp,"%s",buf)>0){
            printf("%s\n",buf);
        }
    fclose(fp);
    }
}