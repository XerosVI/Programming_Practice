#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 100
typedef struct Node{
    int id;
    char num_volo[MAX_STR];
    char posto[MAX_STR];
    struct Node *next;
}Node;
Node *crea(int id, char num_volo[], char posto[]);
void add(Node **head, int id, char num_volo[], char posto[]);
int simili(Node *head, int id, char num_volo[]);
void add_no_duplicates(Node **head, int id, char num_volo[], char posto[]);
int conflitto(Node *head, char num_volo[]);
void num(Node *head, char num_volo[]);

int main(void){
    Node *lista=NULL;
    add(&lista,0,"AZ123","0A");
    add(&lista,1,"AZ123","0A");
    add(&lista,2,"AZ000","0B");
    if(conflitto(lista,"AZ123")==1){
        printf("Conflitto");
    }
    else{
        printf("no conflitto");
    }
    num(lista,"AZ123");
    num(lista,"AZ000");
    return 0;
}


Node *crea(int id, char num_volo[], char posto[]){
    Node *new=malloc(sizeof(Node));
    if(new==NULL){
        exit(1);
    }
    new->id=id;
    strcpy(new->num_volo,num_volo);
    strcpy(new->posto,posto);
    new->next=NULL;
    return new;
}

void add(Node **head, int id, char num_volo[], char posto[]){
    if(head==NULL){
        return;
    }
    Node *curr=*head, *prev=NULL;
    Node *new=crea(id,num_volo,posto);
    while(curr!=NULL&&curr->id<id){
        prev=curr;
        curr=curr->next;
    }
    if(prev==NULL){
        new->next=*head;
        *head=new;
    }
    else{
        prev->next=new;
        new->next=curr;
    }
    
}
        

int simili(Node *head, int id, char num_volo[]){
    if(head==NULL){
        return 0;
    }
    while(head!=NULL&&head->id<id){
        head=head->next;
    }
    while(head!=NULL&&head->id==id){
        if(strcmp(head->num_volo,num_volo)==0){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

void add_no_duplicates(Node **head, int id, char num_volo[], char posto[]){
    if(simili(*head,id,num_volo)==1){
        printf("Gia' presente\n");
    }
    else{
        add(head,id,num_volo,posto);
    }
}

int conflitto(Node *head, char num_volo[]){
    Node *i=head;
    while(i!=NULL){
        if (strcmp(i->num_volo, num_volo) == 0){
            Node *j=i->next;
            while(j!=NULL){
                if(strcmp(j->num_volo, num_volo)==0&&strcmp(j->posto, i->posto)==0){
                    return 1;
                }
                j=j->next;
            }
        }
        i=i->next;
    }
    return 0;
}

void num(Node *head, char num_volo[]){
    int c=0;
    while(head!=NULL){
        if (strcmp(head->num_volo, num_volo) == 0){
            c++;
        }
        head=head->next;
    }
    printf("Ci sono %d passeggeri", c);
}
