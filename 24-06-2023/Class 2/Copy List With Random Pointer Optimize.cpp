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
        
        Node* tmp = head;
        
        //1st step - Duplicating Nodes
        while(tmp!=NULL){
            
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = newNode->next;
            
        }
        
        tmp = head;
        
        //2nd step - Assigning random nodes for new duplicate nodes
        while(tmp!=NULL){
            
            if(tmp->random)
                tmp->next->random = tmp->random->next;
            
            tmp = tmp->next->next;
            
        }
        
        tmp = head;
        Node* newHead = tmp->next;
        Node* tmpN = newHead;
        
        while(tmpN->next!=NULL){
            
            tmp->next = tmp->next->next;
            tmpN->next = tmpN->next->next;
            tmp = tmp->next;
            tmpN = tmpN->next;
            
        }
        
        tmp->next = NULL;
        tmpN->next = NULL;
        
        return newHead;
    }
};
