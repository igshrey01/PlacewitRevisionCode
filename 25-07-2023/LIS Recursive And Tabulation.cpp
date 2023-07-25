class Solution {
public:
    
    int maxLength(vector<int> &nums , int in, int prevIn,int n, vector<vector<int>> &dp){
        
        if(in > n)
            return 0;
        
        if(dp[in][prevIn]!=-1)
            return dp[in][prevIn];
        //notPick
        int notPick = maxLength(nums,in+1,prevIn,n,dp);
        
        //pick
        int pick = 0;
        if(prevIn == 0 or nums[prevIn-1]<nums[in-1])
            pick = 1+maxLength(nums,in+1,in,n,dp);
        
        return dp[in][prevIn] = max(pick,notPick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int> (n+1,0));
        // return maxLength(nums,1,0,n,dp);
        
        for(int in=n;in>=1;in--){
            
            for(int prevInd = n;prevInd>=0;prevInd--){
                
                int notPick = dp[in+1][prevInd];
        
                //pick
                int pick = 0;
                if(prevInd == 0 or nums[prevInd-1]<nums[in-1])
                    pick = 1+dp[in+1][in];
        
                dp[in][prevInd] = max(pick,notPick);
                
                
            }
            
        }
        
        return dp[1][0];
        
    }
};
