#include<stdio.h>
char *find_char(char string[], char c);

int main(void){
    char str[] = "Ciao";
    char l='a';
    char *res=find_char(str,l);
    printf("%s",res);
    *res='x';
    printf("%s",str);
}

char *find_char(char string[], char c){
    size_t i;
    for(i=0; string[i]!='\0'; i++){
        if(c==string[i]){
            return string+i;
        }
    }

    return NULL;
}