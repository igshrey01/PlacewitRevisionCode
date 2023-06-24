//Link - https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> suffix(n+1,0);
        vector<int> ans(n,0);
        suffix[n] = 1;
        
        for(int i=n-1;i>=0;i--)
            suffix[i] = suffix[i+1]*nums[i];    
        
        int mulLeft = 1;
        
        for(int i=0;i<n;i++){
            
            ans[i] = mulLeft*suffix[i+1];
            mulLeft *= nums[i];
            
        }
        
        return ans;
        
    }
};
