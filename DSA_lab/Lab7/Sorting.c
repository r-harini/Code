#include<stdio.h>
#include<stdlib.h>

int* bubblesort(int* a, int n){
    for (int i=0; i<n;i++){
        for (int j=i+1;j<n;j++){
            if (a[i]>a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    return a;
}

int* insertionsort(int* a, int n){
    for (int j=1;j<n;j++){
        int key=a[j];
        int i=j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    return a;
}

int partition(int* A, int p, int r){
    int x=A[r];
    int i=p-1;
    for (int j=p;j<=r-1;j++){
        if (A[j]<x){
            i++;
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
    int t=A[i+1];
    A[i+1]=A[r];
    A[r]=t;
    return i+1;
}

int* quicksort(int* A, int p, int r){
    if (p<r){
        int q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
    return A;
}

void merge(int a[], int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for (j=0;j<n2;j++){
        R[j]=a[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2){
        if (L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        a[k]=L[i];
        i++;
        k++;
    }
    while (j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r){
    if (l<r){
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a, m+1,r);
        merge(a,l,m,r);
    }
}

void print(int* a, int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int a[9]={5,2,9,7,3,8,6,1,4};
    int c=1;
    while (c>0){
        printf("******MENU*******\n");
        printf("1->Bubble sort\n2->Insertion Sort\n3->Quick sort\n4->Merge sort\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                bubblesort(a,9);
                print(a,9);
                break;
            case 2:
                insertionsort(a,9);
                print(a,9);
                break;
            case 3:
                quicksort(a,0,8);
                print(a,9);
                break;
            case 4:
                mergesort(a,0,8);
                print(a,9);
                break;
        }
    }
    return 0;
}