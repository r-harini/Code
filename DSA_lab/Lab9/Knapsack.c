#include<stdio.h> 
  
 
int max(int a, int b) { return (a > b)? a : b; } 
  

int knapSack(int W, int wt[], int val[], int n) 
{ 
   
   if (n == 0 || W == 0) 
       return 0; 
  
   
   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
  
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
                    knapSack(W, wt, val, n-1) 
                  ); 
} 

int main() 
{ 
    int m;
    printf("Enter the no of items:");
    scanf("%d",&m);
    int val[m], wt[m];
    for (int i=0;i<m;i++){
        printf("Enter the value:");
        scanf("%d",&val[i]);
        printf("Enter the weight:");
        scanf("%d",&wt[i]);
    }
    
    int W;
    printf("Enter the max wt:");
    scanf("%d",&W);
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 