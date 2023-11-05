#include<stdio.h>
#define N 10
//Queue using stack
//T.C. O(n)
//S.C. O(n)
int stack[N],top= -1;

void push(int data)
{
    if(top==N-1)
    {
        return;
    }
    top++;
    stack[top]=data;
}
int pop()                 //O(1)
{
    return stack[top--];
}

void enqueue(int data)    //O(n)
{
    push(data);
}

int dequeue()             //O(1)
{
    int data,del;
    if(top== -1)
    {
        return -1;
    }
    else if(top==0)
    return pop();

    data=pop();
    del=dequeue();
    push(data);
    return del;
}

void display()                 //O(n)
{
    for(int i=0;i<=5;i++)
    {
        printf("%d ",stack[i]);
    }
}

int main()
{
    enqueue(6);
    enqueue(8);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(14);
   int d= dequeue();
    display();
}