#include<string.h>
#include<stdio.h>
void sear(int a[][3]);
void main(){
    int a[][3]={{1,2,3},{4,5,6},{7,8,9}};
    sear(a);
    
}
void sear(int a[][3]){
    int n,pos;
    pos=-1;
    printf("Enter element to search: ");
    scanf("%d",&n);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]==n){
            pos=2;
            break;
            }
        }
    }
    if (pos>0)
    printf("%d is present",n);
    else
    printf("%d is absent",n);
    
}
