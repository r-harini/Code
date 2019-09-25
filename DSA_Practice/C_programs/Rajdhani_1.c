struct Node{
    char coach[10];
    struct Node* next;
    struct Node* prev;
}*temp,*head,*tail;

algorithm add(char c*){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    strcpy(n->coach,c);
    if (head==NULL){
        n->next=NULL;
        n->prev=NULL;
        head=n;
        tail=n;
    }
    else{
        n->prev=NULL;
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
        n->prev=NULL;
        temp=head;
        while (temp!=NULL){
            if (strcmp(temp->coach,c2)==0){
                struct Node* old;
                old=temp->next;
                temp->next=n;
                n->prev=temp;
                old->prev=n;
                n->next==old;
                if (temp==tail){
                        n->prev=tail;
                        tail->next=n;
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
        tail->prev->next=NULL;
        tail=tail->prev;
        return tail->data;
    }
}


