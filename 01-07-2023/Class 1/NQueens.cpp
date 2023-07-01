//Link - https://leetcode.com/problems/n-queens/

class Solution {
public:
    
    bool isSafeState(int x, int y, vector<string> &res ,int n){
        
        //Checking column
        for(int i=x-1;i>=0;i--){
            
            if(res[i][y] == 'Q'){
                return false;
            }
            
        }

        
        //Checking top left diagonal
        int i = x-1, j = y-1;
        
        while(i>=0 && j>=0){
            
            if(res[i][j] == 'Q')
                return false;
            
            i--;
            j--;
        }
        
        //Checking top right diagonal
        i=x-1,j=y+1;
        
        while(i>=0 && j<n){
            
            if(res[i][j] == 'Q')
                return false;
            
            i--;
            j++;
               
        }
        return true;
    }
    
     void solve(vector<string> &res, int n, int in,vector<vector<string>> &ans){
        
       if(in == n){
           ans.push_back(res);
           return;
       }
         
        for(int col=0;col<n;col++)
        {
            
            res[in][col] = 'Q';
            if(isSafeState(in,col,res,n)){
                solve(res,n,in+1,ans);
            }
            res[in][col] = '.';
            
        }        
    }
    vector<vector<string>> solveNQueens(int n) {
     
        vector<vector<string>> ans;
        vector<string> res(n,string (n,'.'));
        
        solve(res,n,0,ans);
        
        return ans;
        
    }
};
