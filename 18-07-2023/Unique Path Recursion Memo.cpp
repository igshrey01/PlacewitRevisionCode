class Solution {
    
    vector<vector<int>> dp;
public:
    
    int countWays(int m, int n){
        
        if(m==1 and n==1)
            return 1;
        
        if(m==0 or n==0)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int up = countWays(m-1,n);
        int left = countWays(m,n-1);
        
        return dp[m][n] = up+left;
        
    }
    int uniquePaths(int m, int n) {
        
        dp = vector<vector<int>> (m+1, vector<int> (n+1,-1));
        return countWays(m,n);
        
    }
};
