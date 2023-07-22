class Solution {
    vector<vector<int>> dp;
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        dp = vector<vector<int>> (n+1,vector<int> (2,0));
        
        for(int index=n-1;index>=0;index--){
            
            for(int buy=0;buy<2;buy++){
                
                if(buy){
            
                    int notPick = dp[index+1][buy];
                    int pick = dp[index+1][1-buy]-prices[index];
                    dp[index][buy] = max(pick,notPick);
            
                }
                else{
            
                    int notPick = dp[index+1][buy];
                    int pick = dp[index+1][1-buy]+prices[index];
                    dp[index][buy] = max(pick,notPick);
            
                }
                
            }
            
        }
        
        return dp[0][1];
        
    }
};
