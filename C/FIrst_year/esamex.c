#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STR 50

typedef struct Prodotto{
    char nome[MAX_STR+1];
    char codice[MAX_STR+1];
    char categoria[MAX_STR+1];
    struct Prodotto *next;
}Prodotto;

Prodotto *crea_lista(char nome[], char codice[], char categoria[]);
void insert_head(Prodotto **head,char nome[], char codice[], char categoria[]);
int stampa_categoria(Prodotto *head, char categoria[]);
int verifica_duplicati(Prodotto *head,char codice[]);
void insert_head_no_duplicates(Prodotto **head,char nome[], char codice[], char categoria[]);
void dealloc(Prodotto *head);

int main(void){
    Prodotto *inventario=NULL;
    insert_head_no_duplicates(&inventario,"Maglietta","0001","Indumenti");
    insert_head_no_duplicates(&inventario,"Lavatrice","1111","Elettrodomestici");
    insert_head_no_duplicates(&inventario,"Maglietta","0001","Indumenti");
    printf("Inserire categoria merceologica: ");
    char stringa[MAX_STR+1];
    scanf("%50s",stringa);
    int n=stampa_categoria(inventario,stringa);
    printf("In totale sono %d elementi\n",n);
    dealloc(inventario);
    return 0;
}

Prodotto *crea_lista(char nome[], char codice[], char categoria[]){
    Prodotto *nuovo=malloc(sizeof(Prodotto));
    if(nuovo==NULL){
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    strcpy(nuovo->nome,nome);
    strcpy(nuovo->codice,codice);
    strcpy(nuovo->categoria,categoria);
    nuovo->next=NULL;
    return nuovo;
}

void insert_head(Prodotto **head,char nome[], char codice[], char categoria[]){
    if(head==NULL){
        printf("Errore: puntatore alla testa non valido\n");
        return;
    }
    Prodotto *nuovo=crea_lista(nome,codice,categoria);
    nuovo->next=*head;
    *head=nuovo;
}

int stampa_categoria(Prodotto *head, char categoria[]){
    int c=0;
    printf("Prodotti appartenenti alla categoria %s:\n",categoria);
    while(head!=NULL){
        if(strcmp(head->categoria,categoria)==0){
            c++;
            printf("%s\n",head->nome);
        }
        head=head->next;
    }
    return c;
}

int verifica_duplicati(Prodotto *head,char codice[]){
    while(head!=NULL){
        if(strcmp(head->codice,codice)==0){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

void insert_head_no_duplicates(Prodotto **head,char nome[], char codice[], char categoria[]){
    if(head==NULL){
        printf("Errore: puntatore a head non valido\n");
        return;
    }
    if(verifica_duplicati(*head,codice)==0){
        insert_head(head,nome,codice,categoria);
    }
    else{
        printf("Errore: inserito duplicato\n");
    }
}

void dealloc(Prodotto *head){
    while(head!=NULL){
        Prodotto *temp=head;
        head=head->next;
        free(temp);
    }
}