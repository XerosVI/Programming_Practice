#include<stdio.h>
#include<string.h>
int count(char[], char);
int main(void){
    char str1[100];
    char str2[100];
    printf("Inserire le due stringhe:\t");
    scanf("%99[^\n] %99[^\n]",str1,str2);

    for(char i='a'; i<='z';i++){
        if(count(str1,i)!=count(str2,i)){
            printf("Non sono anagrammi");
            return 0;
        }
    }
    printf("Sono anagrammi");
    return 0;
}

int count(char a[],char c){
    int o=0;
    for(int i=0; a[i]!='\0';i++){
        if(a[i]==c)
            o++;
    }
    return o;
}