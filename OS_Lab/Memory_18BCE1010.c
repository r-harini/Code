#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int firstFit(int blocksize[], int m, int processsize[], int n){
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    int ext=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (blocksize[j]>=processsize[i]){
                allocation[i]=j;
                blocksize[j]-=processsize[i];
                ext+=blocksize[j];
                break;
            }
        }
    }

    printf("\nProc No. \t Proc Size\tBlock no.\n");
    for (int i=0; i<n; i++){
        printf(" %d\t\t%d\t\t",i+1,processsize[i]);
        if (allocation[i]!=-1){
            printf("%d", allocation[i]+1);}
        else{
            printf("Not allocated");
        }    
        printf("\n");
    }
    printf("Total external frag: %d\n",ext);
    return ext;
}

int bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
    int allocation[n]; 
    int ext=0;
    memset(allocation, -1, sizeof(allocation)); 
  
    for (int i=0; i<n; i++) 
    { 
        
        int best = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
                if (best == -1) 
                    best = j; 
                else if (blockSize[best] > blockSize[j]) 
                    best = j; 
            } 
        } 
  
        if (best != -1) 
        { 
            allocation[i] = best; 
            blockSize[best] -= processSize[i]; 
            ext+=blockSize[best];
        } 
    } 
  
    printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("  %d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1) 
            printf("%d", allocation[i]+1);
        else
            printf("Not Allocated");
        printf("\n");
    } 
    printf("Total external frag: %d\n",ext);
    return ext;
} 

int worstFit(int blockSize[], int m, int processSize[],  int n) 
{ 
    int allocation[n]; 
    int ext=0;
    
    memset(allocation, -1, sizeof(allocation)); 
  
    for (int i=0; i<n; i++) 
    { 
        int worst = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
                if (worst == -1) 
                    worst = j; 
                else if (blockSize[worst] < blockSize[j]) 
                    worst = j; 
            } 
        }         
        if (worst != -1) 
        {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i]; 
            ext+=blockSize[worst];
        } 
    } 
  
   printf("\nProcess No.\t Process Size\tBlock no.\n");
    for (int i = 0; i < n; i++) 
    { 
        printf("  %d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1) 
            printf("%d", allocation[i]+1);
        else
            printf("Not Allocated");
        printf("\n");
    } 
    printf("Total external frag: %d\n",ext);
    return ext;
} 

void partitioning(int blockSize[], int m, int processSize[],  int n){
    int totext[3];
    char algos[3][20]={"First Fit", "Best Fit", "Worst Fit"};
    char algo[3]={1,2,3};

    int b1[m], p1[n];
    for (int i=0;i<m; i++){
        b1[i]=blockSize[i];
    }
    for (int i=0;i<n;i++){
        p1[i]=processSize[i];
    }
    printf("\t\tFirst Fit\t\t");
    totext[0]=firstFit(b1, m, p1, n); 


    for (int i=0;i<m; i++){
        b1[i]=blockSize[i];
    }
    for (int i=0;i<n;i++){
        p1[i]=processSize[i];
    }
    printf("\n\t\tBest Fit\t\t");
    totext[1]=bestFit(b1, m, p1, n);


    for (int i=0;i<m; i++){
        b1[i]=blockSize[i];
    }
    for (int i=0;i<n;i++){
        p1[i]=processSize[i];
    }
    printf("\n\t\tWorst Fit\t\t");
    totext[2]=worstFit(b1, m, p1, n);

    int index, min=1000;
    for (int i=0; i<3; i++){
        if (totext[i]<min){
            index=i;
            min=totext[i];
        }
    }
    printf("\n%s is the best algorithm\n", algos[index]);
}



int main() 
{ 
    int blockSize[] = {300, 600, 350, 200, 750, 125}; 
    int processSize[] = {115,500,358,200,375}; 
    int m = sizeof(blockSize) / sizeof(blockSize[0]); 
    int n = sizeof(processSize) / sizeof(processSize[0]); 
    
    partitioning(blockSize, m, processSize, n);
    
    return 0 ; 
} 