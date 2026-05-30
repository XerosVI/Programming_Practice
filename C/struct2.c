#include<stdio.h>
#include<stdlib.h>

struct ingrediente{
    char nome_i[20];
    float peso;
};
typedef struct ingrediente ingrediente;

struct pietanza{
    char nome[30];
    ingrediente *ingredienti;
    unsigned int min_cottura;
    unsigned int sec_cottura;
    char tipo[15];
};
typedef struct pietanza pietanza;

int main(void){
    pietanza cibo;
    size_t num;
    printf("Inserire dati pietanza\n");
    printf("Inserire nome:\t");
    scanf("%s",cibo.nome);
    printf("Inserire numero ingredienti:\t");
    scanf("%zu",&num);
    ingrediente *ingr=malloc(num*sizeof(ingrediente));
    for(size_t i=0; i<num; i++){
        printf("Inserire nome ingrediente %zu:\t", i+1);
        scanf("%s",(ingr+i)->nome_i);
        printf("Inserire dose ingrediente %zu:\t", i+1);
        scanf("%f", &(ingr+i)->peso);
    }
    cibo.ingredienti=ingr;
    printf("Inserire tempo cottura (min e sec):\t");
    scanf("%u %u",&cibo.min_cottura, &cibo.sec_cottura);
    printf("Inserire tipologia:\t");
    scanf("%s",cibo.tipo);
    printf("%s %02u %02u %s",cibo.nome,cibo.min_cottura,cibo.sec_cottura,cibo.tipo);
    for(size_t i=0; i<num; i++){
        printf("%s %.2f", (cibo.ingredienti+i)->nome_i, (cibo.ingredienti+i)->peso);
    }

    free(cibo.ingredienti);
}