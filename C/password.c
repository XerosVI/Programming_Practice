#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
int valida_password(char[]);
int main(void){
    char stringa[50];
    scanf("%49s",stringa);
    if(valida_password(stringa)==1)
        printf("valida");
    else
        printf("NO");
    return 0;
}

int valida_password(char a[]){
    int i;
    bool sp=false, up=false, low=false, d=false;
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^'||a[i]=='&'||a[i]=='*')
            sp=true;
        if(a[i]>='a'&&a[i]<='z')
            low=true;
        if(isupper(a[i]))
            up=true;
        if(a[i]>='0'&&a[i]<='9')
            d=true;
    }
    if(up&&low&&d&&sp&&i>=8)
        return 1;
    else
        return 0;
}