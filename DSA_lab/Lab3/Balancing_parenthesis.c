#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

struct Stack{
    int top;
    char a[30];
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

void push(struct Stack* s, char i){
    if (is_full(s)){
        printf("Stack is full\n");
    }
    else{
        s->top++;
        s->a[s->top]=i;
    }
}

void pop(struct Stack* s){
    if (is_empty(s)){
        printf("Stack is empty\n");
    }
    else{
        //printf("%c",s->a[s->top]);
        s->top--;
    }
}

void display(struct Stack* s){
    for (int i=0;i<(s->top+1);i++){
        printf("%c\n",s->a[i]);
    }
}

int main(){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
    char p[30];
    scanf("%s",p);
    for (int i=0;i<strlen(p);i++){
        if (p[i]=='('){
            push(s,p[i]);
        }
        else if (p[i]==')'){
            pop(s);
        }
        else{
            continue;
        }        
    }

    if (is_empty(s)){
        printf("Balanced");
    }
    else{
        printf("Not balanced");
    }
}