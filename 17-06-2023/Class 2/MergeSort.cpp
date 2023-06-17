class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
        
        vector<int> tmp(high-low+1);
        int left = low;
        int right = mid+1;
        int k = 0;
        while(left<=mid and right<=high){
            
            if(arr[left]>=arr[right]){
                tmp[k] = arr[right];
                right++;
            }
            else{
                tmp[k] = arr[left];
                left++;
            }
            
            k++;
            
        }
        
        while(left<=mid){
            tmp[k++] = arr[left++];
        }
        
        while(right<=high){
            tmp[k++] = arr[right++];
        }
        
        
        for(int i=low;i<=high;i++){
            
            arr[i] = tmp[i-low];
            //cout<<tmp[i-low]<<" ";
        }
        
        //cout<<endl;
         // Your code here
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l == r)
            return;
        
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
