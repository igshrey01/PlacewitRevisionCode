/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int findSize(ListNode* head){
        
        ListNode* p = head;
        int len = 0;
        
        while(p!=NULL){
            len++;
            p=p->next;
        }
        
        return len;
        
    }
    ListNode* middleNode(ListNode* head) {
        
//         int len = findSize(head);
        
//         for(int i=0;i<len/2;i++){
//             head = head->next;
//         }
        
//         return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        return slow;
        
    }
};
