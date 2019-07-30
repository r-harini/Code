#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front;
    int rear;
    int max;
    int a[50];
};

void enqueue(struct Queue* q,int i){
    if (q->rear==q->max-1){
        printf("Queue is full\n");
        return;
    }
    else{
        q->rear++;
        q->a[q->rear]=i;
    }
}

void dequeue(struct Queue* q){
    if (q->front==q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        printf("%d\n", q->a[q->front]);
    }
}

void display(struct Queue* q){
    if (q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        for (int i=q->front+1;i<q->rear+1;i++){
            printf("%d\n",q->a[i]);
        }
    }
}

void is_empty(struct Queue* q){
    if (q->front==q->rear){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

void is_full(struct Queue* q){
    if (q->rear==q->max-1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

int main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
    q->max=5;
    is_empty(q);
    enqueue(q,3);
    is_empty(q);
    enqueue(q,5);
    enqueue(q,4);
    enqueue(q,2);
    enqueue(q,8);
    is_full(q);
    enqueue(q,9);
    
    //dequeue(q);
    //dequeue(q);
   // dequeue(q);
   display(q);
   return 0;
}