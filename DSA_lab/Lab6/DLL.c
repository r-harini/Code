#include<stdio.h>
#include<stdlib.h>

struct Node{
    int ele;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;
struct Node* tail=NULL;

void add(int i){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->prev=NULL;
    if (head==NULL){
        n->next=NULL;
        head=NULL;
        tail=NULL;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
}

void display(){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    while (temp!=NULL){
        
    }
}
