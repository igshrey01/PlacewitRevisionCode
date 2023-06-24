//Link - https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        
        unordered_map<Node*, Node*> oldMapNew;
        Node* newNode = new Node(head->val);
        oldMapNew[head] = newNode;
        
        Node* tmp = head;
        
        while(tmp->next!=NULL){
            
            newNode->next = new Node(tmp->next->val);
            newNode = newNode->next;
            tmp = tmp->next;
            
            oldMapNew[tmp] = newNode;
        }
        
        tmp = head;
        
        while(tmp!=NULL){
            
            oldMapNew[tmp]->random = oldMapNew[tmp->random];
            tmp = tmp->next;
            
        }
        
        return oldMapNew[head];
    }
};
