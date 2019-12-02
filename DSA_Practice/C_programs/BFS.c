#include<stdio.h>
#include<stdlib.h>

#define initial 1
#define waiting 2
#define visited 3
#define MAX 100
int adj[100][100],state[100];
int n,queue[100], front=-1, rear=-1;

void enqueue(int v){
    rear++;
    queue[rear]=v;
}

int dequeue(){
    front++;
    int d=queue[front];
    return d;
}

int is_empty(){
    if (front==rear){
        return 1;
    }
    else{
        return 0;
    }
}

void create_graph(){
    int count, maxedge, org, dest;
    printf("Enter the no. of vertices:");
    scanf("%d",&n);
    maxedge=n*(n-1);
    for (int count=1;count<maxedge;count++){
        printf("Enter edge %d(-1 -1 to quit):",count);
        scanf("%d %d", &org, &dest);
        if (org==-1 && dest==-1) break;
        else{
            adj[org][dest]=1;
        }
    }
}

void BFS(){
    int v;
    printf("Enter the source vertex:");
    scanf("%d",&v);
    for (int i=0;i<n;i++){
        state[i]=initial;
    }
    enqueue(v);
    state[v]=waiting;
    while (!is_empty()){
        v=dequeue();
        printf("%d",v);
        state[v]=visited;
        for (int i=0; i<n;i++){
            if (adj[v][i]==1 && state[i]==initial){
                enqueue(i);
                state[i]=waiting;
            }
        }
    }
    printf("\n");
}

int main(){
    create_graph();
    BFS();
    return 0;
}