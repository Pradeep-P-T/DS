#include<stdio.h>
#include<ctype.h>
#define max 20
void push(char a);
char pop();
char stack[max],top =-1;
int pre(char a);

void main(){
    char infix[max],a;
    char post[max];
    printf("Enter infix expression: ");
    scanf("%s",infix);
    int j=0;
    push('(');
    for(int i=0;i<strlen(infix);i++){
        if(isalnum(infix[i])){
            post[j]=infix[i];
            j+=1;
        }
       else if((infix[i]=='+' || infix[i]=='-' || infix[i]=='/' || infix[i]=='*')){
                if(pre(infix[i])>pre(stack[top])){
                    push(infix[i]);
                }
                else if(pre(infix[i])<=pre(stack[top])){

                    while(1){
                    a=pop();
                    if(a=='('){
                        push(a);
                        break;
                    }
                    post[j]=a;
                    j+=1;
                }
                push(infix[i]);
            }


    }
}
while(top!=-1){
    char y=pop();
    if(y=='('){
        break;
       }
    post[j]=y;
    j+=1;


}
post[j]='\0';
printf("%s",post);

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

int pre(char a){
        if(a=='^'){
            return 3;
        }
        else if( a=='*' || a=='/'){
            return 2;
        }
        else if(a=='+' || a=='-'){
            return 1;
        }
        else{
            return 0;
        }
}
