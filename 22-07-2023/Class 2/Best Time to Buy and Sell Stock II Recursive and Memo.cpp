class Solution {
    vector<vector<int>> dp;
public:
    
    int maxProfitEarned(vector<int>& prices, int index, int n, int buy) {
        
        if(index == n)
            return 0;
        
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        
        if(buy){
            
            int notPick = maxProfitEarned(prices,index+1,n,buy);
            int pick = maxProfitEarned(prices,index+1,n,1-buy)-prices[index];
            return dp[index][buy] = max(pick,notPick);
            
        }
        else{
            
            int notPick = maxProfitEarned(prices,index+1,n,buy);
            int pick = maxProfitEarned(prices,index+1,n,1-buy)+prices[index];
            return dp[index][buy] = max(pick,notPick);
            
        }
        
        
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        dp = vector<vector<int>> (n,vector<int> (2,-1));
        return maxProfitEarned(prices,0,n,1);
        
    }
};
