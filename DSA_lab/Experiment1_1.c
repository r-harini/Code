#include<stdio.h>

void main(){
int a[10],n,h=0;
printf("Enter n:");
scanf("%d",&n);
for (int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
if (n%2==0){
    for (int i=0;i<(n/2)+1;i++){
        if (a[i]!=a[n-i-1]){
            h++;
        }
    }
}
else{
    for (int i=0;i<(n/2);i++){
        if (a[i]!=a[n-i-1]){
            h++;
        }
    }
}
if (h!=0){
    printf ("Not same");
}
else{
    printf("Same");
}
}
