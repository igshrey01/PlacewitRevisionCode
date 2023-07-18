class Solution {
public:

    int climbStairs(int n) {
        
        if(n<=2)
            return n;
        
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3;i<=n;i++){
            
            int countOne = dp[i-1];
            int countTwo = dp[i-2];
        
            dp[i] = countOne+countTwo;
            
        }
        
        return dp[n];
        
    }
};
