#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[50];
    struct Node* prev;
    struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;

void add(char* name){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->prev=NULL;
    strcpy(n->name,name);
    if (head==NULL){
        n->next=NULL;
        head=n;
        tail=n;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
}

void displayfront(){
    struct Node* temp;
    temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    else{
        while (temp!=NULL){
            printf("%s\n",temp->name);
            temp=temp->next;
        }
    }
}

void sort(){
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=head;
    while (temp->next!=NULL){
        struct Node* d=temp->next;
        while (d!=NULL){
            if (strcmp(temp->name, d->name)==1){
                char newname[50];
                strcpy(newname,d->name);
                strcpy(d->name,temp->name);
                strcpy(temp->name,newname);
            }
            d=d->next;
        }
        temp=temp->next;
    }
    printf("Sorted:\n");
}

void findM(){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Finding all names starting with M:\n");
    while (temp!=NULL){
        if (temp->name[0]=='M'){
            printf("%s\n", temp->name);
        }
        temp=temp->next;
    }
}

struct Node* find(char* name){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return temp;
    }
    while (temp!=NULL){
        if (strcmp(temp->name,name)==0){
            printf("Found\n");
            return temp;
        }
        temp=temp->next;
    }
    printf("Not found\n");
    return temp;
}

void replace(char* name1, char* name2){
    struct Node* n=find(name1);
    strcpy(n->name, name2);

}

void displayreversefrom(char* name){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* k;
    while (temp!=NULL){
        if (strcmp(temp->name,name)==0){
            k=temp;
            break;
        }
        temp=temp->next;
    }
    k=k->prev;
    printf("Displaying the names in reverse order:\n");
    while (k!=NULL){
        printf("%s\n",k->name);
        k=k->prev;
    }
}

int main(){
    add("Masooma");
    add ("Harini");
    add("Yash");
    add("Aakash");
    add("Darshan");
    add("Guna");
    displayfront();
    sort();
    displayfront();
    findM();
    struct Node* n=find("Guna");
    replace("Guna", "Harish");
    sort();
    displayreversefrom("Harish");

    return 0;
}