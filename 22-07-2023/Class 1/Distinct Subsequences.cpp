class Solution {
public:
    
    long double countSub(string &s, string &t, int m, int n, vector<vector<long double>> &dp){
        
        if(n == 0)
            return 1;
        
        if(m == 0)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        if(s[m-1] == t[n-1])
            return dp[m][n] = countSub(s,t,m-1,n-1,dp)+countSub(s,t,m-1,n,dp);
        else
            return dp[m][n] = countSub(s,t,m-1,n,dp);
        
    }
    int numDistinct(string s, string t) {
        
        int m = s.size(),n=t.size();
        vector<vector<long double>> dp(m+1,vector<long double> (n+1,-1));
        return countSub(s,t,m,n,dp);
        
//         vector<vector<long double>> dp(m+1,vector<long double> (n+1,0));
        
//         for(int i=0;i<=m;i++)
//             dp[i][0] = 1;
        
//         for(int i=1;i<=m;i++){
            
//             for(int j=1;j<=n;j++){
                
//                 if(s[i-1] == t[j-1])
//                     dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
//                 else
//                     dp[i][j] = dp[i-1][j];
                
//             }
            
//         }
        
//         return dp[m][n];
        
    }
};
