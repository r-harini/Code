#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book{
    int accno;
    char title[50];
    char status[50];
};

struct Node{
    int eid;
    char name[50];
    struct Book b[10];
    int tot;
    struct Node* rchild;
    struct Node* lchild;
};

struct Node* root=NULL;

void add(){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the emp id:");
    scanf("%d",&n->eid);
    printf("Enter the name:");
    scanf("%s", n->name);
    printf("Enter the total books:");
    scanf("%d",&n->tot);
    for (int i=0;i<n->tot;i++){
        printf("Enter the book access no:");
        scanf("%d", &n->b[i].accno);
        printf("Enter the book title:");
        scanf("%s",n->b[i].title);
        printf("Enter the status(Issued/Returned):");
        scanf("%s",n->b[i].status);
    }
    struct Node* temp;
    struct Node* parent;
    n->lchild=NULL;
    n->rchild=NULL;
    if (root==NULL){
        root=n;
    }
    else{
        temp=root;
        parent=NULL;
        while (1){
            parent=temp;
            if (n->eid<parent->eid){
                temp=temp->lchild;
                if (temp==NULL){
                    parent->lchild=n;
                    return;
                }
            }
            else{
                temp=temp->rchild;
                if (temp==NULL){
                    parent->rchild=n;
                    return;
                }
            }
        }
    }
}

void preorder(struct Node* root){
    if (root!=NULL){
        printf("%d\n", root->eid);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(struct Node* root){
    if (root!=NULL){
        inorder(root->lchild);
        printf("%d\n", root->eid);
        inorder(root->rchild);
    }
}

struct Node* find(struct Node* root, int id){
    struct Node* n;
    if (root->eid==id){
        return root;
    }
    else{
        if (id>root->eid){
            n=find(root->rchild,id);
            return n;
        }
        else{
            n=find(root->lchild,id);
            return n;
        }
    }
}

void return_books(int id, int acc_no){
    struct Node* n=find(root, id);
    for (int i=0;i<n->tot;i++){
        if (n->b[i].accno==acc_no){
            strcpy(n->b[i].status,"Returned");
            struct Book temp=b[i];
            b[i]=b[n->tot-1];
            b[n->tot-1]=temp;
            n->tot--;
        }
    }
}

struct Node* FindMin(struct Node* node){
    struct Node* temp=node;
    while (temp && temp->lchild!=NULL){
        temp=temp->lchild;
    }
    return temp;
}

/*struct Node* del(struct Node* root, int id){
    if (root==NULL);
    else if(id<root->eid){
        root->lchild=del(root->lchild,id);
    }
    else if(id>root->eid){
        root->rchild=del(root->rchild,id);
    }
    else{
        if (root->lchild==NULL && root->rchild==NULL){
            free(root);
            root=NULL;
        }
        else if (root->lchild==NULL){
            struct Node* k=root;
            root=root->rchild;
            free(k);
        }
        else if(root->rchild==NULL){
            struct Node* k=root;
            root=root->lchild;
            free(k);
        }
        else{
            struct Node* k=FindMin(root->rchild);
            k->lchild=root->lchild;

        }
    }
}*/

int main(){
    /*add();
    add();
    add();
    add();
    add();
    preorder(root);
    int id;
    printf("Enter the id to be found:");
    scanf("%d",&id);
    struct Node* n=find(root,id);
    printf("%s\n", n->name);
    int accno;
    printf("Enter the accno of the book:");
    scanf("%d",&accno);
    return_books(id,accno);
    n=find(root,id);
    printf("%s\n", n->name);
    printf("%d\n",n->tot);*/

    int c=1,id,accno;

    while (c>0){
        printf("******MENU******\n");
        printf("1->Add\n2->Preorder traversal\n3->Inorder traversal\n");
        printf("4->Find\n5->Return Books\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                add();
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                printf("Enter the id to be found:");
                scanf("%d",&id);
                struct Node* n=find(root,id);
                printf("%s\n",n->name);
                break;
            case 5:
                printf("Enter the emp id:");
                scanf("%d",&id);
                printf("enter the access no of the book:");
                scanf("%d",&accno);
                return_books(id,accno);
                break;
        }
    }
    return 0;
}