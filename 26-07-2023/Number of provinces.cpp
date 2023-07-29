//Link - https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    
    void dfs(int node, vector<int> adj[],vector<int>&visited){
        visited[node]=1;
        
        for(auto adjnode : adj[node]){
            if(!visited[adjnode]){
                dfs(adjnode,adj,visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int>visited(n,0);
         vector<int>adj[n];
         int count=0;
         for(int i=0;i<n;i++)
         {
             // conversion into adjacent matrix
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                    adj[i].push_back(j);
            }
             
            
         }      
        
         for(int i=0;i<n;i++) 
         {
            if(!visited[i])
            {
             dfs(i, adj, visited);
                count++;
            } 
         }
        
        
        return count;
    }
    
};
