#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char nome[20];
    float prezzo;
    unsigned int sconto;
    struct Node *next;
    struct Node *previous;
}Node;

int main (void){
    Node volantino={"Coca cola", 1, 0, NULL, NULL};
    Node n1={"Pepsi", 0.9, 10, NULL, &volantino};
    Node n2={"Fanta", 0.5, 50, NULL, &n1};
    Node n3={"Sprite", 0.8, 20, NULL, &n2};
    volantino.next=&n1;
    n1.next=&n2;
    n2.next=&n3;

    Node *pagina=&volantino;
    int a=0;
    int b=0;
    unsigned int sconto=0;
    while(a==0){
        scanf("%d",&b);
        if(b==0){
            scanf("%d",&b);
            switch (b){
                case 2:
                pagina=pagina->next;
                printf("%s", pagina->nome);
                break;
                case 3:
                pagina=pagina->previous;
                printf("%s", pagina->nome);
                break;
                default:
        }
        }
        else{
            pagina=&volantino;
            while(pagina!=NULL){
                if(sconto<pagina->sconto){
                    sconto=pagina->sconto;
                }
                pagina=pagina->next;
            }
            printf("%u", sconto);
        }
        sconto=0;
        printf("continuare? 0: si... altrimenti: no");
        scanf("%d",&a);
    }
}

