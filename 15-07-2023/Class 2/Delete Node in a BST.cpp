//Link - https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return root;
        
        if(root->val == key){
            
            //1st case
            if(root->left == NULL and root->right == NULL)
                return NULL;
            
            if(root->left == NULL)
                return root->right;
            
            if(root->right == NULL)
                return root->left;
            
            TreeNode* curr = root->right;
            
            while(curr->left!=NULL)
                curr = curr->left;
            
            root->val = curr->val;
            root->right = deleteNode(root->right,curr->val);
            
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        
        return root;
        
    }
};

