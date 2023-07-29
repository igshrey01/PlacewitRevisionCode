//Link - https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n,1e9);
	    dist[0] = 0;
	    
	    for(int i=1;i<=n;i++){
	       
	       for(auto x:edges){
	           int u = x[0];
	           int v = x[1];
	           int wt = x[2];
	           
	           if(dist[v]>dist[u]+wt){
	               dist[v] = dist[u]+wt;
	               if(i == n){
	                   return 1;
	               }
	           }
	       }
	       
	    }
	    
	    return 0;
	    
	}
};
