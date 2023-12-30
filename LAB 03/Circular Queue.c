#include<stdio.h>
#define MAX 10
int rear=-1,front=-1;
int queue[MAX];
void enqueue();
int dequeue();
void display();
int main()
{
    int option,value;
    do
    {
        printf("\nEnter an option to perform following operations:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:enqueue();
            break;
            case 2:value=dequeue();
            printf("Element deleted from queue:%d",value);
            break;
            case 3:display();
            break;            
        }
    } while (option!=4);
    return 0;
}
void enqueue()
{
    int x;
    printf("Enter the element to be inserted\n");
    scanf("%d",&x);
    if(front==0&&rear==MAX-1)
    printf("Overflow");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(front!=0&&rear==MAX-1)
    {
        rear=0;
        queue[rear]=x;
    }
    else
    {
        rear=rear+1;
        queue[rear]=x;
    }
}
int dequeue()
{
    int y;
    if(front==-1&&rear==-1)
    printf("Underflow");
    y=queue[front];
    if(front==rear)
    front=rear=-1;
    else
    {
        if(front==MAX-1)
        front=0;
        else
        front=front+1;
    }
    return y;
}
void display()
{   
    int i;
    printf("Elements in the Queue:\n");
    if(front==-1&&rear==-1)
    printf("Underflow");
    else
    {
        if(front<rear)
        {
        for(i=front;i<=rear;i++)
        printf("\t%d",queue[i]);
        }
        else
        {
            for(i=front;i<MAX;i++)
            printf("\t%d",queue[i]);
            for(i=0;i<=rear;i++)
            printf("\t%d",queue[i]);
        }
    }
}
