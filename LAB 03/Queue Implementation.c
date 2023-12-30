#include<stdio.h>
#include<string.h>
#define MAX 100
int rear=-1,front=-1;
int queue[MAX];
void enqueue();
int dequeue();
void display();
int main()
{
    int option,val;
    do
    {
        printf("\nEnter an option to perform following operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: enqueue();
            break;
            case 2: val=dequeue();
                   printf("Element deleted from queue is: %d",val);
            break;
            case 3: display();
            break;
        }
    }while(option!=4);
     return 0;
}
void enqueue()
{   
    int x;
    printf("Enter the number to be inserted in the queue\n");
    scanf("%d",&x);
    if(rear==MAX-1)
    printf("Overflow");
    else if(front==-1&&rear==-1)
    front=rear=0;
    else
    rear=rear+1;
    queue[rear]=x;
}
int dequeue()
{
    int y;
    if(front==-1||front>rear)
    printf("Underflow");
    else
    {
      y=queue[front];
      front=front+1;
    }
    return y;
}
void display()
{
    int i;
    printf("Elements in the queue:\n");
    if(front==-1||front>rear)
    printf("Underflow");
    for(i=front;i<=rear;i++)
    printf("\t%d",queue[i]);
}
