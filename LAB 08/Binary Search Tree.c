#include<stdio.h>
#include<stdlib.h>

struct node
{
 struct node *left;
 struct node *right;
 int data;
};
struct node *tree=NULL;

void create();
void pre(struct node *);
void post(struct node *);
void in(struct node *);

void main()
{
 int option;
 do
 {
  printf("\n\n***MAIN MENU***\n\n1.Create a binary search tree\n2.Preorder traversal\n3.Postorder traversal\n4.Inorder traversal\n5.Exit\n\nEnter an option: ");
  scanf("%d",&option);
  switch(option)
  {
   case 1: create();
           printf("Binary search tree created\n\n");
           break;
   case 2: printf("\nThe elements in the tree are\n");
           pre(tree);
           break;
   case 3: printf("\nThe elements in the tree are\n");
           post(tree);
           break;
   case 4: printf("\nThe elements in the tree are\n");
           in(tree);
           break;
  }
 }while(option!=5);
}

void create()
{
 int val;
 printf("\nEnter -1 to end");
 printf("\nEnter the element : ");
 scanf("%d",&val);
 while(val!=-1)
 {
 struct node *ptr, *nodeptr, *parentptr;
 ptr = (struct node*)malloc(sizeof(struct node));
 ptr->data = val;
 ptr->left = NULL;
 ptr->right = NULL;
 if(tree==NULL)
 {
  tree=ptr;
  tree->left=NULL;
  tree->right=NULL;
 }
 else
 {
  parentptr=NULL;
  nodeptr=tree;
  while(nodeptr!=NULL)
  {
   parentptr=nodeptr;
   if(val<nodeptr->data)
    nodeptr=nodeptr->left;
   else
    nodeptr = nodeptr->right;
  }
  if(val<parentptr->data)
   parentptr->left = ptr;
  else
   parentptr->right = ptr;
  }
  printf("\nEnter the element : ");
  scanf("%d",&val);
  }
}

void pre(struct node *tree)
{
if(tree!=NULL)
 {
 printf("%d\t", tree->data);
 pre(tree->left);
 pre(tree->right);
 }
}

void in(struct node *tree)
{
 if(tree != NULL)
 {
  in(tree->left);
  printf("%d\t", tree->data);
  in(tree->right);
 }
}

void post(struct node *tree)
{
 if(tree != NULL)
 {
  post(tree->left);
  post(tree->right);
  printf("%d\t", tree->data);
 }
}
