#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int top=-1;
int a[SIZE];
void push();
void pop();
void display();
void main()
{
int option;
while(1)
{
printf("Enter the option for the following operations:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
scanf("%d",&option);
switch(option)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("Invalid input\n");
break;
}
}
}
void push()
{
int x;
if(top==SIZE-1)
{
printf("Overflow\n");
}
else
{
printf("Enter the element to be added\n");
scanf("%d",&x);
top=top+1;
a[top]=x;
}
}
void pop()
{
if(top==-1)
{
printf("Underflow\n");
}
else
{
printf("Popped element is %d\n",a[top]);
top=top-1;
}
}
void display()
{
int i;
if(top==-1)
{
printf("Stack is empty\n");
}
else
{
for(i=top;i>=0;--i)
printf("%d ",a[i]);
}
}
