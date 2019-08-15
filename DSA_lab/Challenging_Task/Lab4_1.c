#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//int top=-1;

struct Book{
int a_no;
char title[50];
char Author[50];
};

struct Stack{
int top;
struct Book* a[10]=(struct Book*)malloc(sizeof(struct Book)*10);
};

void push(struct Stack* s, struct Book* b){
if (s->top!=MAX){
s->top++;
s->a[s->top]=b;
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
struct Book* b=s->a[s->top];
printf("%d\n%s\n%s\n",b->a_no, b->title, b->Author );
s->top--; 
}
}

int main(){
struct Stack* s1=(struct Stack*)malloc(sizeof(struct Stack));
struct Stack* s2=(struct Stack*)malloc(sizeof(struct Stack));
s1->top=-1;
int n1;
printf("Enter n1:");
for (int i=0;i<n1;i++){
struct Book* b=(struct Book*)malloc(sizeof(struct Book));
scanf("%d\n%s\n%s\n",&b->a_no, b->title, b->Author );
push(s1,b);
}
pop(s1);


return 0;
}


