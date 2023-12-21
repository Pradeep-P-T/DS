#include<stdio.h>
void check(int a[], int n);
void main(){
    printf("Enter number of elements: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0;i < n ; i++) {
        scanf("%d",&a[i]);
    }
    check(a,n);
}
void check(int a[],int n){
    int g=a[0];
    int s=a[0];
    for (int i = 0;i < n ; i++){
        if(a[i]>g){
            g=a[i];
        }
        if(a[i]<s){
            s=a[i];
        }
    }
    printf("Biggest is %d\n",g);
    printf("Smallest is %d",s);
}
