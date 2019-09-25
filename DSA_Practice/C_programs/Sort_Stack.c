#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct Stack{
    int top;
    int a[50];
};

int is_empty(struct Stack* s){
    if (s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct Stack* s){
    if (s->top==MAX){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack* s, int i){
    if (is_full(s)){
        printf("Stack is full\n")
    }
    else{
        s->top++;
        s->a[s->top]=i;
    }
}

int pop(struct Stack* s){
    if (is_empty(s)){
        printf("Stack is empty\n");
    }
    else{
        int d=s->a[s->top];
        s->top--;
        return d;
    }
}

void display(struct Stack* s){
    for (int i=0;i<(s->top+1);i++){
        printf("%d\n")
    }
}