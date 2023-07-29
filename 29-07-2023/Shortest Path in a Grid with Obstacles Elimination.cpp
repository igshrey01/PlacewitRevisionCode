//Link - https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    
    bool isSafe(int x, int y,int m, int n, int &k, vector<vector<int>> &grid){
        
        if(x<0 or y<0 or x>=m or y >= n)
            return false;
        
        if(grid[x][y])
        {
            if(k == 0)
                return false;
            
            k--;
        }
        return true;
        
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dist(m,vector<vector<int>> (n,vector<int>(k+1,INT_MAX)));
        
        vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};                                
        if(m==1 and n==1)
            return 0;
        
        queue<vector<int>> q;
        q.push({0,0,k});
        dist[0][0][k] = 0;
        int res = INT_MAX;
        
        while(!q.empty()){
            
            int x = q.front()[0];
            int y = q.front()[1];
            int currK = q.front()[2];
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int xn = x+moves[i][0];
                int yn = y+moves[i][1];
                int valK = currK;
                if(isSafe(xn,yn,m,n,valK,grid)){
                    
                    
                    if(dist[xn][yn][valK]>dist[x][y][currK]+1){
                        
                        dist[xn][yn][valK]=dist[x][y][currK]+1;
                        q.push({xn,yn,valK});
                        
                        if(xn == m-1 and yn == n-1)
                            return dist[xn][yn][valK];
                        
                    }
                    
                }
                
            }
            
            
        }                              
        
        return res == INT_MAX ? -1 : res;
    }
};
