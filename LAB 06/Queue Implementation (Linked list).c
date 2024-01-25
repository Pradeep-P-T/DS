// Queue Implementation using linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *start=NULL;
void enqueue();
void dequeue();
void display();
int main()
{
   int val,option;
    do
    {
        printf("\nEnter the number to perform following operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
        }
    }
    while(option!=4);
    return 0;
}
void enqueue()
{
    struct node *new_node;
    int num;
    printf("Enter the data\n");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
}
void dequeue()
{
  struct node *ptr,*preptr;
  ptr=start;
  if(start==NULL)
  {
  printf("Stack is empty\n");
  exit(0);
  }
  else if(start->next==NULL)
  {
    start=start->next;
    printf("\nElement popped from the stack is: %d\n",ptr->data);
    free(ptr);
  }
  else
  {
    while(ptr->next!=NULL)
    {
    preptr=ptr;
    ptr=ptr->next;
    }
    preptr->next=NULL;
    printf("\nElement popped from the stack is: %d\n",ptr->data);
    free(ptr);
  }
}
void display()
{

    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
