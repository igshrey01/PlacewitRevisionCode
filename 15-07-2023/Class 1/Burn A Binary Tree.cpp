//Link - https://practice.geeksforgeeks.org/problems/burning-tree/1

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    
    unordered_map<Node* , Node*> mapNodeToParent; 
    Node* targetNode;
  public:
  
    void mappingNodeToParent(Node* root){
        
        if(root == NULL)
            return;
        
        if(root->left){
            mapNodeToParent[root->left] = root;
            mappingNodeToParent(root->left);
        }
        
        if(root->right){
            mapNodeToParent[root->right] = root;
            mappingNodeToParent(root->right);
        }
        
    }
    
    void findTargetReference(Node* root, int target){
        
        if(root == NULL)
            return;
        
        if(root->data == target){
            targetNode = root;
            return;
        }
        
        findTargetReference(root->left,target);
        findTargetReference(root->right,target);
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        mappingNodeToParent(root);
        findTargetReference(root,target);
        
        unordered_map<Node*,int> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = 1;
        
        int res = -1;
        
        while(!q.empty()){
            
            res++;
            int c = q.size();
            
            for(int i=0;i<c;i++){
                
                Node* curr = q.front();
                q.pop();
                
                
                if(curr->left and !visited[curr->left]){
                    
                    visited[curr->left] =  1;
                    q.push(curr->left);
                }
                
                if(curr->right and !visited[curr->right]){
                    
                    visited[curr->right] = 1;
                    q.push(curr->right);
                    
                }
                    
                
                if(mapNodeToParent[curr] and !visited[mapNodeToParent[curr]]){
                    
                    visited[mapNodeToParent[curr]] = 1;
                    q.push(mapNodeToParent[curr]);
                    
                }
                
            }
            
        }
        
        return res;
    }
    
    
};
