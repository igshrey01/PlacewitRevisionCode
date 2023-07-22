class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp = vector<vector<int>> (m+1,vector<int> (n+1,0));
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
                cout<<dp[i][j]<<" ";
                
            }
            
            cout<<endl;
            
        }
        
        string res;
        
        int i=m,j=n;
        
        while(i>0 and j>0){
            
            if(text1[i-1] == text2[j-1]){
                res+=text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                
                res+=text1[i-1];
                i--;
                
            }
            else{
                
                res+=text2[j-1];
                j--;
            }
            
        }
        
        while(i>0)
        {
            res+=text1[i-1];
            i--;
        }
        
        while(j>0){
            res+=text2[j-1];
            j--;
        }
        
        reverse(begin(res),end(res));
        return res;
        
       
    }
};
