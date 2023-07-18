class Solution {
    
    vector<vector<int>> dp;
public:
  
    int uniquePaths(int m, int n) {
        
        //dp = vector<vector<int>> (m+1, vector<int> (n+1,0));
        //return countWays(m,n);
        
        vector<int> prev(n+1,0);
        for(int i=1;i<=m;i++){
            
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                
                if(i==1 and j==1)
                {
                    curr[j] = 1;
                    continue;
                }
                
                int up = prev[j];
                int left = curr[j-1];
        
                curr[j] = up+left;
                
            }
            
            prev = curr;
            
        }
        
        return prev[n];
        
    }
};
