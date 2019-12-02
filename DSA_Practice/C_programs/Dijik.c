#include<stdio.h>
#include<limits.h>

int V=0;
int MinDistance(int dist[], int sptSet){
    int min=INT_MAX, minindex=0;
    for (int i=0;i<V;i++){
        if (dist[i]<=min && sptSet[i]==0){
            min=dist[i];
            minindex=i;
        }
    }
    return minindex;
}

void dijik(int graph[V][V], int src){
    int dist[V], sp[V];
    for (int i=0;i<V;i++){
        dist[i]=INT_MAX, sp[i]=0;
    }
    dist[src]=0;
    for (int i=0;i<V-1;i++){
        int u=MinDistance(dist, sp);
        sp[u]=1;
        for (int v=0;v<V;v++){
            if (!sp[i] && graph[u][v] && dist[v]!=INT_MAX && graph[u][v]+dist[u]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    for (int i=0;i<V;i++){
        printf("Edge %d:  Cost: %d\n", i, dist[i]);
    }
}

int main(){
    printf("Enter the numder of vertices:");
    scanf("%d",&V);
    int graph[V][V];
    for (int i=0;i<V;i++){
        for (int j=0; j<V; j++){
            scanf("%d",&graph[i][j]);
        }
    }

    dijik(graph, 0);
    return 0;
}