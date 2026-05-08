#include<stdio.h>

int main(void){
    char lettera;
    unsigned short int shift;
    do{
        printf("Inserire carattere maiuscola dell'alfabeto inglese:\t");
        scanf("%c",&lettera);
        if(lettera<'A'||lettera>'Z') //considero i caratteri come valori interi
            printf("Il carattere non e' una lettera maiuscola.\n");
    }while (lettera<'A'||lettera>'Z');//considero i caratteri come valori interi
    do{
        printf("Inserire valore di spostamento fra 1 e 25:\t");
        scanf("%hu",&shift);
        if(shift<1||shift>25)
            printf("Valore non compreso fra 1 e 25.\n");
    }while(shift<1||shift>25);
    lettera=(lettera-'A'+shift)%26+'A';
    printf("%c\n",lettera);
}