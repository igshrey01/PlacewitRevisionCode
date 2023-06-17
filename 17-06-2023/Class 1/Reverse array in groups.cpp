class Solution{
public:
    //Function to reverse every sub-array group of size k.
    
    void reverseGroup(vector<long long>& arr, int low, int high){
        
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
        
    }
    void reverseInGroups(vector<long long>& arr, int n, int k){
        
        int start = 0;
        
        while(start<n){
            
            int end = start+k-1;
            end = min(n-1,end);
            reverseGroup(arr,start,end);
            start+=k;
            
        }
        
    }
};
