#include<stdio.h>
#include<stdlib.h>



struct stack
{
    int cap,top;
    int *a;
};

struct stack * creates(int cap)
{
    struct stack *s;
    s = malloc(sizeof(struct stack));
    s->cap=cap;
    s->top=-1;
    s->a=malloc(sizeof(int)*cap);
    return s; 
}

int isfull(struct stack *s)
{
    if(s->top==(s->cap-1))
        return 1;
    else
        return 0;
}

int isemp(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, int n)
{
    if(!isfull(s))
    {
        s->top++;
        s->a[s->top]=n;
    }
    else
        printf("its full");
}

int pop(struct stack *s)
{
    if(!isemp(s))
    {
        int n;
        n=s->a[s->top];
        s->top--; 
        return (n);
    }
    else
        return -1; 
}

void disp(struct stack *s)
{
    for(int i=(s->top);i>=0;i--)
        printf("%d\t",s->a[i]);
}



struct queue
{
    int cap;
    int front,rear;
    int *a;
};

struct queue * create(int c)
{
    struct queue * s;
    s=malloc(sizeof(struct queue));
    s->front=-1;
    s->rear=-1;
    s->cap=c;
    s->a=malloc(sizeof(int)*c);
    return s;
}

int isfullq(struct queue *s)
{
    if(s->rear==(s->cap-1))
        return 1;
    else
        return 0;
}

int isempq(struct queue *s)
{
    if(s->front==-1 || s->front>s->rear)
        return 1;
    else
     return 0;
}

void enqueue(struct queue *s, int n)
{
    if(s->rear==-1)
    {
        s->rear++;
        s->front++;
        s->a[s->rear]=n;
    }
    else if(!isfullq(s))
    {
        s->rear++;
        s->a[s->rear]=n;
    }
    else
        printf("its full");
}

void dequeue(struct queue *s)
{
    if(!isempq(s))
    {
        int x;
        x=s->a[s->front];
        s->front++;
        printf("%d is deleted \n",x);
    }
    else
        printf("its empty\n");
}

void dispq(struct queue *s)
{
  for(int i=s->front;i<=s->rear;i++)
     printf("%d\t",a[i]);
}


struct books{
int accessno;
char title[20];
char auth[30];
};


int main()
{
  struct books b1[10],b2[10];
  struct stack *s1,*s2;
  s1=creates(10);
  s2=creates(10);
  struct queue *q1,*q2;
  q1=create(10);
  q2=create(10);
  int c1,c2;
  scanf("%d%d",&c1,&c2);
  for(int i=0;i<c1;i++)
  {
    scanf("%d%s%s",&b1[i].accessno,b1[i].title,b1[i].auth);
    push(s1,b1[i].accessno);
  }
  for(int i=0;i<c2;i++)
  {
    scanf("%d%s%s",&b2[i].accessno,b2[i].title,b2[i].auth);
    push(s2,b2[i].accessno);
  }
  for(int i=0;i<c1;i++)
  {
    int c;
    c=pop(s1);
    printf("the status of counter 1 is : ")
    disp(s1);
    if(c&1!=0)
    {  enqueue(q1,c); disp(q1); }
    else
    {  enqueue(q2,c); disp(q2); }
   }
   for(int i=0;i<c2;i++)
   {
     int c;
     c=pop(s2);
     printf("the status of counter 2 is : ")
     disp(s2);
     if(c&1!=0)
     {  enqueue(q1,c); disp(q1); }
     else
     {  enqueue(q2,c); disp(q2); }     
   }
  
}
