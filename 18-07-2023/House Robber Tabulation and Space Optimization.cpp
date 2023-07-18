class Solution {
public:
    int tabulation(vector<int> &nums,int n){
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        int notPick=INT_MAX,pick=INT_MAX;
        for(int i=1;i<n;i++){
            notPick = dp[i-1];
            pick = nums[i];
            if(i>1){
                pick+=dp[i-2];
            }
            dp[i] = max(pick,notPick);
        }
        return dp[n-1];
    }
    int tabulationSpaceOptimized(vector<int> &nums,int n){
        int prev = nums[0];
        int prev2 = -1;
        for(int i=1;i<n;i++){
            int notPick = prev;
            int pick = nums[i];
            if(i>1){
                pick+=prev2;
            }
            prev2=prev;
            prev = max(pick,notPick);
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return tabulationSpaceOptimized(nums,n);
    }
};
