#include<stdio.h>

void main(){
int n,sum;
printf("Enter n:");
scanf("%d",&n);
int a[n],b[n];
printf("Enter the elements of the array:");
for (int i=0;i<n;i++){
scanf("%d",&a[i]);
}
for (int i=0;i<n;i++){
        sum=0;
    for (int j=0;j<n;j++){
        if(j==i){
            continue;
        }
        else{
            sum+=a[j];
        }
    }
    printf("%d \t", sum);
}
}
