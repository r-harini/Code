#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Node{
    int regno;
    char name[50];
    float cgpa;
    struct Node* next;
};

void display(struct Node* head){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    printf("Displaying the linked list\n");
    while (temp!=NULL){
        printf("%d\n%s\n%f\n",temp->regno,temp->name,temp->cgpa);
        temp=temp->next; 
    }
}

void add(struct Node* head, struct Node* n){
    if (head->next==NULL){
        n->next=NULL;
        head->next=n;
        return;
    }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}

void search(struct Node* head, int r){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while(temp!=NULL){
        if (temp->regno==r){
            printf("%s\n",temp->name);
            return;
        }
        temp=temp->next;
    }
    printf("Register not found\n");
}

void update(struct Node* head, int r, float cg){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while(temp!=NULL){
        if(temp->regno==r){
                temp->cgpa=cg;
                return;
        }
        temp=temp->next;
    }
}

void topper(struct Node* head){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    struct Node* topper=(struct Node*)malloc(sizeof(struct Node));
    float t=0;
    while (temp!=NULL){
        if (temp->cgpa>t){
            topper=temp;
            t=temp->cgpa;
        }
        temp=temp->next;
    }
    printf("%d\n%s\n%f\n",topper->regno,topper->name,topper->cgpa);
}

struct Node* del(struct Node* head, int r){
    struct Node* d=(struct Node*)malloc(sizeof(struct Node));
    if (head->next->regno==r){
        d=head->next;
        head->next=d->next;
        return d;
    }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while (temp->next!=NULL){
        if (temp->next->regno==r){
            d=temp->next;
            temp->next=d->next;
            return d;
        }
        temp=temp->next;
    }
}

void enqueue(struct Node* head, struct Node* n){
    add(head,n);
}

void dequeue(struct Node* head){
    struct Node* d=(struct Node*)malloc(sizeof(struct Node));
    d=head->next;
    head->next=d->next;
    
    printf("%d\n%s\n%f\n",d->regno,d->name,d->cgpa);
    
}

void cgpa_8(struct Node* head, struct Node* queue){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    while (temp!=NULL){
        if (temp->cgpa>8.5){
            n=del(head,temp->regno);
            enqueue(queue,n);
        }
        temp=temp->next;
    }
}

void push(struct Node* stack, struct Node* n){
    add(stack,n);
}

void pop(struct Node* stack){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=stack->next;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    del(stack,temp->regno);
}

void Nine_pointer(struct Node* head, struct Node* s){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    while(temp!=NULL){
        if (temp->cgpa>9){
            n=del(head,temp->regno);
            push(s,n);
        }
        temp=temp->next;
    }
}

int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    int c=1,n,k=0;
    struct Node newnode[30];
    int r;
    float cg;
    struct Node* q=(struct Node*)malloc(sizeof(struct Node));
    q->next=NULL;
    struct Node* s=(struct Node*)malloc(sizeof(struct Node));
    s->next=NULL;
    newnode[0].regno=1010;
    newnode[0].name="harini";
    newnode[0].cgpa=9.3;
    newnode[1].regno=1009;
    newnode[1].name="madhu";
    newnode[1].cgpa=8.3;
    newnode[2].regno=1018;
    newnode[0].name=""
    add(head,&newnode[0]);
    add(head,&newnode[1]);
    display(head);
    Nine_pointer(head, q);
    //display(head);
    display(q);
    /*while(c>0){
        printf("****MENU****\n");
        printf("1->Add student details\n2->Display the list\n3->Search by regno\n");
        printf("4->Search for topper\n5->CGPA>8.5\n6->Update CGPA\n");
        printf("7->Display queue\n8->Nine pointer stack\n9>Display stack\n");
        printf("0->End the process\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter how many you want to add:");
                scanf("%d",&n);
                for (int i=0;i<n;i++){
                    //struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
                    printf("Enter regno, name and cgpa:");
                    scanf("%d\n%s\n%f",&newnode[k].regno, newnode[k].name, &newnode[k].cgpa);
                    add(head,&newnode[k]);
                    k++;
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                
                printf("Enter the register number:");
                scanf("%d",&r);
                search(head,r);
                break;
            case 4:
                topper(head);
                break;
            case 5:
                cgpa_8(head,q);
                break;
            case 6:
                printf("Enter the register number:");
                scanf("%d",&r);
                printf("Enter the updated cgpa:");
                scanf("%f",&cg);
                update(head,r,cg);
                break;
            case 7:
                display(q);
                break;
            case 8:
                Nine_pointer(head,s);
                break;
            case 9:
                display(s);
                break;
        }
    }
    */

}