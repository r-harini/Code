#include <stdio.h>

int i,top=-1;




struct Stack
{

struct Books
{
char an[5],title[50],author[50];
}b[9];

}s;





void display()
{
printf("The status of the stack is:");
for(i=top;i>-1;i--)
{
printf("%s\n%s\n%s\n",s.b[i].an,s.b[i].title,s.b[i].author);
}
}

void pop(){
if (top==-1){
printf("Stack is empty\n");
}
else{
printf("%s\n%s\n%s\n",s.b[top].an,s.b[top].title,s.b[top].author);
top--;
}
}

int push(int i)
{
if(top == 8)
printf("Stack is full");
else
{
scanf("%s",s.b[i].an);
scanf("%s",s.b[i].title);
scanf("%s",s.b[i].author);

top+=1;

}
}

void no_of_books(){
printf("There are %d number of books in the dropbox",top);
}


int main()
{
int n;
scanf("%d",&n);

for(i=0;i<n;i++)
{
push(i);
display();
}


}

