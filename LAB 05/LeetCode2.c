struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* ptrl= head;
    int temp=left-1;
    while(temp--){
        ptrl=ptrl->next;
    }
    int count=right-left+1;
    int* a = (int*)malloc(count * sizeof(int));
    for(int i=0;i<count;i++){
        a[i]=ptrl->val;
        ptrl=ptrl->next;
    }
    struct ListNode* ptr= head;  
    left--;
    while(left--){
        printf("%d",ptr->val);
        ptr=ptr->next;
    }
    
    for(int i=count-1;i>-1;i--){
        
        ptr->val=a[i];
        ptr=ptr->next;
    }
    return head;
}
