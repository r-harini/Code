#include<stdio.h>

void insertionsort(int a, int n){
    for (int j=1; j<n;j++){
        int k=a[j];
        int i=j-1;
        while (i>=0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=k;
    }
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for (int i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for (int j=0;j<n2;j++){
        R[j]=a[m+j+1];
    }
    int i=0, j=0, k=l;
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
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}



int main(){
    int a[9]={1,6,9,2,4,5,8,7,3};
    mergesort(a,0,8);
    for (int i=0;i<9;i++){
        printf("%d ",a[i]);
    }
    return 0;

}