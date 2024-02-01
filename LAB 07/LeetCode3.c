/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode* ptr=head;
    *returnSize=k;
    int count=0;

    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }

    int nums=count/k,a=count%k;
    
    struct ListNode **L=(struct ListNode**)calloc(k,sizeof(struct ListNode*));
    
    ptr=head;
    for(int i=0;i<k;i++){
        L[i] = ptr;

        int segmentSize = nums + (a-- > 0 ? 1 : 0);
        for (int j = 1; j < segmentSize; j++) {
            ptr = ptr->next;
        }

        if (ptr != NULL) {
            struct ListNode* next = ptr->next;
            ptr->next = NULL;
            ptr = next; 
        } 
    }
    return L;
}
