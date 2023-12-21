#include<stdio.h>
void last(int a[]);
void main(){
    int a[10]={12,22,33,44,58,69,77,84,91,22};
    last(a);
    
}
void last(int a[]){
    int n,pos;
    pos=-1;
    printf("Enter element to search: ");
    scanf("%d",&n);
    for(int i=9;i>=0;i--){
        if(a[i]==n){
            pos=i;
            break;
        }
    }
    if(pos>0)
    printf("Last occurance of Element %d is at %d",n,pos);
    else
    printf("Element not present");
    
}
