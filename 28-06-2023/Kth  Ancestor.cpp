//Link - https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
    
    vector<vector<int>> dp;
    int maxL = 0;
    
public:
    
    void preCompute(int node, int par, vector<int> adj[], int l){
        
        dp[node][0] = par;
        for(int i=1;i<=l;i++)
            dp[node][i] = dp[dp[node][i-1]][i-1];
        
        for(auto x:adj[node]){
            
            if(x!=par){
                preCompute(x,node,adj,l);
            }
            
        }
        
    }
    TreeAncestor(int n, vector<int>& parent) {
        
        dp.resize(n+1);
        int l = ceil(log2(n));
        maxL = l;
        for(int i=0;i<=n;i++)
            dp[i].resize(l+1);
        
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++){
            
            adj[i+1].push_back(parent[i]+1);
            adj[parent[i]+1].push_back(i+1);
            
        }
        
        preCompute(1,0,adj,l);
        //Time complexity of precomputation - O(n logn)
//         for(auto x:dp){
            
//             for(auto y:x)
//                 cout<<y<<" ";
            
//             cout<<endl;
            
//         }
        
    }
    
    int getKthAncestor(int node, int k) {
        
        node++;
        for(int i=0;i<=maxL;i++){
            
            if(k%2){
                node = dp[node][i];
            }
            
            k/=2;
            
        }
        
        return node-1;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
