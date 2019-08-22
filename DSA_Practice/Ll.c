#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;

}*temp,*t,*tail;

void add(struct Node* head,int i){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=i;
    n->next=NULL;
    if (head->next==NULL){
        head->next=n;
        return;
    }
    //struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void delete(struct Node* head,int i){
    if (head->next->data==i){
        temp=head->next;
        head->next=head->next->next;
        free(temp);
        return;
    }
    temp=head->next;
    while (temp->next!=NULL){
        if (temp->next->data==i){
            t=temp->next;
            temp->next=temp->next->next;
            free(t);
            return;
        }
        temp=temp->next;
    }
}

void display(struct Node* head){
    temp=head->next;
    while (temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void odd_even(struct Node* head){
    struct Node* head2=(struct Node*)malloc(sizeof(struct Node));
    head2->next=NULL;
    temp=head->next;
    while (temp!=NULL){
        if (temp->data%2==0){
            delete(head,temp->data);
            add(head2,temp->data);
        }
        temp=temp->next;
    }
    temp=head->next;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2->next;
}

int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    
    add(head,1);
    add(head,2);
    add(head,3);
    add(head,4);
    add(head,5);
    add(head,6);
    add(head,7);
    display(head);
    printf("\n");
    //delete(head,4);
    odd_even(head);
    display(head);
    return 0;
}