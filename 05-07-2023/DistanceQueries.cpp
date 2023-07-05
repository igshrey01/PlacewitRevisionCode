#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
 
#define for_n(i,n) for(int i = 0; i < n; i++)
 
void dfs(int node, vi adj[], int par, vi &tin, vi &tout, vvi &dp, int &timer, int l, int level,vi &dist){
 
    tin[node] = ++timer;
    dist[node] = level;
 
    dp[node][0] = par;
 
    for(int i=1;i<=l;i++)
        dp[node][i] = dp[dp[node][i-1]][i-1];
    
    for(auto x:adj[node]){
 
        if(x!=par)
            dfs(x,adj,node,tin,tout,dp,timer,l,level+1,dist);
 
    }
 
    tout[node] = ++timer;
 
}
 
bool isAncestor(int u, int v, vi &tin, vi &tout){
 
    return tin[u]<=tin[v] and tout[v]<=tout[u];
 
}
signed main(){
    
    int t;
    t=1;
    //cin>>t;
    while(t--){
        
        int n,q;
        cin>>n>>q;
 
        vi adj[n+1];
        for(int i=1;i<n;i++){
 
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
 
        }
 
        vi tin(n+1,0),tout(n+1,0),dist(n+1,0);
        
        int l = ceil(log2(n));
        vvi dp(n+1,vi(l+1,0));
        int timer = 0;
 
        dfs(1,adj,0,tin,tout,dp,timer,l,0,dist);
 
        for(int i=0;i<q;i++){

            int u,v;
            cin>>u>>v;
            int inU = u;
            if(isAncestor(u,v,tin,tout)){
                cout<<dist[v]-dist[u]<<"\n";
            }
            else if(isAncestor(v,u,tin,tout)){
                cout<<dist[u]-dist[v]<<"\n";
            }
            else{

                for(int j=l;j>=0;j--){

                    if(dp[u][j]!=0 and !isAncestor(dp[u][j],v,tin,tout))
                        u = dp[u][j];

                }
                int lca = dp[u][0];
                cout<<dist[inU]+dist[v]-2*dist[lca]<<"\n";

            }

        }
 
	}
}
