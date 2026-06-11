#include <stdio.h>
#include <stdlib.h>

char cesare(char c, int k);

int main (int argc, char *argv[]){
    if(argc!=4){
        printf("argomenti inseriti incorrettamente");
        return 1;
    }
    FILE *fp1,*fp2;
    int k=atoi(argv[3]);
    if(k<0||k>25){
        printf("chiave non valida");
        return 1;
    }
    if((fp1=fopen(argv[1],"r"))==NULL){
        printf("File non aperto");
        return -1;
    }
    if((fp2=fopen(argv[2],"w"))==NULL){
        printf("File non aperto");
        return -1;
    }
    char a;
    while(fscanf(fp1,"%c",&a)>0){
        fprintf(fp2,"%c",cesare(a,k));
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

char cesare(char c, int k){
    if(c>='A'&&c<='Z')
        return ((c+k-'A')%26)+'A';
    else if(c>='a'&&c<='z')
        return ((c+k-'a')%26)+'a';
    else
        return c;
}