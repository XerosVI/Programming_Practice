#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
int valida_password(char[]);
int main(void){
    srand(time(NULL));
    int dim;
    char alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    scanf("%d", &dim);
    char a[dim+1];
    do{
    for(int i=0; i<dim;i++){
        a[i]=alfabeto[rand()%strlen(alfabeto)];
    }
    a[dim]='\0';
    }while(valida_password(a)==0);
    printf("%s",a);
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