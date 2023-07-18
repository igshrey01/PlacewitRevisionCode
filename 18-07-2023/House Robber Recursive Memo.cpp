class Solution {
public:
    
    int maxAmount(vector<int>& nums, int n, vector<int> &dp){
        
        if(n<0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int notPick = maxAmount(nums,n-1,dp);
        int pick = nums[n]+maxAmount(nums,n-2,dp);
        
        return dp[n] = max(pick,notPick);
        
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,-1);;
        
        return maxAmount(nums,n-1,dp);
        
    }
};
