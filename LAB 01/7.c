#include<string.h>
#include<stdio.h>
void sub(char a[]);
void main(){
    char a[]="My name is Prajwal P";
    sub(a);
    
}
void sub(char a[]){
    char n[100],pos;
    pos=-1;
    char b[100];
    printf("Enter substring to search: ");
    scanf("%s",n);
    for(int i=0;i<strlen(a)-strlen(n);i++){
        strncpy(b,a+i,strlen(n));
        if(strcmp(b,n)==0){
            pos=1;
            break;
        }
    }
    if (pos>0)
    printf("Substring is present");
    else
    printf("Substring is absent");
    
}
