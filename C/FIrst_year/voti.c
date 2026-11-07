#include<stdio.h>
#define NUM_STUDENTI 6

int main(void){
    short unsigned int voti_studenti[NUM_STUDENTI]={0};
    short unsigned int check;
    while(1){
        printf("\nCosa si vuole fare?\n1: Inserire tutti i valori dei voti\n2: Stampare i voti dal primo all'ultimo\n3: Stampare i voti dall'ultimo al primo\n4: Stampare voto max e min e loro indici\n5: stampare voto medio\naltro: termina programma\n");
        scanf("%hu",&check);
        switch(check){
            case 1:
            for(size_t i=0;i<NUM_STUDENTI;i++)
            {
                printf("Inserire voto studente %zu:\t",i+1);
                scanf("%hu",&voti_studenti[i]);
            }
            break;
            case 2:
            for(size_t i=0;i<NUM_STUDENTI;i++)
                printf("\nvoto studente %zu: %hu",i+1,voti_studenti[i]);
            break;
            case 3:
            for(size_t i=NUM_STUDENTI;i>0;i--)
                printf("\nvoto studente %zu: %hu",i, voti_studenti[i-1]);
            break;
            case 4:
            unsigned short int max=voti_studenti[0], min=voti_studenti[0];
            size_t index_max=0, index_min=0;
            for(size_t i=0;i<NUM_STUDENTI;i++)
            {
                if(max<voti_studenti[i]){
                    max=voti_studenti[i];
                    index_max=i;
                }
                if(min>voti_studenti[i]){
                    min=voti_studenti[i];
                    index_min=i;
                }
            }
            printf("\nmax= %hu in posizione %zu\nmin= %hu in posizione %zu",max,index_max,min,index_min);
            break;
            case 5:
            check=0;
            for(size_t i=0;i<NUM_STUDENTI;i++)
                check+=voti_studenti[i];
            printf("\nLa media e' uguale a %.1lf",(double)check/NUM_STUDENTI);
            break;
            default:
            return 0;
        }
    }
}