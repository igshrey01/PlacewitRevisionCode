class Solution {
    
    vector<vector<int>> dp;
public:
    
    int uniquePaths(int m, int n) {
        
        dp = vector<vector<int>> (m+1, vector<int> (n+1,0));
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(i==1 and j==1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = dp[i-1][j];
                int left = dp[i][j-1];
        
                dp[i][j] = up+left;
                
            }
            
        }
        
        return dp[m][n];
        
    }
};
