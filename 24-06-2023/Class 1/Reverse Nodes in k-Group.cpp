//Link - https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    
    int length(ListNode* head){
        
        ListNode* p = head;
        int len = 0;
        
        while(p!=NULL)
        {
            len++;
            p = p->next;    
        }
        
        return len;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = length(head);
        ListNode* res = NULL;
        ListNode* prev = NULL;
        ListNode* lastPrev = NULL;
        
        while(len>=k){
            
            ListNode *start = head;
            prev = NULL;
            
            for(int i=0;i<k;i++){
                
                ListNode *curr = head->next;
                head->next = prev;
                prev = head;
                head = curr;
                
            }
            
            if(!res){
                res = prev;
            }
            else{
                lastPrev->next = prev;
            }
            
            lastPrev = start;
            len-=k;
        }
        
        
        lastPrev->next = head;
        return res;
        
    }
};
