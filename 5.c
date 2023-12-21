#include<stdio.h>
void lsear(int a[]);
void main(){
    int a[]={12,22,33,44,58,69,77,84,91,103};
    lsear(a);
    
}
void lsear(int a[]){
    int n,pos;
    pos=-1;
    printf("Enter element to search: ");
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        if(a[i]==n){
            pos=i;
        }
    }
    if(pos>0)
    printf("Element %d is at %d",n,pos);
    else
    printf("Element not present");
    
}
