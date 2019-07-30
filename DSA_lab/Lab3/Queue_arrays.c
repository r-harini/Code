#include<stdio.h>
#define MAX 5

int queue[30],front=-1, rear=-1;

int is_empty(int* q){
    if (front==rear && front==-1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(int* q){
    if (rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int* q, int i){
    if (is_full(q)){
        printf("Queue is full\n");
    }
    else{
        rear++;
        q[rear]=i;
    }
}

void dequeue(int* q){
    if (is_empty(q)){
        printf("Queue is empty\n");
    }
    else{
        front++;
        printf("%d\n",q[front]);
    }
}

void display(int* q){
    if (is_empty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Displaying the queue:\n");
        for (int i=front+1;i<rear+1;i++){
            printf("%d\n",q[i]);
        }
    }
}

int main(){
    enqueue(queue,5);
    enqueue(queue,4);
    enqueue(queue,3);
    enqueue(queue,2);
    enqueue(queue,1);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}