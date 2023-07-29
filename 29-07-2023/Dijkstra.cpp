//Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        
        while(!pq.empty()){
            
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto x:adj[node]){
                
                int adjNode = x[0];
                int wt = x[1];
                
                if(dist[adjNode]>currDist+wt){
                    
                    dist[adjNode] = wt+currDist;
                    pq.push({dist[adjNode],adjNode});
                    
                }
                
            }
            
        }
        
        return dist;
    }
};
