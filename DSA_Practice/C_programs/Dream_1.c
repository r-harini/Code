struct Node{
    char name[30];
    int regno;
    char company[30];
    int pkg;
    struct Node* next;
    struct Node* prev;
}*head1,*tail1,*head2,*tail2, *head, *tail;

struct Node* head1=NULL;
struct Node* tail1=NULL;
struct Node* head2=NULL;
struct Node* tail2=NULL;
struct Node* head=NULL;
struct Node* tail=NULL;

algorithm insert(struct Node* head, struct Node* tail, char* name, char* company, int reg, int pkg){
    struct Node* n=(struct Node*)malloc;
    n->name=name;
    n->regno=reg;
    n->company=company;
    n->pkg;
    n->next=NULL;
    n->prev=NULL;
    if (head==NULL){
        head=n;
        tail=n;
        return;
    }
    else{
        n->next=head;
        head->prev=n;
        head=n;
        return;
    }
}

algorithm merge_lists(struct Node* head1, struct Node* tail1, struct Node* head2, struct Node* tail2, struct Node* head, struct Node* tail){
    head=head1;
    tail1->next=head2;
    head2->prev=tail1;
    tail=tail2;
}

algorithm sort(struct Node* head, struct Node* tail){
    struct Node* temp1=head;
    while (temp1->next!=NULL){
        struct Node* temp2=temp1->next;
        while (temp2!=NULL){
            if (temp1->regno>temp2->regno){
                struct Node* temp3=temp1;
                temp1->next=temp2->next;
                temp1->prev=temp2->prev;
                temp2->prev->next=temp1;
                temp2->next->prev=temp1;
                temp2->next=temp3->next;
                temp2->prev=temp3->prev;
                temp3->prev->next=temp2;
                temp3->next->prev=temp2;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

algorithm delete(struct Node* n){
    struct Node* temp=n->next;
    n->prev->next=n->next;
    n->next->prev=n->prev;
    n->next=NULL;
    n->prev=NULL;
    return temp->next;
}

algorithm remove_duplicate(struct Node* head, struct Node* tail){
    struct Node* temp=head;
    while (temp->next!=NULL){
        if (temp->regno==temp->next->regno){
            int r;
            printf ("Press 0 for %s and 1 for %s",temp->company, temp->next->company);
            scanf("%d",&r);
            if (r){
                temp=delete(temp->next);
            }
            else{
                temp=delete(temp);
            }
        }
        else{
            temp=temp->next;
        }
    }
}