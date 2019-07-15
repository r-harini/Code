#include<stdio.h>

void main(){
int a[10],n,h=0,x;
printf("Enter n:");
scanf("%d",&n);
for (int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
if (n%2==0){
    x=(n/2)+1;
}
else{
    x=n/2;
}
for (int i=0;i<x;i++){
        if (a[i]!=a[n-i-1]){
            h++;
        }
    }
if (h!=0){
    printf ("Not same");
}
else{
    printf("Same");
}
}
