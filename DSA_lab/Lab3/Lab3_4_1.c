#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

struct Disks{
    char type[10];
    int ID;
    int year;
    char mname[10];
};

struct Stack{
    int top;
    struct Disks* a[100];
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
    if (s->top==(MAX-1)){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack* s, struct Disks* d){
    if (is_full(s)){
        printf("Stack is full\n");
    }
    else{
        s->top++;
        s->a[s->top]=d;
    }
}

struct Disks* pop(struct Stack* s){
    if (is_empty(s)){
        printf("Stack is empty\n");
    }
    else{
        struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
        d=s->a[s->top];
        //printf("%s\n%d\n%d\n%s\n", d->type, d->ID, d->year, d->mname);
        s->top--;
        return d;
    }
}

void display_s(struct Stack* s){
    for (int i=0;i<(s->top+1);i++){
        struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
        d=s->a[i];
        printf("%s\n%d\n%d\n%s\n ", d->type, d->ID, d->year, d->mname);
    }
}

struct Queue{
    int front;
    int rear;
    struct Disks* a[50];
};

int qis_full(struct Queue* q){
    if (q->front==q->rear && q->rear>-1){
        return 1;
    }
    else{
        return 0;
    }
}

int qis_empty(struct Queue* q){
    if (q->rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue* q, struct Disks* d){
    if (qis_full(q)){
        printf("Queue is full\n");
    }
    else{
        q->rear++;
        q->a[q->rear]=d;
    }
}

void dequeue(struct Queue* q){
    if (qis_empty(q)){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
        d=q->a[q->front];
        printf("%s\n%d\n%d\n%s\n ", d->type, d->ID, d->year, d->mname);
    }
}

void display_q(struct Queue* q){
    if (qis_empty(q)){
        printf("Queue is empty\n");
    }
    else{
        for (int i=(q->front+1);i<(q->rear+1);i++){
        struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
        d=q->a[i];
        printf("%s\n%d\n%d\n%s\n ", d->type, d->ID, d->year, d->mname);
        }
    }
}

void check_year(struct Queue* q, struct Disks* d){
    if (d->year==2015 && strcmp(d->type, "CD")==0){
        printf("\n%s is from 2015\n",d->mname);
        enqueue(q,d);
    }
}

void sort_disks(struct Disks* d,int n){
    struct Disks t;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (d[i].year>d[j].year){
                t=d[i];
                d[i]=d[j];
                d[j]=t;
            }
        }
    }
}

void move_DVD_stack(struct Stack* s, struct Disks* d){
    if (strcmp(d->type,"DVD")==0){
        push(s,d);
        printf("\n%s is moved to the stack\n", d->mname);
    }
}

void check_2018(struct Stack* s, struct Stack* s1,struct Queue* q){
    struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
    for (int i=0;i<s->top;i++){
        d=pop(s);
        if (strcmp(d->type,"DVD")==0 && d->year==2018){
            printf("\n%s is added to the queue\n",d->mname);
            enqueue(q,d);
        }
        else{
            push(s1,d);
        }
    }
}

int main(){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
    struct Stack* s1=(struct Stack*)malloc(sizeof(struct Stack));
    s1->top=-1;
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->rear=-1;
    q->front=-1;
    struct Queue* q2=(struct Queue*)malloc(sizeof(struct Queue));
    q2->rear=-1;
    q2->front=-1;
    int n;
    //printf("Enter n:");
    scanf("%d",&n);
    
    struct Disks d[n];

    for (int i=0;i<n;i++){
        //struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
        printf("Enter the type(CD/DVD), ID, year, mname:\n");
        scanf("%s %d %d %s",d[i].type, &d[i].ID, &d[i].year, d[i].mname);
        //push(s,d);
    }

    for (int i=0;i<n;i++){
        check_year(q,&d[i]);
        //push(s,&d[i]);
    }

    sort_disks(d,n);
    for (int i=0;i<n;i++){
        move_DVD_stack(s,&d[i]);
    }

    check_2018(s,s1,q2);

    //pop(s);
    //printf("%s\n%d\n%d\n%s\n ", d[1].type, d[1].ID, d[1].year, d[1].mname);

    //dequeue(q);

    /*printf("enter the type(CD/DVD), ID, year, mname:\n");
    scanf("%s %d %d %s",d->type, &d->ID, &d->year, d->mname);
    push(s,d);
    struct Disks* d=(struct Disks*)malloc(sizeof(struct Disks));
    d->type="CD";
    d->ID=101;
    d->year=2015;
    d->mname="Pirates";
    push(s,d);
    struct Disks* d1=(struct Disks*)malloc(sizeof(struct Disks));
    d1->type="CD";
    d1->ID=123;
    d1->year=2015;
    d1->mname="Mermaids";
    push(s,d1);
    */

    //pop(s);
    //pop(s);
    
    return 0;
}