//Link - https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int> adj[n];
        
        for(auto x:pre)
            adj[x[1]].push_back(x[0]);
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            
            for(auto x:adj[i])
                indegree[x]++;
            
        }
        
        queue<int> q;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            
            if(indegree[i] == 0)
                q.push(i);
            
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto x:adj[node]){
                
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
                
            }
            
        }
        
        return res.size() == n;
        
        
    }
};
