#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front;
    int rear;
    int max;
    int a[50];
};

void enqueue(struct Queue* q,int i){
    if (q->rear==q->max){
        printf("Queue is full");
        return;
    }
    else{
        q->rear++;
        q->a[q->rear]=i;
    }
}

void dequeue(struct Queue* q){
    if (q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        q->front++;
        printf("%d", q->a[q->front]);
    }
}

void main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
    q->max=5;
    enqueue(q,3);
    enqueue(q,5);
    enqueue(q,4);
    dequeue(q);
    dequeue(q);
    dequeue(q);

}