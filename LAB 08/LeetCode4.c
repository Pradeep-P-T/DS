/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *ptr,*ptr1;
    int count=0,num;
    if(head==NULL || head->next==NULL){
        return head;
    }
    ptr=head;
    while(ptr->next!=NULL){
        count++;
        ptr=ptr->next;
    }
    num=k%(count+1);
    while(num--){
        ptr=head;
        while(ptr->next!=NULL){
        ptr1=ptr;
        ptr=ptr->next;
        }
        ptr->next=head;
        ptr1->next=NULL;
        head=ptr;
    }
    return head;
}
