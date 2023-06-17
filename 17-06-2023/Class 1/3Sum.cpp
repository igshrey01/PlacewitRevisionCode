class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(begin(nums),end(nums));
        
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++){
            
            int low = i+1,high = n-1;
            
            while(low<high){
                
                long long tar = (long long)nums[low]+(long long)nums[high]+(long long)nums[i];
                
                if(tar == 0){
                    
                    vector<int> triple = {nums[i],nums[low],nums[high]};
                    
                    while(low<high and nums[low] == triple[1])
                        low++;
                    
                    while(low<high and nums[high] == triple[2])
                        high--;
                    
                    res.push_back(triple);
                    
                }
                
                else if(tar>0)
                    high--;
                
                else
                    low++;
                
            }
            
            while(i+1<n and nums[i] == nums[i+1])
                i++;
            
        }
        
        return res;
    }
};
