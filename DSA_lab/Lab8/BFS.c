#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[100][100];
int n, state[100];
int queue[100], front=-1, rear=-1;

void enqueue(int vertex){
if (rear==MAX-1){
printf("Queue is full\n");
}
else{
if (front==-1){
front=0;}
rear++;
queue[rear]=vertex;
}
}

int is_empty(){
if (front==-1||front>rear)
return 1;
else
return 0;
}

int dequeue(){
int delete_item;
if (front==-1||front>rear){
printf("Queue is empty\n");
exit(1);
}
delete_item=queue[front];
front=front+1;
return delete_item;
}

void create_graph(){
int count, max_edge, origin,dest;
printf("Enter the no. of vertices:");
scanf("%d",&n);
max_edge=n*(n-1);
for (count=1;count<max_edge;count++){
printf("Enter edge %d(-1 -1 to quit):", count);
scanf("%d %d",&origin, &dest);
if ((origin==-1)&&(dest==-1))break;
if (origin>=n||dest>=n||origin<0||dest<0){
printf("Invalid edge!\n");
count--;
}
else{
adj[origin][dest]=1;
}
}
}

void BFS(int v){
int i;
enqueue(v);
state[v]=waiting;
while(!is_empty()){
v=dequeue();
printf("%d",v);
state[v]=visited;

for (i=0;i<n;i++){
if (adj[v][i]==1 && state[i]==initial){
enqueue(i);
state[i]=waiting;
}
}
}
printf("\n");
}

void BF_Traversal()
{
int v;
	
	for(v=0; v<n; v++) 
		state[v] = initial;
	
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	BFS(v);
}

int main()
{
	create_graph();
	BF_Traversal();
	return 0;
}