class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        
        int ansXor = 0;
        for(int i=1;i<=n;i++)
            ansXor = ansXor xor i;
        
        for(auto x:array)
            ansXor = ansXor xor x;
        
        return ansXor;
    }
};
