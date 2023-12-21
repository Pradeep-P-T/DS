#include<stdio.h>
void swap(int *ptr1, int *ptr2);
void main()
{
    int x,y;
    printf("Enter x and y:\n");
    scanf("%d %d",&x,&y);
    swap(&x,&y);
    printf("After swapping x=%d and y=%d",x,y);
}
void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
