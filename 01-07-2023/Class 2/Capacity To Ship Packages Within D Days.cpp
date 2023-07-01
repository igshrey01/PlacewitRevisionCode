//Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    bool check(vector<int>&weights,int days,int mid){
        int temp=0;
        int ct=1;
        for(auto x:weights){
            temp+=x;
            if(temp>mid){
                ct++;
                temp=x;
            }
        }
        if(ct<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int e=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
