#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Disks{
    char type[10];
    int ID;
    int year;
    char mname[50];
};

struct Stack{
    int top;
    int max;
    struct Disks a[100];
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

void push(struct Stack* s, struct Disks d){
    if (s->top!=s->max){
        s->top++;
        s->a[s->top]=d;
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
        struct Disks d=s->a[s->top];
        printf("%s\n%d\n%d\n%s\n ", d.type, d.ID, d.year, d.mname);
        s->top--; 
    }
}

void display_s(struct Stack* s){
    for (int i=0;i<(s->top+1);i++){

        printf("%d\n %d\n %s\n", s->a[i].ID, s->a[i].year, s->a[i].mname);
    }
}

struct Queue{
    int front;
    int rear;
    int max;
    struct Disks a[50];
};

void enqueue(struct Queue* q, struct Disks d){
    if (q->rear==q->max-1){
        printf("Queue is full\n");
        return;
    }
    else{
        q->rear++;
        q->a[q->rear]=d;
    }
}

void dequeue(struct Queue* q){
    if (q->front==q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        struct Disks d=q->a[q->front];
        printf("%s\n%d\n%d\n%s\n ", d.type, d.ID, d.year, d.mname);
    }
}

void display_q(struct Queue* q){
    if (q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        for (int i=q->front+1;i<q->rear+1;i++){
            printf("%d\n",q->a[i]);
        }
    }
}

void check_year(struct Queue* q, struct Disks d){
    if (d.year==2015 && strcmp(d.type,"CD")==0){
        enqueue(q,d);
    }
}

void main(){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    //struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
    struct Disks d[15];
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        //struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
        printf("enter the type(CD/DVD), ID, year, mname:\n");
        scanf("%s %d %d %s",d[i].type, &d[i].ID, &d[i].year, d[i].mname);
        //push(s,d);
    }

    for (int i=0;i<n;i++){
        check_year(q, d[i]);
    }
    dequeue(q);

}