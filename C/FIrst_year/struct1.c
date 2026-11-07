#include<stdio.h>

struct persona{
    char nome[30];
    unsigned int eta;
    float altezza;
    float peso;
};

void stampa(struct persona *p);

int main(void){
    struct persona uno={"Francesco", 20, 1.75, 70.5};
    stampa(&uno);
    return 0;
}

void stampa(struct persona *p){
    printf("%s %u %.2f %.2f",p->nome,p->eta,p->altezza,p->peso);
}