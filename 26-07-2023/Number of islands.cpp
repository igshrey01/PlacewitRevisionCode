//Link - https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    void dfs(int row, int col, int m, int n, vector<vector<char>> &grid){
        
        if(row<0 or col<0 or row == m or col == n)
            return;
        
        if(grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        
        dfs(row-1,col,m,n,grid);
        dfs(row+1,col,m,n,grid);
        dfs(row,col-1,m,n,grid);
        dfs(row,col+1,m,n,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m =grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(i,j,m,n,grid);
                }
            
            }
            
        }
        
        return ans;
        
    }
};
