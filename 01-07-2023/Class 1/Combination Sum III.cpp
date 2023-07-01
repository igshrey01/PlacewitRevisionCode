//Link - https://leetcode.com/problems/combination-sum-iii/

class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    
public:
    
    void findComb(int num, int in, int k, int target){
        
        if(num == 10){
            
            if(target == 0 and in == k)
                ans.push_back(temp);
            
            return;
            
        }
        
        //notPick
        findComb(num+1,in,k,target);
        
        temp.push_back(num);
        if(target>=num)
            findComb(num+1,in+1,k,target-num);
        temp.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        findComb(1,0,k,n);
        return ans;
        
    }
};
