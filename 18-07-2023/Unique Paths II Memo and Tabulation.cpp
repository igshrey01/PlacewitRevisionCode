class Solution {
    vector<vector<int>> dp;
    
public:
    
    int countWays(int m, int n, vector<vector<int>>& obstacleGrid){
        
        
        if(m==0 or n==0 or obstacleGrid[m-1][n-1])
            return 0;
        
        if(m==1 and n==1)
            return 1;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int up = countWays(m-1,n,obstacleGrid);
        int left = countWays(m,n-1,obstacleGrid);
        
        return dp[m][n] = up+left;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        dp = vector<vector<int>> (m+1, vector<int> (n+1,0));
        //return countWays(m,n,obstacleGrid);
        
        if(obstacleGrid[0][0])
            return 0;
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(i==1 and j==1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                if(obstacleGrid[i-1][j-1] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                int up = dp[i-1][j];
                int left = dp[i][j-1];
        
                dp[i][j] = up+left;
                
                //cout<<dp[i][j]<<" ";
            }
            
            //cout<<endl;
            
        }
        
        return dp[m][n];
    }
};
