#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char coach[10];
    struct Node* next;
}*temp,*head,*tail;

algorithm add(char c*){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    strcpy(n->coach,c);
    if (head==NULL){
        n->next=NULL;
        head=n;
        tail=n;
    }
    else{
        n->next=head;
        head=n;
    }
}

algorithm insert(char c1*, char c2*){
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    else{
        struct Node* n=(struct Node*)malloc(sizeof(struct Node));
        strcpy(n,c1);
        n->next=NULL;
        temp=head;
        while (temp!=NULL){
            if (strcmp(temp->coach,c2)==0){
                struct Node* old;
                old=temp->next;
                temp->next=n;
                n->next==old;
                if (temp==tail){
                    tail=n;
                }
                return;
            }
        }
        printf("Node not found");
    }
}

algorithm delete_last(){
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    else{
        temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
    }
}

