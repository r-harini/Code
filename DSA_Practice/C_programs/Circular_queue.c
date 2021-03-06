#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front;
    int rear;
    int max;
    int a[50];
};

void enqueue(struct Queue* q,int i){
    if ((q->rear==(q->max-1) && q->front==-1) || ((q->front==(q->rear)&&q->rear>-1))){
        printf("Queue is full\n");
        return;
    }
    else{     
        q->rear=(((q->rear)+1) % (q->max));
        q->a[q->rear]=i;
    }
}

void dequeue(struct Queue* q){
    if (q->front==-1 && q->rear==-1){
        printf("Queue is empty\n");
    }
    else{
        q->front=((q->front+1)%(q->max));
        if(q->front==(q->rear)){    
            printf("%d\n", q->a[q->front]);
            q->front=-1;
            q->rear=-1;
        }
        else{
        printf("%d\n", q->a[q->front]);
        }
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
    struct Queue* q= (struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
    q->max=3;
    enqueue(q,5);
    enqueue(q,4);
    enqueue(q,3);
    dequeue(q);
    enqueue(q,2);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}