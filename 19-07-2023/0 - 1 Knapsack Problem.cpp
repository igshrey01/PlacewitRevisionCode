class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int maxValue(int wt[] , int val[] , int i , vector<vector<int>>&dp, int W){
        if(i==0){
            return 0;
        }
        
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        int notpick = maxValue(wt,val,i-1,dp,W);
        int pick = INT_MIN;
        if(W-wt[i-1]>=0){
            pick = val[i-1] + maxValue(wt,val,i-1,dp,W-wt[i-1]);
        }
        
        return dp[i][W] = max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       //return maxValue(wt,val,n,dp,W);
       
       for(int i=1;i<=n;i++){
           
           for(int w=0;w<=W;w++){
               
                int notpick = dp[i-1][w];
                int pick = INT_MIN;
                if(w-wt[i-1]>=0){
                    pick = val[i-1] + dp[i-1][w-wt[i-1]];
                }
        
                dp[i][w] = max(pick,notpick);
               
           }
           
           //prev = curr
       }
       
       return dp[n][W];
       
    }
};
