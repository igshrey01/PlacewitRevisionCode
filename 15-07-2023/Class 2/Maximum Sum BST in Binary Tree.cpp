//Link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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

struct nodeTree{
    
    public:
    int maxValue;
    int minValue;
    int sumBST;
    
    nodeTree(int maxValue, int minValue, int sumBST){
        
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->sumBST = sumBST;
        
    }
    
};


class Solution {
    
    int ans = 0;
public:
    
    nodeTree dfs(TreeNode* root){
        
        if(root == NULL)
            return nodeTree(INT_MIN, INT_MAX, 0);
        
        nodeTree left = dfs(root->left);
        nodeTree right = dfs(root->right);
        
        if(root->val>left.maxValue and root->val<right.minValue){
            
            int tmp = root->val+left.sumBST+right.sumBST;
            ans = max(ans,tmp);
            
            return nodeTree(max(root->val,right.maxValue), min(root->val,left.minValue), tmp);
            
        }
        else{
            return nodeTree(INT_MAX,INT_MIN,0);
        }
        
    }
    int maxSumBST(TreeNode* root) {
        
        dfs(root);
        return ans;
        
    }
};

