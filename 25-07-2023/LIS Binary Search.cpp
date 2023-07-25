class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> tmp(n,INT_MAX);
        
        for(int i=0;i<n;i++){
            
            int in = lower_bound(begin(tmp),end(tmp),nums[i])-begin(tmp);
            tmp[in] = nums[i];
            
        }
        
        return lower_bound(begin(tmp),end(tmp),INT_MAX)-begin(tmp);
        
    }
};
