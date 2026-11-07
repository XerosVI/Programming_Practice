#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("argomenti inseriti errati");
        return 1;
    }
    FILE *fp1, *fp2;
    if((fp1=fopen(argv[1],"r"))==NULL){
        return 1;
    }
    if((fp2=fopen(argv[2],"w"))==NULL){
        return 1;
    }
    int a, somma=0;
    char s[100];
    int n=0;
    while(fscanf(fp1,"%s %d",s,&a)>0){
        somma+=a;
        n++;
    }
    float media=(float)somma/n;
    fprintf(fp2,"%.2f",media);
    rewind(fp1);
    while(fscanf(fp1,"%s %d",s,&a)>0){
        if(a>(int)media){
            fprintf(fp2,"\n%s",s);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}