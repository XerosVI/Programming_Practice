#include<stdio.h>
#include<ctype.h>
void count(char c, int *arr);
int main(void){
    char filename[30];
    printf("Digitare il nome del file di testo di cui contare le 26 lettere dell'alfabeto: ");
    scanf("%s",filename);
    FILE *fp;
    if((fp=fopen(filename, "r"))==NULL){
        printf("ERRORE");
        return -1;
    }
    char c;
    int counter[26]={0};
    while(fscanf(fp,"%c",&c)==1){
        count(c,counter);
    }
    fclose(fp);
    fp=fopen("frequenza_lettere.txt", "w");
    for(char i='A'; i<='Z';i++){
        fprintf(fp,"Occorrenze di %c: %d\n",i,counter[i-'A']);
    }
    fclose(fp);
    return 0;
}

void count(char c, int *arr){
    c=tolower(c);
    for(char i='a'; i<='z';i++){
        if(i==c){
            arr[i-'a']++;
        }
    }
}