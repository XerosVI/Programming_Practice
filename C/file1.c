#include<stdio.h>

int main(void){
    char filename[30];
    printf("Digitare il nome del file di testo di cui contare le righe: ");
    scanf("%s",filename);
    FILE *fp;
    if((fp=fopen(filename, "r"))==NULL){
        printf("ERRORE");
        return -1;
    }
    char c;
    int counter=0;
    int file_vuoto=0;
    while(fscanf(fp,"%c",&c)==1){
        file_vuoto=1;
        if(c=='\n'){
            counter++;
        }
    }

    printf("ci sono %d righe",counter+file_vuoto);
    fclose(fp);
    return 0;
}