#include<stdio.h>

struct Sales{
int p_code;
char p_name[50];
int amt;
};

void main(){
struct Sales s[10];
for (int i=0;i<3;i++){
    scanf("%d",&s[i].p_code);
    scanf("%s",s[i].p_name);
    scanf("%d",&s[i].amt);
}
struct Sales temp;
for (int i=0;i<3;i++){
    for (int j=i;j<3;j++){
        if (s[i].amt>s[j].amt){
            temp=s[j];
            s[j]=s[i];
            s[i]=temp;
        }
    }
}
for (int i=0;i<3;i++){
    printf("%d\t%s\t%d\n",s[i].p_code,s[i].p_name,s[i].amt);
}
}
