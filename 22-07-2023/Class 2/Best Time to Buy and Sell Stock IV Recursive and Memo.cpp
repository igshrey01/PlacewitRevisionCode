class Solution {
public:
    int maximumProfit(vector<int>& prices, int index, int buy,int n,int k, vector<vector<vector<int>>> &dp){
        
        //Base Cases
        if(index == n or k==0)
            return 0;
        
        if(dp[index][buy][k]!=-1)
            return dp[index][buy][k];
        
        int profit = 0;
        if(buy){
            
            int notPick = maximumProfit(prices,index+1,buy,n,k,dp);
            int pick = maximumProfit(prices,index+1,1-buy,n,k,dp)-prices[index];
            profit = max(pick,notPick);
        }
        else{
            
            int notPick = maximumProfit(prices,index+1,buy,n,k,dp);
            int pick = maximumProfit(prices,index+1,1-buy,n,k-1,dp)+prices[index];
            profit = max(pick,notPick);
            
        }
        
        return dp[index][buy][k] = profit;
        
    }
    int maxProfit(int k,vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return maximumProfit(prices,0,1,n,k,dp);
    }
};
