#include<stdio.h>
int pali(char[]);
int main(void){

    char u[]="Ciao";
    printf("%d", pali(u));
    char p[]="i topi non avevano nipoti";
    printf("%d", pali(p));
    return 0;
}

int pali(char a[]) {
    int i,j,k=0;
    for(i=0; a[i]!='\0';i++);
    for(j=0; a[j]!='\0';j++){
        i--;
        while(a[j]==' ') j++;
        while(a[i]==' ') i--;
        if(a[i]!=a[j]){
            return 0;
        }
    }
    return 1;
}