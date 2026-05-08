#include<stdio.h>
#include<string.h>

int main(void){
    int up=0, low=0, d=0, o=0;
    char a[100];
    scanf("%99[^\n]", a);
    for(int i=0; a[i]!='\0';i++){
        if(a[i]>='A'&&a[i]<='Z')
            up++;
        else if(a[i]>='a'&&a[i]<='z')
            low++;
        else if(a[i]>='0'&&a[i]<='9')
            d++;
        else o++;
    }
    printf("%d %d %d %d",up,low,d,o);
    return 0;
}