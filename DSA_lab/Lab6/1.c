#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* tail=NULL;

void add(int i){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=i;

    if (tail==NULL){
        n->next=n;
        tail=n;
        return;
    }
    n->next=tail->next;
    tail->next=n;
}

void delete(int i){
    struct Node* temp=tail->next;

    if (tail==NULL){
        printf("List is empty\n");
        return;
    }

    do{
        if (temp->next->data==i){
            struct Node* d= temp->next;
            temp->next=temp->next->next;
            d->next=NULL;
        }
        temp=temp->next;
    }while (temp->next!=tail->next);
}

int count(){
    struct Node* temp=tail->next;
    int c=0;

    if (tail==NULL){
        printf("List is empty\n");
        return 0;
    }

    do{
        c++;
        temp=temp->next;
    }while (temp!=tail->next);
    
    return c;
}

void traverse(){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=tail->next;
    do{
        printf("%d\n", temp->data);
        temp=temp->next;
    }while (temp!=tail->next);
}

int main(){
    add(1);
    add(2);
    add(3);
    traverse();
    delete(2);
    traverse();
    int c=count();
    printf("%d\n",c);
    
    return 0;
}