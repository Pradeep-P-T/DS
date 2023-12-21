#include<stdio.h>
void bsear(int a[]);
void main(){
    int a[]={12,22,33,44,58,69,77,84,91,103};
    bsear(a);
    
}
void bsear(int a[]){
    int len=10;
    int mid=len/2;
    int beg=0;
    int end=len-1;
    int n,pos;
    pos=-1;
    printf("Enter element to search: ");
    scanf("%d",&n);
    while(a[beg]<=a[end]){
        mid=(beg+end)/2;
        if(a[mid]<n){
            beg=mid+1;
        }
        if(a[mid]>n){
            end=mid-1;
        }
        if(a[mid]==n){
            pos=mid;
            break;
        }
        
    }
    if(pos>0)
    printf("Element %d is at %d",n,(pos));
    else
    printf("Element not present");
    
}
