class Solution {
public:
    
    int findParent(int node, vector<int> &parent){
        
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node],parent);
        
    }
    
    void doUnion(int u, int v, vector<int>& parent, vector<int> &rank){
        
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
    int minCostConnectPoints(vector<vector<int>>& points) {
     
        vector<vector<int>> edges;
        int np = points.size();
        
        vector<int> rank(np,0);
        vector<int> parent(np,0);
        
        for(int i=0;i<np;i++){
            
            for(int j=i+1;j<np;j++){
                
                int wt = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({wt,i,j});
        
                
            }
            parent[i] = i;            
        }
        
        sort(begin(edges),end(edges));
        int ans = 0;
        
        for(auto &x:edges){
            
            int wt = x[0];
            int u = x[1];
            int v = x[2];
            
            int parU = findParent(u,parent);
            int parV = findParent(v,parent);
            
            if(parU == parV)
                continue;
            
            doUnion(u,v,parent,rank);
            ans+=wt;
        }
        
        return ans;
        
    }
};
