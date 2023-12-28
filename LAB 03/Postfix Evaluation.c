#include<stdio.h>
#include<ctype.h>
#define max 20
void push(char a);
char pop();
char stack[max],top =-1;
float compute(int a,int b,char c);

void main(){
    char postfix[max];
    char ans[max];
    int a,b;
    char c;
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    int j=0;
    for(int i=0;i<strlen(postfix);i++){
        if(isdigit(postfix[i])){
            push(postfix[i]);
        }
       else if((postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='/' || postfix[i]=='*')){
                a=pop()-'0';
                b=pop()-'0';
                c=compute(a,b,postfix[i]);
                printf("%c",c);
                push(c);
                }

            }
}
void push(char a){
    if(top>max-1){
        printf("Stack overflow");
        exit(0);
    }
    else{
        ++top;
        stack[top]=a;
    }
}

char pop(){
    if(top==-1){
        printf("Stack underflow:");
        exit(0);
    }
    else{
        return stack[top--];

    }
}

float compute(int a,int b,char c){
    if(c=='+')
        return a+b;
    else if(c=='-')
        return a-b;
    else if(c=='*')
        return a*b;
    else if(c=='/')
        return a/b;
}
