#include<stdio.h>
#include<stdlib.h>



struct Stack{
int top;
int max;
int a[100];
};


void is_empty(struct Stack* s){
if (s->top==-1){
printf("true\n");
}
else{
printf("false\n");
}
}

void is_full(struct Stack* s){
if (s->top==s->max){
printf("true\n");
}
else{
printf("false\n");
}
}

void push(struct Stack* s, int i){
if (s->top!=s->max){
s->top++;
s->a[s->top]=i;
}
else{
printf("Stack is full\n");
}
}

void pop(struct Stack* s){
if (s->top==-1){
printf("Stack is empty\n");
}
else{
printf("%d\n", s->a[s->top]);
s->top--; 
}
}

void display(struct Stack* s){
for (int i=0;i<(s->top+1);i++){
printf("%d\n", s->a[i]);
}
}




int main(){
struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack)); 
s->top=-1;
s->max=5;
is_empty(s);
push(s,5);
//pop(s);
push(s,3);
//pop(s);
push(s,4);
push(s,2);
push(s,1);
pop(s);
pop(s);
//pop(s);
display(s);

return 0;
}
