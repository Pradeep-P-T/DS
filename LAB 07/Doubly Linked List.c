//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
struct node *prev;
};

struct node *start=NULL;
void create();
void insert();
void delete();
void display();

void main()
{
int option;
do
{
printf("\n***MAIN MENU***\n\n1.Create a doubly linked list.\n2.Insert at left\n3.Delete (specific value)\n4.Display\n5.Exit\n\nEnter an option: ");
scanf("%d",&option);
switch(option)
{
case 1: create();
        printf("\nDoubly linked list created\n");
        break;
case 2: insert();
        printf("\nNode inserted\n");
        break;
case 3: delete();
        printf("\nNode deleted\n");
        break;
case 4: printf("\nElements in the doubly linked list\n");
        display();
        break;
}
}while(option!=5);
}

void create()
{
struct node *new_node, *ptr;
int num;
printf("\nEnter -1 to end");
printf("\nEnter the data : ");
scanf("%d",&num);
while(num!=-1)
{
if(start==NULL)
{
new_node=(struct node*)malloc(sizeof(struct node));
new_node->prev = NULL;
new_node->data = num;
new_node->next = NULL;
start=new_node;
}
else
{
ptr=start;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=num;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
new_node->prev=ptr;
new_node->next=NULL;
}
printf("\nEnter the data : ");
scanf("%d", &num);
}
}

void insert()
{
    struct node *new_node, *ptr;
    int pos, val, count = 0;

    printf("\nEnter the data : ");
    scanf("%d", &val);
    printf("\nEnter the position before which the data has to be inserted:");
    scanf("%d", &pos);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    ptr = start;
    while (count < pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    if (count == pos - 1 && ptr != NULL)
    {
        new_node->next = ptr;  

        if (ptr->prev != NULL)
        {
            new_node->prev = ptr->prev;
            ptr->prev->next = new_node; 
        }
        else
        {
            start = new_node;
            new_node->prev = NULL;
        }

        ptr->prev = new_node; 
    }
    else
    {
        printf("Invalid position. Insertion failed.\n");
        free(new_node); 
    }
}

void delete()
{
struct node *ptr;
int num;
printf("Enter the data to be deleted\n");
scanf("%d", &num);
ptr = start;
while (ptr != NULL && ptr->data == num)
{
start = ptr->next;
if (start != NULL)
start->prev = NULL;
free(ptr);
ptr = start;
}
while (ptr != NULL && ptr->data != num)
ptr = ptr->next;
if (ptr == NULL)
{
printf("Data not found. Deletion failed.\n");
}
else
{
if (ptr->prev != NULL)
ptr->prev->next = ptr->next;
if (ptr->next != NULL)
ptr->next->prev = ptr->prev;
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
}
