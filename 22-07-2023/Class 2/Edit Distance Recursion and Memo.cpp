class Solution {
    
    vector<vector<int>> dp;
public:
    
    int minDist(string &text1, string &text2, int m, int n){
        
        if(m == 0)  return n;
        if(n == 0)  return m;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        if(text1[m-1] == text2[n-1])
            return dp[m][n] = minDist(text1,text2,m-1,n-1);
        else{
            
            int insertC = 1+minDist(text1,text2,m,n-1);
            int deleteC = 1+minDist(text1,text2,m-1,n);
            int replaceC = 1+minDist(text1,text2,m-1,n-1);
            
            return dp[m][n] = min({insertC,deleteC,replaceC});
            
        }
        
    }
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        dp = vector<vector<int>> (m+1,vector<int> (n+1,-1));
        return minDist(word1,word2,m,n);
        
    }
};
