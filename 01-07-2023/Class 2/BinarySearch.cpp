//Link - https://leetcode.com/problems/binary-search/

class Solution {
public:
    
    int bSearch(vector<int>& nums, int target, int low, int high){
        
        if(low>high)
            return -1;
        
        int mid = low+(high-low)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid]>target)
            return bSearch(nums,target,low,mid-1);
        else
            return bSearch(nums,target,mid+1,high);
        
    }
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size()-1;
        
//         while(low<=high){
            
//             int mid = low+(high-low)/2;
//             if(nums[mid] == target)
//                 return mid;
            
//             if(nums[mid]>target)
//                 high = mid-1;
//             else
//                 low = mid+1;
            
//         }
        
        //return -1
        return bSearch(nums,target,low,high);
        
    }
};
