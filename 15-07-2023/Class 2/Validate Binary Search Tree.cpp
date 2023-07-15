//Link - https://leetcode.com/problems/validate-binary-search-tree/

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
    
    bool validBST(TreeNode* root, long long maxValue, long long minValue){
        
        if(root == NULL)
            return true;
        
        if(root->val>maxValue or root->val<minValue)
            return false;
        
        return validBST(root->left,(long long)root->val-1,minValue) and validBST(root->right,maxValue,(long long)root->val+1);
        
    }
    bool isValidBST(TreeNode* root) {
        
        return validBST(root,LLONG_MAX,LLONG_MIN);
        
    }
};
