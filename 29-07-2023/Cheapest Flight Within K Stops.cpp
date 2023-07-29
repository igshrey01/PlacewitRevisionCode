//Link - https://leetcode.com/problems/cheapest-flights-within-k-stops/

typedef vector<int> vi;

//{dist,remK,node}
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        k++;
        vector<vector<int>> dist(n,vector<int> (k+1,INT_MAX));
        
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        pq.push({0,k,src});
        dist[src][k] = 0;
        
        while(!pq.empty()){
            
            int currDist = pq.top()[0];
            int remK = pq.top()[1];
            int node = pq.top()[2];
            
            pq.pop();
            
            if(node == dst)
                return currDist;
            
            if(remK == 0)
                continue;
            
            for(auto x:adj[node]){
                
                int adjNode = x.first;
                int wt = x.second;
                
                if(dist[adjNode][remK-1]>currDist+wt){
                    
                    dist[adjNode][remK-1] = currDist+wt;
                    pq.push({dist[adjNode][remK-1],remK-1,adjNode});
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};
