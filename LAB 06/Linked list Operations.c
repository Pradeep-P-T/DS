// Sort, Reverse & Concatenate

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *s1=NULL;
struct node *s2=NULL;
struct node *start=NULL;
struct node *create(struct node*);
void sort();
struct node *concatenate(struct node*,struct node*);
void reverse();
void display(struct node*);

int main()
{
    int option;
    struct node *a=NULL;
    do{
        printf("\n*****MAIN MENU*****\n\n1.Create a linked list\n2.Create two linked lists for concatenation\n3.Sort\n4.Concatenate\n5.Reverse\n6.Display linked list\n7.Display Concatenated linked list\n8.Exit\n");
        printf("\nEnter an option to perform the following operations: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:start=create(start);
                   printf("\nLinked list created successfully\n");
                   break;                 
            case 2:printf("\nLinked list 1:\n");
                   s1=create(s1);
                   printf("\nLinked list 2:\n");
                   s2=create(s2);
                   printf("\nLinked lists created successfully\n");
                   break;
            case 3:sort();
                   printf("\nLinked list sorted\n");
                   break;
            case 4:a=concatenate(s1,s2);
                   printf("\nLinked lists concatenated successfully\n");
                   break;
            case 5:reverse();
                   printf("\nLinked list reversed\n");
                   break;
            case 6:printf("\nElements in the linked list\n");
                   display(start);
                   break;
            case 7:printf("\nElements in the linked list after concatenation:\n");
                   display(a);
                   break;    
                     
        }
    }while(option!=8);
    return 0;
}

struct node * create(struct node *start)
{
    struct node *ptr,*new_node;
    int num;
    printf("Enter -1 to exit\n");
    printf("\nEnter the data: ");
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
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
}

void sort()
{
    struct node *i,*j;
    int temp;
    for(i=start;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
          if(i->data>j->data)
          {
            temp=i->data;
            i->data=j->data;
            j->data=temp;
          }
        }
    }
}

struct node *concatenate(struct node *t1,struct node *t2)
{
    struct node *ptr;
    ptr=t1;
    while(ptr->next!=NULL)
    {
     ptr=ptr->next;
    }
ptr->next=t2;
return t1;
}

void reverse()
{
  struct node *prev=NULL;
  struct node *next=NULL;
  struct node *cur=start;
  while(cur!=NULL)
  {
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }
  start=prev;    
}

void display(struct node *p)
{
    struct node *ptr;
    ptr=p;
    while(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
