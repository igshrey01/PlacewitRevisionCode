class Solution {
    
    vector<vector<int>> dp;
public:
    
    int findLCS(string &text1, string &text2, int m ,int n){
        
        if(m == 0 or n == 0)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        if(text1[m-1] == text2[n-1])
            return dp[m][n] = 1+findLCS(text1,text2,m-1,n-1);
        else
            return dp[m][n] = max(findLCS(text1,text2,m-1,n),findLCS(text1,text2,m,n-1));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        // dp = vector<vector<int>> (m+1,vector<int> (n+1,-1));
        
        // return findLCS(text1,text2,m,n);
        
        dp = vector<vector<int>> (m+1,vector<int> (n+1,0));
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
            }
            
        }
        
        return dp[m][n];
    }
};
