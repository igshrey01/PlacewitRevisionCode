class Solution {
public:
    int mod = 1e9+7;
    int solve(int num , int n , int x,vector<vector<int>>& dp){
        if(pow(num,x) == n) return 1;
        if(pow(num,x) > n) return 0;

        if(dp[num][n] != -1) return dp[num][n];
        int nottake = solve(num+1,n,x,dp);
        int take = solve(num+1,n - pow(num,x),x,dp);
        return dp[num][n] = (take + nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,x,dp);
    }
};
