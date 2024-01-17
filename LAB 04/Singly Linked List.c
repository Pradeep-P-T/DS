// Insertion in Singly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert_begin();
void insert_end();
void insert_pos();
void display();
int main()
{
    int option;
    do{
        printf("\n***MAIN MENU***\n1.Insert at beginning\n2.Insert at end\n3.Insert at any position\n4.Display\n5.Exit\n");
        printf("\nEnter an option to perform the following operations: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:insert_begin();
                   printf("\nElement inserted successfully\n");
                   break;
            case 2:insert_end();
                   printf("\nElement inserted successfully\n");
                   break;
            case 3:insert_pos();
                   printf("\nElement inserted successfully\n");
                   break;                   
            case 4:printf("\nElements in the linked list:\n");
                   display();
                   break;
        }
    }while(option!=5);
    return 0;
}
void insert_begin()
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
void insert_end()
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter the data\n");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=new_node;
}
void insert_pos()
{
    struct node *new_node,*ptr,*prev;
    int num,pos,count=1;
    printf("Enter the data\n");
    scanf("%d",&num);
    printf("Enter the position to be inserted\n");
    scanf("%d",&pos);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    if(pos==1)
    {
    new_node->next=start;
    start=new_node;
    }
    else
    {
        ptr=start;
        while(count<pos&&ptr!=NULL)
        {
         prev=ptr;
         ptr=ptr->next;
         count++;
        }
        if(count==pos)
        {
         prev->next=new_node;
         new_node->next=ptr;
        }
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
