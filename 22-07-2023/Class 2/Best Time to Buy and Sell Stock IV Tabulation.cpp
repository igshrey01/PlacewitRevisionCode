class Solution {
public:
    
    int maxProfit(int k,vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));
        
        for(int index=n-1;index>=0;index--){
            
            for(int buy=0;buy<2;buy++){
                
                for(int kk=1;kk<=k;kk++){
                    
                    int profit = 0;
                    if(buy){
            
                        int notPick = dp[index+1][buy][kk];
                        int pick = dp[index+1][1-buy][kk]-prices[index];
                        profit = max(pick,notPick);
                    }
                    else{
            
                        int notPick = dp[index+1][buy][kk];
                        int pick = dp[index+1][1-buy][kk-1]+prices[index];
                        profit = max(pick,notPick);
            
                    }
        
                    dp[index][buy][kk] = profit;
                    
                    
                }
                
            }
            
        }
        return dp[0][1][k];
    }
};
