#include<stdio.h>
#include<stdlib.h>

int stack[20], top=-1;

void push(int stack*, int top, int i){
    if (top==10){
        printf("Stack is full\n");
    }
    else{
        top++;
        stack[top]=i;
    }
}

int pop(int stack*, int top){
    if (top==-1){
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("%d\n",stack[top]);
        int i=stack[top];
        top--;
        return i;
    }
}

void splitstack(int stack*, int top){
    int s1[20],s2[20],t1,t2;
    t1=-1;
    t2=-1;
    for (i=0;i<top+1;i++){
        if (i%2==0){
            push(s1,t1,stack[i]);
        }
        else{
            push(s2,t2,stack[i]);
        }
    }
    for (i=0;i<t2+1;i++){
        int k=pop(s2,t2);
        push(stack, top, k);
    }
    for (i=0;i<t1+1;i++){
        int k=pop(s1,t1);
        push(stack, top, k);
        
    }

}