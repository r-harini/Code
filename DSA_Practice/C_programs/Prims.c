#include<stdio.h>

int main(){
    int min, mincost=0, visited[20]={0},cost[20][20],ne=1;
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the adjaceny matrix:\n");
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            scanf("%d", &cost[i][j]);
            if (cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    visited[1]=1;
    int a,b;
    while (ne<n){
        int min=999;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (cost[i[j]<min && visited!=0]){
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        if (visited[a]==0|| visited[b]==0){
            printf("Edge %d(%d %d): %d",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost=%d", mincost);

}