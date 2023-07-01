//Link - https://leetcode.com/problems/subsets/

class Solution {
public:
    
    void generateSubset(vector<int>& nums, int in , int n, vector<int>& temp, vector<vector<int>>& res){
        
        if(in == n){
            res.push_back(temp);
            return;
        }
        
        //notPick
        generateSubset(nums,in+1,n,temp,res);
        
        //pick
        temp.push_back(nums[in]);
        generateSubset(nums,in+1,n,temp,res);
        temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n  = nums.size();
        vector<vector<int>> res;
//         vector<int> tmp;
//         generateSubset(nums,0,n,tmp,res);
        
        for(int i=0;i<(1<<n);i++){
            
            vector<int> temp;
            int tmpN = i;
            
            for(int j=0;j<n;j++){
                
                if(tmpN%2){
                    temp.push_back(nums[j]);
                }
                
                tmpN/=2;
                
            }
            
            res.push_back(temp);
        }
        
        return res;
        
    }
};
