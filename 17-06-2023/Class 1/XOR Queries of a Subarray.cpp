class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n=arr.size();
        vector<int> prefixXor(n,0);
        vector<int> res;
        prefixXor[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixXor[i]=prefixXor[i-1]^arr[i];
        }
        int m=queries.size();
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0){
                res.push_back(prefixXor[r]);
            }
            else{
                res.push_back(prefixXor[l-1]^prefixXor[r]);
            }
        }
        return res;
    }
};
