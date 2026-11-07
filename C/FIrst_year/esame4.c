#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int id;
    char nome[30];
    int sezione;
    struct Node *next;
}Node;

void add(Node *head, int id, char nome[], int sezione);
int votato(Node *head, int id);
Node *crea(int id, char nome[], int sezione);
void stampa(Node *head);

int main(void){
    printf("I candidati sono Pippo, Pluto e Topolino\n");
    int a=0;
    int id;
    int sezione;
    char nome[30];
    Node *lista=NULL;
    while(a!=-1){
        printf("Cosa si vuole fare?\n");
        printf("1. Inserire 4 voti\n");
        printf("2. Verificare se id=3 presente\n");
        printf("3. stampare voti di ciascun canditato\n");
        scanf("%d",&a);
        switch(a){
            case 1:
            for(size_t i=0; i<4; i++){
                printf("Inserire id nome e sezione elettorale ");
                scanf("%d",&id);
                scanf("%s",nome);
                scanf("%d",&sezione);
                if(lista==NULL){
                lista=crea(id,nome,sezione);
                }
                else{
                    add(lista,id,nome,sezione);
                }
            }
            break;
            case 2:
            if(votato(lista,3)==0){
                printf("\nNo");
            }
            else{
                printf("\nSi");
            }
            break;
            case 3:
            stampa(lista);
            break;
            case -1:
            //deallocare lista
            return 0;
            default:
        }
    }
}


void add(Node *head, int id, char nome[], int sezione){
    int check=0;
    if(head!=NULL){
        Node *new=malloc(sizeof(Node));
        new->id=id;
        strcpy(new->nome,nome);
        new->sezione=sezione;
        new->next=NULL;
        while(head->next!=NULL){
            if(head->id==id){
                check=1;
                break;
            }
            head=head->next;
        }
        if(check==0&&head->id!=id){
            head->next=new;
        }
    }
    
}

int votato(Node *head, int id){
    while(head!=NULL){
        if(head->id==id){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

Node *crea(int id, char nome[], int sezione){
    Node *head=malloc(sizeof(Node));
    head->id=id;
    head->sezione=sezione;
    head->next=NULL;
    strcpy(head->nome,nome);
    return head;
}

void stampa(Node *head){
    int pippo=0, pluto=0, topolino=0;
    Node *inizio=head;
    while(head!=NULL){
        if(strcmp(head->nome,"Pippo")==0){
            pippo++;
        }
        head=head->next;
    }
    printf("Pippo ha %d voti",pippo);
    head=inizio;
    while(head!=NULL){
        if(strcmp(head->nome,"Pluto")==0){
            pluto++;
        }
        head=head->next;
    }
    printf("Pluto ha %d voti",pluto);
    head=inizio;
    while(head!=NULL){
        if(strcmp(head->nome,"Topolino")==0){
            topolino++;
        }
        head=head->next;
    }
    printf("Topolino ha %d voti",topolino);
    if(pippo>pluto&&pippo>topolino){
        printf("Pippo vince");
    }
    else if(pluto>pippo&&pluto>topolino){
        printf("Pluto vince");
    }
    else if(topolino>pluto&&topolino>pippo){
        printf("Topolino vince");
    }
    else{
        printf("C'e' un pareggio");
    }
}