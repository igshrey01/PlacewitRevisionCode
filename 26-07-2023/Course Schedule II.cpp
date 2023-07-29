//Link - https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<int> adj[n];
        
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> indegree(n,0);
       
       for(int i=0;i<n;i++){
           
           for(auto x:adj[i])
               indegree[x]++;
           
       }
       
       //2nd step = Push elements whose indegree is 0 in queue
       queue<int> q;
       
       for(int i=0;i<n;i++){
           if(indegree[i] == 0)
               q.push(i);
       }
       
       vector<int> res;
       
       while(!q.empty()){
           
           int node = q.front();
           q.pop();
           res.push_back(node);
           
           for(auto adjNode:adj[node]){
               
               indegree[adjNode]--;
               if(indegree[adjNode] == 0)
                   q.push(adjNode);
                    
               
           }
           
       }
       
        if(res.size() != n){
            return {};
        }
       return res;
    }
};
