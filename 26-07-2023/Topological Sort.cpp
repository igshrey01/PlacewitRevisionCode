//Link - https://practice.geeksforgeeks.org/problems/topological-sort/1
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    //1st step - Find indegree of each node
	    
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        
	        for(auto x:adj[i])
	            indegree[x]++;
	        
	    }
	    
	    //2nd step = Push nodes in the queue whose indegree is 0
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        
	        if(indegree[i] == 0)
	            q.push(i);
	        
	    }
	    
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        topo.push_back(node);
	        q.pop();
	        
	        for(auto adjNode:adj[node]){
	            
	            indegree[adjNode]--;
	            if(indegree[adjNode] == 0)
	                q.push(adjNode);
	            
	        }
	        
	        
	    }
	    
	    return topo;
	    
	}
};
