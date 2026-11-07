#include<stdio.h>
int main(void){
    char filename[30];
    FILE *fp;
    printf("Digitare il nome del file di testo da codificare in ROT13: ");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL){
        printf("ERRORE");
        return -1;
    }
    char c;
    while(fscanf(fp,"%c",&c)==1){
            if((c<='M'&&c>='A')||(c<='m'&&c>='a')){
                c+=13;
            }
            else if((c<='Z'&&c>='N')||(c<='z'&&c>='n')){
                c-=13;
            }
            printf("%c",c);
    }
}