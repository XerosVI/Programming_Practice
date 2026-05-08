#include<stdio.h>

int main(void) {
    unsigned short int num,h=0,da=0,u=0,t;
    do {
        printf("Inserire un numero fra 100 e 999:\t");
        scanf("%hu",&num);
        if (num>999||num<100)
            printf("Il valore non e' compreso fra 100 e 999.\n"); //se l'istruzione e' una sola non servono le {}
    } while(num>999||num<100);
    t=num; //salvo il valore in t per non perdere il valore originale
    h=num/100;
    num%=100;
    da=num/10;
    num%=10;
    u=num;
    printf("le cifre di %hu sono\n%hu\n%hu\n%hu\n",t,h,da,u);
}