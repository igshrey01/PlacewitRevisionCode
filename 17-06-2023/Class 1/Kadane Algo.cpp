class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int currSum = 0, maxSum = INT_MIN;
        
        for(auto x:nums){
            
            currSum+=x;
            maxSum = max(maxSum,currSum);
            currSum = max(0,currSum);
            
        }
        
        return maxSum;
    }
};
