//https://leetcode.com/problems/merge-k-sorted-lists/

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
    
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int k = lists.size();
        
        for(int i=0;i<k;i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        
        while(!pq.empty()){
            
            ListNode* currNode = pq.top();
            pq.pop();
            
            if(currNode->next)
                pq.push(currNode->next);
            
            tmp->next = currNode;
            tmp = currNode;
            
        }
        
        return res->next;
        
    }
};
