class Solution {
    
    vector<vector<int>> dp;
    
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        // dp = vector<vector<int>> (n+1,vector<int> (amount+1,-1));
        // int val = minCoins(coins,n,amount);
        // return  val>= 1e8 ? -1 : val ;
        
        //dp = vector<vector<int>> (n+1,vector<int> (amount+1,0));
        
        vector<int> prev(amount+1,0);
        for(int i=1;i<=amount;i++)
            prev[i] = 1e8;
        
        prev[0] = 0;
        
        for(int index=1;index<=n;index++){
            
            vector<int> curr(amount+1,0);
            for(int am=1;am<=amount;am++){
                
                int notPick = prev[am];
                int pick = 1e8;
        
                if(am>=coins[index-1])
                    pick = 1+curr[am-coins[index-1]];
        
                curr[am] = min(pick,notPick);
                    
            }
            
            prev = curr;
            
        }
        int val = prev[amount];
        return  val>= 1e8 ? -1 : val ;
    }
};
