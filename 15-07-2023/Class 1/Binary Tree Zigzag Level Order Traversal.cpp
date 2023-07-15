//Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int leftToRight = 1;
        
        while(!q.empty()){
            
            int c = q.size();
            vector<int> tmp(c,0);
            
            for(int i=0;i<c;i++){
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(leftToRight)
                    tmp[i] = curr->val;
                else
                    tmp[c-i-1] = curr->val;
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
            }
            
            leftToRight = 1-leftToRight;
            res.push_back(tmp);
            
        }
        
        return res;
        
    }
};
