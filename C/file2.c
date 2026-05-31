#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void write_pietanza(const char filename[]);
void cerca_e_leggi_pietanza(const char filename[]);

int main (void){
    size_t i=0;
    char str1[30];
    char scelta='a';
    while(scelta!='f'){
        printf("a per aggiungere pietanza, b c d e vedi cose, f esci, altro loop");
        scanf(" %c",&scelta);
        switch(scelta){
            case 'a':write_pietanza("menu.txt");
                break;
            case 'b':
                cerca_e_leggi_pietanza("menu.txt");
                break;
            case 'f':
                return 0;
            default:
        }
    }
}

void write_pietanza (const char filename[]){
    FILE *fp;
    if((fp=fopen(filename,"a"))==NULL){
        printf("ERRORE\n");
    }
    else{
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
        fprintf(fp,"%s, %02umin %02usec, %s, %zu ingredienti",cibo.nome,cibo.min_cottura,cibo.sec_cottura,cibo.tipo,cibo.num_ingredienti);
        for(size_t i=0; i<cibo.num_ingredienti; i++){
            fprintf(fp,", %s %.2f",cibo.ingredienti[i].nome_i,cibo.ingredienti[i].peso);
        }
        fprintf(fp,"%s","\n");
        fclose(fp);
        free(ingr);
    }
}

void cerca_e_leggi_pietanza(const char filename[]){
    FILE *fp;
    printf("inserire nome pietanza da cercare: ");
    char piatto_cercato[30];
    scanf("%s",piatto_cercato);
    if((fp=fopen(filename,"r"))==NULL){
        printf("ERR");
    }
    else{
        pietanza cibo;
        while(fscanf(fp,"%[^,], %umin %usec, %[^,], %zu ingredienti",cibo.nome, &cibo.min_cottura, &cibo.sec_cottura, cibo.tipo, &cibo.num_ingredienti)>0){
            if (strcmp(cibo.nome, piatto_cercato) == 0){
                cibo.ingredienti=malloc(cibo.num_ingredienti*sizeof(ingrediente));
                for(size_t i=0; i<cibo.num_ingredienti; i++){
                    fscanf(fp,", %s %f",cibo.ingredienti[i].nome_i,&cibo.ingredienti[i].peso);
                }
            printf("\n--- PIATTO TROVATO ---\n");
            printf("Nome: %s\n", cibo.nome);
            printf("Tipo: %s\n", cibo.tipo);
            printf("Tempo Cottura: %02u:%02u\n", cibo.min_cottura, cibo.sec_cottura);
            printf("Ingredienti (%zu):\n", cibo.num_ingredienti);
            for (size_t i = 0; i < cibo.num_ingredienti; i++) {
                printf("  - %s: %.2f g/ml\n", cibo.ingredienti[i].nome_i, cibo.ingredienti[i].peso);
            }
            printf("----------------------\n");

            free(cibo.ingredienti);
            break;
        }else {
            fscanf(fp, "%*[^\n]\n");
                
        }
    }
}
}