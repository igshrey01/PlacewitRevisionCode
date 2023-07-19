//Link - https://leetcode.com/problems/coin-change-ii/

class Solution {
    
    vector<vector<int>> dp;
public:
    
    int totalCombination(int index,int amount, vector<int>& coins){
        
        if(index == 0){
            
            if(amount == 0) return 1;
            return 0;
            
        }
        
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        int notPick = totalCombination(index-1,amount,coins);
        int pick = 0;
        
        if(amount>=coins[index-1])
            pick = totalCombination(index,amount-coins[index-1],coins);
        
        return dp[index][amount] = pick+notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        // dp = vector<vector<int>> (n+1,vector<int> (amount+1,-1));
        // return totalCombination(n,amount,coins);
        dp = vector<vector<int>> (n+1,vector<int> (amount+1,0));
        
        dp[0][0] = 1;
        
        for(int index=1;index<=n;index++){
            
            for(int am=0;am<=amount;am++){
                
                int notPick = dp[index-1][am];
                int pick = 0;
        
                if(am>=coins[index-1])
                    pick = dp[index][am-coins[index-1]];
        
                dp[index][am] = pick+notPick;
                
            }
            
        }
        
        return dp[n][amount];
        
    }
};
