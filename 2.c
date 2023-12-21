#include<stdio.h>
#include<string.h>
void sort(char arr[][100]);
void main(){
    char arr[][100]={"Hello","my","Name","is","Prajwal"};
    sort(arr);
}
void sort(char arr[][100]){
    //Sorted based on ASCII values of first letter
    int j=0;
    char a[][100]={};
    int min,b;
    char c,temp[100];
    while(j<5){
        min=123;
        for(int i=0;i<5;i++){
            b=arr[i][0];
            if(b<min){
                min=b;
            }
        }
        for(int i=0;i<5;i++){
            b=arr[i][0];
            if(b==min){
                strcpy(a[j],arr[i]);
                arr[i][0]='}';
            }
        }
        j++;
    }
    for(int i=0;i<5;i++){
        printf("%s\n",a[i]);
    }
}
