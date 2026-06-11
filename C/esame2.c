#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char nome[30];
    unsigned int numero;
    char city[30];
    struct Node *next;
}Node;

void add(Node *head, char nome[], unsigned int numero, char city[]);
Node *find(Node *head, const char nome[]);
Node *find_city(Node *head, const char city[]);
Node *crea(char nome[], unsigned int numero, char city[]);
void dealloc(Node *head);

int main(void){
    int a=0;
    char nome[30], city[30];
    unsigned int numero;
    Node *rubrica=NULL;
    Node *t=NULL;
    while(a!=-1){
        printf("Cosa si vuole fare?\n1. Inserire contatto\n2.Visualizzare numero di un contatto\n3. Visualizzare elenco residenti in una città specifica\n-1: Esci\n");
        scanf(" %d",&a);
        switch(a){
            case 1:
            printf("Inserire in ordine nome numero e citta': ");
            scanf(" %[^\n] %u %[^\n]",nome,&numero,city);
            if(rubrica==NULL){
                rubrica=crea(nome,numero,city);
            }
            else if(find(rubrica,nome)==NULL){
                add(rubrica,nome,numero,city);
            }
            else{
                printf("Contatto gia' esistente\n");
            }
            break;
            case 2:
            printf("Inserire nome: ");
            scanf(" %[^\n]",nome);
            t=find(rubrica,nome);
            if(t==NULL){
                printf("Non trovato\n");
            }
            else{
                printf("numero: %u\n",t->numero);
            }
            break;
            case 3:
            printf("Inserire citta': ");
            scanf(" %[^\n]",city);
            t=find_city(rubrica,city);
            while(t!=NULL){
                printf("%s\n",t->nome);
                t=find_city(t->next,city);
            }
            break;
            case -1:
            dealloc(rubrica);
            return 0;
            default:
            printf("Valore non valido\n");
            
        }
    }
}

void add(Node *head, char nome[], unsigned int numero, char city[]){
    Node *new=malloc(sizeof(Node));
    if(head!=NULL&&new!=NULL){
        strcpy(new->nome,nome);
        new->numero=numero;
        strcpy(new->city,city);
        new->next=NULL;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=new;
    }
    
}

Node *crea(char nome[], unsigned int numero, char city[]){
        Node *new=malloc(sizeof(Node));
        strcpy(new->nome,nome);
        new->numero=numero;
        strcpy(new->city,city);
        new->next=NULL;
        return new;
}

Node *find(Node *head, const char nome[]){
    while(head!=NULL){
        if(strcmp(head->nome,nome)==0){
            break;
        }
        head=head->next;
    }
    return head;
}

Node *find_city(Node *head, const char city[]){
    while(head!=NULL){
        if(strcmp(head->city,city)==0){
            break;
        }
        head=head->next;
    }
    return head;
}

void dealloc(Node *head){
    Node *t;
    while(head!=NULL){
        t=head->next;
        free(head);
        head=t;
    }
}