#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

struct ingrediente{
    char nome_i[20];
    float peso;
};
typedef struct ingrediente ingrediente;

struct pietanza{
    char nome[30];
    size_t num_ingredienti;
    ingrediente *ingredienti;
    unsigned int min_cottura;
    unsigned int sec_cottura;
    char tipo[15];
};
typedef struct pietanza pietanza;

pietanza get_pietanza();
void view(size_t,char [],pietanza[]);
void see(size_t,char[], pietanza[]);
void find(size_t,char[], pietanza[]);

int main (void){
    printf("a per aggiungere pietanza, b c d vedi cose, f esci, altro loop");
    size_t i=0;
    pietanza menu[N];
    char str1[30];
    char scelta='a';
    while(scelta!='f'){
        scanf(" %c",&scelta);
        switch(scelta){
            case 'a':
                menu[i++]=get_pietanza();
                break;
            case 'b':
                scanf("%s", str1);
                view(i,str1,menu);
                break;
            case 'c':
                scanf("%s", str1);
                see(i,str1,menu);
                break;
            case 'd':
                scanf("%s", str1);
                find(i,str1,menu);
                break;
            case 'f':
                return 0;
            default:
        }
    }
}

pietanza get_pietanza (){
    pietanza cibo;
    printf("Inserire dati pietanza\n");
    printf("Inserire nome:\t");
    scanf("%s",cibo.nome);
    printf("Inserire numero ingredienti:\t");
    scanf("%zu",&cibo.num_ingredienti);
    ingrediente *ingr=malloc(cibo.num_ingredienti*sizeof(ingrediente));
    for(size_t i=0; i<cibo.num_ingredienti; i++){
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
    return cibo;
}

void view(size_t n, char s[], pietanza p[]){
    for(size_t i=0; i<n;i++){
        if(strcmp(s,p[i].nome)==0){
            printf("%s %.2f",p[i].ingredienti->nome_i,p[i].ingredienti->peso);
            break;
        }
    }
}

void see(size_t n,char s[], pietanza p[]){
    for(size_t i=0; i<n;i++){
        if(strcmp(s,p[i].tipo)==0){
            printf("%s\n",p[i].nome);
        }
    }
}

void find(size_t n, char s[], pietanza p[]){
    for(size_t i=0; i<n;i++){
        for(size_t j=0; j<p[i].num_ingredienti;j++)
            if(strcmp(s,p[i].ingredienti[j].nome_i)==0){
                printf("%s\n",p[i].nome);
        }
    }
}