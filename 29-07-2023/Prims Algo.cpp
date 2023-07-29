typedef pair<int,int> pi;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
     
        vector<int> key(V,INT_MAX);
        vector<bool> inMST(V,0);
        
        key[0] = 0;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({key[0],0});
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            pq.pop();
            inMST[node] = true;
            
            for(auto x:adj[node]){
                
                int adjNode = x[0];
                int wt = x[1];
                
                if(inMST[adjNode] == false and key[adjNode]>wt){
                    key[adjNode] = wt;
                    pq.push({key[adjNode],adjNode});
                }
                
            }

        }
        
        int sumMST = 0;
        for(auto x:key)
            sumMST+=x;
        return sumMST;
    }
};
