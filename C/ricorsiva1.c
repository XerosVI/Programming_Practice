#include<stdio.h>

int strlength(char []);
int main (void){
    int i;
    i=strlength("Ciaooooooo");
    printf("%d", i);
}
int strlength(char str[]){
    if(str[0]=='\0'){
        return 0;
    }
    else
        return 1+strlength(str+1);
    
}

