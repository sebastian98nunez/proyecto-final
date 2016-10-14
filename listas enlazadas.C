#include <stdio.h>

struct node{
    int value;
    struct node *next;
};

struct node *crear(int n){

    int i;
    struct node *prev,*cur,*head;
    head=malloc(sizeof(struct node));
    head->value=1;
    prev=head;
    for(i=2;i<=n;i++){
        cur=malloc(sizeof(struct node));
        cur->value=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next=NULL;
    return head;
}

void imprimir(struct node *head){
    struct node *prev;
    prev=head;
    while(prev->next!=NULL){
        printf("%d ",prev->value);
        prev=prev->next;
    }
    printf("%d",prev->value);
 }

void insertarenorden(struct node *head, int element){
    struct node *prev,*curr,*tempo;
    prev=malloc(sizeof(struct node));
    curr=malloc(sizeof(struct node));
    prev=head;
    curr=head->next;
    while(curr->value < element ){
        prev=prev->next;
        curr=curr->next;
    }
    if (curr->value != element){
        tempo=malloc(sizeof(struct node));
        tempo->value=element;
        tempo->next=curr;
        prev->next=tempo;
    }
    if (prev->next == NULL){
        tempo=malloc(sizeof(struct node));
        tempo->value=element;
        tempo->next=NULL;
        curr->next=tempo;
    }

}


void  concatenar(struct node *head, struct node *head2){
    struct node *cont;
    cont=malloc(sizeof(struct node));
    cont=head;
    while(cont->next != NULL)
        cont=cont->next;
    cont->next=head2;
}

void borrar(int n, struct node *head){
        struct node *prev,*cur,*temp;
        if(head->value==n){
            temp =head;
            head=head->next;
            free(temp);

        }
        else{
            prev=head;
            cur=head->next;
            while(cur !=NULL){
                if(cur->value==n){
                    prev->next=cur->next;
                    free(cur);
                    break;
                    }
            prev=cur;
            cur=cur->next;
            }
        }
}

void insertarmedio(struct node *head, int element){
    int cont=1;
    struct node *prev,*curr,*tempo;
    prev=malloc(sizeof(struct node));
    curr=malloc(sizeof(struct node));
    prev=head;
    curr=head;
    while(curr->next != NULL ){
        curr=curr->next;
        cont++;
    }
    cont= cont/2;
    while(prev->value != (cont)){
        prev=prev->next;
    }
    curr=prev->next;
    tempo=malloc(sizeof(struct node));
    tempo->value=element;
    tempo->next=curr;
    prev->next=tempo;
    }

struct node *insertarinicio(struct node *head, int elemento){
    struct node *tempo,*curr;
    tempo=malloc(sizeof(struct node));
    curr=malloc(sizeof(struct node));
    tempo->value=elemento;
    tempo->next=head;
    return tempo;
}

int main(){
    struct node *head, *head2;
    head=crear(20);
    head2=crear(20);
    borrar(5,head);
    concatenar(head,head2);
    imprimir(head);
    printf("%c",('\n'));
    head=insertarinicio(head,5);
    insertarenorden(head,5);
    insertarmedio(head,60);
    imprimir(head);
}
