#include<stdio.h>

int main(void){
    unsigned int importo,t;
    unsigned int c50,c20,c10,c5,c2,c1;

    printf("Inserire importo in centesimi:\t");
    scanf("%u",&importo);
    t=importo; //salvo il valore in una variabile temporanea solo perché non voglio perdere il valore originale
    c50=importo/50;
    importo%=50;
    c20=importo/20;
    importo%=20;
    c10=importo/10;
    importo%=10;
    c5=importo/5;
    importo%=5;
    c2=importo/2;
    importo%=2;
    c1=importo;
        printf("%u centesimi = %u moneta/e da 50 + %u da 20 + %u da 10 + %u da 5 + %u da 2 + %u da 1\n",t,c50,c20,c10,c5,c2,c1);
    }