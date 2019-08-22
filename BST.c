#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* root=NULL;

void insert(int i){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=i;
    n->lchild=NULL;
    n->rchild=NULL;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=root;
    if (temp==NULL){
        root=n;
        return;
    }
    struct Node* parent=(struct Node*)malloc(sizeof(struct Node));
    parent=root;
    while (parent!=NULL){
        if (i<parent->data){
            temp=parent->lchild;
            if (temp==NULL){
                parent->lchild=n;
                return;
            }
            parent=temp;
        }
        else{
            temp=parent->rchild;
            if (temp==NULL){
                parent->rchild=n;
                return;
            }
            parent=temp;
        }
    }
}

void preorder(struct Node* root){
    if (root!=NULL){
        printf("%d\n",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
    return;
}

void delnode(int i){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=root;
    if (root==NULL){
        return;
    }
    struct Node* parent=(struct Node*)malloc(sizeof(struct Node));
    parent=root;
    while (temp!=NULL){
        if (i<parent->data){
            temp=parent->lchild;
            if (i==temp->data){
                parent->lchild=;
                
            }
        }
        else if(i>parent->data){
            temp=parent->rchild;
        }
        else{
            
        }
    }
}
        
int main(){
    //struct Node* root= (struct Node*)malloc(sizeof(struct Node));
    //root->lchild=NULL;
    insert(3);
    insert(2);
    insert(4);
    insert(5);
    insert(1);
    preorder(root);
}