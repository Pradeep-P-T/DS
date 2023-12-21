#include<stdio.h>
void C_A();
int W();
int D();
void main(){
    int n=0;
    int bal=0;
    printf("Enter:-\n1 to Make new account\n2 to Withdraw\n3 to Deposit\n4 to Check balance\n5 to Exit\n");
    while(n!=5){
        scanf("%d",&n);
        switch(n){
            case 1: C_A();
                    break;
            case 2: bal=bal-W();
                    break;
            case 3: bal=bal+D();
                    break;
            case 4: printf("Balance is %d",bal);
                    break;
            case 5: break;
            default: printf("Invalid input");
        }
    }
}
void C_A(){
    char n[100];
    int a;
    printf("Enter account name: \n");
    scanf("%s", n);
    printf("Enter age");
    scanf("%d",&a);
}
int W(){
    int num;
    printf("Enter amount to withdraw: ");
    scanf("%d",&num);
    return num;
}
int D(){
    int num;
    printf("Enter amount to deposit: ");
    scanf("%d",&num);
    return num;
}
