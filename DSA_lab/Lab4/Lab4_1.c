#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


void display(struct Node* head){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    
    printf("Displaying the linked list\n");
    while(temp!=NULL){
        
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    
}

void add(struct Node* head, int i){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=i;
    newnode->next=NULL;

    if (head->next==NULL){
        head->next=newnode;
        
        return;
    }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insert(struct Node* head,int a, int i){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=i;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while (temp!=NULL){
        if (temp->data==a){
            newnode->next=temp->next;
            temp->next=newnode;
            return;
        }
        else{
            temp=temp->next;
        }
    }
    printf("Node not found\n");
}

void find(struct Node* head,int i){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while(temp!=NULL){
        if(temp->data==i){
            printf("%d found\n",i);
            return;
        }
        else{
            temp=temp->next;
        }
    }
    printf("Not found\n");
}

int o=0,e=0;
void odd_even(struct Node* head){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while(temp!=NULL){
        if (temp->data%2==0){
            e++;
        }
        else{
            o++;
        }
        temp=temp->next;
    }
}

struct Node* deletenode(struct Node* head,int i){
    struct Node* del=(struct Node*)malloc(sizeof(struct Node));
    if (head->next->data==i){
        del=head->next;
        head->next=del->next;
        return del;
    }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    while(temp->next!=NULL){
        if (temp->next->data==i){
            del=temp->next;
            temp->next=del->next;
            return del;
        }
        temp=temp->next;
    }
}

void remove_odd(struct Node* head, struct Node* head1){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head->next;
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    while (temp!=NULL){
        if ((temp->data)%2==1){
            n=deletenode(head, temp->data);
            add(head1,n->data);
        }
        temp=temp->next;
    }
}


int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    struct Node* head1=(struct Node*)malloc(sizeof(struct Node));
    head1->next=NULL;
    int c=1,n,a;
    int i;
    while (c>0){
        printf("****MENU*****\n");
        printf("1->Add a number\n2->Display the list\n3->Insert a number\n");
        printf("4->Find a number\n5->Check how many odd or even numbers\n");
        printf("6->Delete a number\n7->Remove all odd nos\n0->End the process\n******\n");
        scanf("%d",&c);
        switch (c) {
            case 1:
                printf("Enter how many numbers you want to add:");
                scanf("%d",&n);
                for (int i=0;i<n;i++){
                    printf("Enter the value:");
                    scanf("%d",&a);
                    add(head,a);
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the number to be inserted:");
                scanf("%d",&a);
                printf("Enter the number after which to be inserted:");
                scanf("%d",&i);
                insert(head,i,a);
                break;
            case 4:
                printf("Enter the number to be found:");
                scanf("%d",&a);
                find(head,a);
                break;
            case 5:
                odd_even(head);
                printf("Odd nos:%d\n Even nos:%d\n",o,e);
                break;
            case 6:
                printf("Enter the number to be deleted:");
                scanf("%d",&a);
                deletenode(head,a);
                break;
            case 7:
                remove_odd(head,head1);
                display(head1);
                break;
        }
    }
    
    return 0;
}