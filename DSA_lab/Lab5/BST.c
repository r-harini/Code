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
    struct Node* temp;
    struct Node* parent;
    n->data=data;
    n->lchild=NULL;
    n->rchild=NULL;
    if (root==NULL){
        root=n;
    }
    else{
        temp=root;
        parent=NULL;
        while(1){
            parent=temp;
            if (data<parent->data){
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
        printf("%d  ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(struct Node* root){
    if (root!=NULL){
        inorder(root->lchild);
        printf("%d  ", root->data);
        inorder(root->rchild);
    }
}

void postorder(struct Node* root){
    if (root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d  ", root->data);
    }
}

struct Node* FindMin(struct Node* node){
    struct Node* temp=node;
    while (temp && temp->lchild!=NULL){
        temp=temp->lchild;
    }
    return temp;
}

struct Node * del(struct Node*root,int y) // Deletion function.
{
	if(root == NULL)
	;
	else if(y < root->data) 
	root->lchild = del(root->lchild,y);
	else if(y > root->data)
	root->rchild = del(root->rchild,y);
	else
	{
		if(root->lchild == NULL && root->rchild == NULL) // No Child.
		{
			free(root);
			root = NULL;
		}
		else if(root->lchild == NULL) // One Child.
		{
			struct Node* k = root;
			root = root->rchild;
			free(k);
		}
		else if(root->rchild == NULL)
		{
			struct Node* k = root;
			root = root->lchild;
			free(k);
		}
		else // Two Children.
		{
			struct Node* k = FindMin(root->rchild);
			root->data = k->data;
			root->rchild = del(root->rchild,k->data);
		}
		
	}
	
	return root;
	
}


struct Node* maximum(struct Node* root){
    while (root->rchild!=NULL){
        root=root->rchild;
    }
    return root;
}




int main(){
    int c=1,n,a;
    //int array[8] = { 45,25,42,52,16,7,48,57};
    //for (int i=0;i<8;i++){
    //    insert(array[i]);
    //}
    while (c>0){
        printf("*****MENU******\n");
        printf("1->insert a number\n2->Preorder Traversal\n3->Inorder traversal\n");
        printf("4->Postorder traversal\n5->Find min\n6->Find max\n");
        printf("7->Delete\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter how many numbers to be inserted:");
                scanf("%d",&n);
                for (int i=0;i<n;i++){
                    printf("Enter the value:");
                    scanf("%d",&a);
                    insert(a);
                }
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("%d\n", FindMin(root)->data);
                break;
            case 6:
                printf("%d\n", maximum(root)->data);
                break;
            case 7:
                printf("Enter the number to be deleted:");
                scanf("%d",&a);
                del(root,a);
                break;
                
        }
    }
    return 0;
}