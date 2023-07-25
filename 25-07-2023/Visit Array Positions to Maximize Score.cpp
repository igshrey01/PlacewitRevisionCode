#define ll long long
class Solution {
    
    vector<vector<ll>> dp;
public:
    
    ll maxScoree(vector<int>& nums, int x,int in, int n, int par){
        
        if(in == n)
            return 0;
        
        if(dp[in][par]!=-1)
            return dp[in][par];
        
        ll notpick = maxScoree(nums,x,in+1,n,par);
        ll pick = maxScoree(nums,x,in+1,n,nums[in]%2)+nums[in];
        
        if(nums[in]%2!=par)
            pick -=x;
        
        return dp[in][par] = max(pick,notpick);
        
    }
    long long maxScore(vector<int>& nums, int x) {
        
        int n = nums.size();
        dp = vector<vector<ll>> (n,vector<ll> (2,-1));
        return maxScoree(nums,x,1,n,nums[0]%2)+nums[0];
        
    }
};
