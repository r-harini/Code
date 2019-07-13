#include<stdio.h>

void main(){
int n,x,y;
printf("Enter n:");
scanf("%d",&n);
printf ("Enter x and y:");
scanf("%d %d",&x,&y);
int a[n];
for (int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("The output is: \n");
for (int i=x;i<y+1;i++){
    printf("%d \n",a[i-1]);
}
}
