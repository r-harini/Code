#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[100][100];
int n, state[100];
int stack[100], top=-1; 

void push(int vertex){
if (top==MAX-1){
printf("Stack is full\n");
}
else{
top++;
stack[top]=vertex;
}
}

int is_empty(){
if (top==-1)
return 1;
else
return 0;
}

int pop(){
int d;
if (top==-1){
printf("Stack is empty\n");
exit(1);
}
d=stack[top];
top--;
return d;
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

void DFS(int v){
int i;
push(v);
state[v]=waiting;
while(!is_empty()){
v=pop();
printf("%d",v);
state[v]=visited;

for (i=0;i<n;i++){
if (adj[v][i]==1 && state[i]==initial){
push(i);
state[i]=waiting;
}
}
}
printf("\n");
}

void DF_Traversal()
{
int v;
	
	for(v=0; v<n; v++) 
		state[v] = initial;
	
	printf("Enter Start Vertex for DFS: \n");
	scanf("%d", &v);
	DFS(v);
}

int main()
{
	create_graph();
	DF_Traversal();
	return 0;
}
