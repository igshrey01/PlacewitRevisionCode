//Link - https://leetcode.com/problems/coin-change/
class Solution {
    
    vector<vector<int>> dp;
    
public:
    
    int minCoins(vector<int>& coins, int index, int amount){
        
        if(index == 0){
            
            if(amount>0)    return 1e8;
            return 0;
            
        }
        
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int notPick = minCoins(coins,index-1,amount);
        int pick = 1e8;
        
        if(amount>=coins[index-1])
            pick = 1+minCoins(coins,index,amount-coins[index-1]);
        
        return dp[index][amount] = min(pick,notPick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        // dp = vector<vector<int>> (n+1,vector<int> (amount+1,-1));
        // int val = minCoins(coins,n,amount);
        // return  val>= 1e8 ? -1 : val ;
        
        dp = vector<vector<int>> (n+1,vector<int> (amount+1,0));
        
        for(int i=1;i<=amount;i++)
            dp[0][i] = 1e8;
        
        dp[0][0] = 0;
        
        for(int index=1;index<=n;index++){
            
            for(int am=1;am<=amount;am++){
                
                int notPick = dp[index-1][am];
                int pick = 1e8;
        
                if(am>=coins[index-1])
                    pick = 1+dp[index][am-coins[index-1]];
        
                dp[index][am] = min(pick,notPick);
                    
            }
            
        }
        int val = dp[n][amount];
        return  val>= 1e8 ? -1 : val ;
    }
};
