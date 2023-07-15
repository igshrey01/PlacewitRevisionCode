//Link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

vector<int> leftView(Node *root)
{
   vector<int> res;
    if(root == NULL)
        return res;
        
    queue<Node*> q;
    q.push(root);
        
        
    while(!q.empty()){
            
        int c = q.size();
            
        for(int i=0;i<c;i++){
            
            Node* curr = q.front();
            q.pop();
                
            if(i == 0)
                res.push_back(curr->data);
                
            if(curr->left)
                q.push(curr->left);
                
            if(curr->right)
                q.push(curr->right);
                
        }
        
            
    }
        
    return res;
}
