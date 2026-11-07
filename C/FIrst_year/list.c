#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *new_list(int value);
void insert_tail(Node *head, int value);
void stampa(Node *head);
int counter(Node *head, int value);
Node *delete_node(Node *head, int value);
void square_node(Node *head);
void free_list(Node *head);
//manca solo insert_head ma non era richiesta

int main(void) {
    Node *lista=NULL;
    int x;
    char a='a';
    while(a!='e'){
        printf("\nCosa fare? a: aggiungere elementi.  b: contare elementi.  c: cancella nodi.  d: fai il quadrato di tutti i nodi.  e: chiudi programma. ");
        scanf(" %c",&a);
        switch(a){
                case 'a':
                    printf("Quale elemento? ");
                    scanf("%d",&x);
                    if(lista==NULL){
                        lista=new_list(x);
                    }
                    else
                        insert_tail(lista,x);
                    stampa(lista);
                    break;
                case 'b':
                    printf("Quale elemento contare? ");
                    scanf("%d",&x);
                    printf("L'elemento e' presente %d volte", counter(lista,x));
                    break;
                case 'c':
                    printf("Quali nodi cancellare a partire dal valore da inserire? ");
                    scanf("%d",&x);
                    while(counter(lista,x)!=0){
                        lista=delete_node(lista,x);
                    }
                    stampa(lista);
                    break;
                case 'd':
                    square_node(lista);
                    stampa(lista);
                    break;
                default:
                    break;
            }
    }
    free_list(lista);
    return 0;
}

void insert_tail(Node *head, int value){
    Node *new=malloc(sizeof(Node));
    if(new!=NULL){
        new->value=value;
        new->next=NULL;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=new;
    }
    else{
        printf("Elemento non inserito\n");
    }
}

Node *new_list(int value){
    Node *head=malloc(sizeof(Node));
    if(head!=NULL){
        head->value=value;
        head->next=NULL;
    }
    else{
        printf("Lista non creata\n");
    }
    return head;
}

void stampa(Node *head){
    if(head==NULL){
        printf("lista vuota\n");
    }
    else{
        printf("Lista:\n");
        while(head!=NULL){
            printf("%d ",head->value);
            head=head->next;
        }
    }
}

int counter(Node *head, int value){
    int c=0;
    while(head!=NULL){
        if(head->value==value){
            c++;
        }
        head=head->next;
    }
    return c;

}

Node *delete_node(Node *head, int value){
    if(head==NULL){
        return NULL;
    }
    Node *temp=NULL;
    if(head->value==value){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
        Node *prev=NULL;
        Node *curr=head;
        
        while(curr!=NULL&&curr->value!=value){
            prev=curr;
            curr=curr->next;
        }
        if(curr!=NULL){
            temp=curr;
            prev->next=curr->next;
            free(temp);
        }
    }
    return head;
}

void square_node(Node *head){
    while(head!=NULL){
        head->value*=(head->value);
        head=head->next;
    }
}

void free_list(Node *head){
    Node *next;
    while(head!=NULL){
        next=head->next;
        free(head);
        head=next;
    }
}