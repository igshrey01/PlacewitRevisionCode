//Link = https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int findParent(int node, vector<int> &parent){
        
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node],parent);
        
    }
    
    void doUnion(int u, int v, vector<int> &parent, vector<int> &rank){
        
        int parU = findParent(u,parent);
        int parV = findParent(v,parent);
        
        if(parU == parV)
            return;
        
        if(rank[parU]<rank[parV]){
            parent[parU] = parV;
        }
        else if(rank[parU]>rank[parV]){
            parent[parV] = parU;
        }
        else{
            rank[parU]++;
            parent[parV] = parU;
        }
        
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<vector<int>> edges;
        
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                edges.push_back({x[1],i,x[0]});
            }
        }
        
        sort(begin(edges),end(edges));
        int ans = 0;
        
        vector<int> parent(V,0);
        vector<int> rank(V,0);
        
        for(int i=0;i<V;i++)
            parent[i] = i;
        
        for(auto x:edges){
            
            int wt = x[0];
            int u = x[1];
            int v = x[2];
            
            int parU = findParent(u,parent);
            int parV = findParent(v,parent);
            
            
            if(parU == parV)
                continue;
            
            ans+=wt;
            doUnion(u,v,parent,rank);
            
        }    
        
        return ans;
        
    }
};
