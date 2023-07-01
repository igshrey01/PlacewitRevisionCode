//Link - https://leetcode.com/problems/combination-sum/

class Solution {
    
    vector<vector<int>> res;
    vector<int> tmp;
public:
    
    void findCombination(vector<int>& candidates, int target, int in, int n){
        
        if(in == n){
            
            if(target == 0)
                res.push_back(tmp);
            
            return;
            
        }
        
        //notPick
        findCombination(candidates,target,in+1,n);
        
        tmp.push_back(candidates[in]);
        if(target>=candidates[in])
            findCombination(candidates,target-candidates[in],in,n);
        
        tmp.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        findCombination(candidates,target,0,n);
        
        return res;
        
    }
};
