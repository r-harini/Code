#include<stdio.h>
#define MAX 5

int stack[20],top=-1;

int is_empty(int* s){
    if (top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(int* s){
    if (top==MAX){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int* s, int i){
    if (is_full(s)){
        printf("Stack is full\n");
    }
    else{
        top++;
        s[top]=i;
    }
}

void pop(int*s){
    if (is_empty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n",s[top]);
        top--;
    }
}

void display(int* s){
    if (is_empty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Displaying the stack:\n");
        for (int i=0;i<top+1;i++){
            printf("%d\n",s[i]);
        }
    }
}

int main(){
    push(stack,5);
    push(stack,4);
    push(stack,3);
    push(stack,2);
    push(stack,1);
    pop(stack);
    pop(stack);
    display(stack);
}