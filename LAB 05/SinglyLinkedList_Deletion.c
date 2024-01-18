// Deletion in Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create();
void delete_begin();
void delete_end();
void delete_pos();
void display();
int main()
{
    int option;
    do{
        printf("\n***MAIN MENU***\n1.Create linked list\n2.Delete from beginning\n3.Delete from end\n4.Delete from any position\n5.Display linked list\n6.Exit\n");
        printf("\nEnter an option to perform the following operations: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:create();
                   printf("\nLinked list created successfully\n");
                   break;
            case 2:delete_begin();
                   printf("Element deleted successfully\n");
                   break;
            case 3:delete_end();
                   printf("Element deleted successfully\n");
                   break; 
            case 4:delete_pos();
                   printf("Element deleted successfully\n");
                   break;       
            case 5:printf("\nElements in the linked list:\n");
                   display();
                   break;
        }
    }while(option!=6);
    return 0;
}
void create()
{
    struct node *ptr,*new_node;
    int num;
    printf("Enter -1 to exit\n");
    printf("\nEnter the data\n");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL)
        {
            start=new_node;
            new_node->next=NULL;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("Enter the data\n");
        scanf("%d",&num);
    }
}
void delete_begin()
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
}
void delete_end()
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
    preptr=ptr;
    ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
}
void delete_pos()
{
    struct node *ptr,*preptr,*postptr;
    int pos,count=1;
    printf("Enter the position: ");
    scanf("%d",&pos);
    ptr=start;
    if(pos==1)
    {
        start=start->next;
        free(ptr);
    }
    else
    {
        while(count<pos&&ptr!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
            postptr=ptr->next;
            count++;
        }
        if(pos==count)
        {
            preptr->next=postptr;
            free(ptr);
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
