#include<stdio.h>
int my_strtok(const char *string, char sep, char token[][20]);
int main(void){
    char ano[10][20];
    printf(" %d ",my_strtok("uno due tre quattro",' ', ano));
    int i=0;
    for(i=0;i<my_strtok("uno due tre quattro",' ', ano);i++){
        printf("%s ",ano[i]);
    }
}

int my_strtok(const char *string, char sep, char token[][20]){
    int j=0;
    size_t i=0;
    size_t pippo=0;
    while(j<10&&string[i]!='\0'){
        for(i=pippo; i<pippo+20&&string[i]!='\0'; i++){
            if(string[i]==sep){
                token[j][i-pippo]='\0';
                pippo=i+1;
                break;
            }
            token[j][i-pippo]=string[i];
        }
        j++;
    }
    return j;
}
