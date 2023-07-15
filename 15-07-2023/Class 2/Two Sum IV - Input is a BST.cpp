//Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    
    bool search(TreeNode* root, int val, TreeNode* pp){
        
        if(root == NULL)
            return false;
        if(root->val == val and root!=pp)
            return true;
        else if(root->val>val)
            return search(root->left,val,pp);
        else
            return search(root->right,val,pp);
        
        return false;
    }
    
    bool ifExist(TreeNode* root, int k, TreeNode* rootMain){
        
        if(root == NULL)
            return false;
        
        if(search(rootMain,k-root->val,root))
            return true;
        
        return ifExist(root->left,k,rootMain) or ifExist(root->right,k,rootMain);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        return ifExist(root,k,root);
        
    }
};
