#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node *next;
};

void PrintList(struct Node* n){
while (n!=NULL){
    printf("%d\n",n->data);
    n=n->next;
}
}

void push(struct Node** headref, int e){
struct Node* n=(struct Node*)malloc(sizeof(struct Node));
n->data=e;
n->next=(*headref);
*headref=n;
}

void insert(struct Node* prevnode, int e){
struct Node* n=(struct Node*)malloc(sizeof(struct Node));
n->data=e;
n->next=prevnode->next;
prevnode->next=n;

}

int main(){
struct Node* head=NULL;
struct Node* second=NULL;
struct Node* third=NULL;

head=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));

head->data=1;
head->next=second;

second->data=2;
second->next=third;

third->data=4;
third->next=NULL;

push(&head, 0);

insert(second,3);
insert(second->next,5);
insert(second->next->next,8);

PrintList(head);

return 0;
}
