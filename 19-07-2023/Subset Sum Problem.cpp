//Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{   
public:

    int subsetSum(vector<int> &arr, int index, int sum, vector<vector<int>> &dp){
        
      
        if(index == 0){
            if(sum == 0) return 1;
            return 0;
        }
        
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        
        int notPick = subsetSum(arr,index-1,sum,dp);
        int pick = 0;
        
        if(sum>=arr[index-1])
            pick = subsetSum(arr,index-1,sum-arr[index-1],dp);
        
        return dp[index][sum] = pick or notPick;
        
    }
    bool isSubsetSum(vector<int> arr, int sum){
        // code here 
        int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        // return subsetSum(arr,n,sum,dp);
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
        dp[0][0] = 1;
        
        for(int index=1;index<=n;index++){
            
            for(int s=0;s<=sum;s++){
                
                int notPick = dp[index-1][s];
                int pick = 0;
        
                if(s>=arr[index-1])
                    pick = dp[index-1][s-arr[index-1]];
        
                dp[index][s] = pick or notPick;
                
            }
            
        }
        
        return dp[n][sum];
    }
};
