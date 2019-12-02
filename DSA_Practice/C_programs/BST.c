#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* root=NULL;

void insert(int data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->lchild=NULL;
    n->rchild=NULL;
    if (root==NULL){
        root=n;
        return;
    }
    else{
        struct Node* temp=root;
        struct Node* parent;
        while (1){
            parent=temp;
            if (data<parent->data){
                temp=parent->lchild;
                if (temp==NULL){
                    parent->lchild=n;
                    return;
                }
            }
            else{
                temp=parent->rchild;
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
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

struct Node* FindMin(struct Node* node){
    while (node && node->lchild!=NULL){
        node=node->lchild;
    }
    return node;
}

struct Node* del(struct Node* root, int data){
    if (root==NULL);
    else if (data>root->data){
        root->rchild=del(root->rchild, data);
    }
    else if (data<root->data){
        root->lchild=del(root->lchild,data);
    }
    else{
        if (root->lchild==NULL && root->rchild==NULL){
            free(root);
            root=NULL;
        }
        else if (root->rchild==NULL){
            struct Node* k=root;
            root=root->lchild;
            free(k);
        }
        else if (root->lchild==NULL){
            struct Node* k=root;
            root=root->rchild;
            free(k);
        }
        else{
            struct Node* k=FindMin(root->rchild);
            root->data=k->data;
            root->rchild=del(root->rchild,k->data);
        }
    }
    return root;
}

int prod(struct Node* root){
    int p, p1, p2;
    if (root->lchild==NULL && root->rchild==NULL){
        return root->data;
    }
    else if (root->lchild==NULL){
        p1=prod(root->rchild);
        return p1;
    }
    else if (root->rchild==NULL){
        return prod(root->lchild);
    }
    else{
        p1=prod(root->lchild);
        p2=prod(root->rchild);
        return p1*p2;
    }
}

int count(struct Node* root){
    if (root->lchild==NULL && root->rchild==NULL){
        return 0;
    }
    else if (root->lchild==NULL){
        return count(root->rchild)+1;
    }
    else if (root->rchild==NULL){
        return count (root->lchild)+1;
    }
    else{
        return count(root->rchild)+count(root->lchild)+1;
    }
}


int main(){
    insert(17);
    insert(12);
    insert(20);
    insert(11);
    insert(14);
    insert(18);
    preorder(root);
    printf("\n %d", count(root));
    //del(root, 12);
    //preorder(root);
    return 0;
}