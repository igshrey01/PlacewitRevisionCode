#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
 
#define for_n(i,n) for(int i = 0; i < n; i++)
 
void dfs(int node, vi adj[], int par, vi &tin, vi &tout, vvi &dp, int &timer, int l){
 
    tin[node] = ++timer;
 
    dp[node][0] = par;
 
    for(int i=1;i<=l;i++)
        dp[node][i] = dp[dp[node][i-1]][i-1];
    
    for(auto x:adj[node]){
 
        if(x!=par)
            dfs(x,adj,node,tin,tout,dp,timer,l);
 
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
        for(int i=2;i<=n;i++){
 
            int tmp;
            cin>>tmp;
 
            adj[tmp].push_back(i);
            adj[i].push_back(tmp);
 
        }
 
        vi tin(n+1,0),tout(n+1,0);
        
        int l = ceil(log2(n));
        vvi dp(n+1,vi(l+1,0));
        int timer = 0;
 
        dfs(1,adj,0,tin,tout,dp,timer,l);
 
        for(int i=0;i<q;i++){

            int u,v;
            cin>>u>>v;

            if(isAncestor(u,v,tin,tout)){
                cout<<u<<"\n";
            }
            else if(isAncestor(v,u,tin,tout)){
                cout<<v<<endl;
            }
            else{

                for(int j=l;j>=0;j--){

                    if(dp[u][j]!=0 and !isAncestor(dp[u][j],v,tin,tout))
                        u = dp[u][j];

                }

                cout<<dp[u][0]<<"\n";

            }

        }
 
	}
}
