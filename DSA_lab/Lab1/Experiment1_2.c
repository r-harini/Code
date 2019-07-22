#include<stdio.h>

void main(){
int a[10],a1[10],a2[10];
for (int i=0;i<10;i++){
    scanf("%d",&a[i]);
}
for (int i=0;i<5;i++){
    a1[i]=a[i];
}
int j=0;
for (int i=5;i<10;i++){
    a2[j]=a[i];
    j++;
}
printf("The output is: \n");
for (int i=0;i<5;i++){
    printf("%d\t %d \n",a1[i],a2[i]);
}
}
