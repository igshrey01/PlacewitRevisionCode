class Solution {
public:
    int countWays(int n, vector<int> &dp){
        
        if(n<=2)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int countOne = countWays(n-1,dp);
        int countTwo = countWays(n-2,dp);
        
        return dp[n] = countOne+countTwo;
        
    }
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        return countWays(n,dp);
        
    }
};
